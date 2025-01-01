/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IpduM_Container.c
 *      Project:  MICROSAR IpduM
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Microsar IPDU Multiplexer source file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define IPDUM_CONTAINER_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "IpduM.h"
#include "IpduM_Container.h"
#include "SchM_IpduM.h"
#include "vstdlib.h"
#include "PduR_IpduM.h"

#if (IPDUM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/
#define IPDUM_RESET                             0u

#define IPDUM_HEADERSIZE_SMALL                  4u
#define IPDUM_HEADERSIZE_LARGE                  8u

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
#define IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

/* Stores the information about the header of a contained pdu. */
typedef struct
{
  uint32 headerId;
  uint32 dlc;
} IpduM_ContainedPduHeaderType;  /* PRQA S 3205 */ /* MD_IpduM_3205 */

#define IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define IPDUM_START_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_WriteHeader()
*******************************************************************************************/
/*! \brief        Writes the header to the container PDU buffer.
 *  \details      The caller has to ensure there is enough free space in the buffer!
 *  \param[in]    pContainerBuf   Pointer to buffer containing container PDU
 *  \param[in]    headerId          Header information: ID
 *  \param[in]    dlc               Header information: DLC
 *  \param[in]    headerSize
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different buffers
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_WriteHeader(P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf, uint32 headerId, uint32 dlc, PduLengthType headerSize);
#endif

#if ((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_Container_ReadHeader()
*******************************************************************************************/
/*! \brief        Reads the header from the start position of the provided buffer
 *  \details      -
 *  \param[in]    headerSize
 *  \param[in]    pContainerBuf   Pointer to buffer containing container PDU, must be at least headerSize bytes large!
 *  \return       header          Header at the beginning of the provided container PDU buffer
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different buffers
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(IpduM_ContainedPduHeaderType, IPDUM_CODE) IpduM_Container_ReadHeader(P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf, uint32 headerSize);
#endif

# if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_GetHeaderSize()
*******************************************************************************************/
/*! \brief        Gets header size for given container.
 *  \details      -
 *  \param[in]    rxContainerId
 *  \return       headerSize
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_ContainerRx_GetHeaderSize(IpduM_RxContainerPduIterType rxContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_GetHeaderSize()
*******************************************************************************************/
/*! \brief        Gets header size for given container.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       headerSize
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_ContainerTx_GetHeaderSize(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_GetAsPointer()
*******************************************************************************************/
/*! \brief        Returns the pointer and length of this queue instance via pduInfoPtr.
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx
 *  \return       pointer and length to this instance buffer
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(PduInfoType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_GetAsPointer(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx);
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_Get()
*******************************************************************************************/
/*! \brief        Copies the data from the queue instance to the destination buffer.
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx
 *  \param[out]   destBuffer pointer to the destination buffer
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_Get(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) destBuffer);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Init()
*******************************************************************************************/
/*! \brief        Initializes the request queue data structures.
 *  \details      -
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Init(void);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_IsEmpty()
*******************************************************************************************/
/*! \brief        Checks if the request queue for a given container is empty.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       TRUE if the queue has no PDUs
 *  \return       FALSE if there are PDUs in the queue
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_IsEmpty(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_ContainsPdu()
*******************************************************************************************/
/*! \brief        Checks if a Pdu is already queued in the request queue.
 *  \details      -
 *  \param[in]    txContainedId
 *  \return       TRUE if the PDU is in the container
 *  \return       FALSE if the PDU is not in the container
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_ContainsPdu(IpduM_TxContainedPduIterType txContainedId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_CalculateSize()
*******************************************************************************************/
/*! \brief        Calculates the size of data stored in the request queue (the DLCs combined)
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       Size of data stored in the request queue
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(PduLengthType, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_CalculateSize(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Put()
*******************************************************************************************/
/*! \brief        Adds a Pdu to the request queue.
 *  \details      -
 *  \param[in]    txContainedId
 *  \param[in]    sduLength       length of the received PDU for size estimation
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Put(IpduM_TxContainedPduIterType txContainedId, PduLengthType sduLength);
#endif

#if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TransmitEmptyPdu()
*******************************************************************************************/
/*! \brief        Sends an empty PDU with DLC=0 with the given Container PDU ID.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       E_OK            Transmission was successful
 *  \return       E_NOT_OK        Transmission was unsuccessful
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TransmitEmptyPdu(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_RestoreReadIDs
*******************************************************************************************/
/*! \brief        Restores the read IDs inside the FillLastIsBestContainer API.
 *  \details      The restore point is set by IpduM_ContainerTx_RequestQueue_SetRestorePoint.
 *                Both APIs must be called in the same exclusive area and this sequence must not be interrupted by other APIs.
 *                FillLastIsBestContainer API can also be used without the restore feature of the request queue.
 *  \param[in]    txContainerId   ID of the container PDU
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_RestoreReadIDs(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_SetRestorePoint
*******************************************************************************************/
/*! \brief        Marks the point from which the read operations from the queue can be restored.
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_SetRestorePoint(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Remove
*******************************************************************************************/
/*! \brief        Removes the oldest ID from the request queue.
 *  \details      -
 *  \param[in]    txRequestQueueIndirectionIdx
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Remove(IpduM_CRequestQueueInfoIterType txRequestQueueInfoIdx);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Peek
*******************************************************************************************/
/*! \brief        Read and return the oldest ID in the request queue without removing it.
 *  \details      -
 *  \param[in]    txRequestQueueIndirectionIdx
 *  \param[out]   containedPduId  ID of the Pdu
 *  \param[out]   containedPduLength  Length of the Pdu in the Transmit call
 *  \return       E_OK        Pdu available. Out parameter can be used.
 *                E_NOT_OK    No Pdu available. Out parameter must NOT be used.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Peek(IpduM_CRequestQueueInfoIterType txRequestQueueInfoIdx,
                                                                                        P2VAR(IpduM_TxContainedPduIdxOfRequestQueueBufferType, AUTOMATIC, IPDUM_APPL_DATA) containedPduId,
                                                                                        P2VAR(PduLengthType, AUTOMATIC, IPDUM_APPL_DATA) containedPduLength);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_FillLastIsBestContainer()
*******************************************************************************************/
/*! \brief        Fills the last-is-best buffer with data via trigger transmit
 *  \details      -
 *  \param[in]    txContainerId   ID of the container PDU
 *  \return       DataPtr and Length of the container PDU
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(PduInfoType, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_FillLastIsBestContainer(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_DirectDP()
*******************************************************************************************/
/*! \brief        Transmits request queue Container PDU with Direct DataProvision.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       E_OK            Transmission was successful, current instance is marked empty.
 *  \return       E_NOT_OK        Transmission was unsuccessful, current instance is untouched.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs.
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_DirectDP(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if ((IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_TriggerTxDP()
*******************************************************************************************/
/*! \brief        Transmits request queue Container PDU with TriggerTransmit DataProvision.
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs.
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_TriggerTxDP(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TriggerTransmission()
*******************************************************************************************/
/*! \brief        Trigger the transmission of a request queue container.
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs.
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TriggerTransmission(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu()
*******************************************************************************************/
/*! \brief        Queues Tx container queue.
 *  \details      If the queue is full: clears oldest item, throws DET, sets it as current.
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_AddPdu_DynamicLayout()
*******************************************************************************************/
/*! \brief        Adds contained PDU to current container PDU with dynamic layout.
 *  \details      -
 *  \param[in]    txContainedId
 *  \param[in]    PduInfoPtr      Pointer to the PDU data to be transmitted.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_AddPdu_DynamicLayout(IpduM_TxContainedPduIterType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if ((IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_AddPdu_StaticLayout()
*******************************************************************************************/
/*! \brief        Adds contained PDU to current container PDU with static layout.
 *  \details      -
 *  \param[in]    txContainedId
 *  \param[in]    PduInfoPtr      Pointer to the PDU data to be transmitted.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_AddPdu_StaticLayout(IpduM_TxContainedPduIterType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if ((IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_ClearBuffer()
*******************************************************************************************/
/*! \brief        Clear the queue instance buffer with the clearPattern.
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx Idx to the instance which shall be reset
 *  \param[in]    clearPattern
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_ClearBuffer(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, uint8 clearPattern);
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_ResetUpdateBits()
*******************************************************************************************/
/*! \brief        Resets the update bits used in a static layout.
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx Idx to the instance which shall be reset
 *  \param[in]    txContainerId Id to get the update bit positions
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_ResetUpdateBits(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, IpduM_CTxContainerPduIterType txContainerId);
#endif

#if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_SearchRxHeaderId()
*******************************************************************************************/
/*! \brief        Searches for the received Container PDU header ID in the list of Rx Contained PDUs.
 *  \details      -
 *  \param[in]    rxContainerPduIdx
 *  \param[in]    headerId               Header ID to be searched for.
 *  \param[out]   foundRxContainedPduId  ID of the found RxContainedPdu.
 *  \return       E_OK      Found a matching RxContainedPdu (returned via @foundRxContainedPduId)
 *                E_NOT_OK  Did not find any matching RxContainedPdu. @foundRxContainedPduId must not be used.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerRx_SearchRxHeaderId(IpduM_RxContainerPduIterType rxContainerPduIdx, uint32 headerId, P2VAR(IpduM_RxContainedPduIterType, AUTOMATIC, IPDUM_APPL_DATA) foundRxContainedPduId);
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Put()
*******************************************************************************************/
/*! \brief        Enqueue the rx Container Pdu
 *  \details      -
 *  \param[in]    rxContainerId     ID of the Container PDU.
 *  \param[in]    dataPtr           data pointer
 *  \param[in]    pduLength         actual length of the data
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_Queue_Put(IpduM_RxContainerPduIterType rxContainerId, P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength);
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Get()
*******************************************************************************************/
/*! \brief        Dequeue the rx Container Pdu
 *  \details      -
 *  \param[in]    rxContainerId     ID of the Container PDU.
 *  \param[out]   dataPtr           data pointer
 *  \param[in,out]pduLength         in: size of buffer; out: actual length of the data
 *  \return       E_OK              Pdu was read from the queue
 *                E_NOT_OK          No Pdu was read. Queue is empty.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerRx_Queue_Get(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, P2VAR(PduLengthType, AUTOMATIC, IPDUM_APPL_DATA) pduLength);
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Remove
*******************************************************************************************/
/*! \brief        Remove the oldest element from the Container Rx Queue.
 *  \details      -
 *  \param[in]    rxContainerId     ID of the Container PDU.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_Queue_Remove(IpduM_RxContainerPduIterType rxContainerId);
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Init
*******************************************************************************************/
/*! \brief        Initialize the container rx queue
 *  \details      -
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_Queue_Init(void);
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_IsFull
*******************************************************************************************/
/*! \brief        Returns if the queue is full.
 *  \details      -
 *  \param[in]    rxContainerId     ID of the Container PDU.
 *  \return       TRUE  queue is full
 *                FALSE queue is not full
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerRx_Queue_IsFull(IpduM_RxContainerPduIterType rxContainerId);
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_IsEmpty
*******************************************************************************************/
/*! \brief        Returns if the queue is empty.
 *  \details      -
 *  \param[in]    rxContainerId     ID of the Container PDU.
 *  \return       TRUE  queue is empty
 *                FALSE queue is not empty
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerRx_Queue_IsEmpty(IpduM_RxContainerPduIterType rxContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_IsTriggered()
*******************************************************************************************/
/*! \brief        Checks trigger conditions and returns the result.
 *  \details      -
 *  \param[in]    txContainedId
 *  \param[in]    containerLength
 *  \return       TRUE   Container is triggered.
 *                FALSE  Contianer is not triggered.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        SPEC-2068537, SPEC-6231909, SPEC-2068539, SPEC-2068543, SPEC-2068545, SPEC-2068549, SPEC-2068551, SPEC-2068552
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_IsTriggered(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, uint32 containerLength);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_Start
*******************************************************************************************/
/*! \brief        Start send timeouts after adding a PDU to a container
 *  \details      -
 *  \param[in]    txContainedId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_Start(IpduM_TxContainedPduIterType txContainedId);
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_SetContainerPduTimeout
*******************************************************************************************/
/*! \brief        Start container Pdu send timeout after adding the first PDUs to it
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        SPEC-2068537, SPEC-6231909, SPEC-2068539, SPEC-2068543, SPEC-2068545, SPEC-2068549, SPEC-2068551, SPEC-2068552
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_SetContainerPduTimeout(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_Stop
*******************************************************************************************/
/*! \brief        Stop container Pdu send timeout
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_Stop(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_SetContainedPduTimeout
*******************************************************************************************/
/*! \brief        Start/Update contained Pdu send timeout after adding new PDUs to it
 *  \details      -
 *  \param[in]    txContainedId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        SPEC-2068537, SPEC-6231909, SPEC-2068539, SPEC-2068543, SPEC-2068545, SPEC-2068549, SPEC-2068551, SPEC-2068552
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_SetContainedPduTimeout(IpduM_TxContainedPduIterType txContainedId);
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_IsRunning
*******************************************************************************************/
/*! \brief        Is the sendTimeout for the container Pdu running?
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_IsRunning(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_MainFunction
*******************************************************************************************/
/*! \brief        Cyclicly decrements the SendTimeout
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       TRUE   SendTimeout is expired
 *                FALSE  SendTimeout is still running
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_MainFunction(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty()
*******************************************************************************************/
/*! \brief        Checks if the FIFO for a given container is empty.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       TRUE if the FIFO is empty
 *  \return       FALSE if the FIFO it not empty
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IsFifoQueueFull()
*******************************************************************************************/
/*! \brief        Checks if the FIFO for a given container is full.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       TRUE if the FIFO is full
 *  \return       FALSE if the FIFO it not full
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IsFifoQueueFull(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_FitsPduIntoCurrentOpenInstance()
*******************************************************************************************/
/*! \brief        Checks if the provided Pdu fits into the open container instance
 *  \details      -
 *  \param[in]    txContainerId
 *  \param[in]    pduLength
 *  \return       TRUE if it fits
 *  \return       FALSE if it doesn't fit
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_DataQueue_FitsPduIntoCurrentOpenInstance(IpduM_CTxContainerPduIterType txContainerId, PduLengthType pduLength);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_GetFillCount
*******************************************************************************************/
/*! \brief        Return how much data is in the data queue instance
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx
 *  \return       amount of bytes
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(PduLengthType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_GetFillCount(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_Put
*******************************************************************************************/
/*! \brief        Put the provided Pdu into this queue Instance.
 *  \details      Pdu is written at the writeOffset position. This offset is zero based and only describes the position inside this queue instance.
 *  \param[in]    dataQueueInstanceIdx
 *  \param[in]    PduInfoPtr pointer to the Pdu which shall be put into the queue
 *  \param[in]    writeOffset
 *  \return       E_OK      put was successful
 *  \return       E_NOT_OK  put was not successful
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_Put(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr, PduLengthType writeOffset);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_PutHeader
*******************************************************************************************/
/*! \brief        Put the provided header into this queue instance.
 *  \details      The header is written at the writeOffset position. This offset is zero based and only describes the position inside this queue instance.
 *  \param[in]    dataQueueInstanceIdx
 *  \param[in]    writeOffset
 *  \param[in]    headerId
 *  \param[in]    dlc
 *  \param[in]    headerSize
 *  \return       E_OK     put header was successful
 *  \return       E_NOT_OK put header was not successful
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_PutHeader(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, PduLengthType writeOffset, uint32 headerId, uint32 dlc, uint8 headerSize);
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_SetBit
*******************************************************************************************/
/*! \brief        Set the bit @bitPosition.
 *  \details      The bitPosition is zero based. It indicates the bitPosition relative to the beginning of this queue instance.
 *  \param[in]    dataQueueInstanceIdx
 *  \param[in]    bitPosition
 *  \return       E_OK     the bit was set
 *  \return       E_NOT_OK the bit was not set
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_SetBit(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, uint16 bitPosition);
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_ClearBit
*******************************************************************************************/
/*! \brief        Clear the bit @bitPosition.
 *  \details      The bitPosition is zero based. It indicates the bitPosition relative to the beginning of this queue instance.
 *  \param[in]    dataQueueInstanceIdx
 *  \param[in]    bitPosition
 *  \return       E_OK     the bit was cleared
 *  \return       E_NOT_OK the bit was not cleared
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_ClearBit(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, uint16 bitPosition);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_GetFreeBytesCount
*******************************************************************************************/
/*! \brief        Return how much bytes are available in the queue instance
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx
 *  \return       amount of bytes
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(PduLengthType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_GetFreeBytesCount(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IncrementWritePtr
*******************************************************************************************/
/*! \brief        Increment the internal write pointer
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IncrementWritePtr(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IncrementReadPtr
*******************************************************************************************/
/*! \brief        Increment the internal read pointer
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IncrementReadPtr(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_Init
*******************************************************************************************/
/*! \brief        Clear the instance data buffer
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx instance to be cleared
 *  \param[in]    txContainerIdx id to find the optional update bit positions
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_Init(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, IpduM_CTxContainerPduIterType txContainerIdx);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_Init
*******************************************************************************************/
/*! \brief        Initializes all data queue related data structures
 *  \details      -
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_Init(void);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_TransmitContainerPdu_DirectDP()
*******************************************************************************************/
/*! \brief        Transmit the next container instance from the queue with direct data provision.
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       E_OK            Transmission was successful, last queue item is removed.
 *  \return       E_NOT_OK        Transmission was unsuccessful.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs.
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_TransmitContainerPdu_DirectDP(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_UnpackContainerPdu()
*******************************************************************************************/
/*! \brief        Retrieves all contained PDUs from the container PDU and sends RxIndications where configured.
 *  \details      -
 *  \param[in]    rxContainerId
 *  \param[in]    dataPtr        Pointer to the received PDU data.
 *  \param[in]    pduLength      Length of received rx container
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_UnpackContainerPdu(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength);
#endif

#if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_UnpackContainerPdu_DynamicLayout()
*******************************************************************************************/
/*! \brief        Retrieves all contained PDUs from a dynamic layout container PDU and sends RxIndications where configured.
 *  \details      -
 *  \param[in]    rxContainerId
 *  \param[in]    dataPtr        Pointer to the received PDU data.
 *  \param[in]    pduLength      Length of received rx container
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_UnpackContainerPdu_DynamicLayout(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength);
#endif

#if(IPDUM_EXISTS_NONE_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_UnpackContainerPdu_StaticLayout()
*******************************************************************************************/
/*! \brief        Retrieves all contained PDUs from a static layout container PDU and sends RxIndications where configured.
 *  \details      -
 *  \param[in]    rxContainerId
 *  \param[in]    dataPtr        Pointer to the received PDU data.
 *  \param[in]    pduLength      Length of received rx container
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_UnpackContainerPdu_StaticLayout(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu()
*******************************************************************************************/
/*! \brief        Transmits (if direct transmission configured) or queues current container PDU.
 *  \details      -
 *  \param[in]    txContainerId
 *  \param[in]    queueCurrentContainer shall the current container instance be queued before triggering its transmission.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu(IpduM_CTxContainerPduIterType txContainerId, boolean queueCurrentContainer);
#endif


#if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_StartTimeout()
*******************************************************************************************/
/*! \brief        Load TxConfirmation timeout counter
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConf_StartTimeout(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_StopTimeout()
*******************************************************************************************/
/*! \brief        Reset TxConfirmation timeout counter
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConf_StopTimeout(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_IsTransmissionAllowed
*******************************************************************************************/
/*! \brief        Is a transmission to the destination allowed
 *  \details      -
 *  \param[in]    txContainerId
 *  \return       TRUE  transmission is allowed
 *                FALSE transmission is not allowed
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_TxConf_IsTransmissionAllowed(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if ((IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_CopyContainedPduIDs2TxConfBuffer()
*******************************************************************************************/
/*! \brief        Copies the IDs of the to be confirmed contained Pdus of the queued container instance to the tx confirmation buffer.
 *  \details      -
 *  \param[in]    dataQueueInstanceIdx the IDs are copied from this queue instance idx
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different container IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_CopyContainedPduIDs2TxConfBuffer(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_AddPdu2IdBuffer()
*******************************************************************************************/
/*! \brief        Write contained PduID to TxConfirmation Buffer
 *  \details      -
 *  \param[in]    txContainedId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different contained IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_AddPdu2IdBuffer(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId);
#endif

#if((IPDUM_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON) && (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerTx_RequestQueueHandling_TriggerTransmit()
*******************************************************************************************/
/*! \brief          Requests the PDU data before transmission
 *  \details        -
 *  \param[in]      txContainerId
 *  \param[in,out]  PduInfoPtr    Pointer to lower layer buffer
 *  \return         E_OK          Data was copied correctly
 *  \return         E_NOT_OK      Data could not be copied correctly, PduInfoPtr does not contain valid data
 *  \pre            -
 *  \context        TASK|ISR
 *  \reentrant      TRUE for different handle IDs
 *  \synchronous    TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TriggerTransmit(IpduM_TxContainerPduIdxOfCTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if((IPDUM_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerTx_DataQueueHandling_TriggerTransmit()
*******************************************************************************************/
/*! \brief          Requests the PDU data before transmission
 *  \details        -
 *  \param[in]      txContainerId
 *  \param[in,out]  PduInfoPtr    Pointer to lower layer buffer
 *  \return         E_OK          Data was copied correctly
 *  \return         E_NOT_OK      Data could not be copied correctly, PduInfoPtr does not contain valid data
 *  \pre            -
 *  \context        TASK|ISR
 *  \reentrant      TRUE for different handle IDs
 *  \synchronous    TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_TriggerTransmit(IpduM_TxContainerPduIdxOfCTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_RequestQueueHandling_Transmit()
*******************************************************************************************/
/*! \brief        Requests the transmission of a contained PDU
 *  \details      -
 *  \param[in]    txContainedId
 *  \param[in]    PduInfoPtr    Pointer to payload buffer
 *  \return       E_OK          Transmit request was accepted by IpduM
 *  \return       E_NOT_OK      Transmit request was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_Transmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_DataQueueHandling_Transmit()
*******************************************************************************************/
/*! \brief        Requests the transmission of a contained PDU
 *  \details      -
 *  \param[in]    txContainedId
 *  \param[in]    PduInfoPtr    Pointer to payload buffer
 *  \return       E_OK          Transmit request was accepted by IpduM
 *  \return       E_NOT_OK      Transmit request was not accepted
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_Transmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_TxConfBuffer_Init()
*******************************************************************************************/
/*! \brief        Initializes all variables related to the Tx Confirmation Buffer
 *  \details      -
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Init(void);
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_TxConfBuffer_Put()
*******************************************************************************************/
/*! \brief        Puts the txConfId into the Tx Confirmation Buffer
 *  \details      -
 *  \param[in]    txContainerId
 *  \param[in]    txConfId      Id to put into the buffer
 *  \return       E_OK          Was put into the queue successfully.
 *  \return       E_NOT_OK      Wasn't put into the queue. Buffer is full.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Put(IpduM_CTxContainerPduIterType txContainerId, PduIdType txConfId);
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_TxConfBuffer_Get()
*******************************************************************************************/
/*! \brief        Gets the next Id from the Tx Confirmation Buffer
 *  \details      -
 *  \param[in]    txContainerId
 *  \param[out]   txConfId      Pdu Id which is returned
 *  \return       E_OK          Id was read successfully.
 *  \return       E_NOT_OK      Id was not read. Buffer is empty.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Get(IpduM_CTxContainerPduIterType txContainerId, P2VAR(PduIdType, AUTOMATIC, PDUR_APPL_DATA) txConfId);
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_MainFunction()
*******************************************************************************************/
/*! \brief        Performs cyclic actions for request queue Pdus.
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_MainFunction(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_MainFunction()
*******************************************************************************************/
/*! \brief        Performs cyclic actions for data queue Pdus.
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_MainFunction(IpduM_CTxContainerPduIterType txContainerId);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_Init()
*******************************************************************************************/
/*! \brief        Initializes txContainerPDU structure
 *  \details      -
 *  \pre          Interrupts are disabled
 *  \pre          Module is uninitialized
 *  \pre          IpduM_InitMemory has been called unless IpduM_ModuleInitialized is initialized by start-up code
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_Init(void);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_AdaptMetaDataSize()
*******************************************************************************************/
/*! \brief        Changes length in last PDU's header to match CanIf processing
 *  \details      -
 *  \param[in]    txContainerId
 *  \param[in,out]pduInfoPtr
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_AdaptMetaDataSize(IpduM_CTxContainerPduIterType txContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerRx_AdaptMetaDataSize()
*******************************************************************************************/
/*! \brief        Changes length in last PDU's header to match CanIf processing
 *  \details      -
 *  \param[in]    rxContainerId
 *  \param[in,out]pduInfoPtr
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_AdaptMetaDataSize(IpduM_RxContainerPduIterType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#define IPDUM_STOP_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
#define IPDUM_START_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_WriteHeader()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_WriteHeader(P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf,  uint32 headerId, uint32 dlc, PduLengthType headerSize)
{
# if (IPDUM_EXISTS_SHORT_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  if(headerSize == IPDUM_HEADERSIZE_SMALL) /*COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
#  if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    pContainerBuf[0] = ((uint8) (headerId >> 0));       /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[1] = ((uint8) (headerId >> 8));       /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[2] = ((uint8) (headerId >> 16));      /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[3] = ((uint8) (dlc >> 0));    /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
#  else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    pContainerBuf[0] = ((uint8) (headerId >> 16));      /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[1] = ((uint8) (headerId >> 8));       /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[2] = ((uint8) (headerId >> 0));       /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[3] = ((uint8) (dlc >> 0));    /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
#  endif
  }
# endif
# if (IPDUM_EXISTS_LONG_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  if(headerSize == IPDUM_HEADERSIZE_LARGE) /*COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
#  if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    pContainerBuf[0] = ((uint8) (headerId >> 0));       /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[1] = ((uint8) (headerId >> 8));       /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[2] = ((uint8) (headerId >> 16));      /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[3] = ((uint8) (headerId >> 24));      /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[4] = ((uint8) (dlc >> 0));    /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[5] = ((uint8) (dlc >> 8));    /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[6] = ((uint8) (dlc >> 16));   /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[7] = ((uint8) (dlc >> 24));   /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
#  else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    pContainerBuf[0] = ((uint8) (headerId >> 24));      /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[1] = ((uint8) (headerId >> 16));      /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[2] = ((uint8) (headerId >> 8));       /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[3] = ((uint8) (headerId >> 0));       /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[4] = ((uint8) (dlc >> 24));   /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[5] = ((uint8) (dlc >> 16));   /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[6] = ((uint8) (dlc >> 8));    /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    pContainerBuf[7] = ((uint8) (dlc >> 0));    /* PRQA S 2985 */ /* MD_IpduM_2985 */ /* SBSW_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */ /* VCA_IPDUM_ARRAY_WRITE_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
#  endif
  }
# endif
  IPDUM_DUMMY_STATEMENT(headerSize);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if ((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_Container_ReadHeader()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(IpduM_ContainedPduHeaderType, IPDUM_CODE) IpduM_Container_ReadHeader(P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) pContainerBuf, uint32 headerSize)
{
  IpduM_ContainedPduHeaderType header;
  
  header.headerId = 0;
  header.dlc = 0;

# if(IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
  if(headerSize == IPDUM_HEADERSIZE_SMALL) /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    /* short header */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 0) |  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[1]) << 8) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[2]) << 16); /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    header.dlc = ((uint32) pContainerBuf[3]); /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    /* *INDENT-ON* */
