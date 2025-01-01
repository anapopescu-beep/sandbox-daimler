/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*      \file   Crypto_30_vHsm_Ipc_Types.h
 *      \brief  Vector Hardware Security Module Firmware Ipc Types
 *
 *      \details  Declares data structures required for interaction with Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_VHSM_IPC_TYPES_H)
# define CRYPTO_30_VHSM_IPC_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Crypto_30_vHsm_Ipc.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define Crypto_30_vHsm_Ipc_GetTxChannelMemoryOffset(txChannelId)    CRYPTO_30_VHSM_IPC_PROTOCOL_INFO_SIZE + CRYPTO_30_VHSM_IPC_GLOBALINFO_MEMORY_SIZE + \
                                                                      ((txChannelId) * (CRYPTO_30_VHSM_IPC_TX_CHANNEL_MEMORY_SIZE)) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetRxChannelMemoryOffset(rxChannelId)     (Crypto_30_vHsm_Ipc_GetTxChannelMemoryOffset(Crypto_30_vHsm_GetIpcChannelsOfvHsm()) + \
                                                                      ((rxChannelId) * (CRYPTO_30_VHSM_IPC_RX_CHANNEL_MEMORY_SIZE))) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetTxChannelWriteIndexOffset(txChannelId) Crypto_30_vHsm_Ipc_GetTxChannelMemoryOffset(txChannelId) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetRxChannelWriteIndexOffset(rxChannelId) Crypto_30_vHsm_Ipc_GetRxChannelMemoryOffset(rxChannelId) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetTxChannelReadIndexOffset(txChannelId)  (Crypto_30_vHsm_Ipc_GetTxChannelMemoryOffset(txChannelId) + CRYPTO_30_VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetRxChannelReadIndexOffset(rxChannelId)  (Crypto_30_vHsm_Ipc_GetRxChannelMemoryOffset(rxChannelId) + CRYPTO_30_VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetTxChannelBufferOffset(txChannelId)     (Crypto_30_vHsm_Ipc_GetTxChannelMemoryOffset(txChannelId) + CRYPTO_30_VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetRxChannelBufferOffset(rxChannelId)     (Crypto_30_vHsm_Ipc_GetRxChannelMemoryOffset(rxChannelId) + CRYPTO_30_VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE) /* PRQA S 3453 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */

# define Crypto_30_vHsm_Ipc_GetGlobalInfoOffset()                    CRYPTO_30_VHSM_IPC_PROTOCOL_INFO_SIZE

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#endif /* CRYPTO_30_VHSM_IPC_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Ipc_Types.h
 *********************************************************************************************************************/
