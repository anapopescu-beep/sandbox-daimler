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
 *            Module: CanTp
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.h
 *   Generation Time: 2023-08-03 15:01:27
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined(CANTP_LCFG_H)
#define CANTP_LCFG_H
/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "CanTp_Cfg.h"
#include "CanTp_Types.h"


/**********************************************************************************************************************
 *  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPCIterableTypes  CanTp Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanTp_CalcBS */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfCalcBS() } \endspec */ 
typedef uint8_least CanTp_CalcBSIterType;

/**   \brief  type used to iterate CanTp_RxChannelMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxChannelMap() } \endspec */ 
typedef uint8_least CanTp_RxChannelMapIterType;

/**   \brief  type used to iterate CanTp_RxPduMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxPduMap() } \endspec */ 
typedef uint8_least CanTp_RxPduMapIterType;

/**   \brief  type used to iterate CanTp_RxSduCfg */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfg() } \endspec */ 
typedef uint8_least CanTp_RxSduCfgIterType;

/**   \brief  type used to iterate CanTp_RxSduCfgInd */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfgInd() } \endspec */ 
typedef uint8_least CanTp_RxSduCfgIndIterType;

/**   \brief  type used to iterate CanTp_RxSduSnv2Hdl */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduSnv2Hdl() } \endspec */ 
typedef uint8_least CanTp_RxSduSnv2HdlIterType;

/**   \brief  type used to iterate CanTp_RxState */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxState() } \endspec */ 
typedef uint8_least CanTp_RxStateIterType;

/**   \brief  type used to iterate CanTp_TxChannelMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxChannelMap() } \endspec */ 
typedef uint8_least CanTp_TxChannelMapIterType;

/**   \brief  type used to iterate CanTp_TxSduCfg */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfg() } \endspec */ 
typedef uint8_least CanTp_TxSduCfgIterType;

/**   \brief  type used to iterate CanTp_TxSduCfgInd */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfgInd() } \endspec */ 
typedef uint8_least CanTp_TxSduCfgIndIterType;

/**   \brief  type used to iterate CanTp_TxSduSnv2Hdl */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduSnv2Hdl() } \endspec */ 
typedef uint8_least CanTp_TxSduSnv2HdlIterType;

/**   \brief  type used to iterate CanTp_TxSemaphores */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSemaphores() } \endspec */ 
typedef uint8_least CanTp_TxSemaphoresIterType;

/**   \brief  type used to iterate CanTp_TxState */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxState() } \endspec */ 
typedef uint8_least CanTp_TxStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCValueTypes  CanTp Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanTp_CalcBS */
typedef uint8 CanTp_CalcBSType;

/**   \brief  value based type definition for CanTp_CompatibilityVersion */
typedef uint32 CanTp_CompatibilityVersionType;

/**   \brief  value based type definition for CanTp_RxChannelMap */
typedef PduIdType CanTp_RxChannelMapType;

/**   \brief  value based type definition for CanTp_AddressingFormatOfRxPduMap */
typedef uint8 CanTp_AddressingFormatOfRxPduMapType;

/**   \brief  value based type definition for CanTp_GenericConnectionOfRxPduMap */
typedef boolean CanTp_GenericConnectionOfRxPduMapType;

/**   \brief  value based type definition for CanTp_PduMetadataLengthOfRxPduMap */
typedef uint8 CanTp_PduMetadataLengthOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxSduCfgIndEndIdxOfRxPduMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfgInd() } \endspec */ 
typedef uint8 CanTp_RxSduCfgIndEndIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxSduCfgIndStartIdxOfRxPduMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfgInd() } \endspec */ 
typedef uint8 CanTp_RxSduCfgIndStartIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_RxSduCfgIndUsedOfRxPduMap */
typedef boolean CanTp_RxSduCfgIndUsedOfRxPduMapType;

