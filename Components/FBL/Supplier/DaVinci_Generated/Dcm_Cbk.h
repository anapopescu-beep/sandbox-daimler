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
 *              File: Dcm_Cbk.h
 *   Generation Time: 2023-07-05 16:23:56
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (DCM_CBK_H)
# define DCM_CBK_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Platform_Types.h"
# include "ComStack_Types.h"
# include "FblCw_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/




/**
 * \defgroup DcmHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtCAN_RQ_BODY3_ST3_ec0e6e12_Rx_2873db84 1u /**< [RBTM_FL] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_ExtEth_RQ_BODY3_ST3_75192bc2_Rx_5a27dd11 3u /**< [RBTM_FL] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FL_03_IntEth_RQ_BODY3_ST3_b50fdb38_Rx_6a163982 5u /**< [RBTM_FL] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtCAN_RQ_BODY3_ST3_f1557fc1_Rx_3b6533a8 1u /**< [RBTM_FR] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_ExtEth_RQ_BODY3_ST3_68423a11_Rx_510ebea9 3u /**< [RBTM_FR] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_RBTM_FR_03_IntEth_RQ_BODY3_ST3_a854caeb_Rx_536fd8c4 5u /**< [RBTM_FR] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtCAN_RQ_BODY3_ST3_18e7f235_Rx_2b322367 0u /**< [RBTM_FL, RBTM_FR] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_ExtEth_RQ_BODY3_ST3_81f0b7e5_Rx_d414628a 2u /**< [RBTM_FL, RBTM_FR] */
#define DcmConf_DcmDslProtocolRx_SDU_DIAG_GLOBAL_IntEth_RQ_BODY3_ST3_41e6471f_Rx_c0cc433b 4u /**< [RBTM_FL, RBTM_FR] */
/**\} */




/**
 * \defgroup DcmHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtCAN_RS_BODY3_ST3_b462d7d3_Tx_70f6d2b0 0u /**< [RBTM_FL] */
#define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_ExtEth_RS_BODY3_ST3_2d759203_Tx_2b590afc 1u /**< [RBTM_FL] */
#define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FL_03_IntEth_RS_BODY3_ST3_ed6362f9_Tx_3060e687 2u /**< [RBTM_FL] */
#define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtCAN_RS_BODY3_ST3_a939c600_Tx_82eb6958 0u /**< [RBTM_FR] */
#define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_ExtEth_RS_BODY3_ST3_302e83d0_Tx_afb57ffd 1u /**< [RBTM_FR] */
#define DcmConf_DcmDslProtocolTx_SDU_DIAG_RBTM_FR_03_IntEth_RS_BODY3_ST3_f038732a_Tx_f8a04d74 2u /**< [RBTM_FR] */
/**\} */

# if ( FBLCW_MODULE_COMM == STD_OFF )
/* ComM indications for DCM */
#  define Dcm_ComM_FullComModeEntered(a)
#  define Dcm_ComM_SilentComModeEntered(a)
#  define Dcm_ComM_NoComModeEntered(a)
# endif

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
# define FBLCW_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Dcm_StartOfReception
**********************************************************************************************************************/
/** \brief       The function call indicates the reception start of a segmented PDU.
    \param[in]   id             id of the TP DcmDslProtocolRx PDU.
    \param[in]   info           Pointer to a PduInfoType structure containing the payload data
    \param[in]   TpSduLength    length of the entire the TP SDU that will be received.
    \param[out]  bufferSizePtr  length of the available receive buffer in FblCw.\n
                                This parameter is used e.g. in CanTp to calculate the Block Size (BS).
    \return      a BufReq_ReturnType constant of ComStackTypes.h.
    \pre         The FblCw is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Dcm_StartOfReception calls for the same id.
    \note        The function is called by the PduR.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_StartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
  Dcm_CopyRxData
**********************************************************************************************************************/
/** \brief       This function is called to trigger the copy process of a segmented PDU.\n
                 The function can be called several times and\n
                 each call to this function copies parts of the received data.\n
    \param[in]   id             id of the TP DcmDslProtocolRx PDU.
    \param[in]   info           a PduInfoType pointing to the data to be copied in the FblCw data buffer.
    \param[out]  bufferSizePtr  available receive buffer after data has been copied.
    \return      a BufReq_ReturnType constant of ComStackTypes.h.      
    \pre         The FblCw is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Dcm_CopyRxData calls for the same id.
    \note        The function is called by the PduR.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_CopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) bufferSizePtr);

/**********************************************************************************************************************
  Dcm_TpRxIndication
**********************************************************************************************************************/
/** \brief       The function is called to indicate the complete receiption of a FblCw TP SDU
                 or to report an error that occurred during reception.
    \param[in]   id             id of the TP DcmDslProtocolRx PDU.
    \param[in]   result         a Std_ReturnType to indicate the result of the reception.
    \return      none
    \pre         The FblCw is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Dcm_TpRxIndication calls for the same id.
    \note        The function is called by the PduR.
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_TpRxIndication(PduIdType id, Std_ReturnType result);

/**********************************************************************************************************************
  Dcm_CopyTxData
**********************************************************************************************************************/
/** \brief       This function is called to request transmit data of a TP DcmDslProtocolTx PDU\n
                 The function can be called several times and\n
                 each call to this function copies the next part of the data to be transmitted.\n
    \param[in]   id             id of the TP DcmDslProtocolTx PDU.
    \param[in]   info           a PduInfoType pointing to the destination buffer.
    \param[in]   retry          NULL_PTR to indicate a successful copy process\n
                                or a RetryInfoType containing a TpDataStateType constant of ComStackTypes.h.
    \param       availableDataPtr   Indicates the remaining number of bytes that are available in the TX buffer.\n
                                availableDataPtr can be used by TP modules that support dynamic payload lengths\n
                                (e.g. Iso FrTp) to determine the size of the following CFs.
    \return      a BufReq_ReturnType constant of ComStackTypes.h.
    \pre         The FblCw is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Dcm_CopyTxData calls for the same id.
    \note        The function is called by the PduR.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, FBLCW_CODE) Dcm_CopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, FBLCW_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, FBLCW_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, FBLCW_APPL_DATA) availableDataPtr);

/**********************************************************************************************************************
  Dcm_TpTxConfirmation
**********************************************************************************************************************/
/** \brief       The function is called to confirm a successful transmission of a TP DcmDslProtocolTx PDU\n
                 or to report an error that occurred during transmission.
    \param[in]   id             id of the TP DcmDslProtocolTx PDU.
    \param[in]   result         a Std_ReturnType to indicate the result of the transmission.
    \return      none
    \pre         The FblCw is initialized and active.
    \context     This function can be called on interrupt and task level and has not to be interrupted by other\n
                 Dcm_TpTxConfirmation calls for the same id.
    \note        The function is called by the PduR.
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_TpTxConfirmation(PduIdType id, Std_ReturnType result);

# if ( FBLCW_MODULE_COMM == STD_ON )
/**********************************************************************************************************************
 *  Dcm_ComM_NoComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM call-back for entering no communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_NO_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_NoComModeEntered(NetworkHandleType channel);

/**********************************************************************************************************************
 *  Dcm_ComM_SilentComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM callback for entering silent communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_SILENT_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_SilentComModeEntered(NetworkHandleType channel);

/**********************************************************************************************************************
 *  Dcm_ComM_FullComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM callback for entering full communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_FULL_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_FullComModeEntered(NetworkHandleType channel);
# endif

# define FBLCW_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_19.1 */
/*lint -restore */

#endif  /* DCM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Dcm_Cbk.h
**********************************************************************************************************************/