#  else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 16) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[1]) << 8) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[2]) << 0);  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    header.dlc = (((uint32) pContainerBuf[3]) << 0);  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    /* *INDENT-ON* */
#  endif
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }
# endif
# if(IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
  if(headerSize == IPDUM_HEADERSIZE_LARGE) /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    /* long header */
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  if (IPDUM_HEADER_BYTE_ORDER == IPDUM_LITTLE_ENDIAN)
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 0) |  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[1]) << 8) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[2]) << 16) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[3]) << 24); /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    header.dlc =
      (((uint32) pContainerBuf[4]) << 0) |  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[5]) << 8) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[6]) << 16) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[7]) << 24); /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    /* *INDENT-ON* */
#  else /* (IPDUM_HEADER_BYTE_ORDER == IPDUM_BIG_ENDIAN) */
    /* *INDENT-OFF* */
    header.headerId =
      (((uint32) pContainerBuf[0]) << 24) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[1]) << 16) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[2]) << 8) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[3]) << 0);  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    header.dlc =
      (((uint32) pContainerBuf[4]) << 24) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[5]) << 16) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[6]) << 8) | /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
      (((uint32) pContainerBuf[7]) << 0);  /* PRQA S 2985 */ /* MD_IpduM_2985 */  /* VCA_IPDUM_ARRAY_READ_WITH_SIZE_VARIABLE_CHECKED_BY_CALLER */
    /* *INDENT-ON* */
#  endif
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }
# endif
  IPDUM_DUMMY_STATEMENT(headerSize);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(pContainerBuf);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return header;
}
#endif

# if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_GetHeaderSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_ContainerRx_GetHeaderSize(IpduM_RxContainerPduIterType rxContainerId)
{
  uint8 headerSize = 0;
# if (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfRxContainerPdu(rxContainerId) == IPDUM_LONG_HEADERSIZEOFRXCONTAINERPDU) /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    headerSize = IPDUM_HEADERSIZE_LARGE;
  }
# endif
# if (IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfRxContainerPdu(rxContainerId) == IPDUM_SHORT_HEADERSIZEOFRXCONTAINERPDU) /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    headerSize = IPDUM_HEADERSIZE_SMALL;
  }
# endif
  IPDUM_DUMMY_STATEMENT(rxContainerId);    /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  return headerSize;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_GetHeaderSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(uint8, IPDUM_CODE) IpduM_ContainerTx_GetHeaderSize(IpduM_CTxContainerPduIterType txContainerId)
{
  uint8 headerSize = 0;
# if (IPDUM_EXISTS_LONG_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfTxContainerPdu(txContainerId) == IPDUM_LONG_HEADERSIZEOFTXCONTAINERPDU) /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    headerSize = IPDUM_HEADERSIZE_LARGE;
  }
# endif
# if (IPDUM_EXISTS_SHORT_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfTxContainerPdu(txContainerId) == IPDUM_SHORT_HEADERSIZEOFTXCONTAINERPDU) /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    headerSize = IPDUM_HEADERSIZE_SMALL;
  }