/**   \brief  value based type definition for CanTp_TxSduCfgIndEndIdxOfRxPduMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfgInd() } \endspec */ 
typedef uint8 CanTp_TxSduCfgIndEndIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_TxSduCfgIndStartIdxOfRxPduMap */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfgInd() } \endspec */ 
typedef uint8 CanTp_TxSduCfgIndStartIdxOfRxPduMapType;

/**   \brief  value based type definition for CanTp_TxSduCfgIndUsedOfRxPduMap */
typedef boolean CanTp_TxSduCfgIndUsedOfRxPduMapType;

/**   \brief  value based type definition for CanTp_BlockSizeOfRxSduCfg */
typedef uint8 CanTp_BlockSizeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_CanTypeOfRxSduCfg */
typedef uint8 CanTp_CanTypeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_ChannelModeOfRxSduCfg */
typedef uint8 CanTp_ChannelModeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_GenericConnectionOfRxSduCfg */
typedef boolean CanTp_GenericConnectionOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_LoLayerTxFcPduIdOfRxSduCfg */
typedef PduIdType CanTp_LoLayerTxFcPduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_NArOfRxSduCfg */
typedef uint8 CanTp_NArOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_NBrOfRxSduCfg */
typedef uint8 CanTp_NBrOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_NCrOfRxSduCfg */
typedef uint8 CanTp_NCrOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_PduMetadataLengthOfRxSduCfg */
typedef uint8 CanTp_PduMetadataLengthOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_PduRRxSduIdOfRxSduCfg */
typedef PduIdType CanTp_PduRRxSduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxAddressOfRxSduCfg */
typedef uint8 CanTp_RxAddressOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxAddressingFormatOfRxSduCfg */
typedef uint8 CanTp_RxAddressingFormatOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxMaxPayloadLengthOfRxSduCfg */
typedef uint8 CanTp_RxMaxPayloadLengthOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPaddingActivationOfRxSduCfg */
typedef boolean CanTp_RxPaddingActivationOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxPduIdOfRxSduCfg */
typedef PduIdType CanTp_RxPduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxTaTypeOfRxSduCfg */
typedef uint8 CanTp_RxTaTypeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxWftMaxOfRxSduCfg */
typedef uint8 CanTp_RxWftMaxOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_STminOfRxSduCfg */
typedef uint8 CanTp_STminOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_SduMetadataLengthOfRxSduCfg */
typedef uint8 CanTp_SduMetadataLengthOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxFcAddressOfRxSduCfg */
typedef uint8 CanTp_TxFcAddressOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxFcPduConfirmationPduIdOfRxSduCfg */
typedef PduIdType CanTp_TxFcPduConfirmationPduIdOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxSduCfgIdxOfRxSduCfg */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfg() } \endspec */ 
typedef uint8 CanTp_TxSduCfgIdxOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_TxSduCfgUsedOfRxSduCfg */
typedef boolean CanTp_TxSduCfgUsedOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_RxSduCfgInd */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfg() } \endspec */ 
typedef uint8 CanTp_RxSduCfgIndType;

/**   \brief  value based type definition for CanTp_RxSduCfgIdxOfRxSduSnv2Hdl */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfg() } \endspec */ 
typedef uint8 CanTp_RxSduCfgIdxOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_RxSduCfgUsedOfRxSduSnv2Hdl */
typedef boolean CanTp_RxSduCfgUsedOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_SizeOfCalcBS */
typedef uint8 CanTp_SizeOfCalcBSType;

/**   \brief  value based type definition for CanTp_SizeOfRxChannelMap */
typedef uint8 CanTp_SizeOfRxChannelMapType;

/**   \brief  value based type definition for CanTp_SizeOfRxPduMap */
typedef uint8 CanTp_SizeOfRxPduMapType;

/**   \brief  value based type definition for CanTp_SizeOfRxSduCfg */
typedef uint8 CanTp_SizeOfRxSduCfgType;

