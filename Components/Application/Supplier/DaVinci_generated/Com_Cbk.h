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
 *            Module: Com
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cbk.h
 *   Generation Time: 2023-07-10 14:36:08
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (COM_CBK_H)
# define COM_CBK_H

/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "Com_Cot.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/



/**
 * \defgroup ComHandleIdsComRxPdu Handle IDs of handle space ComRxPdu.
 * \brief Rx Pdus
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_BeltAdj_FL_Stat_ST3_d2ce0dbb_Rx               29u     /**< [Right] */
#define ComConf_ComIPdu_BeltAdj_FR_Stat_ST3_eba9bce0_Rx               29u     /**< [Left] */
#define ComConf_ComIPdu_BeltHdOvr_FL_State_ST3_342163b7_Rx            30u     /**< [Left] */
#define ComConf_ComIPdu_BeltHdOvr_FR_State_ST3_c8a18c7a_Rx            30u     /**< [Right] */
#define ComConf_ComIPdu_Develop8_Rq_RBTM_FL_ST3_fa67f89a_Rx           31u     /**< [Left] */
#define ComConf_ComIPdu_Develop8_Rq_RBTM_FR_ST3_25b7d179_Rx           31u     /**< [Right] */
#define ComConf_ComIPdu_RBTM_FL_Stat_ST3_dd2436a1_Rx                  32u     /**< [Right] */
#define ComConf_ComIPdu_RBTM_FR_Stat_ST3_e44387fa_Rx                  32u     /**< [Left] */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_ADAS_POSITION_ST3_0b61d436_Rx                 0u      /**< [Left, Right] */
#define ComConf_ComIPdu_ADAS_PREDICTION_ST3_6_262b63d1_Rx             1u      /**< [Left, Right] */
#define ComConf_ComIPdu_ADAS_PREDICTION_ST3_7_512c5347_Rx             2u      /**< [Left, Right] */
#define ComConf_ComIPdu_ADAS_PROFILE_SHORT_ST3_1_506b5dfc_Rx          3u      /**< [Left, Right] */
#define ComConf_ComIPdu_ADAS_PROFILE_SHORT_ST3_31_05b1585f_Rx         4u      /**< [Left, Right] */
#define ComConf_ComIPdu_Bckl_Sw_Fx_Stat_ST3_9c2de10c_Rx               5u      /**< [Left, Right] */
#define ComConf_ComIPdu_BeltAdj_UI_Set_Rq_ST3_1223a83d_Rx             6u      /**< [Left, Right] */
#define ComConf_ComIPdu_CLkS_Dr_State_ST3_513e9c19_Rx                 7u      /**< [Left, Right] */
#define ComConf_ComIPdu_ComIPduPnc_EIRA_CAN_Rx                        8u      /**< [Left, Right] */
#define ComConf_ComIPdu_DIAG_Stat_ST3_3a031d4a_Rx                     9u      /**< [Left, Right] */
#define ComConf_ComIPdu_DI_OdoSpeedometer_ST3_6fef7507_Rx             10u     /**< [Left, Right] */
#define ComConf_ComIPdu_DPC_Md_Rq_ESP_d1_ST3_e30f951d_Rx              11u     /**< [Left, Right] */
#define ComConf_ComIPdu_ELC_Lvr_Stat_ST3_d97bab99_Rx                  12u     /**< [Left, Right] */
#define ComConf_ComIPdu_EVC_CfgList_01_08_Pr5_ST3_32c5e6fb_Rx         13u     /**< [Left, Right] */
#define ComConf_ComIPdu_Ign_Stat_ST3_1e3dc39f_Rx                      14u     /**< [Left, Right] */
#define ComConf_ComIPdu_Impact2_ST3_e5526ccc_Rx                       15u     /**< [Left, Right] */
#define ComConf_ComIPdu_Impact3_ST3_d832457c_Rx                       16u     /**< [Left, Right] */
#define ComConf_ComIPdu_NTG_Master_Navi_ST3_dea580a6_Rx               17u     /**< [Left, Right] */
#define ComConf_ComIPdu_PN14_Master_Stat1_ST3_eba3e383_Rx             18u     /**< [Left, Right] */
#define ComConf_ComIPdu_PT4_PTCoor4_ST3_bf069154_Rx                   19u     /**< [Left, Right] */
#define ComConf_ComIPdu_PT4_PTCoor9_d1_BC_F_ST3_da786b84_Rx           20u     /**< [Left, Right] */
#define ComConf_ComIPdu_PT4_PTCoor_DrvPosn_Gear_ST3_6b508375_Rx       21u     /**< [Left, Right] */
#define ComConf_ComIPdu_PresfAct_Adj_ST3_61c58c91_Rx                  22u     /**< [Left, Right] */
#define ComConf_ComIPdu_SBeltTens_SP_Lvl_ST3_46421e11_Rx              23u     /**< [Left, Right] */
#define ComConf_ComIPdu_VSS_TP_Auth_ST3_7c9f23ce_Rx                   24u     /**< [Left, Right] */
#define ComConf_ComIPdu_VSS_TP_RealTmOffset_ST3_62955a84_Rx           25u     /**< [Left, Right] */
#define ComConf_ComIPdu_VSS_TP_SecTickCount_Lvl2_ST3_4917056b_Rx      26u     /**< [Left, Right] */
#define ComConf_ComIPdu_VSS_TP_SharedSecret_ST3_605b0fee_Rx           27u     /**< [Left, Right] */
#define ComConf_ComIPdu_VSS_TP_VIN_ST3_8e87972a_Rx                    28u     /**< [Left, Right] */
/**\} */