# endif

  return headerSize;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_GetAsPointer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(PduInfoType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_GetAsPointer(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx)
{
  PduInfoType pduInfo;

  pduInfo.SduDataPtr = IpduM_GetAddrDataQueueBuffer(IpduM_GetDataQueueBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx));
  pduInfo.SduLength  = IpduM_ContainerTx_DataQueueInstance_GetFillCount(dataQueueInstanceIdx);

  return pduInfo;
}
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_Get()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_Get(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) destBuffer)
{
  PduInfoType containerBuffer;
  containerBuffer = IpduM_ContainerTx_DataQueueInstance_GetAsPointer(dataQueueInstanceIdx);

  /* Copy PDU from container buffer to provided destination buffer */
  VStdLib_MemCpy_s(destBuffer->SduDataPtr, destBuffer->SduLength, containerBuffer.SduDataPtr, containerBuffer.SduLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_IPDUM_VSTDLIB_SAFE */  /* VCA_IPDUM_VSTDLIB_MEMCPY_SAFE */
  destBuffer->SduLength = containerBuffer.SduLength;  /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_PTR_WRITE */
}
#endif

#if ((IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_CopyContainedPduIDs2TxConfBuffer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_CopyContainedPduIDs2TxConfBuffer(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_DataQueueIdBufferWriteIdxOfDataQueueInstanceType dataQueueIdBufferReadIdx =  IpduM_GetDataQueueIdBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx);
  IpduM_DataQueueIdBufferWriteIdxOfDataQueueInstanceType dataQueueIdBufferWriteIdx =  IpduM_GetDataQueueIdBufferWriteIdxOfDataQueueInstance(dataQueueInstanceIdx);

  for(; dataQueueIdBufferReadIdx < dataQueueIdBufferWriteIdx; dataQueueIdBufferReadIdx++)
  {
    (void) IpduM_ContainerTx_TxConfBuffer_Put(txContainerId, IpduM_GetDataQueueIdBuffer(dataQueueIdBufferReadIdx));
  }
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty(IpduM_CTxContainerPduIterType txContainerId)
{
  boolean retVal = FALSE;
  IpduM_DataQueueInfoIdxOfTxContainerPduType dataQueueInfoIdx = IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId);

  if( (IpduM_WriteCountOfDataQueueInfoType) (IpduM_GetWriteCountOfDataQueueInfo(dataQueueInfoIdx) - IpduM_GetReadCountOfDataQueueInfo(dataQueueInfoIdx)) == 0u)
  {
    retVal = TRUE;
  }

  return retVal;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IsFifoQueueFull
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IsFifoQueueFull(IpduM_CTxContainerPduIterType txContainerId)
{
  boolean retVal = FALSE;
  IpduM_DataQueueInfoIdxOfTxContainerPduType dataQueueInfoIdx = IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId);

  /* There are QueueDepth + 1 instances to always have a 'current open instance'. */
  IpduM_DataQueueInstanceLengthOfDataQueueInfoType queueDepth = IpduM_GetDataQueueInstanceLengthOfDataQueueInfo(dataQueueInfoIdx) - 1u; /* PRQA S 2842 */ /* MD_IpduM_2842 */
  IpduM_WriteCountOfDataQueueInfoType containerWriteCount = IpduM_GetWriteCountOfDataQueueInfo(dataQueueInfoIdx); /* PRQA S 2842 */ /* MD_IpduM_2842 */
  IpduM_ReadCountOfDataQueueInfoType containerReadCount = IpduM_GetReadCountOfDataQueueInfo(dataQueueInfoIdx); /* PRQA S 2842 */ /* MD_IpduM_2842 */

  if( (IpduM_WriteCountOfDataQueueInfoType) (containerWriteCount - containerReadCount) >= queueDepth)
  {
    retVal = TRUE;
  }

  return retVal;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_FitsPduIntoCurrentOpenInstance
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_DataQueue_FitsPduIntoCurrentOpenInstance(IpduM_CTxContainerPduIterType txContainerId, PduLengthType pduLength)
{
  IpduM_DataQueueInstanceWriteIdxOfDataQueueInfoType dataQueueInstanceWriteIdx = IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId));

  return (IpduM_ContainerTx_DataQueueInstance_GetFreeBytesCount(dataQueueInstanceWriteIdx) >= (IpduM_ContainerTx_GetHeaderSize(txContainerId) + pduLength));
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_GetFillCount
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(PduLengthType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_GetFillCount(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx)
{
  return IpduM_GetFillCountOfDataQueueInstance(dataQueueInstanceIdx);
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_Put
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_Put(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr, PduLengthType writeOffset)
{
  Std_ReturnType retVal = E_NOT_OK;

  IpduM_DataQueueBufferStartIdxOfDataQueueInstanceType dataQueueBufferStartIdx = IpduM_GetDataQueueBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx);
  IpduM_DataQueueBufferEndIdxOfDataQueueInstanceType dataQueueBufferEndIdx = IpduM_GetDataQueueBufferEndIdxOfDataQueueInstance(dataQueueInstanceIdx);

  if((dataQueueBufferStartIdx + writeOffset + PduInfoPtr->SduLength) <= dataQueueBufferEndIdx)  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    VStdLib_MemCpy(IpduM_GetAddrDataQueueBuffer(dataQueueBufferStartIdx + writeOffset), PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_IPDUM_VSTDLIB_SAFE */  /* VCA_IPDUM_VSTDLIB_MEMCPY_SAFE */
    retVal = E_OK;
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  else
  {
    IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_DATAQUEUEINSTANCE_PUT, IPDUM_E_GENERATED_DATA);
  }
# endif

  return retVal;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_PutHeader
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_PutHeader(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, PduLengthType writeOffset, uint32 headerId, uint32 dlc, uint8 headerSize)
{
  Std_ReturnType retVal = E_NOT_OK;

  IpduM_DataQueueBufferStartIdxOfDataQueueInstanceType dataQueueBufferStartIdx = IpduM_GetDataQueueBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx);
  IpduM_DataQueueBufferEndIdxOfDataQueueInstanceType dataQueueBufferEndIdx = IpduM_GetDataQueueBufferEndIdxOfDataQueueInstance(dataQueueInstanceIdx);

  if((dataQueueBufferStartIdx + writeOffset + headerSize) <= dataQueueBufferEndIdx)  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    IpduM_ContainerTx_WriteHeader(IpduM_GetAddrDataQueueBuffer(dataQueueBufferStartIdx + writeOffset), headerId, dlc, headerSize); /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* SBSW_IPDUM_ADDTXPDUTOCURRCONTAINER_CALL_CONTAINERWRITEHEADER */
    retVal = E_OK;
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  else
  {
    IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_DATAQUEUEINSTANCE_PUTHEADER, IPDUM_E_GENERATED_DATA);
  }
# endif

  return retVal;
}
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_SetBit
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_SetBit(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, uint16 bitPosition)
{
  Std_ReturnType retVal = E_NOT_OK;

  IpduM_DataQueueBufferStartIdxOfDataQueueInstanceType dataQueueBufferStartIdx = IpduM_GetDataQueueBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx);
  IpduM_DataQueueBufferEndIdxOfDataQueueInstanceType dataQueueBufferEndIdx = IpduM_GetDataQueueBufferEndIdxOfDataQueueInstance(dataQueueInstanceIdx);

  PduLengthType updateBitBytePos = bitPosition >> 3u;
  uint8 updateBitSetPattern = (uint8) (0x01u << (bitPosition % 8u));

  if((dataQueueBufferStartIdx + updateBitBytePos) <= dataQueueBufferEndIdx) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    uint8 dataByte = IpduM_GetDataQueueBuffer(dataQueueBufferStartIdx + updateBitBytePos);

    dataByte |= updateBitSetPattern;
    IpduM_SetDataQueueBuffer(dataQueueBufferStartIdx + updateBitBytePos, dataByte); /* SBSW_IPDUM_ARRAY_WRITE_WITH_INDEX_CHECK */

    retVal = E_OK;
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  else
  {
    IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_DATAQUEUEINSTANCE_SETBIT, IPDUM_E_GENERATED_DATA);
  }
# endif

  return retVal;
}
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_ClearBit
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_ClearBit(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, uint16 bitPosition)
{
  Std_ReturnType retVal = E_NOT_OK;

  IpduM_DataQueueBufferStartIdxOfDataQueueInstanceType dataQueueBufferStartIdx = IpduM_GetDataQueueBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx);
  IpduM_DataQueueBufferEndIdxOfDataQueueInstanceType dataQueueBufferEndIdx = IpduM_GetDataQueueBufferEndIdxOfDataQueueInstance(dataQueueInstanceIdx);

  PduLengthType updateBitBytePos = bitPosition >> 3u;
  uint8 updateBitClearPattern = ~((uint8) (0x01u << (bitPosition % 8u)));

  if((dataQueueBufferStartIdx + updateBitBytePos) <= dataQueueBufferEndIdx) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    uint8 dataByte = IpduM_GetDataQueueBuffer(dataQueueBufferStartIdx + updateBitBytePos);

    dataByte &= updateBitClearPattern;
    IpduM_SetDataQueueBuffer(dataQueueBufferStartIdx + updateBitBytePos, dataByte); /* SBSW_IPDUM_ARRAY_WRITE_WITH_INDEX_CHECK */

    retVal = E_OK;
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  else
  {
    IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_DATAQUEUEINSTANCE_CLEARBIT, IPDUM_E_GENERATED_DATA);
  }
# endif

  return retVal;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_GetFreeBytesCount
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(PduLengthType, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_GetFreeBytesCount(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx)
{
  IpduM_DataQueueBufferLengthOfDataQueueInstanceType   dataQueueBufferLength = IpduM_GetDataQueueBufferLengthOfDataQueueInstance(dataQueueInstanceIdx);

  return  (((PduLengthType) dataQueueBufferLength) - IpduM_ContainerTx_DataQueueInstance_GetFillCount(dataQueueInstanceIdx));
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IncrementWritePtr
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IncrementWritePtr(IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_DataQueueInfoIdxOfTxContainerPduType dataQueueInfoIdx = IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId);

  IpduM_IncWriteCountOfDataQueueInfo(dataQueueInfoIdx);      /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  IpduM_IncDataQueueInstanceWriteIdxOfDataQueueInfo(dataQueueInfoIdx);        /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  if(IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(dataQueueInfoIdx) >= IpduM_GetDataQueueInstanceEndIdxOfDataQueueInfo(dataQueueInfoIdx))
  {
    IpduM_SetDataQueueInstanceWriteIdxOfDataQueueInfo(dataQueueInfoIdx, IpduM_GetDataQueueInstanceStartIdxOfDataQueueInfo(dataQueueInfoIdx));  /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_IncrementReadPtr
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_IncrementReadPtr(IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_DataQueueInfoIdxOfTxContainerPduType dataQueueInfoIdx = IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId);

  /* increment read pointer */
  IpduM_IncReadCountOfDataQueueInfo(dataQueueInfoIdx); /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  IpduM_IncDataQueueInstanceReadIdxOfDataQueueInfo(dataQueueInfoIdx); /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  if(IpduM_GetDataQueueInstanceReadIdxOfDataQueueInfo(dataQueueInfoIdx) >= IpduM_GetDataQueueInstanceEndIdxOfDataQueueInfo(dataQueueInfoIdx))
  {
    IpduM_SetDataQueueInstanceReadIdxOfDataQueueInfo(dataQueueInfoIdx, IpduM_GetDataQueueInstanceStartIdxOfDataQueueInfo(dataQueueInfoIdx)); /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_Init
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_Init(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, IpduM_CTxContainerPduIterType txContainerIdx)
{
  /* Reset dataBuffer Write Idx to 'clear' the buffer */
  IpduM_SetFillCountOfDataQueueInstance(dataQueueInstanceIdx, 0u);    /* SBSW_IPDUM_DIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  IpduM_SetDataQueueIdBufferWriteIdxOfDataQueueInstance(dataQueueInstanceIdx, IpduM_GetDataQueueIdBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx));    /* SBSW_IPDUM_DIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

# if (IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  /* Initialize current containers with header type == none */
  if(IpduM_GetHeaderSizeOfTxContainerPdu(txContainerIdx) == IPDUM_NONE_HEADERSIZEOFTXCONTAINERPDU)
  {
    IpduM_ContainerTx_DataQueueInstance_ClearBuffer(dataQueueInstanceIdx, IpduM_GetUnusedBitPatternOfTxContainerPdu(txContainerIdx));
#  if(IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON)
    IpduM_ContainerTx_DataQueueInstance_ResetUpdateBits(dataQueueInstanceIdx, txContainerIdx);
#  endif
  }
# endif

  IPDUM_DUMMY_STATEMENT(txContainerIdx);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_Init
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_Init(void)
{
  IpduM_CTxContainerPduIterType txContainerIdx;

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  for(txContainerIdx = 0u; txContainerIdx < IpduM_GetSizeOfCTxContainerPdu(); txContainerIdx++)
  {
    if(IpduM_IsDataQueueInfoUsedOfTxContainerPdu(txContainerIdx))  /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    {
      IpduM_DataQueueInfoIdxOfTxContainerPduType dataQueueInfoIdx = IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerIdx);

      /* DataQueueInfo Initialization */
      IpduM_SetDataQueueInstanceWriteIdxOfDataQueueInfo(dataQueueInfoIdx, IpduM_GetDataQueueInstanceStartIdxOfDataQueueInfo(dataQueueInfoIdx));    /* SBSW_IPDUM_CSL02_OVER_CSL03 */
      IpduM_SetDataQueueInstanceReadIdxOfDataQueueInfo(dataQueueInfoIdx, IpduM_GetDataQueueInstanceStartIdxOfDataQueueInfo(dataQueueInfoIdx));    /* SBSW_IPDUM_CSL02_OVER_CSL03 */
      IpduM_SetWriteCountOfDataQueueInfo(dataQueueInfoIdx, 0u);    /* SBSW_IPDUM_CSL02_OVER_CSL03 */
      IpduM_SetReadCountOfDataQueueInfo(dataQueueInfoIdx, 0u);    /* SBSW_IPDUM_CSL02_OVER_CSL03 */

      {/* DataQueueInstance Initialization */
        IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx = IpduM_GetDataQueueInstanceStartIdxOfDataQueueInfo(dataQueueInfoIdx);

        for (; dataQueueInstanceIdx < IpduM_GetDataQueueInstanceEndIdxOfDataQueueInfo(dataQueueInfoIdx); dataQueueInstanceIdx++)
        {
          IpduM_ContainerTx_DataQueueInstance_Init(dataQueueInstanceIdx, txContainerIdx);
        }
      }
    }
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
}
#endif

#if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_StartTimeout()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConf_StartTimeout(IpduM_CTxContainerPduIterType txContainerId)
{
  if(IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId)) /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
  {
    /* Load timeout counter */
    IpduM_SetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId), IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(txContainerId)); /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
}
#endif

#if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_StopTimeout()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConf_StopTimeout(IpduM_CTxContainerPduIterType txContainerId)
{
  if(IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId)) /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
  {
    /* Reset timeout counter */
    IpduM_SetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId), IPDUM_RESET); /* PRQA S 2842 */ /* MD_IpduM_2842 */ /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
}
#endif

#if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_IsTransmissionAllowed
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_TxConf_IsTransmissionAllowed(IpduM_CTxContainerPduIterType txContainerId)
{
  return (IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(txContainerId) == 0u) || (IpduM_IsTxLoInfoUsedOfTxContainerPdu(txContainerId) && (IpduM_GetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(IpduM_GetTxLoInfoIdxOfTxContainerPdu(txContainerId)) == 0u));  /* COV_IPDUM_DEPENDENT_VALUES */
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_AddPdu2IdBuffer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_AddPdu2IdBuffer(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);

  IpduM_DataQueueInfoIdxOfTxContainerPduType dataQueueInfoIdx = IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId);
  IpduM_DataQueueInstanceWriteIdxOfDataQueueInfoType dataQueueInstanceWriteIdx = IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(dataQueueInfoIdx);
  IpduM_DataQueueIdBufferWriteIdxOfDataQueueInstanceType dataQueueIdBufferWriteIdx =  IpduM_GetDataQueueIdBufferWriteIdxOfDataQueueInstance(dataQueueInstanceWriteIdx);

  if(dataQueueIdBufferWriteIdx < IpduM_GetDataQueueIdBufferEndIdxOfDataQueueInstance(dataQueueInstanceWriteIdx))  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    IpduM_SetDataQueueIdBuffer(dataQueueIdBufferWriteIdx, (PduIdType) txContainedId);    /* SBSW_IPDUM_CSL01 */
    IpduM_IncDataQueueIdBufferWriteIdxOfDataQueueInstance(dataQueueInstanceWriteIdx);    /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  else
  {
    IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_DATAQUEUE_ADDPDU2IDBUFFER, IPDUM_E_GENERATED_DATA);
  }