/**   \brief  value based type definition for CanTp_SizeOfRxSduCfgInd */
typedef uint8 CanTp_SizeOfRxSduCfgIndType;

/**   \brief  value based type definition for CanTp_SizeOfRxSduSnv2Hdl */
typedef uint8 CanTp_SizeOfRxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_SizeOfRxState */
typedef uint8 CanTp_SizeOfRxStateType;

/**   \brief  value based type definition for CanTp_SizeOfTxChannelMap */
typedef uint8 CanTp_SizeOfTxChannelMapType;

/**   \brief  value based type definition for CanTp_SizeOfTxSduCfg */
typedef uint8 CanTp_SizeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_SizeOfTxSduCfgInd */
typedef uint8 CanTp_SizeOfTxSduCfgIndType;

/**   \brief  value based type definition for CanTp_SizeOfTxSduSnv2Hdl */
typedef uint8 CanTp_SizeOfTxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_SizeOfTxSemaphores */
typedef uint8 CanTp_SizeOfTxSemaphoresType;

/**   \brief  value based type definition for CanTp_SizeOfTxState */
typedef uint8 CanTp_SizeOfTxStateType;

/**   \brief  value based type definition for CanTp_TxChannelMap */
typedef PduIdType CanTp_TxChannelMapType;

/**   \brief  value based type definition for CanTp_CanTypeOfTxSduCfg */
typedef uint8 CanTp_CanTypeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_ChannelModeOfTxSduCfg */
typedef uint8 CanTp_ChannelModeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_LoLayerTxPduIdOfTxSduCfg */
typedef PduIdType CanTp_LoLayerTxPduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_NAsOfTxSduCfg */
typedef uint8 CanTp_NAsOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_NBsOfTxSduCfg */
typedef uint8 CanTp_NBsOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_NCsOfTxSduCfg */
typedef uint8 CanTp_NCsOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_PduMetadataLengthOfTxSduCfg */
typedef uint8 CanTp_PduMetadataLengthOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_PduRTxSduIdOfTxSduCfg */
typedef PduIdType CanTp_PduRTxSduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxFcAddressOfTxSduCfg */
typedef uint8 CanTp_RxFcAddressOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxFcPduIdOfTxSduCfg */
typedef PduIdType CanTp_RxFcPduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxSduCfgIdxOfTxSduCfg */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfRxSduCfg() } \endspec */ 
typedef uint8 CanTp_RxSduCfgIdxOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_RxSduCfgUsedOfTxSduCfg */
typedef boolean CanTp_RxSduCfgUsedOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_SduMetadataLengthOfTxSduCfg */
typedef uint8 CanTp_SduMetadataLengthOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TransmitCancellationOfTxSduCfg */
typedef boolean CanTp_TransmitCancellationOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxAddressOfTxSduCfg */
typedef uint8 CanTp_TxAddressOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxAddressingFormatOfTxSduCfg */
typedef uint8 CanTp_TxAddressingFormatOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxMaxPayloadLengthOfTxSduCfg */
typedef uint8 CanTp_TxMaxPayloadLengthOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPaddingActivationOfTxSduCfg */
typedef boolean CanTp_TxPaddingActivationOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxPduConfirmationPduIdOfTxSduCfg */
typedef PduIdType CanTp_TxPduConfirmationPduIdOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxTaTypeOfTxSduCfg */
typedef uint8 CanTp_TxTaTypeOfTxSduCfgType;

/**   \brief  value based type definition for CanTp_TxSduCfgInd */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfg() } \endspec */ 
typedef uint8 CanTp_TxSduCfgIndType;

/**   \brief  value based type definition for CanTp_TxSduCfgIdxOfTxSduSnv2Hdl */
/*! \spec strong type invariant () { self < CanTp_GetSizeOfTxSduCfg() } \endspec */ 
typedef uint8 CanTp_TxSduCfgIdxOfTxSduSnv2HdlType;

