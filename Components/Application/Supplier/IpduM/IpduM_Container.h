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
 *         File:  IpduM_Container.h
 *      Project:  MICROSAR IpduM
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Microsar IPDU Multiplexer header file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#ifndef IPDUM_CONTAINER_H
# define IPDUM_CONTAINER_H

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "IpduM_Cfg.h"
# include "IpduM_Lcfg.h"
# include "IpduM_PBcfg.h"
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
# define IPDUM_START_SEC_CODE
# include "IpduM_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */

#if ((IPDUM_CCONTAINERRXQUEUEINFO == STD_ON) || (IPDUM_CTXCONTAINERPDU == STD_ON))
/*******************************************************************************************
*  IpduM_Container_Init()
*******************************************************************************************/
/*! \brief        Initializes container PDU related structures
 *  \details      Initializes all component variables related to container PDUs
 *  \pre          Interrupts are disabled
 *  \pre          Module is uninitialized
 *  \pre          IpduM_InitMemory has been called unless IpduM_ModuleInitialized is initialized by start-up code
 *  \context      TASK
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \trace        SPEC-2914519, SPEC-2914520, SPEC-2914521, SPEC-2068173
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_Container_Init(void);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_Transmit()
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
 *  \trace        SPEC-2068537, SPEC-6231909, SPEC-2068539, SPEC-2068543, SPEC-2068545, SPEC-2068549, SPEC-2068551, SPEC-2068552
*******************************************************************************************/
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_Transmit(IpduM_TxUpIndIdxOfTxUpInfoType txContainedId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if(IPDUM_TRIGGER_TRANSMIT_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_TriggerTransmit()
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
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_ContainerTx_TriggerTransmit(IpduM_TxContainerPduIdxOfCTxLoInfoType txContainerId, P2VAR(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if ((IPDUM_TX_CONFIRMATION_API == STD_ON && IPDUM_EXISTS_CONTAINER_PATHWAYTYPEOFCTXLOINFO == STD_ON))
/*******************************************************************************************
*  IpduM_ContainerTx_TxConf_TxConfirmation()
*******************************************************************************************/
/*! \brief        Indicates complete transmission of a PDU
 *  \details      -
 *  \param[in]    TxPduId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConf_TxConfirmation(PduIdType TxPduId);
#endif

#if (IPDUM_RXCONTAINERPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerRx_RxIndication()
*******************************************************************************************/
/*! \brief        Indicates complete reception of a PDU
 *  \details      -
 *  \param[in]    rxContainerId
 *  \param[out]   PduInfoPtr         Pointer to buffer containing PDU
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
 *  \trace        SPEC-2068566, SPEC-2068569, SPEC-2068570, SPEC-2068572, SPEC-2068576
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_ContainerRx_RxIndication(IpduM_RxPathwayIndIdxOfRxInfoType rxContainerId, P2CONST(PduInfoType, AUTOMATIC, IPDUM_APPL_DATA) PduInfoPtr);
#endif

#if (IPDUM_TXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerTx_MainFunction()
*******************************************************************************************/
/*! \brief        Performs actions not directly initiated by calls from the PduR.
 *  \details      -
 *  \param[in]    mainFunctionTxIndirectionIdx index to know the execution context of this mainfunction.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_ContainerTx_MainFunction(IpduM_MainFunctionTxIndirectionIterType mainFunctionTxIndirectionIdx);
#endif

#if (IPDUM_CCONTAINERRXQUEUEINFO == STD_ON)
/*******************************************************************************************
 *  IpduM_ContainerRx_MainFunction()
*******************************************************************************************/
/*! \brief        Performs actions not directly initiated by calls from the PduR.
 *  \details      -
 *  \param[in]    mainFunctionRxIndirectionIdx index to know the execution context of this mainfunction.
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE
 *  \synchronous  TRUE
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_ContainerRx_MainFunction(IpduM_MainFunctionRxIndirectionIterType mainFunctionRxIndirectionIdx);
#endif

#if (IPDUM_TXCONFIRMATIONOFTXCONTAINEDPDU == STD_ON)
/*******************************************************************************************
*  IpduM_ContainerTx_TxConfBuffer_Clear()
*******************************************************************************************/
/*! \brief        Resets the TxConfirmationBuffer of the container to its init values.
 *  \details      -
 *  \param[in]    txContainerId
 *  \pre          -
 *  \context      TASK|ISR
 *  \reentrant    TRUE for different handle IDs
 *  \synchronous  TRUE
*******************************************************************************************/
FUNC(void, IPDUM_CODE) IpduM_ContainerTx_TxConfBuffer_Clear(IpduM_CTxContainerPduIterType txContainerId);
#endif

# define IPDUM_STOP_SEC_CODE
# include "IpduM_MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */

#endif /* IPDUM_CONTAINER_H */

/**********************************************************************************************************************
 *  END OF FILE: IpduM_Container.h
 *********************************************************************************************************************/