# endif
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Init()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Init(void)
{
  IpduM_CRequestQueueInfoIterType requestQueueInfoIdx = 0;

  for(; requestQueueInfoIdx < IpduM_GetSizeOfCRequestQueueInfo(); requestQueueInfoIdx++)
  {
    IpduM_SetReadIdxOfRequestQueueInfo(requestQueueInfoIdx, 0); /* SBSW_IPDUM_CSL01 */
    IpduM_SetReadTmpIdxOfRequestQueueInfo(requestQueueInfoIdx, 0); /* SBSW_IPDUM_CSL01 */
    IpduM_SetWriteIdxOfRequestQueueInfo(requestQueueInfoIdx, 0); /* SBSW_IPDUM_CSL01 */
  }
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_IsEmpty()
*******************************************************************************************/
/*! 
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_IsEmpty(IpduM_CTxContainerPduIterType txContainerId)
{
  /* if nothing is found (default), the result is true */
  boolean retVal = TRUE;

  IpduM_RequestQueueInfoStartIdxOfRequestQueuePrioIndirectionType requestQueueInfoIterator = IpduM_GetRequestQueueInfoStartIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));
  IpduM_RequestQueueInfoEndIdxOfRequestQueuePrioIndirectionType requestQueueInfoEndIdx = IpduM_GetRequestQueueInfoEndIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));
  /* loop over all priorities for this container */
  for(; requestQueueInfoIterator < requestQueueInfoEndIdx; requestQueueInfoIterator++)
  {
    IpduM_ReadIdxOfRequestQueueInfoType readIdx = IpduM_GetReadIdxOfRequestQueueInfo(requestQueueInfoIterator);
    IpduM_ReadIdxOfRequestQueueInfoType writeIdx = IpduM_GetWriteIdxOfRequestQueueInfo(requestQueueInfoIterator);
    
    /* If read and write Idx are the same, this queue is empty */
    if(readIdx != writeIdx)
    {
      /* there is data in the queue */
      retVal = FALSE;
      break;
    }
  }
  return retVal;
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_ContainsPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_ContainsPdu(IpduM_TxContainedPduIterType txContainedId)
{
  boolean retVal = FALSE;
  
  IpduM_RequestQueueInfoIdxOfTxContainedPduType requestQueueInfoIdx = IpduM_GetRequestQueueInfoIdxOfTxContainedPdu(txContainedId);
  IpduM_RequestQueueBufferStartIdxOfRequestQueueInfoType requestQueueBufferStartIdx = IpduM_GetRequestQueueBufferStartIdxOfRequestQueueInfo(requestQueueInfoIdx);
  IpduM_RequestQueueBufferLengthOfRequestQueueInfoType requestQueueBufferLength = IpduM_GetRequestQueueBufferLengthOfRequestQueueInfo(requestQueueInfoIdx);
  IpduM_ReadIdxOfRequestQueueInfoType readIdxIterator = IpduM_GetReadIdxOfRequestQueueInfo(requestQueueInfoIdx);
  IpduM_ReadIdxOfRequestQueueInfoType writeIdx = IpduM_GetWriteIdxOfRequestQueueInfo(requestQueueInfoIdx);
  
  while(readIdxIterator != writeIdx)
  {
    if(IpduM_GetTxContainedPduIdxOfRequestQueueBuffer(requestQueueBufferStartIdx + readIdxIterator) == txContainedId)
    {
      retVal = TRUE;
      break;
    }
    readIdxIterator++;
    if(readIdxIterator >= requestQueueBufferLength)
    {
      readIdxIterator = 0u;
    }
  }
  return retVal;
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_CalculateSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(PduLengthType, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_CalculateSize(IpduM_CTxContainerPduIterType txContainerId)
{
  PduLengthType sizeOfData = 0u;
  IpduM_RequestQueueInfoStartIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoIdx = IpduM_GetRequestQueueInfoStartIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));
  IpduM_RequestQueueInfoEndIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoEndIdx = IpduM_GetRequestQueueInfoEndIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));
  PduLengthType headerSize = (PduLengthType) IpduM_ContainerTx_GetHeaderSize(txContainerId);
  
  for(; txRequestQueueInfoIdx < txRequestQueueInfoEndIdx; txRequestQueueInfoIdx++)
  {
    IpduM_RequestQueueBufferStartIdxOfRequestQueueInfoType requestQueueBufferStartIdx = IpduM_GetRequestQueueBufferStartIdxOfRequestQueueInfo(txRequestQueueInfoIdx);
    IpduM_RequestQueueBufferLengthOfRequestQueueInfoType requestQueueBufferLength = IpduM_GetRequestQueueBufferLengthOfRequestQueueInfo(txRequestQueueInfoIdx);
    IpduM_ReadIdxOfRequestQueueInfoType readIdxIterator = IpduM_GetReadIdxOfRequestQueueInfo(txRequestQueueInfoIdx);
    IpduM_WriteIdxOfRequestQueueInfoType writeIdx = IpduM_GetWriteIdxOfRequestQueueInfo(txRequestQueueInfoIdx);
    
    while(readIdxIterator != writeIdx)
    {
      
      sizeOfData += IpduM_GetDlcOfRequestQueueBuffer(requestQueueBufferStartIdx + readIdxIterator);
      sizeOfData += headerSize;
      readIdxIterator++;
      if(readIdxIterator >= requestQueueBufferLength)
      {
        readIdxIterator = 0u;
      }
    }
  }
  return sizeOfData;
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Put()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Put(IpduM_TxContainedPduIterType txContainedId, PduLengthType sduLength)
{
  IpduM_RequestQueueInfoIdxOfTxContainedPduType requestQueueInfoIdx = IpduM_GetRequestQueueInfoIdxOfTxContainedPdu(txContainedId);
  IpduM_RequestQueueBufferStartIdxOfRequestQueueInfoType requestQueueBufferStartIdx = IpduM_GetRequestQueueBufferStartIdxOfRequestQueueInfo(requestQueueInfoIdx);
  IpduM_RequestQueueBufferLengthOfRequestQueueInfoType requestQueueBufferLength = IpduM_GetRequestQueueBufferLengthOfRequestQueueInfo(requestQueueInfoIdx);
  IpduM_ReadIdxOfRequestQueueInfoType writeIdx = IpduM_GetWriteIdxOfRequestQueueInfo(requestQueueInfoIdx);
  IpduM_TxContainerPduIdxOfTxContainedPduType txContainerIdx = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  
  /* Set FirstContainedPdu Flag. This can be evaluated e.g. by the trigger module. */
  IpduM_SetFirstContainedPduOfTxContainerPdu(txContainerIdx, IpduM_ContainerTx_RequestQueue_IsEmpty(txContainerIdx));  /* SBSW_IPDUM_CSL02_OVER_CSL03 */

  if(IpduM_ContainerTx_RequestQueue_ContainsPdu(txContainedId) != TRUE)
  {
    if((requestQueueBufferStartIdx + writeIdx) < IpduM_GetSizeOfRequestQueueBuffer()) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
    {
      /* add PDU to queue */
      IpduM_SetTxContainedPduIdxOfRequestQueueBuffer(requestQueueBufferStartIdx + writeIdx, (IpduM_TxContainedPduIdxOfRequestQueueBufferType)txContainedId); /* SBSW_IPDUM_CSL01 */
      IpduM_SetDlcOfRequestQueueBuffer(requestQueueBufferStartIdx + writeIdx, sduLength); /* SBSW_IPDUM_CSL01 */
      writeIdx++;
      if(writeIdx >= requestQueueBufferLength)
      {
        writeIdx = 0u;
      }
      IpduM_SetWriteIdxOfRequestQueueInfo(requestQueueInfoIdx, writeIdx); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
    }
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
    else
    {
      IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_REQUESTQUEUE_ADDPDU, IPDUM_E_GENERATED_DATA);
    }
# endif
  }
}
#endif