/**   \brief  value based type definition for CanTp_TxSduCfgUsedOfTxSduSnv2Hdl */
typedef boolean CanTp_TxSduCfgUsedOfTxSduSnv2HdlType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanTpPCStructTypes  CanTp Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanTp_RxPduMap */
/*! 
 * \spec strong type invariant () { 
 *   (!CanTp_IsRxSduCfgIndUsedOfRxPduMap(0) || (self.RxSduCfgIndEndIdxOfRxPduMap < CanTp_GetSizeOfRxSduCfgInd())) &&
 *   (!CanTp_IsRxSduCfgIndUsedOfRxPduMap(0) || (self.RxSduCfgIndStartIdxOfRxPduMap < CanTp_GetSizeOfRxSduCfgInd())) &&
 *   (!(self.TxSduCfgIndStartIdxOfRxPduMap != CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP) || (self.TxSduCfgIndEndIdxOfRxPduMap < CanTp_GetSizeOfTxSduCfgInd())) &&
 *   (!(self.TxSduCfgIndStartIdxOfRxPduMap != CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP) || (self.TxSduCfgIndStartIdxOfRxPduMap < CanTp_GetSizeOfTxSduCfgInd()))
 * }
 * \endspec 
 */ 
typedef struct sCanTp_RxPduMapType
{
  CanTp_RxSduCfgIndEndIdxOfRxPduMapType RxSduCfgIndEndIdxOfRxPduMap;  /**< the end index of the 0:n relation pointing to CanTp_RxSduCfgInd */
  CanTp_RxSduCfgIndStartIdxOfRxPduMapType RxSduCfgIndStartIdxOfRxPduMap;  /**< the start index of the 0:n relation pointing to CanTp_RxSduCfgInd */
  CanTp_TxSduCfgIndEndIdxOfRxPduMapType TxSduCfgIndEndIdxOfRxPduMap;  /**< the end index of the 0:n relation pointing to CanTp_TxSduCfgInd */
  CanTp_TxSduCfgIndStartIdxOfRxPduMapType TxSduCfgIndStartIdxOfRxPduMap;  /**< the start index of the 0:n relation pointing to CanTp_TxSduCfgInd */
} CanTp_RxPduMapType;

/**   \brief  type used in CanTp_RxSduCfg */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.TxSduCfgIdxOfRxSduCfg != CANTP_NO_TXSDUCFGIDXOFRXSDUCFG) || (self.TxSduCfgIdxOfRxSduCfg < CanTp_GetSizeOfTxSduCfg()))
 * }
 * \endspec 
 */ 
typedef struct sCanTp_RxSduCfgType
{
  CanTp_LoLayerTxFcPduIdOfRxSduCfgType LoLayerTxFcPduIdOfRxSduCfg;
  CanTp_PduRRxSduIdOfRxSduCfgType PduRRxSduIdOfRxSduCfg;
  CanTp_RxPduIdOfRxSduCfgType RxPduIdOfRxSduCfg;
  CanTp_TxFcPduConfirmationPduIdOfRxSduCfgType TxFcPduConfirmationPduIdOfRxSduCfg;
  CanTp_BlockSizeOfRxSduCfgType BlockSizeOfRxSduCfg;
  CanTp_NArOfRxSduCfgType NArOfRxSduCfg;
  CanTp_NCrOfRxSduCfgType NCrOfRxSduCfg;
  CanTp_RxTaTypeOfRxSduCfgType RxTaTypeOfRxSduCfg;
  CanTp_RxWftMaxOfRxSduCfgType RxWftMaxOfRxSduCfg;
  CanTp_STminOfRxSduCfgType STminOfRxSduCfg;
  CanTp_TxSduCfgIdxOfRxSduCfgType TxSduCfgIdxOfRxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_TxSduCfg */
} CanTp_RxSduCfgType;

