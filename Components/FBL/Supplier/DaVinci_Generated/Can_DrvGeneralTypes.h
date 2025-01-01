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
 *            Module: Can
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_DrvGeneralTypes.h
 *   Generation Time: 2023-07-05 16:23:56
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined(CAN_DRVGENERALTYPES_H)
#define CAN_DRVGENERALTYPES_H

/* -----------------------------------------------------------------------------
    Types
 ----------------------------------------------------------------------------- */

/* CAN416, CAN065_Conf */
/* size of ID depend on used ID type like standard (16bit), extended (32bit) or mixed (32bit) */
/* in case of mixed ID type the highest bit is used to mark the ID as extended */
/* second highest bit is used as marker for CAN-FD message (extended: bit30, standard: bit14) */
typedef VAR(uint32, TYPEDEF) Can_IdType;

/* CAN429 */
typedef VAR(uint8, TYPEDEF) Can_HwHandleType;
typedef VAR(sint16, TYPEDEF) Can_SignedHwHandleType;

typedef P2VAR(uint8, TYPEDEF, CAN_APPL_VAR) Can_SduPtrType;

/* CAN415 */
typedef struct Can_PduTypeTag
{
  Can_IdType id;
  uint8 length;
  Can_SduPtrType sdu;
  PduIdType swPduHandle;
} Can_PduType;

/* CAN417 */
typedef enum {
  CAN_T_START = 0,
  CAN_T_STOP,
  CAN_T_SLEEP,
  CAN_T_WAKEUP
} Can_StateTransitionType;

typedef enum {
  CAN_CS_UNINIT = 0,
  CAN_CS_STARTED = 1,
  CAN_CS_STOPPED = 2,
  CAN_CS_SLEEP = 3
} Can_ControllerStateType;

typedef enum {
  CAN_ERRORSTATE_ACTIVE = 0,
  CAN_ERRORSTATE_PASSIVE,
  CAN_ERRORSTATE_BUSOFF
} Can_ErrorStateType;

/* CAN039 - for CBD compatibility OK is 1 - REQUESTED */
typedef enum {
  CAN_NOT_OK = 0,
  CAN_OK = 1,
  CAN_BUSY = 2,
  /* compatibility: */
  CAN_NOT_SUPPORTED = 3,
  CAN_REQUESTED = 4
} Can_ReturnType;
#define CAN_30_GLOBAL_DEFINES /* ESCAN00104925: deactivate local defines in <=R20 */
#define CAN_FREE CAN_OK

/* CAN496 */
typedef struct Can_HwTypeTag
{
  Can_IdType CanId;
  Can_HwHandleType Hoh;
  uint8 ControllerId;
} Can_HwType;

/* CAN496 - Error types */
typedef enum Can_ErrorTypeTag
{
  /* Tx Errors */
  CAN_ERROR_TYPE_NOT_AVAILABLE    = 0x0, 
  CAN_ERROR_BIT_MONITORING1       = 0x1,
  CAN_ERROR_BIT_MONITORING0       = 0x2,
  CAN_ERROR_BIT                   = 0x3,
  CAN_ERROR_CHECK_ACK_FAILED      = 0x4,
  CAN_ERROR_ACK_DELIMITER         = 0x5,
  CAN_ERROR_ARBITRATION_LOST      = 0x6,
  CAN_ERROR_OVERLOAD              = 0x7,
  /* Rx Errors */
  CAN_ERROR_CHECK_FORM_FAILED     = 0x8,
  CAN_ERROR_CHECK_STUFFING_FAILED = 0x9,
  CAN_ERROR_CHECK_CRC_FAILED      = 0xA,
  CAN_ERROR_BUS_LOCK              = 0xB
} Can_ErrorType;

#endif /* CAN_DRVGENERALTYPES_H */
 

