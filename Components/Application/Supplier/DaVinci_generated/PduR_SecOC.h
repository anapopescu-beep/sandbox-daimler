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
 *            Module: PduR
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_SecOC.h
 *   Generation Time: 2023-07-10 14:36:13
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (PDUR_SECOC_H)
# define PDUR_SECOC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Cfg.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* \trace SPEC-629 */

#define PDUR_START_SEC_CODE
# include "PduR_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PduR_SecOCRxIndication
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the SecOC to indicate the complete reception of a SecOC I-PDU.\n
 *           The PDU Router evaluates the SecOC I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \param    RxPduId           ID of the received SecOC I-PDU
 * \param    info        Payload information of the received I-PDU (pointer to data and data length)
 * \return   none
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_SecOCRxIndication calls for the same SecOCRxPduId.
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-674, SPEC-1096, SPEC-2020085
 * \note     The function is called by SecOC.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_SecOCRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

/* PduR_SecOCTxConfirmation API disabled due to disabled TxConfirmation in PduRBswModule settings. */







/**********************************************************************************************************************
 * PduR_SecOCTransmit
 *********************************************************************************************************************/
/*!
 * \brief    The function serves to request the transmission of an upper layer I-PDU.\n
 *           The PDU Router evaluates the SecOC I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to a lower IF module using the appropriate I-PDU handle of the destination layer.
 * \param    id                ID of the SecOC I-PDU to be transmitted
 * \param    info              Payload information of the I-PDU (pointer to data and data length)
 * \return   Std_ReturnType\n
 *           E_OK              The request was accepted by the PDU Router and by the destination layer.\n
 *           E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
 *                             or the SecOCTxPduId is not valid\n
 *                             or the SecOCTxPduId is not forwarded in this identity\n
 *                             or the info is not valid\n
 *                             or the request was not accepted by the destination layer.\n
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_SecOCTransmit calls for the same SecOCTxPduId.
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-679, SPEC-686, SPEC-1827, SPEC-1096, SPEC-2020085, SPEC-38411
 * \note     The function is called by SecOC.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_SecOCTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);






#define PDUR_STOP_SEC_CODE
# include "PduR_MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* PDUR_SECOC_H */


/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/*  module specific MISRA deviations:
    MD_PduR_3451_3449:   MISRA rule: 8.8
    Reason:         The global identifier has been declared in more than one file. the function declaration has to be in
                    the PduR_<Module>.h. Affected APIs are CancelReceive, CancelTransmit and ChangeParameter.
    Risk:           no risk.
    Prevention:     To avoid a duplicate declaration uns the BSW-Module "use-Tag" flag.
*/

/**********************************************************************************************************************
 * END OF FILE: PduR_SecOC.h
 *********************************************************************************************************************/