/**
 * \defgroup ComHandleIdsComTxPdu Handle IDs of handle space ComTxPdu.
 * \brief Tx Pdus
 * \{
 */

/* Handle IDs active in a single predefined variant */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPdu_BeltAdj_FL_Stat_ST3_d2ce0dbb_Tx               0u      /**< [Left] */
#define ComConf_ComIPdu_BeltAdj_FR_Stat_ST3_eba9bce0_Tx               0u      /**< [Right] */
#define ComConf_ComIPdu_Develop8_Rs_RBTM_FL_ST3_9a3b4dd1_Tx           1u      /**< [Left] */
#define ComConf_ComIPdu_Develop8_Rs_RBTM_FR_ST3_45eb6432_Tx           1u      /**< [Right] */
#define ComConf_ComIPdu_ECU_Stat_RBTM_FL_ST3_f703b6eb_Tx              2u      /**< [Left] */
#define ComConf_ComIPdu_ECU_Stat_RBTM_FR_ST3_28d39f08_Tx              2u      /**< [Right] */
#define ComConf_ComIPdu_Meas8_RBTM_FL_ST3_a92f14da_Tx                 3u      /**< [Left] */
#define ComConf_ComIPdu_Meas8_RBTM_FR_ST3_76ff3d39_Tx                 3u      /**< [Right] */
#define ComConf_ComIPdu_NM_RBTM_FL_ST3_0cdf2d0f_Tx                    4u      /**< [Left] */
#define ComConf_ComIPdu_NM_RBTM_FR_ST3_d30f04ec_Tx                    4u      /**< [Right] */
#define ComConf_ComIPdu_RBTM_FL_Stat_ST3_dd2436a1_Tx                  5u      /**< [Left] */
#define ComConf_ComIPdu_RBTM_FL_Tens_ST3_553ec607_Tx                  6u      /**< [Left] */
#define ComConf_ComIPdu_RBTM_FR_Stat_ST3_e44387fa_Tx                  5u      /**< [Right] */
#define ComConf_ComIPdu_RBTM_FR_Tens_ST3_6c59775c_Tx                  6u      /**< [Right] */
#define ComConf_ComIPdu_ROE_RBTM_FL_ST3_a66ccb5f_Tx                   7u      /**< [Left] */
#define ComConf_ComIPdu_ROE_RBTM_FR_ST3_79bce2bc_Tx                   7u      /**< [Right] */
/**\} */

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
#define COM_START_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /*MD_MSR_MemMap */
/**********************************************************************************************************************
  Com_RxIndication
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after an I-PDU has been received.
    \param[in]    RxPduId      ID of AUTOSAR COM I-PDU that has been received. Identifies the data that has been received.
                               Range: 0..(maximum number of I-PDU IDs received by AUTOSAR COM) - 1
    \param[in]    PduInfoPtr   Payload information of the received I-PDU (pointer to data and data length).
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737026
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr);

/**********************************************************************************************************************
  Com_TxConfirmation
**********************************************************************************************************************/
/** \brief        This function is called by the lower layer after the PDU has been transmitted on the network.
                  A confirmation that is received for an I-PDU that does not require a confirmation is silently discarded.
    \param[in]    TxPduId   ID of AUTOSAR COM I-PDU that has been transmitted.
                            Range: 0..(maximum number of I-PDU IDs transmitted by AUTOSAR COM) - 1
    \return       none
    \context      The function can be called on interrupt and task level. It is not allowed to use CAT1 interrupts with Rte (BSW00326]). Due to this, the interrupt context shall be configured to a CAT2 interrupt if an Rte is used.
    \synchronous  TRUE
    \reentrant    TRUE, for different Handles
    \trace        SPEC-2737028
    \note         The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType TxPduId);

/**********************************************************************************************************************
  Com_TriggerTransmit
**********************************************************************************************************************/
/** \brief          This function is called by the lower layer when an AUTOSAR COM I-PDU shall be transmitted.
                    Within this function, AUTOSAR COM shall copy the contents of its I-PDU transmit buffer
                    to the L-PDU buffer given by SduPtr.
                    Use case:
                    This function is used e.g. by the LIN Master for sending out a LIN frame. In this case, the trigger transmit
                    can be initiated by the Master schedule table itself or a received LIN header.
                    This function is also used by the FlexRay Interface for requesting PDUs to be sent in static part
                    (synchronous to the FlexRay global time). Once the I-PDU has been successfully sent by the lower layer
                    (PDU-Router), the lower layer must call Com_TxConfirmation().
    \param[in]      TxPduId       ID of AUTOSAR COM I-PDU that is requested to be transmitted by AUTOSAR COM.
    \param[in,out]  PduInfoPtr    Contains a pointer to a buffer (SduDataPtr) where the SDU
                                  data shall be copied to, and the available buffer size in SduLengh.
                                  On return, the service will indicate the length of the copied SDU
                                  data in SduLength.
    \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
    \return         E_NOT_OK      No data has been copied, because
                                  Com is not initialized
                                  or TxPduId is not valid
                                  or PduInfoPtr is NULL_PTR
                                  or SduDataPtr is NULL_PTR
                                  or SduLength is too small.
    \context        TASK|ISR2
    \synchronous    TRUE
    \reentrant      TRUE, for different Handles
    \trace          SPEC-2737022, SPEC-2737023, SPEC-2737024
    \note           The function is called by the lower layer.
**********************************************************************************************************************/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_VAR) PduInfoPtr);


#define COM_STOP_SEC_CODE
#include "MemMap.h"    /* PRQA S 5087 1 */ /* MD_MSR_MemMap */

#endif  /* COM_CBK_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cbk.h
**********************************************************************************************************************/