#if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TransmitEmptyPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TransmitEmptyPdu(IpduM_CTxContainerPduIterType txContainerId)
{
  PduInfoType pduInfo;
  uint8 data = 0;
  /* The actual memory this pointer is pointing at doesn't matter, because the SduLength is zero. Must not be a NULL_PTR though. */
  pduInfo.SduDataPtr = &data;
  pduInfo.SduLength = 0u; /* PRQA S 2982 */ /* MD_IpduM_2982_initValue */

  return PduR_IpduMTransmit(IpduM_GetTxContainerPduRefOfTxContainerPdu(txContainerId), &pduInfo); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_EMPTY */ /* VCA_IPDUM_FUNCTIONCALL_PDUINFOPTR_SELF_CONSTRUCTED */
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_RestoreReadIDs
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_RestoreReadIDs(IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_RequestQueueInfoStartIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoIdx = IpduM_GetRequestQueueInfoStartIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));
  IpduM_RequestQueueInfoEndIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoEndIdx = IpduM_GetRequestQueueInfoEndIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));

  for(; txRequestQueueInfoIdx < txRequestQueueInfoEndIdx; txRequestQueueInfoIdx++)
  {
    IpduM_SetReadIdxOfRequestQueueInfo(txRequestQueueInfoIdx, IpduM_GetReadTmpIdxOfRequestQueueInfo(txRequestQueueInfoIdx)); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  }
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_SetRestorePoint
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_SetRestorePoint(IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_RequestQueueInfoStartIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoIdx = IpduM_GetRequestQueueInfoStartIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));
  IpduM_RequestQueueInfoEndIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoEndIdx = IpduM_GetRequestQueueInfoEndIdxOfRequestQueuePrioIndirection(IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId));

  for(; txRequestQueueInfoIdx < txRequestQueueInfoEndIdx; txRequestQueueInfoIdx++)
  {
    IpduM_SetReadTmpIdxOfRequestQueueInfo(txRequestQueueInfoIdx, IpduM_GetReadIdxOfRequestQueueInfo(txRequestQueueInfoIdx)); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  }
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Remove
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Remove(IpduM_CRequestQueueInfoIterType txRequestQueueInfoIdx)
{
  IpduM_ReadIdxOfRequestQueueInfoType readIdx = IpduM_GetReadIdxOfRequestQueueInfo(txRequestQueueInfoIdx);

  readIdx++;
  if(readIdx >= IpduM_GetRequestQueueBufferLengthOfRequestQueueInfo(txRequestQueueInfoIdx))
  {
    readIdx = 0u;
  }

  IpduM_SetReadIdxOfRequestQueueInfo(txRequestQueueInfoIdx, readIdx); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_Peek
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_Peek(IpduM_CRequestQueueInfoIterType txRequestQueueInfoIdx, P2VAR(IpduM_TxContainedPduIdxOfRequestQueueBufferType, AUTOMATIC, IPDUM_APPL_DATA) containedPduId, P2VAR(PduLengthType, AUTOMATIC, IPDUM_APPL_DATA) containedPduLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  IpduM_ReadIdxOfRequestQueueInfoType readIdx = IpduM_GetReadIdxOfRequestQueueInfo(txRequestQueueInfoIdx);
  IpduM_WriteIdxOfRequestQueueInfoType writeIdx = IpduM_GetWriteIdxOfRequestQueueInfo(txRequestQueueInfoIdx);

  IpduM_RequestQueueBufferStartIdxOfRequestQueueInfoType requestQueueBufferStartIdx = IpduM_GetRequestQueueBufferStartIdxOfRequestQueueInfo(txRequestQueueInfoIdx);

  if(readIdx != writeIdx)
  {
    *containedPduId = IpduM_GetTxContainedPduIdxOfRequestQueueBuffer(requestQueueBufferStartIdx + readIdx); /* SBSW_IPDUM_PTR_WRITE_TYPED_CHECKED_BY_CALLER */
    *containedPduLength = IpduM_GetDlcOfRequestQueueBuffer(requestQueueBufferStartIdx + readIdx); /* SBSW_IPDUM_PTR_WRITE_TYPED_CHECKED_BY_CALLER */

    if(*containedPduId < IpduM_GetSizeOfTxContainedPdu())  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
    {
      retVal = E_OK;
    }
    else
    {
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
      IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_REQUESTQUEUE_PEEK, IPDUM_E_GENERATED_DATA);
# endif
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueue_FillLastIsBestContainer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(PduInfoType, IPDUM_CODE) IpduM_ContainerTx_RequestQueue_FillLastIsBestContainer(IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_RequestQueuePrioIndirectionIdxOfTxContainerPduType requestQueuePrioIndirectionIdx = IpduM_GetRequestQueuePrioIndirectionIdxOfTxContainerPdu(txContainerId);
  IpduM_RequestQueueInfoStartIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoIdx = IpduM_GetRequestQueueInfoStartIdxOfRequestQueuePrioIndirection(requestQueuePrioIndirectionIdx);
  IpduM_RequestQueueInfoEndIdxOfRequestQueuePrioIndirectionType txRequestQueueInfoEndIdx = IpduM_GetRequestQueueInfoEndIdxOfRequestQueuePrioIndirection(requestQueuePrioIndirectionIdx);

  IpduM_ContainerTxLIBBufferStartIdxOfRequestQueuePrioIndirectionType txLIBBufferStartIdx = IpduM_GetContainerTxLIBBufferStartIdxOfRequestQueuePrioIndirection(requestQueuePrioIndirectionIdx);
  IpduM_ContainerTxLIBBufferLengthOfRequestQueuePrioIndirectionType   txLIBBufferLength = IpduM_GetContainerTxLIBBufferLengthOfRequestQueuePrioIndirection(requestQueuePrioIndirectionIdx);

  PduLengthType writtenBytes = 0u;
  PduLengthType pduLength = (PduLengthType) IpduM_GetPduLengthOfTxContainerPdu(txContainerId);
  PduLengthType freeBytes = (pduLength <= txLIBBufferLength) ? pduLength : txLIBBufferLength;  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  PduLengthType headerSize = (PduLengthType) IpduM_ContainerTx_GetHeaderSize(txContainerId);
  PduInfoType libBuffer;

  for(; txRequestQueueInfoIdx < txRequestQueueInfoEndIdx; txRequestQueueInfoIdx++)
  {
    IpduM_TxContainedPduIdxOfRequestQueueBufferType containedPduId;
    PduLengthType containedPduLength;

    while(IpduM_ContainerTx_RequestQueue_Peek(txRequestQueueInfoIdx, &containedPduId, &containedPduLength) == E_OK) /* SBSW_IPDUM_FUNCTIONCALL_OUT_PTR */
    {
      if(freeBytes >= (containedPduLength + headerSize))
      {
        PduInfoType pduInfo;
        pduInfo.SduDataPtr = IpduM_GetAddrContainerTxLIBBuffer(txLIBBufferStartIdx + writtenBytes + headerSize);  /* data starts after the header */
        pduInfo.SduLength = freeBytes - headerSize; /* available size left in buffer */

        if(PduR_IpduMTriggerTransmit(IpduM_GetTxContainedPduRefOfTxContainedPdu(containedPduId), &pduInfo) == E_OK) /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_SELF_CONSTRUCTED */ /* VCA_IPDUM_FUNCTIONCALL_PDUINFOPTR_SELF_CONSTRUCTED */
        {
          IpduM_ContainerTx_WriteHeader(IpduM_GetAddrContainerTxLIBBuffer(txLIBBufferStartIdx + writtenBytes), IpduM_GetHeaderIdOfTxContainedPdu(containedPduId), pduInfo.SduLength, headerSize); /* SBSW_IPDUM_FILLLASTISBEST_CALL_CONTAINERWRITEHEADER */

# if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
          (void) IpduM_ContainerTx_TxConfBuffer_Put(txContainerId, containedPduId);
# endif
          writtenBytes += (pduInfo.SduLength + headerSize);
          freeBytes -= (pduInfo.SduLength + headerSize);
        }

        IpduM_ContainerTx_RequestQueue_Remove(txRequestQueueInfoIdx);
      }
      else
      {
        break;
      }
    }
  }

  /* Return the LIB buffer and Container Length */
  libBuffer.SduDataPtr = IpduM_GetAddrContainerTxLIBBuffer(txLIBBufferStartIdx);
  libBuffer.SduLength  = writtenBytes;

  return libBuffer;
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_DirectDP()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_DirectDP(IpduM_CTxContainerPduIterType txContainerId)
{
  Std_ReturnType transmitResult = E_NOT_OK;   /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
  if(IpduM_ContainerTx_TxConf_IsTransmissionAllowed(txContainerId))  /* COV_IPDUM_TXCONF_ALWAYS_ZERO */
# endif
  {
    PduInfoType pduInfo;

    IpduM_ContainerTx_RequestQueue_SetRestorePoint(txContainerId);
    /* last-is-best PDU: load data to last-is-best buffer via TriggerTransmit, then use this buffer for transmission */
    pduInfo = IpduM_ContainerTx_RequestQueue_FillLastIsBestContainer(txContainerId);
    IpduM_ContainerTx_AdaptMetaDataSize(txContainerId, &pduInfo); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */

# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
    IpduM_ContainerTx_TxConf_StartTimeout(txContainerId);
# endif

    transmitResult = PduR_IpduMTransmit(IpduM_GetTxContainerPduRefOfTxContainerPdu(txContainerId), &pduInfo);  /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_PDURTRANSMIT */

    if(transmitResult != E_OK)
    {
      IpduM_ContainerTx_RequestQueue_RestoreReadIDs(txContainerId);

# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
      IpduM_ContainerTx_TxConf_StopTimeout(txContainerId);
# endif
    }
  }

  return transmitResult;
}
#endif

#if ((IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_TriggerTxDP()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_TriggerTxDP(IpduM_CTxContainerPduIterType txContainerId)
{
  (void) IpduM_ContainerTx_TransmitEmptyPdu(txContainerId);
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TriggerTransmission()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TriggerTransmission(IpduM_CTxContainerPduIterType txContainerId)
{
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
  if(IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId))
  {
    IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_TriggerTxDP(txContainerId);
  }
  else
# endif
  {
    (void) IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_DirectDP(txContainerId);
  }
}
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConfBuffer_Init()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Init(void)
{
  IpduM_CContainerTxConfirmationBufferInfoIterType containerTxConfirmationBufferInfoIdx;

  for(containerTxConfirmationBufferInfoIdx = 0u; containerTxConfirmationBufferInfoIdx < IpduM_GetSizeOfCContainerTxConfirmationBufferInfo(); containerTxConfirmationBufferInfoIdx++)
  {
    IpduM_SetContainerTxConfirmationBufferReadIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx, IpduM_GetContainerTxConfirmationBufferStartIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx));  /* SBSW_IPDUM_CSL01 */
    IpduM_SetContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx, IpduM_GetContainerTxConfirmationBufferStartIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx));  /* SBSW_IPDUM_CSL01 */
  }
}
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConfBuffer_Clear()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Clear(IpduM_CTxContainerPduIterType txContainerId)
{
  if(IpduM_IsContainerTxConfirmationBufferInfoUsedOfTxContainerPdu(txContainerId))  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    IpduM_ContainerTxConfirmationBufferInfoIdxOfTxContainerPduType containerTxConfirmationBufferInfoIdx = IpduM_GetContainerTxConfirmationBufferInfoIdxOfTxContainerPdu(txContainerId);

    IpduM_SetContainerTxConfirmationBufferReadIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx, IpduM_GetContainerTxConfirmationBufferStartIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx));  /* SBSW_IPDUM_CSL02_OVER_CSL03 */
    IpduM_SetContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx, IpduM_GetContainerTxConfirmationBufferStartIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx));  /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
}
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConfBuffer_Put()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Put(IpduM_CTxContainerPduIterType txContainerId, PduIdType txConfId)
{
  Std_ReturnType retVal = E_NOT_OK;

  if(IpduM_IsContainerTxConfirmationBufferInfoUsedOfTxContainerPdu(txContainerId))  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    IpduM_ContainerTxConfirmationBufferInfoIdxOfTxContainerPduType containerTxConfirmationBufferInfoIdx = IpduM_GetContainerTxConfirmationBufferInfoIdxOfTxContainerPdu(txContainerId);
    IpduM_ContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfoType containerTxConfirmationBufferWriteIdx = IpduM_GetContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);
    IpduM_ContainerTxConfirmationBufferEndIdxOfContainerTxConfirmationBufferInfoType   containerTxConfirmationBufferEndIdx = IpduM_GetContainerTxConfirmationBufferEndIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);

    if(containerTxConfirmationBufferWriteIdx < containerTxConfirmationBufferEndIdx)  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
    {
      IpduM_SetContainerTxConfirmationBuffer(containerTxConfirmationBufferWriteIdx, txConfId);  /* SBSW_IPDUM_CSL02_OVER_CSL03 */
      IpduM_IncContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);  /* SBSW_IPDUM_CSL02_OVER_CSL03 */
      retVal = E_OK;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConfBuffer_Get()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Get(IpduM_CTxContainerPduIterType txContainerId, P2VAR(PduIdType, AUTOMATIC, PDUR_APPL_DATA) txConfId)
{
  Std_ReturnType retVal = E_NOT_OK;

  if(IpduM_IsContainerTxConfirmationBufferInfoUsedOfTxContainerPdu(txContainerId))  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    IpduM_ContainerTxConfirmationBufferInfoIdxOfTxContainerPduType containerTxConfirmationBufferInfoIdx = IpduM_GetContainerTxConfirmationBufferInfoIdxOfTxContainerPdu(txContainerId);
    IpduM_ContainerTxConfirmationBufferReadIdxOfContainerTxConfirmationBufferInfoType  containerTxConfirmationBufferReadIdx = IpduM_GetContainerTxConfirmationBufferReadIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);
    IpduM_ContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfoType containerTxConfirmationBufferWriteIdx = IpduM_GetContainerTxConfirmationBufferWriteIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);
    IpduM_ContainerTxConfirmationBufferEndIdxOfContainerTxConfirmationBufferInfoType   containerTxConfirmationBufferEndIdx = IpduM_GetContainerTxConfirmationBufferEndIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);

    if(containerTxConfirmationBufferReadIdx < containerTxConfirmationBufferWriteIdx)
    {
      if(containerTxConfirmationBufferReadIdx < containerTxConfirmationBufferEndIdx)  /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
      {
        *txConfId = IpduM_GetContainerTxConfirmationBuffer(containerTxConfirmationBufferReadIdx);  /* SBSW_IPDUM_RETURN_VIA_PTR */
        IpduM_IncContainerTxConfirmationBufferReadIdxOfContainerTxConfirmationBufferInfo(containerTxConfirmationBufferInfoIdx);  /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

        retVal = E_OK;
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }

  return retVal;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_TransmitContainerPdu_DirectDP()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_TransmitContainerPdu_DirectDP(IpduM_CTxContainerPduIterType txContainerId)
{
  Std_ReturnType transmitResult = E_NOT_OK;  /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
  if(IpduM_ContainerTx_TxConf_IsTransmissionAllowed(txContainerId))
# endif
  {
    IpduM_DataQueueInstanceReadIdxOfDataQueueInfoType dataQueueInstanceReadIdx = IpduM_GetDataQueueInstanceReadIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId));

    PduInfoType pduInfo;
    pduInfo = IpduM_ContainerTx_DataQueueInstance_GetAsPointer(dataQueueInstanceReadIdx);
    IpduM_ContainerTx_AdaptMetaDataSize(txContainerId, &pduInfo); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */

# if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
    IpduM_ContainerTx_DataQueueInstance_CopyContainedPduIDs2TxConfBuffer(dataQueueInstanceReadIdx, txContainerId);
# endif
      
# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
    IpduM_ContainerTx_TxConf_StartTimeout(txContainerId);
# endif

    transmitResult = PduR_IpduMTransmit(IpduM_GetTxContainerPduRefOfTxContainerPdu(txContainerId), &pduInfo);  /* SBSW_IPDUM_TRANSMITCURRCONTAINERPDU_CALL_PDURTRANSMIT */

    if(transmitResult == E_OK)
    {
      /* Reset the read queue instance and remove it by incrementing the readIdx of the queue. */
      IpduM_ContainerTx_DataQueueInstance_Init(dataQueueInstanceReadIdx, txContainerId);
      IpduM_ContainerTx_DataQueue_IncrementReadPtr(txContainerId);
    }
# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
    else
    {
      IpduM_ContainerTx_TxConf_StopTimeout(txContainerId);
    }
# endif
  }

  return transmitResult;
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu(IpduM_CTxContainerPduIterType txContainerId)
{
  if(IpduM_ContainerTx_DataQueue_IsFifoQueueFull(txContainerId))
  {
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
    IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERTX_DATAQUEUE_QUEUECURRCONTAINERPDU, IPDUM_E_QUEUEOVFL);
# endif

    /* Reset the read queue instance and remove it by incrementing the readIdx of the queue. */
    IpduM_ContainerTx_DataQueueInstance_Init(IpduM_GetDataQueueInstanceReadIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId)), txContainerId);
    IpduM_ContainerTx_DataQueue_IncrementReadPtr(txContainerId);
  }

  /* Queue the container PDU (i.e. increment write pointer). */
  IpduM_ContainerTx_DataQueue_IncrementWritePtr(txContainerId);
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu(IpduM_CTxContainerPduIterType txContainerId, boolean queueCurrentContainer)
{
  boolean wasQueueEmpty = IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty(txContainerId);

# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
  /* Depending on the call context, the current container instance must be closed and queued:
   *   - the current container instance is full (both direct and triggered transmission)
   *   - direct transmission: the current container instance is always closed before transmission.
   * For trigger transmit: the current container instance is left open until it is fetched in the TriggerTransmit API. */
  if(queueCurrentContainer)
# endif
  {
    IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu(txContainerId);
  }

  if(wasQueueEmpty) /* Only transmit to the lower layer if there are no other pending transmits. */
  {
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
    if(IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId))
    {
      if(IpduM_ContainerTx_TransmitEmptyPdu(txContainerId) == E_NOT_OK)
      {
        /* Close and queue the current container instance. This way the transmission can be retried in the next Mainfunction. */
        IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu(txContainerId);
      }
    }
    else
# endif
    {
      (void) IpduM_ContainerTx_DataQueueHandling_TransmitContainerPdu_DirectDP(txContainerId);
    }
  }

  IPDUM_DUMMY_STATEMENT(queueCurrentContainer);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_AddPdu_DynamicLayout()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_AddPdu_DynamicLayout(IpduM_TxContainedPduIterType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  IpduM_DataQueueInstanceWriteIdxOfDataQueueInfoType dataQueueInstanceWriteIdx = IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId));
  PduLengthType writeOffset = IpduM_GetFillCountOfDataQueueInstance(dataQueueInstanceWriteIdx);    /* SBSW_IPDUM_CSL02_OVER_CSL03 */

  /* Set FirstContainedPdu Flag. This can be evaluated e.g. by the trigger module. */
  IpduM_SetFirstContainedPduOfTxContainerPdu(txContainerId, (IpduM_ContainerTx_DataQueueInstance_GetFillCount(dataQueueInstanceWriteIdx) == 0u));  /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

  {
    uint8 headerSize = IpduM_ContainerTx_GetHeaderSize(txContainerId);

    (void) IpduM_ContainerTx_DataQueueInstance_PutHeader(dataQueueInstanceWriteIdx, writeOffset, IpduM_GetHeaderIdOfTxContainedPdu(txContainedId), PduInfoPtr->SduLength, headerSize); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
    writeOffset += headerSize;
  }

  {
    (void) IpduM_ContainerTx_DataQueueInstance_Put(dataQueueInstanceWriteIdx, PduInfoPtr, writeOffset); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
    writeOffset += PduInfoPtr->SduLength;
  }

  IpduM_SetFillCountOfDataQueueInstance(dataQueueInstanceWriteIdx, writeOffset);    /* SBSW_IPDUM_CSL02_OVER_CSL03 */

  /* Write the Id to the internal 'Id buffer' as well. */
  IpduM_ContainerTx_DataQueue_AddPdu2IdBuffer((IpduM_TxUpIndIdxOfTxUpInfoType) txContainedId);
}
#endif

#if ((IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueue_AddPdu_StaticLayout()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueue_AddPdu_StaticLayout(IpduM_TxContainedPduIterType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  IpduM_DataQueueInstanceWriteIdxOfDataQueueInfoType dataQueueInstanceWriteIdx = IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId));

  /* Set FirstContainedPdu Flag. This can be evaluated e.g. by the trigger module. */
  IpduM_SetFirstContainedPduOfTxContainerPdu(txContainerId, (IpduM_ContainerTx_DataQueueInstance_GetFillCount(dataQueueInstanceWriteIdx) == 0u));  /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

  {
    /* PDUs with no headers and static layout */
    /* Write the sdu to the buffer */
    (void) IpduM_ContainerTx_DataQueueInstance_Put(dataQueueInstanceWriteIdx, PduInfoPtr, IpduM_GetOffsetOfTxContainedPdu(txContainedId)); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */

# if (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON)
    if(IpduM_IsUpdateBitUsedOfTxContainedPdu(txContainedId))
    {
      (void) IpduM_ContainerTx_DataQueueInstance_SetBit(dataQueueInstanceWriteIdx, IpduM_GetUpdateIndicationBitPositionOfTxContainedPdu(txContainedId));
    }
# endif

    /* Mark Pdu as non-empty */
    IpduM_SetFillCountOfDataQueueInstance(dataQueueInstanceWriteIdx, IpduM_GetDataQueueBufferLengthOfDataQueueInstance(dataQueueInstanceWriteIdx));    /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  }

  /* Write the Id to the internal 'Id buffer' as well. */
  IpduM_ContainerTx_DataQueue_AddPdu2IdBuffer((IpduM_TxUpIndIdxOfTxUpInfoType) txContainedId);
}
#endif

#if ((IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_ClearBuffer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_ClearBuffer(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, uint8 clearPattern)
{
  IpduM_DataQueueBufferEndIdxOfDataQueueInstanceType dataQueueBufferIdx = IpduM_GetDataQueueBufferStartIdxOfDataQueueInstance(dataQueueInstanceIdx);

  for(; dataQueueBufferIdx < IpduM_GetDataQueueBufferEndIdxOfDataQueueInstance(dataQueueInstanceIdx); dataQueueBufferIdx++)
  {
    IpduM_SetDataQueueBuffer(dataQueueBufferIdx, clearPattern);    /* SBSW_IPDUM_CSL01 */
  }
}
#endif

#if ((IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON) && (IPDUM_UPDATEBITUSEDOFTXCONTAINEDPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueInstance_ResetUpdateBits()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
*******************************************************************************************/
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueInstance_ResetUpdateBits(IpduM_CDataQueueInstanceIterType dataQueueInstanceIdx, IpduM_CTxContainerPduIterType txContainerId)
{
  IpduM_TxContainedPduIterType txContainedPduIdx = IpduM_GetTxContainedPduStartIdxOfTxContainerPdu(txContainerId);

  for(; txContainedPduIdx < IpduM_GetTxContainedPduEndIdxOfTxContainerPdu(txContainerId); txContainedPduIdx++)
  {
    if(IpduM_IsUpdateBitUsedOfTxContainedPdu(txContainedPduIdx))
    {
      (void) IpduM_ContainerTx_DataQueueInstance_ClearBit(dataQueueInstanceIdx, IpduM_GetUpdateIndicationBitPositionOfTxContainedPdu(txContainedPduIdx));
    }
  }
}
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_UnpackContainerPdu()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_UnpackContainerPdu(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength)
{
  switch(IpduM_GetHeaderSizeOfRxContainerPdu(rxContainerId))
  {
# if (IPDUM_EXISTS_NONE_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
    case IPDUM_NONE_HEADERSIZEOFRXCONTAINERPDU:
      IpduM_ContainerRx_UnpackContainerPdu_StaticLayout(rxContainerId, dataPtr, pduLength); /* SBSW_IPDUM_FUNCTIONCALL_PTR_LENGTH_CHECKED_BY_CALLER */
      break;
# endif

# if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
#  if(IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
    case IPDUM_SHORT_HEADERSIZEOFRXCONTAINERPDU:
#  endif
#  if(IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
    case IPDUM_LONG_HEADERSIZEOFRXCONTAINERPDU:
#  endif
      IpduM_ContainerRx_UnpackContainerPdu_DynamicLayout(rxContainerId, dataPtr, pduLength); /* SBSW_IPDUM_FUNCTIONCALL_PTR_LENGTH_CHECKED_BY_CALLER */
      break;
# endif

    default: /* COV_IPDUM_SWITCH_CASE_DEFAULT */
      /* Because of Misra: Nothing to do. */
      break;
  }
}
#endif

