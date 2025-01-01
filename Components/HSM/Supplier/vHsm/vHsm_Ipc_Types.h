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
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Ipc_Types.h
 *        \brief  Vector Hardware Security Module Firmware (vHsm)
 *
 *      \details  Inter-processor communication between Host and Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_IPC_TYPES_H)
# define VHSM_IPC_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "vHsm_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE                     (4u)
# define VHSM_IPC_CHANNEL_READ_INDEX_MEMORY_SIZE                      (4u)

# define vHsm_Ipc_GetRxChannelMemoryOffset(channelId)                 (VHSM_IPC_PROTOCOL_INFO_MEMORY_SIZE) + VHSM_IPC_GLOBALINFO_MEMORY_SIZE+ \
                                                                      ((channelId) * (VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE + VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE))

# define vHsm_Ipc_GetTxChannelMemoryOffset(channelId)                 (vHsm_Ipc_GetRxChannelMemoryOffset(vHsm_GetChannelsOfIpc()) + \
                                                                      ((channelId) * (VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE + VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE)))

# define vHsm_Ipc_GetRxChannelWriteIndexOffset(channelId)             vHsm_Ipc_GetRxChannelMemoryOffset(channelId)

# define vHsm_Ipc_GetTxChannelWriteIndexOffset(channelId)             vHsm_Ipc_GetTxChannelMemoryOffset(channelId)

# define vHsm_Ipc_GetRxChannelReadIndexOffset(channelId)              (vHsm_Ipc_GetRxChannelMemoryOffset(channelId) + VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE)

# define vHsm_Ipc_GetTxChannelReadIndexOffset(channelId)              (vHsm_Ipc_GetTxChannelMemoryOffset(channelId) + VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE)

# define vHsm_Ipc_GetRxChannelBufferOffset(channelId)                 (vHsm_Ipc_GetRxChannelMemoryOffset(channelId) + VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE)

# define vHsm_Ipc_GetTxChannelBufferOffset(channelId)                 (vHsm_Ipc_GetTxChannelMemoryOffset(channelId) + VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE)

# define vHsm_Ipc_GetGlobalInfoOffset()                               VHSM_IPC_PROTOCOL_INFO_MEMORY_SIZE

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct vHsm_Ipc_Channel_MemoryLayoutTypeStruct
{
  uint32 writeIdxOffset;    /* Shared memory offset to buffer reserved for write index
                            * (value equals index of next free entry) of channel. */

  uint32 readIdxOffset;     /* Shared memory offset to buffer reserved for read index
                            * (value equals index of next pending entry) of channel. */

  uint32 bufferOffset;      /* Shared memory offset to buffer reserved for all channel entries. */
} vHsm_Ipc_Channel_MemoryLayoutType;

typedef struct vHsm_Ipc_MemoryLayoutTypeStruct
{
  /* Describes the memory layout of the protocol information */
  uint32 protocolInfoOffset;

  /* Describes the memory layout of all RX channels. */
  vHsm_Ipc_Channel_MemoryLayoutType rxChannelMemoryLayout[vHsm_GetChannelsOfIpc()];

  /* Describes the memory layout of all TX channels. */
  vHsm_Ipc_Channel_MemoryLayoutType txChannelMemoryLayout[vHsm_GetChannelsOfIpc()];

  /* Shared memory offsets to buffers reserved for vHSM stack protection canary PE1/PE2. */
  uint32 stackProtectionCanaryPE1Offset;
  uint32 stackProtectionCanaryPE2Offset;

  /* Shared memory offset to buffer reserved for vHSM random seed. */
  uint32 seedOffset;

  /* Shared memory offsets to buffers reserved for vHSM development error detection (DET). */
  uint32 detModuleIdOffset;
  uint32 detInstanceIdOffset;
  uint32 detApiIdOffset;
  uint32 detErrorIdOffset;

  /* Shared memory offset to buffer reserved for vHSM Ready flag. */
  uint32 readyFlagOffset;

  /* Shared memory offset to buffer reserved for vHSM End-RAM-Execution flag. */
  uint32 endRamExecFlagOffset;

  /* Shared memory offset to buffer reserved for vHSM Is-RAM-Execution flag. */
  uint32 ramExecFlagOffset;

  /* Shared memory offset to buffer reserved for vHSM Det-Report flag. */
  uint32 detReportFlagOffset;

} vHsm_Ipc_MemoryLayoutType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* VHSM_IPC_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Ipc_Types.h
 *********************************************************************************************************************/