/**   \brief  type used in CanTp_RxSduSnv2Hdl */
/*! 
 * \spec strong type invariant () { 
 *   (!CanTp_IsRxSduCfgUsedOfRxSduSnv2Hdl(0) || (self.RxSduCfgIdxOfRxSduSnv2Hdl < CanTp_GetSizeOfRxSduCfg()))
 * }
 * \endspec 
 */ 
typedef struct sCanTp_RxSduSnv2HdlType
{
  CanTp_RxSduCfgIdxOfRxSduSnv2HdlType RxSduCfgIdxOfRxSduSnv2Hdl;  /**< the index of the 0:1 relation pointing to CanTp_RxSduCfg */
} CanTp_RxSduSnv2HdlType;

/**   \brief  type used in CanTp_TxSduCfg */
/*! 
 * \spec strong type invariant () { 
 *   (!CanTp_IsRxSduCfgUsedOfTxSduCfg(0) || (self.RxSduCfgIdxOfTxSduCfg < CanTp_GetSizeOfRxSduCfg()))
 * }
 * \endspec 
 */ 
typedef struct sCanTp_TxSduCfgType
{
  CanTp_LoLayerTxPduIdOfTxSduCfgType LoLayerTxPduIdOfTxSduCfg;
  CanTp_PduRTxSduIdOfTxSduCfgType PduRTxSduIdOfTxSduCfg;
  CanTp_RxFcPduIdOfTxSduCfgType RxFcPduIdOfTxSduCfg;
  CanTp_TxPduConfirmationPduIdOfTxSduCfgType TxPduConfirmationPduIdOfTxSduCfg;
  CanTp_RxSduCfgIdxOfTxSduCfgType RxSduCfgIdxOfTxSduCfg;  /**< the index of the 0:1 relation pointing to CanTp_RxSduCfg */
} CanTp_TxSduCfgType;

/**   \brief  type used in CanTp_TxSduSnv2Hdl */
/*! 
 * \spec strong type invariant () { 
 *   (!CanTp_IsTxSduCfgUsedOfTxSduSnv2Hdl(0) || (self.TxSduCfgIdxOfTxSduSnv2Hdl < CanTp_GetSizeOfTxSduCfg()))
 * }
 * \endspec 
 */ 