#if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_UnpackContainerPdu_DynamicLayout()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_UnpackContainerPdu_DynamicLayout(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength)
{
  PduLengthType containedPduIdx = 0u;
  uint8 headerSize = IpduM_ContainerRx_GetHeaderSize(rxContainerId);

  PduInfoType pduInfo;
  pduInfo.SduDataPtr = dataPtr;
  pduInfo.SduLength = pduLength;
  
  IpduM_ContainerRx_AdaptMetaDataSize(rxContainerId, &pduInfo); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */

  /* PDUs with long headers and short headers */
  /* loop over all contained-pdus */
  while((containedPduIdx + headerSize) <= pduLength)
  {
    IpduM_ContainedPduHeaderType header;      /* header.headerId; header.dlc */

    /* get header id and dlc of the contained PDU */
    header = IpduM_Container_ReadHeader(&(dataPtr[containedPduIdx]), headerSize);       /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */ /* VCA_PDUINFOPTR_SELF_CONSTRUCTED */

    /* Increment read idx to begin of pdu */
    containedPduIdx += headerSize;

    /* if header id == 0: break loop */
    if(header.headerId == 0u)
    {
      break;
    }
    if(((containedPduIdx) + header.dlc) <= pduLength)     /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
    {
      /* look up the header id in IpduM_RxContainedPdu */
      IpduM_RxContainedPduIterType rxContainedPduId = 0u;

      if(IpduM_ContainerRx_SearchRxHeaderId(rxContainerId, header.headerId, &rxContainedPduId) == E_OK)  /* SBSW_IPDUM_FUNCTIONCALL_OUT_PTR */
      {
        /* check if either "accept all" is configured or PDU is configured for this container */
        if((IpduM_IsRxContainerPduUsedOfRxContainedPdu(rxContainedPduId) && (IpduM_GetRxContainerPduIdxOfRxContainedPdu(rxContainedPduId) == rxContainerId))
#  if (IPDUM_ACCEPTALLPDUSOFRXCONTAINERPDU == STD_ON)
         || IpduM_IsAcceptAllPdusOfRxContainerPdu(rxContainerId)
#  endif
        ) /* COV_IPDUM_INVALID_CONFIGURATION */
        {
          /* header id exists */
          PduInfoType dynamicPduInfo;
          dynamicPduInfo.SduDataPtr = &(dataPtr[containedPduIdx]);
          dynamicPduInfo.SduLength = (PduLengthType) header.dlc;
          /* send RxIndication for the referenced PduR-PDU to PduR module */
          PduR_IpduMRxIndication(IpduM_GetContainedPduRefOfRxContainedPdu(rxContainedPduId), &dynamicPduInfo);       /* SBSW_IPDUM_UNPACKRXCONTAINERPDU_CALL_PDURRXINDICATION */ /* VCA_IPDUM_FUNCTIONCALL_PDUINFOPTR_SELF_CONSTRUCTED */
        }
      }
    }
#  if (IPDUM_DEV_ERROR_REPORT == STD_ON)
    else
    {
      IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERRX_UNPACKCONTAINERPDU_DYNAMICLAYOUT, IPDUM_E_HEADER);
    }
#  endif

    /* increment contained pdu read idx by dlc */
    containedPduIdx += (PduLengthType) header.dlc;
  }
}
#endif

#if (IPDUM_EXISTS_NONE_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_UnpackContainerPdu_StaticLayout()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_UnpackContainerPdu_StaticLayout(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength)
{
  IpduM_RxContainedPduIndEndIdxOfRxContainerPduType containedPduIndIdx;

  /* PDUs with static layout and no header */
  for(containedPduIndIdx = IpduM_GetRxContainedPduIndStartIdxOfRxContainerPdu(rxContainerId); containedPduIndIdx < IpduM_GetRxContainedPduIndEndIdxOfRxContainerPdu(rxContainerId); containedPduIndIdx++)
  {
    PduLengthType containedPduIdx = IpduM_GetRxContainedPduInd(containedPduIndIdx);

#  if (IPDUM_UPDATEBITUSEDOFRXCONTAINEDPDU == STD_ON)
    /* Check Update Bit */
    PduLengthType updateBitBytePos;
    uint8 updateBitMask;
    updateBitBytePos = (PduLengthType) ((PduLengthType) IpduM_GetUpdateIndicationBitPositionOfRxContainedPdu(containedPduIdx) >> 3u);
    updateBitMask = (uint8) (0x01u << (IpduM_GetUpdateIndicationBitPositionOfRxContainedPdu(containedPduIdx) % 8u));
    /* if (update bits used AND update bit is set) OR (update bits not used) */
    if((IpduM_IsUpdateBitUsedOfRxContainedPdu(containedPduIdx) && ((dataPtr[updateBitBytePos] & updateBitMask) != 0x00u)) || !IpduM_IsUpdateBitUsedOfRxContainedPdu(containedPduIdx))
#  endif
    {
      PduInfoType staticPduInfo;
      staticPduInfo.SduDataPtr = &(dataPtr[IpduM_GetOffsetOfRxContainedPdu(containedPduIdx)]);
      staticPduInfo.SduLength = IpduM_GetLengthOfRxContainedPdu(containedPduIdx);

      /* if contained pdus completely fits into received container */
      if(IpduM_GetEndBytePositionOfRxContainedPdu(containedPduIdx) <= pduLength)
      {
        /* send RxIndication for the referenced PduR-PDU to PduR module */
        PduR_IpduMRxIndication(IpduM_GetContainedPduRefOfRxContainedPdu(containedPduIdx), &staticPduInfo);    /* SBSW_IPDUM_UNPACKRXCONTAINERPDU_CALL_PDURRXINDICATION */ /* VCA_IPDUM_FUNCTIONCALL_PDUINFOPTR_SELF_CONSTRUCTED */
      }
    }
  }
}
#endif

#if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_SearchRxHeaderId()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerRx_SearchRxHeaderId(IpduM_RxContainerPduIterType rxContainerPduIdx, uint32 headerId, P2VAR(IpduM_RxContainedPduIterType, AUTOMATIC, IPDUM_APPL_DATA) foundRxContainedPduId)
{
  Std_ReturnType retVal = E_NOT_OK;
  IpduM_RxContainedPduIndEndIdxOfRxContainerPduType containedPduIndIdx;

  for(containedPduIndIdx = IpduM_GetRxContainedPduIndStartIdxOfRxContainerPdu(rxContainerPduIdx); containedPduIndIdx < IpduM_GetRxContainedPduIndEndIdxOfRxContainerPdu(rxContainerPduIdx); containedPduIndIdx++)
  {
    IpduM_RxContainedPduIterType rxContainedPduId = IpduM_GetRxContainedPduInd(containedPduIndIdx);

    if(IpduM_GetHeaderIdOfRxContainedPdu(rxContainedPduId) == (IpduM_HeaderIdOfRxContainedPduType)headerId)
    {
      *foundRxContainedPduId = rxContainedPduId;  /* SBSW_IPDUM_FUNCTIONCALL_OUT_PTR */
      retVal = E_OK;
      break;
    }
  }

  return retVal;
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Put()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_Queue_Put(IpduM_RxContainerPduIterType rxContainerId, P2CONST(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, PduLengthType pduLength)
{
  IpduM_ContainerRxQueueInfoIdxOfRxContainerPduType containerRxQueueInfoIdx = IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId);
  IpduM_ContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfoType containerRxQueueInstanceWriteIdx = IpduM_GetContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx);
  IpduM_ContainerRxQueueBufferStartIdxOfContainerRxQueueInstanceType containerRxQueueBufferStartIdx = IpduM_GetContainerRxQueueBufferStartIdxOfContainerRxQueueInstance(containerRxQueueInstanceWriteIdx);
  IpduM_ContainerRxQueueBufferLengthOfContainerRxQueueInstanceType containerRxQueueBufferLength = IpduM_GetContainerRxQueueBufferLengthOfContainerRxQueueInstance(containerRxQueueInstanceWriteIdx);

  VStdLib_MemCpy_s(IpduM_GetAddrContainerRxQueueBuffer(containerRxQueueBufferStartIdx), containerRxQueueBufferLength, dataPtr, pduLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_IPDUM_VSTDLIB_SAFE */  /* VCA_IPDUM_VSTDLIB_MEMCPY_SAFE */

  /* store actual received pduLength */
  IpduM_SetReceivedSizeOfContainerRxQueueInstance(containerRxQueueInstanceWriteIdx, pduLength);    /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

  /* update write pointers */
  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  IpduM_IncWriteCountOfContainerRxQueueInfo(containerRxQueueInfoIdx);    /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

  IpduM_IncContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx);      /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  if(IpduM_GetContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx) >= IpduM_GetContainerRxQueueInstanceEndIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx))
  {
    IpduM_SetContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx, IpduM_GetContainerRxQueueInstanceStartIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx));        /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Get()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerRx_Queue_Get(IpduM_RxContainerPduIterType rxContainerId, P2VAR(uint8, AUTOMATIC, IPDUM_APPL_DATA) dataPtr, P2VAR(PduLengthType, AUTOMATIC, IPDUM_APPL_DATA) pduLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  if(!IpduM_ContainerRx_Queue_IsEmpty(rxContainerId))
  {
    IpduM_ContainerRxQueueInfoIdxOfRxContainerPduType containerRxQueueInfoIdx = IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId);
    IpduM_ContainerRxQueueInstanceReadIdxOfContainerRxQueueInfoType containerRxQueueInstanceReadIdx = IpduM_GetContainerRxQueueInstanceReadIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx);
    IpduM_ContainerRxQueueBufferStartIdxOfContainerRxQueueInstanceType containerRxQueueBufferStartIdx = IpduM_GetContainerRxQueueBufferStartIdxOfContainerRxQueueInstance(containerRxQueueInstanceReadIdx);
    IpduM_ContainerRxQueueBufferLengthOfContainerRxQueueInstanceType containerRxQueueBufferLength = IpduM_GetContainerRxQueueBufferLengthOfContainerRxQueueInstance(containerRxQueueInstanceReadIdx);

    VStdLib_MemCpy_s(dataPtr, *pduLength, IpduM_GetAddrContainerRxQueueBuffer(containerRxQueueBufferStartIdx), containerRxQueueBufferLength);  /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_IPDUM_VSTDLIB_SAFE */  /* VCA_IPDUM_VSTDLIB_MEMCPY_SAFE */

    *pduLength = IpduM_GetReceivedSizeOfContainerRxQueueInstance(containerRxQueueInstanceReadIdx);  /* SBSW_IPDUM_DEQUEUE_CONTAINER_PTR_WRITE */

    IpduM_ContainerRx_Queue_Remove(rxContainerId);

    retVal = E_OK;
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

  return retVal;
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Remove
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_Queue_Remove(IpduM_RxContainerPduIterType rxContainerId)
{
  IpduM_ContainerRxQueueInfoIdxOfRxContainerPduType containerRxQueueInfoIdx = IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId);

  /* increment read pointer */
  IpduM_IncReadCountOfContainerRxQueueInfo(containerRxQueueInfoIdx); /* SBSW_IPDUM_CSL02_OVER_CSL03 */

  IpduM_IncContainerRxQueueInstanceReadIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx); /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  if(IpduM_GetContainerRxQueueInstanceReadIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx) >= IpduM_GetContainerRxQueueInstanceEndIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx))
  {
    IpduM_SetContainerRxQueueInstanceReadIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx, IpduM_GetContainerRxQueueInstanceStartIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx)); /* SBSW_IPDUM_CSL02_OVER_CSL03 */
  }
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_Init
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_Queue_Init(void)
{
  IpduM_CContainerRxQueueInfoIterType containerRxQueueInfoIdx;

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  for(containerRxQueueInfoIdx = 0u; containerRxQueueInfoIdx < IpduM_GetSizeOfCContainerRxQueueInfo(); containerRxQueueInfoIdx++)
  {
    IpduM_SetContainerRxQueueInstanceReadIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx, IpduM_GetContainerRxQueueInstanceStartIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx));   /* SBSW_IPDUM_CSL01 */
    IpduM_SetContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx, IpduM_GetContainerRxQueueInstanceStartIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx));  /* SBSW_IPDUM_CSL01 */
    IpduM_SetReadCountOfContainerRxQueueInfo(containerRxQueueInfoIdx, 0u); /* SBSW_IPDUM_CSL01 */
    IpduM_SetWriteCountOfContainerRxQueueInfo(containerRxQueueInfoIdx, 0u);        /* SBSW_IPDUM_CSL01 */
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_IsFull
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerRx_Queue_IsFull(IpduM_RxContainerPduIterType rxContainerId)
{
  IpduM_ContainerRxQueueInfoIdxOfRxContainerPduType containerRxQueueInfoIdx = IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId);

  return ((IpduM_WriteCountOfContainerRxQueueInfoType) (IpduM_GetWriteCountOfContainerRxQueueInfo(containerRxQueueInfoIdx) - IpduM_GetReadCountOfContainerRxQueueInfo(containerRxQueueInfoIdx))
                >= IpduM_GetContainerRxQueueInstanceLengthOfContainerRxQueueInfo(containerRxQueueInfoIdx));
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_Queue_IsEmpty
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerRx_Queue_IsEmpty(IpduM_RxContainerPduIterType rxContainerId)
{
  IpduM_ContainerRxQueueInfoIdxOfRxContainerPduType containerRxQueueInfoIdx = IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId);

  return (IpduM_WriteCountOfContainerRxQueueInfoType) (IpduM_GetWriteCountOfContainerRxQueueInfo(containerRxQueueInfoIdx) - IpduM_GetReadCountOfContainerRxQueueInfo(containerRxQueueInfoIdx)) == 0u;
}
#endif

#if ((IPDUM_CCONTAINERRXQUEUEINFO == STD_ON) || (IPDUM_CTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_Container_Init()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_Container_Init(void)
{
# if(IPDUM_TXCONTAINEDPDU == STD_ON)
  IpduM_ContainerTx_Init();  /* PRQA S 2987 */ /* MD_IpduM_2987 */
# endif

# if(IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
  IpduM_ContainerTx_DataQueue_Init();
# endif

# if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
  IpduM_ContainerRx_Queue_Init();
# endif

# if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
  IpduM_ContainerTx_RequestQueue_Init();  /* PRQA S 2987 */ /* MD_IpduM_2987 */
# endif

# if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
  IpduM_ContainerTx_TxConfBuffer_Init();  /* PRQA S 2987 */ /* MD_IpduM_2987 */
# endif
}
#endif

#if (IPDUM_TXCONTAINEDPDU== STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_Init()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_Init(void)
{
  IpduM_VTxContainerPduIterType txContainerPduIdx;

  for(txContainerPduIdx = 0u; txContainerPduIdx < IpduM_GetSizeOfVTxContainerPdu(); txContainerPduIdx++)
  {
    IpduM_SetFirstContainedPduOfTxContainerPdu(txContainerPduIdx, FALSE);  /* SBSW_IPDUM_CSL01 */
# if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
    IpduM_SetContainerPduSendTimeoutOfTxContainerPdu(txContainerPduIdx, 0); /* SBSW_IPDUM_CSL01 */
# endif
  }
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_IsTriggered()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_IsTriggered(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, uint32 containerLength)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  boolean isTriggered;

  if(containerLength > IpduM_GetTxSizeThresholdOfTxContainerPdu(txContainerId))
  {
    isTriggered = TRUE;
  }
# if (IPDUM_TXPDUTRIGGEROFTXCONTAINEDPDU == STD_ON)
  else if(IpduM_IsTxPduTriggerOfTxContainedPdu(txContainedId))
  {
    isTriggered = TRUE;
  }
# endif
# if (IPDUM_FIRSTCONTAINEDPDUTRIGGEROFTXCONTAINERPDU == STD_ON)
  else if(IpduM_IsFirstContainedPduTriggerOfTxContainerPdu(txContainerId) && IpduM_IsFirstContainedPduOfTxContainerPdu(txContainerId))  /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  {
    isTriggered = TRUE;
  }
# endif
  else
  {
    /* else path because of MISRA. */
    isTriggered = FALSE;
  }

  return isTriggered;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_Start
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_Start(IpduM_TxContainedPduIterType txContainedId)
{
# if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
  IpduM_TxContainerPduIdxOfTxContainedPduType txContainerIdx = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);

  if(IpduM_IsFirstContainedPduOfTxContainerPdu(txContainerIdx))
  {
    IpduM_ContainerTx_SendTimeout_SetContainerPduTimeout(txContainerIdx);
  }
# endif
# if (IPDUM_SENDTODEFOFTXCONTAINEDPDU == STD_ON)
  IpduM_ContainerTx_SendTimeout_SetContainedPduTimeout(txContainedId);
# endif

  IPDUM_DUMMY_STATEMENT(txContainedId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */  /* lint -e{438} */
}
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_SetContainerPduTimeout
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_SetContainerPduTimeout(IpduM_CTxContainerPduIterType txContainerId)
{
  if(IpduM_IsSendToDefOfTxContainerPdu(txContainerId))
  {
    /* Start timeout */
    IpduM_SetContainerPduSendTimeoutOfTxContainerPdu(txContainerId, IpduM_GetSendTimeoutOfTxContainerPdu(txContainerId)); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
  }

  IPDUM_DUMMY_STATEMENT(txContainerId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */  /* lint -e{438} */
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_Stop
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_Stop(IpduM_CTxContainerPduIterType txContainerId)
{
# if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
  IpduM_SetContainerPduSendTimeoutOfTxContainerPdu(txContainerId, 0); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
# endif

  IPDUM_DUMMY_STATEMENT(txContainerId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */  /* lint -e{438} */
}
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_SetContainedPduTimeout
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_SetContainedPduTimeout(IpduM_TxContainedPduIterType txContainedId)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);

  if(IpduM_IsSendToDefOfTxContainedPdu(txContainedId))
  {
    if((IpduM_GetContainerPduSendTimeoutOfTxContainerPdu(txContainerId) > IpduM_GetSendTimeoutOfTxContainedPdu(txContainedId)) /* Update current running timer if contained Pdu timeout is smaller. */
        || (IpduM_GetContainerPduSendTimeoutOfTxContainerPdu(txContainerId) == 0u)) /* OR Update timer to start it initially. */
    {
      IpduM_SetContainerPduSendTimeoutOfTxContainerPdu(txContainerId, IpduM_GetSendTimeoutOfTxContainedPdu(txContainedId)); /* SBSW_IPDUM_INDIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
    }
  }

  IPDUM_DUMMY_STATEMENT(txContainedId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */  /* lint -e{438} */
}
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_SendTimeout_IsRunning
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_IsRunning(IpduM_CTxContainerPduIterType txContainerId)
{
  boolean isRunning = FALSE;

  if(IpduM_GetContainerPduSendTimeoutOfTxContainerPdu(txContainerId) > 0u)
  {
    isRunning = TRUE;
  }

  return isRunning;
}
#endif

#if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_SendTimeout_MainFunction()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(boolean, IPDUM_CODE) IpduM_ContainerTx_SendTimeout_MainFunction(IpduM_CTxContainerPduIterType txContainerId)
{
  boolean isSendTimeoutElapsed = FALSE;

  IpduM_ContainerPduSendTimeoutOfTxContainerPduType containerPduSendTimeout = IpduM_GetContainerPduSendTimeoutOfTxContainerPdu(txContainerId);

  if(containerPduSendTimeout == 1u)
  {
    isSendTimeoutElapsed = TRUE;
  }
  IpduM_DecContainerPduSendTimeoutOfTxContainerPdu(txContainerId); /* SBSW_IPDUM_DIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */

  return isSendTimeoutElapsed;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_Transmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires txContainedId < IpduM_GetSizeOfTxContainedPdu();
 * \endspec
 */
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_Transmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  uint8 errorId = IPDUM_E_NO_ERROR;
  Std_ReturnType retVal = E_NOT_OK;
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);
  IpduM_PduLengthOfTxContainerPduType bufferInstanceLength = IpduM_GetPduLengthOfTxContainerPdu(txContainerId);
  PduLengthType pduLength = PduInfoPtr->SduLength;

/* *INDENT-OFF* */
  /* Long headers are 8 bytes, short headers are 4 bytes in size.
     Long headers have 4 bytes ID and 4 bytes DLC.
     Short headers have 3 bytes ID and 1 byte DLC. */
/* *INDENT-ON* */
  uint8 headerSize = IpduM_ContainerTx_GetHeaderSize(txContainerId);

# if (IPDUM_DEV_ERROR_DETECT == STD_ON)
  IpduM_PduLengthOfTxContainerPduType pduAndHeaderLength = (IpduM_PduLengthOfTxContainerPduType)pduLength + (IpduM_PduLengthOfTxContainerPduType)headerSize;
  if(pduAndHeaderLength > bufferInstanceLength)
  {
    errorId = IPDUM_E_PARAM;
  }
#  if (IPDUM_EXISTS_SHORT_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  else if((pduLength > 255u) && (headerSize == IPDUM_HEADERSIZE_SMALL)) /* COV_IPDUM_SINGLE_HEADERSIZE_CONFIG */
  {
    /* For short headers, only 8 bits are available for DLC. So values >255 are not allowed here. */
    errorId = IPDUM_E_PARAM;
  }
#  endif
  else
# endif
  {
    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    {
# if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
      if(IpduM_IsRequestQueuePrioIndirectionUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
      {
        IpduM_ContainerTx_RequestQueueHandling_Transmit(txContainedId, PduInfoPtr);  /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
      }
# endif
# if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
      if(IpduM_IsDataQueueInfoUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
      {
        IpduM_ContainerTx_DataQueueHandling_Transmit(txContainedId, PduInfoPtr);  /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
      }
# endif

      /* PDU is added to the PDU by here */
      retVal = E_OK;
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }

# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_CONTAINERTX_TRANSMIT, (errorId));
  }
# endif
  IPDUM_DUMMY_STATEMENT(errorId);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */  /* lint -e{438} */

  return retVal;
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_Transmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_Transmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);

  /* PDUs that use the request queue get only their ID added */
  IpduM_ContainerTx_RequestQueue_Put(txContainedId, PduInfoPtr->SduLength);

  IpduM_ContainerTx_SendTimeout_Start(txContainedId);

  /* Check trigger conditions and trigger the PDU if conditions are met. */
  if(IpduM_ContainerTx_IsTriggered(txContainedId, IpduM_ContainerTx_RequestQueue_CalculateSize(txContainerId)))
  {

    IpduM_ContainerTx_RequestQueueHandling_TriggerTransmission(txContainerId);

    IpduM_ContainerTx_SendTimeout_Stop(txContainerId);
  }
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_Transmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_Transmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduIdxOfTxContainedPdu(txContainedId);

# if (IPDUM_EXISTS_NONE_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfTxContainerPdu(txContainerId) == IPDUM_NONE_HEADERSIZEOFTXCONTAINERPDU)
  {
    /* Pdu always fits in container with static layout. The Pdu will be overwritten at its configured position. */
    IpduM_ContainerTx_DataQueue_AddPdu_StaticLayout(txContainedId, PduInfoPtr); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
  }
  else
# endif
  {
    if(!IpduM_ContainerTx_DataQueue_FitsPduIntoCurrentOpenInstance(txContainerId, PduInfoPtr->SduLength))
    {
      /* Handover queueCurrentContainer == TRUE. The current container must always be queued and closed, as it is full. */
      IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu(txContainerId, TRUE);

      IpduM_ContainerTx_SendTimeout_Stop(txContainerId);
    }
    /* PDU now does fit into current container instance: add PDU. */
    IpduM_ContainerTx_DataQueue_AddPdu_DynamicLayout(txContainedId, PduInfoPtr); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
  }

  IpduM_ContainerTx_SendTimeout_Start(txContainedId);

  /* Check trigger conditions and trigger the PDU if conditions are met. */
  if(IpduM_ContainerTx_IsTriggered(txContainedId, IpduM_ContainerTx_DataQueueInstance_GetFillCount(IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId)))))
  {
    IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu(txContainerId, IpduM_IsDirectDataProvisionOfTxContainerPdu(txContainerId));

    IpduM_ContainerTx_SendTimeout_Stop(txContainerId);
  }
}
#endif

#if(IPDUM_TRIGGER_TRANSMIT_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TriggerTransmit(IpduM_TxContainerPduIdxOfCTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  IpduM_PduLengthOfTxContainerPduType bufferInstanceLength = IpduM_GetPduLengthOfTxContainerPdu(txContainerId);

  if(PduInfoPtr->SduLength >= bufferInstanceLength)
  {
# if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
    if(IpduM_IsRequestQueuePrioIndirectionUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    {
      retVal = IpduM_ContainerTx_RequestQueueHandling_TriggerTransmit(txContainerId, PduInfoPtr);  /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
    }
# endif
# if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
    if(IpduM_IsDataQueueInfoUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
    {
      retVal = IpduM_ContainerTx_DataQueueHandling_TriggerTransmit(txContainerId, PduInfoPtr);  /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
    }
# endif
  }
  return retVal;
}
#endif

#if((IPDUM_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON) && (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_TriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_TriggerTransmit(IpduM_TxContainerPduIdxOfCTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  if(!IpduM_ContainerTx_RequestQueue_IsEmpty(txContainerId))
  {
    PduInfoType pduInfo;

    /* current instance is closed -> reset its send timeout */
    IpduM_ContainerTx_SendTimeout_Stop(txContainerId);

    /* last-is-best PDU: load data to last-is-best buffer via TriggerTransmit, then use this buffer for transmission */
    pduInfo = IpduM_ContainerTx_RequestQueue_FillLastIsBestContainer(txContainerId);

    /* Copy PDU from container buffer to provided destination buffer */
    VStdLib_MemCpy_s(PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength, pduInfo.SduDataPtr, pduInfo.SduLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_IPDUM_VSTDLIB_SAFE */  /* VCA_IPDUM_VSTDLIB_MEMCPY_SAFE */

    PduInfoPtr->SduLength = pduInfo.SduLength;  /* SBSW_IPDUM_CONTAINERTRIGGERTRANSMIT_PTR_WRITE */

# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
    IpduM_ContainerTx_TxConf_StartTimeout(txContainerId);
# endif
    retVal = E_OK;
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

  return retVal;
}
#endif

#if((IPDUM_TRIGGER_TRANSMIT_API == STD_ON) && (IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON) && (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_TriggerTransmit()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
IPDUM_LOCAL_INLINE FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_TriggerTransmit(IpduM_TxContainerPduIdxOfCTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  boolean pleaseCopyTheData = FALSE;

  SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  if(IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty(txContainerId))
  {
    IpduM_DataQueueInstanceWriteIdxOfDataQueueInfoType dataQueueInstanceWriteIdx = IpduM_GetDataQueueInstanceWriteIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId));

    if(IpduM_ContainerTx_DataQueueInstance_GetFillCount(dataQueueInstanceWriteIdx) > 0u)
    {/* Queue is empty, but the current open instance has data. Put it in the queue and read it below. */
      IpduM_ContainerTx_DataQueue_QueueCurrContainerPdu(txContainerId);
      IpduM_ContainerTx_SendTimeout_Stop(txContainerId);
      pleaseCopyTheData = TRUE;
    }
  }
  else
  {
    pleaseCopyTheData = TRUE;
  }

  if(pleaseCopyTheData == TRUE)
  {
    IpduM_DataQueueInstanceReadIdxOfDataQueueInfoType dataQueueInstanceReadIdx = IpduM_GetDataQueueInstanceReadIdxOfDataQueueInfo(IpduM_GetDataQueueInfoIdxOfTxContainerPdu(txContainerId));

    IpduM_ContainerTx_DataQueueInstance_Get(dataQueueInstanceReadIdx, PduInfoPtr); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */
# if(IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
    IpduM_ContainerTx_DataQueueInstance_CopyContainedPduIDs2TxConfBuffer(dataQueueInstanceReadIdx, txContainerId);
# endif

    /* Reset the read queue instance and remove it by incrementing the readIdx of the queue. */
    IpduM_ContainerTx_DataQueueInstance_Init(dataQueueInstanceReadIdx, txContainerId);
    IpduM_ContainerTx_DataQueue_IncrementReadPtr(txContainerId);

# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)
    IpduM_ContainerTx_TxConf_StartTimeout(txContainerId);
# endif
    retVal = E_OK;
  }
  SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();

  return retVal;
}
#endif

#if (IPDUM_TX_CONFIRMATION_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_TxConf_TxConfirmation()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConf_TxConfirmation(PduIdType TxPduId)
{
# if (IPDUM_TXCONFIRMATIONTIMEOUTOFTXCONTAINERPDU == STD_ON)  /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  IpduM_CTxContainerPduIterType containerPduId = IpduM_GetTxContainerPduIdxOfCTxLoInfoOfTxLoInfoWithInvalidIndexes(TxPduId);
  if(0u != IpduM_GetTxConfirmationTimeoutOfTxContainerPdu(containerPduId))
  {
    if(0u != IpduM_GetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(TxPduId))
    {
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
#  if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
      {
        PduIdType txConfId;

        while(IpduM_ContainerTx_TxConfBuffer_Get(containerPduId, &txConfId) == E_OK)  /* SBSW_IPDUM_RETURN_VIA_PTR */
        {
          if(IpduM_IsTxConfirmationOfTxContainedPdu(txConfId))  /* COV_IPDUM_ALWAYS_TXCONFIRMATION */
          {
            PduR_IpduMTxConfirmation(IpduM_GetTxContainedPduRefOfTxContainedPdu(txConfId)); /* VCA_IPDUM_FUNCTIONCALL_WITH_ONLY_ID */
          }
        }
        IpduM_ContainerTx_TxConfBuffer_Clear(containerPduId);
      }
#  endif

      IpduM_SetTxConfTimeoutCntOfVTxLoInfoOfTxLoInfoWithInvalidIndexes(TxPduId, IPDUM_RESET);      /* Clear counter */ /* SBSW_IPDUM_DIRECT_ACCESS_FROM_EXTERNAL_PARAMETER */
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    }
  }
# endif

  IPDUM_DUMMY_STATEMENT(TxPduId);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_RxIndication()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * \spec
 *   requires rxContainerId < IpduM_GetSizeOfRxContainerPdu();
 * \endspec
 */
FUNC(void, IPDUM_CODE) IpduM_ContainerRx_RxIndication(IpduM_RxPathwayIndIdxOfRxInfoType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
# if (IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
  if(IpduM_IsContainerRxQueueInfoUsedOfRxContainerPdu(rxContainerId))
  {/* Deferred processing. Enqueue PDU for later reception handling. */
    PduLengthType pduLength = PduInfoPtr->SduLength;
    PduLengthType bufferLength = IpduM_GetContainerRxQueueBufferLengthOfContainerRxQueueInstance(IpduM_GetContainerRxQueueInstanceWriteIdxOfContainerRxQueueInfo(IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId)));

    /* API Pattern Check against configured Queue Size. */
    /* Handle larger than configured PDUs by trimming to configured length */
    if(pduLength > bufferLength)
    {
      pduLength = bufferLength;
#  if (IPDUM_DEV_ERROR_REPORT == STD_ON)
      IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERRX_RXINDICATION, IPDUM_E_HEADER);
#  endif
    }

    /* If the PDU does not fit into container: DET, oldest entry will be overwritten while enqueueing */
    if(IpduM_ContainerRx_Queue_IsFull(rxContainerId))
    {
      /* Queue is full, return an error */
#  if (IPDUM_DEV_ERROR_REPORT == STD_ON)
      IpduM_Det_ReportRuntimeError(IPDUM_APIID_CONTAINERRX_RXINDICATION, IPDUM_E_QUEUEOVFL);
#  endif
      SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
      IpduM_ContainerRx_Queue_Remove(rxContainerId);
      SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    }

    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    IpduM_ContainerRx_Queue_Put(rxContainerId, PduInfoPtr->SduDataPtr, pduLength);  /* SBSW_IPDUM_CONTAINERRXINDICATION_CALL_ENQUEUERXCONTAINER */
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }
  else  
# endif
  {
    /* Immediate processing. Send RxIndications for all received contained-PDUs. */
    IpduM_ContainerRx_UnpackContainerPdu(rxContainerId, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength); /* SBSW_IPDUM_CONTAINERRXINDICATION_CALL_UNPACKRXCONTAINERPDU */
  }
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_AdaptMetaDataSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_AdaptMetaDataSize(IpduM_CTxContainerPduIterType txContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  /* J1939 only uses short headers */
# if (IPDUM_EXISTS_SHORT_HEADERSIZEOFTXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfTxContainerPdu(txContainerId) == IPDUM_SHORT_HEADERSIZEOFTXCONTAINERPDU) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    if(IpduM_GetMetaDataSizeOfTxContainerPdu(txContainerId) > 0u) /* COV_IPDUM_NO_META_DATA */
    {
        /* decrease DLC of last header by meta data size */
        PduInfoPtr->SduDataPtr[3] -= IpduM_GetMetaDataSizeOfTxContainerPdu(txContainerId); /* SBSW_IPDUM_ADAPTMETADATA_ARRAY_WRITE_ACCESS */
    }
  }
# endif
  IPDUM_DUMMY_STATEMENT(txContainerId);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#if((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_ContainerRx_AdaptMetaDataSize()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerRx_AdaptMetaDataSize(IpduM_RxContainerPduIterType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)
{
  /* J1939 only uses short headers */
# if (IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON)
  if(IpduM_GetHeaderSizeOfRxContainerPdu(rxContainerId) == IPDUM_SHORT_HEADERSIZEOFRXCONTAINERPDU) /* COV_IPDUM_DEFENSIVE_PROGRAMMING */
  {
    if(IpduM_GetMetaDataSizeOfRxContainerPdu(rxContainerId) > 0u) /* COV_IPDUM_NO_META_DATA */
    {
      /* increase DLC of last header by meta data size */
      PduInfoPtr->SduDataPtr[3] += IpduM_GetMetaDataSizeOfRxContainerPdu(rxContainerId); /* SBSW_IPDUM_ADAPTMETADATA_ARRAY_WRITE_ACCESS */
    }
  }
# endif
  IPDUM_DUMMY_STATEMENT(rxContainerId);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  IPDUM_DUMMY_STATEMENT(PduInfoPtr);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}
#endif

#define IPDUM_STOP_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define IPDUM_START_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

#if ((IPDUM_EXISTS_SHORT_HEADERSIZEOFRXCONTAINERPDU == STD_ON) || (IPDUM_EXISTS_LONG_HEADERSIZEOFRXCONTAINERPDU == STD_ON))
/*******************************************************************************************
 *  IpduM_CalculateSizeOfContainer()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(uint32, IPDUM_CODE) IpduM_CalculateSizeOfContainer(PduLengthType headerSize, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr)   /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  uint8 errorId = IPDUM_E_NO_ERROR;
  PduLengthType containerSize = 0u;
  
# if (IPDUM_DEV_ERROR_DETECT == STD_ON)
  if(!IpduM_IsInitialized())
  {
    errorId = IPDUM_E_UNINIT;
  }
  else if((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    errorId = IPDUM_E_PARAM_POINTER;
  } 
  else if(!(headerSize == IPDUM_HEADERSIZE_LARGE) && !(headerSize == IPDUM_HEADERSIZE_SMALL))  /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
  {
    errorId = IPDUM_E_PARAM;
  }
  else
# endif
  {
    IpduM_ContainedPduHeaderType currentHeader;

    while(containerSize <= (PduInfoPtr->SduLength - headerSize))  /* stop iterating one headersize before the end to avoid reading a partial header */
    {
      /* read header, add current contained PDU's length (including header) to containerSize */
      currentHeader = IpduM_Container_ReadHeader(&(PduInfoPtr->SduDataPtr[containerSize]), headerSize); /* SBSW_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */ /* VCA_IPDUM_FUNCTIONCALL_PDUINFOPTR_CHECKED_BY_CALLER */

      /* detect end of container */
      if(currentHeader.headerId == 0u)
      {
        break;
      }

      containerSize += headerSize + (PduLengthType) currentHeader.dlc;
    }
  }
  
# if (IPDUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != IPDUM_E_NO_ERROR)
  {
    IpduM_Det_ReportError(IPDUM_APIID_CALCULATECONTAINERSIZE, (errorId));
  }
# endif
  IPDUM_DUMMY_STATEMENT(errorId);       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return containerSize;
}
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_MainFunction()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_ContainerTx_MainFunction(IpduM_MainFunctionTxIndirectionIterType mainFunctionTxIndirectionIdx)
{
  IpduM_TxContainerPduIndStartIdxOfMainFunctionTxIndirectionType txContainerPduIndIdx = IpduM_GetTxContainerPduIndStartIdxOfMainFunctionTxIndirection(mainFunctionTxIndirectionIdx);
  IpduM_TxContainerPduIndEndIdxOfMainFunctionTxIndirectionType   txContainerPduIndEndIdx = IpduM_GetTxContainerPduIndEndIdxOfMainFunctionTxIndirection(mainFunctionTxIndirectionIdx);

  for(; txContainerPduIndIdx < txContainerPduIndEndIdx; txContainerPduIndIdx++)
  {
    IpduM_CTxContainerPduIterType txContainerId = IpduM_GetTxContainerPduInd(txContainerPduIndIdx);

    SchM_Enter_IpduM_IPDUM_EXCLUSIVE_AREA_0();
    {
# if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
      if(IpduM_IsRequestQueuePrioIndirectionUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
      {
        IpduM_ContainerTx_RequestQueueHandling_MainFunction(txContainerId);
      }
# endif
# if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
      if(IpduM_IsDataQueueInfoUsedOfTxContainerPdu(txContainerId)) /* COV_IPDUM_VAR_DEPENDENT_SWITCH */
      {
        IpduM_ContainerTx_DataQueueHandling_MainFunction(txContainerId);
      }
# endif
    }
    SchM_Exit_IpduM_IPDUM_EXCLUSIVE_AREA_0();
  }
}
#endif

#if (IPDUM_DATAQUEUEINFOUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_DataQueueHandling_MainFunction()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_DataQueueHandling_MainFunction(IpduM_CTxContainerPduIterType txContainerId)
{
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
  if(IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId)) /* PRQA S 2842 */ /* MD_IpduM_2842 */
  {
    if(!IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty(txContainerId))
    {
      /* Informative Transmit for TriggerTx container. This will be executed even if a previous TxConfirmation is expected. */
      (void) IpduM_ContainerTx_TransmitEmptyPdu(txContainerId);
    }
  }
  else
# endif
  {
    Std_ReturnType transmitResult = E_OK;

    while(!IpduM_ContainerTx_DataQueue_IsFifoQueueEmpty(txContainerId) && (transmitResult == E_OK))
    {
      /* returns E_NOT_OK for transmission failure */
      transmitResult = IpduM_ContainerTx_DataQueueHandling_TransmitContainerPdu_DirectDP(txContainerId);
    }
  }

# if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
  if(IpduM_ContainerTx_SendTimeout_IsRunning(txContainerId))
  {
    boolean isSendTimeoutExpired = IpduM_ContainerTx_SendTimeout_MainFunction(txContainerId);

    if(isSendTimeoutExpired)
    {
      IpduM_ContainerTx_DataQueueHandling_TriggerTransmissionOfCurrContainerPdu(txContainerId, IpduM_IsDirectDataProvisionOfTxContainerPdu(txContainerId));
    }
  }
# endif
}
#endif