typedef struct sCanTp_TxSduSnv2HdlType
{
  CanTp_TxSduCfgIdxOfTxSduSnv2HdlType TxSduCfgIdxOfTxSduSnv2Hdl;  /**< the index of the 0:1 relation pointing to CanTp_TxSduCfg */
} CanTp_TxSduSnv2HdlType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCRootPointerTypes  CanTp Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to CanTp_CalcBS */
typedef P2VAR(CanTp_CalcBSType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_CalcBSPtrType;

/**   \brief  type used to point to CanTp_RxChannelMap */
typedef P2VAR(volatile CanTp_RxChannelMapType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_RxChannelMapPtrType;

/**   \brief  type used to point to CanTp_RxPduMap */
typedef P2CONST(CanTp_RxPduMapType, TYPEDEF, CANTP_CONST) CanTp_RxPduMapPtrType;

/**   \brief  type used to point to CanTp_RxSduCfg */
typedef P2CONST(CanTp_RxSduCfgType, TYPEDEF, CANTP_CONST) CanTp_RxSduCfgPtrType;

/**   \brief  type used to point to CanTp_RxSduCfgInd */
typedef P2CONST(CanTp_RxSduCfgIndType, TYPEDEF, CANTP_CONST) CanTp_RxSduCfgIndPtrType;

/**   \brief  type used to point to CanTp_RxSduSnv2Hdl */
typedef P2CONST(CanTp_RxSduSnv2HdlType, TYPEDEF, CANTP_CONST) CanTp_RxSduSnv2HdlPtrType;

/**   \brief  type used to point to CanTp_RxState */
typedef P2VAR(CanTp_RxStateType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_RxStatePtrType;

/**   \brief  type used to point to CanTp_TxChannelMap */
typedef P2VAR(volatile CanTp_TxChannelMapType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_TxChannelMapPtrType;

/**   \brief  type used to point to CanTp_TxSduCfg */
typedef P2CONST(CanTp_TxSduCfgType, TYPEDEF, CANTP_CONST) CanTp_TxSduCfgPtrType;

/**   \brief  type used to point to CanTp_TxSduCfgInd */
typedef P2CONST(CanTp_TxSduCfgIndType, TYPEDEF, CANTP_CONST) CanTp_TxSduCfgIndPtrType;

/**   \brief  type used to point to CanTp_TxSduSnv2Hdl */
typedef P2CONST(CanTp_TxSduSnv2HdlType, TYPEDEF, CANTP_CONST) CanTp_TxSduSnv2HdlPtrType;

/**   \brief  type used to point to CanTp_TxSemaphores */
typedef P2VAR(CanTp_TxSemaphoreType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_TxSemaphoresPtrType;

/**   \brief  type used to point to CanTp_TxState */
typedef P2VAR(CanTp_TxStateType, TYPEDEF, CANTP_VAR_NOINIT) CanTp_TxStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanTpPCRootValueTypes  CanTp Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanTp_PCConfig */
typedef struct sCanTp_PCConfigType
{
  CanTp_RxSduCfgPtrType RxSduCfgOfPCConfig;  /**< the pointer to CanTp_RxSduCfg */
  CanTp_TxSduCfgPtrType TxSduCfgOfPCConfig;  /**< the pointer to CanTp_TxSduCfg */
} CanTp_PCConfigType;

typedef CanTp_PCConfigType CanTp_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access CanTp_PCConfig in a symbol based style. */
typedef struct sCanTp_PCConfigsType
{
  CanTp_PCConfigType Config_Left;  /**< [Config_Left] */
  CanTp_PCConfigType Config_Right;  /**< [Config_Right] */
} CanTp_PCConfigsType;

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
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTp_RxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPduMap
  \details
  Element                Description
  RxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_RxSduCfgInd
  RxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_RxSduCfgInd
  TxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_TxSduCfgInd
  TxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_TxSduCfgInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[6];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgLeft
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgLeft
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  BlockSize               
  NAr                     
  NCr                     
  RxTaType                
  RxWftMax                
  STmin                   
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgLeft[6];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgRight
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgRight
  \details
  Element                     Description
  LoLayerTxFcPduId        
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  BlockSize               
  NAr                     
  NCr                     
  RxTaType                
  RxWftMax                
  STmin                   
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfgRight[6];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[6];
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduSnv2Hdl
  \details
  Element        Description
  RxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[6];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgLeft
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgLeft
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgLeft[3];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgRight
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgRight
  \details
  Element                   Description
  LoLayerTxPduId        
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfgRight[3];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduCfgIndType, CANTP_CONST) CanTp_TxSduCfgInd[3];
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduSnv2Hdl
  \details
  Element        Description
  TxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[3];
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_CalcBS
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[6];
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxChannelMap
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(CanTp_RxChannelMapType, CANTP_VAR_NOINIT) CanTp_RxChannelMap[6];
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_RxStateType, CANTP_VAR_NOINIT) CanTp_RxState[1];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxChannelMap
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(CanTp_TxChannelMapType, CANTP_VAR_NOINIT) CanTp_TxChannelMap[3];
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSemaphores
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[3];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(CanTp_TxStateType, CANTP_VAR_NOINIT) CanTp_TxState[1];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_PCConfig
**********************************************************************************************************************/
/** 
  \var    CanTp_PCConfig
  \details
  Element     Description
  RxSduCfg    the pointer to CanTp_RxSduCfg
  TxSduCfg    the pointer to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(CanTp_PCConfigsType, CANTP_CONST) CanTp_PCConfig;
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/* -----------------------------------------------------------------------------
    &&&~ Global data types and structures
 ----------------------------------------------------------------------------- */



#endif /* CANTP_LCFG_H */