#if (IPDUM_REQUESTQUEUEPRIOINDIRECTIONUSEDOFTXCONTAINERPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_RequestQueueHandling_MainFunction()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
IPDUM_LOCAL_INLINE FUNC(void, IPDUM_CODE) IpduM_ContainerTx_RequestQueueHandling_MainFunction(IpduM_CTxContainerPduIterType txContainerId)
{
# if (IPDUM_SENDTODEFOFTXCONTAINERPDU == STD_ON)
  if(IpduM_ContainerTx_SendTimeout_IsRunning(txContainerId))
  {
    boolean isSendTimeoutExpired = IpduM_ContainerTx_SendTimeout_MainFunction(txContainerId);

    if(isSendTimeoutExpired)
    {
      IpduM_ContainerTx_RequestQueueHandling_TriggerTransmission(txContainerId);
    }
  }
  else
# endif
  {
# if (IPDUM_TRIGGERTRANSMITOFTXCONTAINERPDU == STD_ON)
    if(IpduM_IsTriggerTransmitOfTxContainerPdu(txContainerId)) /* PRQA S 2842 */ /* MD_IpduM_2842 */
    {
      if(!IpduM_ContainerTx_RequestQueue_IsEmpty(txContainerId))
      {
        /* For TriggerTransmit Pdus only the oldest Pdu is transmitted. */
        IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_TriggerTxDP(txContainerId);
      }
    }
    else
# endif
    {
      Std_ReturnType transmitResult = E_OK;

      while(!IpduM_ContainerTx_RequestQueue_IsEmpty(txContainerId) && (transmitResult == E_OK))
      {
        /* returns E_NOT_OK for empty queue and transmission failure */
        transmitResult = IpduM_ContainerTx_RequestQueueHandling_TransmitContainer_DirectDP(txContainerId);
      }
    }
  }
}
#endif

#if(IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_MainFunction()
*******************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, IPDUM_CODE) IpduM_ContainerRx_MainFunction(IpduM_MainFunctionRxIndirectionIterType mainFunctionRxIndirectionIdx)
{
  IpduM_RxContainerPduIndStartIdxOfMainFunctionRxIndirectionType rxContainerPduIndIdx = IpduM_GetRxContainerPduIndStartIdxOfMainFunctionRxIndirection(mainFunctionRxIndirectionIdx);
  IpduM_RxContainerPduIndEndIdxOfMainFunctionRxIndirectionType   rxContainerPduIndEndIdx = IpduM_GetRxContainerPduIndEndIdxOfMainFunctionRxIndirection(mainFunctionRxIndirectionIdx);

  for(; rxContainerPduIndIdx < rxContainerPduIndEndIdx; rxContainerPduIndIdx++)
  {
    IpduM_RxContainerPduIterType rxContainerId = IpduM_GetRxContainerPduInd(rxContainerPduIndIdx);

    if(IpduM_IsContainerRxQueueInfoUsedOfRxContainerPdu(rxContainerId))
    {
      IpduM_ContainerRxQueueInfoIdxOfRxContainerPduType containerRxQueueInfoIdx = IpduM_GetContainerRxQueueInfoIdxOfRxContainerPdu(rxContainerId);

      IpduM_ContainerRxQueueInstanceLengthOfContainerRxQueueInfoType queueDepth = IpduM_GetContainerRxQueueInstanceLengthOfContainerRxQueueInfo(containerRxQueueInfoIdx);
      IpduM_ContainerRxQueueInstanceLengthOfContainerRxQueueInfoType readCounter = 0u;

      for(; readCounter < queueDepth; readCounter++)
      {
        IpduM_RxContainerMainFunctionBufferPtrType rxMfBuffer = IpduM_GetAddrRxContainerMainFunctionBuffer(IpduM_GetRxContainerMainFunctionBufferStartIdxOfContainerRxQueueInfo(containerRxQueueInfoIdx));
        PduLengthType pduLength = (PduLengthType) IpduM_GetRxContainerMainFunctionBufferLengthOfContainerRxQueueInfo(containerRxQueueInfoIdx);

        if(IpduM_ContainerRx_Queue_Get(rxContainerId, rxMfBuffer, &pduLength) == E_OK)    /* SBSW_IPDUM_MAINFUNCTIONRX_CALL_DEQUEUE_CONTAINER */
        {
          IpduM_ContainerRx_UnpackContainerPdu(rxContainerId, rxMfBuffer, pduLength);    /* SBSW_IPDUM_MAINFUNCTIONRX_CALL_UNPACKRXCONTAINERPDU */
        }
        else
        {/* No more pdus in the queue */
          break;
        }
      }
    }
  }
}
#endif

#define IPDUM_STOP_SEC_CODE
#include "IpduM_MemMap.h"    /* PRQA S 5087 */        /*  MD_MSR_MemMap */

/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* *INDENT-OFF* */
/* module specific MISRA deviations:

   MD_IpduM_2842: Index Access to pointer array
     Reason:      QAC cannot determine whether the pointer value is correct. However, the ComStackLib generates
                  those values and if the indices used are correct, the pointers are, too. The indices are either
                  calculated using ComStackLib indirections, ComStackLib SizeOf() macros or passed on by a caller
                  of this function, hence being checked by the caller. So all indices used in these macros are
                  correct.
     Risk:        No risk.
     Prevention:  No prevention necessary.
   
   MD_IpduM_2982_initValue: Redundant assignment, value always modified.
     Reason:      This init value is used to ensure the pduInfo ptr is always containing a valid size.
     Risk:        No risk.
     Prevention:  No prevention necessary.
     
   MD_IpduM_2985: Misra Rule 2.2
     Reason:      The bit shift of 0 bits is because of maintainability and comprehensibility. Or the result depends on the configuration.
     Risk:        No risk, because only warning that the operation is redundant.
     Prevention:  No prevention necessary.
     
   MD_IpduM_2987: Misra Rule 2.2
     Reason:     False-Positive: Function has a side effect. QAC has a problem with the access over the CfgPtr in Postbuild-Loadable.
     Risk:       No risk.
     Prevention: No prevention necessary

   MD_IpduM_3205: Misra Rule 2.3
     Reason:      This type shall not be encapsulated as it introduces unnecessary dependencies between preprocessor switches.
     Risk:        No risk.
     Prevention:  No prevention necessary
*/

/* COV_JUSTIFICATION_BEGIN

  \ID COV_IPDUM_SINGLE_HEADERSIZE_CONFIG
    \ACCEPT TX
    \ACCEPT TF tf tx
    \ACCEPT TF tx tf
    \ACCEPT TX tx tx
    \ACCEPT XF xf xx
    \REASON Configurations with only one type of headersize needed to cover this.

  \ID COV_IPDUM_VAR_DEPENDENT_SWITCH
    \ACCEPT TX
    \ACCEPT TF tf tx
    \ACCEPT TF tx tf
    \ACCEPT TX tx tx
    \ACCEPT TX tf tf tf
    \ACCEPT TX tx tf tf
    \ACCEPT TF tx tf tf
    \ACCEPT TX tf tx tx
    \REASON The nested switch depends on a previous switch.
  
  \ID COV_IPDUM_NO_META_DATA
    \ACCEPT XF
    \REASON The configuration has no meta data. As meta data is only valid for short header, little endian PDUs, not all configurations have this.

  \ID COV_IPDUM_DEPENDENT_VALUES
    \ACCEPT TF tf tx tf
    \REASON Generated values depend on each other.

  \ID COV_IPDUM_TXCONF_ALWAYS_ZERO
    \ACCEPT XF
    \ACCEPT TX
    \ACCEPT TF tf tx tf
    \REASON A TxConfirmation Timeout of zero is a special value which is used for unused TxConfirmation Timeouts.

  \ID COV_IPDUM_DEFENSIVE_PROGRAMMING
    \ACCEPT TX
    \ACCEPT XF
    \ACCEPT TF tf tx
    \ACCEPT TX tx tx
    \REASON This condition is used because of safe programming, should never be false in production code.

  \ID COV_IPDUM_INVALID_CONFIGURATION
    \ACCEPT TX tf tf tx
    \ACCEPT TF tx tf
    \ACCEPT TX tx tx
    \REASON This condition (a && b || c) cannot be fully covered for c==false because the first condition (before the  "||") will alwas match false if c== false, so c is not evaluated in this case. Coverage of this code section would require an invalid configuration.
            If c is preprocessed out, the only valid configuration is a==true and b==true/false.

  \ID COV_IPDUM_REQUESTQUEUE_WITH_NONE_HEADER
    \ACCEPT TF tf tx
    \REASON Request queue (last is best) with none-header is not supported. None-headers internally are always using the data queue.

  \ID COV_IPDUM_SEARCH_HEADER_ID_LOOP_ABORT
    \ACCEPT TX
    \REASON This is a search function, normal termination of the loop would only occur if the searched item was not found.

  \ID COV_IPDUM_COMPLEMENTARY_CHECK
    \ACCEPT TF tf tx tf
    \REASON This condition (a || (!a && b)) cannot be fully covered for a==true because the first condition (before the "||") will always match, so the second (!a) is not evaluated.

  \ID COV_IPDUM_ALWAYS_TXCONFIRMATION
    \APPLYOVERRIDE
    \REASON Condition is always TRUE if there are only contained Pdus which all have a TxConfirmation.

  \ID COV_IPDUM_TERMINATION_ZEROES
    \ACCEPT TF tx tf
    \REASON Double condition in the loop for safe programming reasons

  \ID COV_IPDUM_HEADERSIZE_IN_SIZE_CALCULATION
    \ACCEPT TX tf tf
    \REASON This function is only used with non-zero headers, so in (a || b) always either a or b is true, so the composite condition can never go false.
    
  \ID COV_IPDUM_SWITCH_CASE_DEFAULT
    \ACCEPT X
    \REASON Misra forces the default case, but there are cases where it is not necessary.
COV_JUSTIFICATION_END */

/* *INDENT-ON* */

/**********************************************************************************************************************
  END OF FILE: IpduM_Container.c
**********************************************************************************************************************/
