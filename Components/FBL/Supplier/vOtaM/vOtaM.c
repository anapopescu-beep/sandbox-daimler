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
/**        \file  vOtaM.c
 *         \brief  Bootloader OTA Manger source file
 *         \details  Main source file containing all public API implementations
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

#define VOTAM_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "fbl_inc.h"
#include "vOtaM.h"
#include "vOtaM_Appl.h"
#if defined( FBL_DIAG_ENABLE_SAFE_SWAP )
# include "vOtaMSafeSwap_ProgramFlow.h"
#endif /* FBL_DIAG_ENABLE_SAFE_SWAP */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Vendor specific version information is BCD coded */
#if ((VSOTAM_SW_MAJOR_VERSION != (0x03)) || (VSOTAM_SW_MINOR_VERSION != (0x09)) || (VSOTAM_SW_PATCH_VERSION != (0x01)))
# error "Vendor specific version numbers of vOtaM.c and vOtaM.h are inconsistent"
#endif

/* Check versions of all included header files */
#if ((VOTAM_CFG_MAJOR_VERSION != (0x01)) || (VOTAM_CFG_MINOR_VERSION != (0x05)))
# error "Version numbers of vOtaM.c and vOtaM_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/* Number of partitions for extended use case (A,B,Backup) */
#define VOTAM_NUMBER_PARTITIONS_EXTENDED        3u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/* Since the bootloader API works with the old MIO interface, we have to set the address area globally.
 * Therefore we must remember the current address area before working with another address area
 * to be able to restore it. */

#define VOTAM_SWITCH_ADDRESS_AREA(id)                                      \
      {                                                                    \
         backupAddrArea = MemDriver_GetAddressArea();                      \
         MemDriver_SetAddressArea(vOtaM_GetAddrAreaIdOfPartition((id)));   \
      }

#define VOTAM_RESTORE_ADDRESS_AREA()                                       \
      {                                                                    \
         MemDriver_SetAddressArea(backupAddrArea);                         \
      }

#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
/* Macros to set vMemAccM variant */
# define VOTAM_SET_VARIANT(v)                \
   {                                         \
      (void)vMemAccM_SetActiveVariant(v);    \
      activeVariantCurrent = (v);                  \
   }

/* Macros to set the variant configuration to the currently active/inactive variant */
# define VOTAM_SET_INACTIVE_VARIANT()     VOTAM_SET_VARIANT((activeVariantStartup == VMEMACCM_VARIANT_ID_STARTUP) ? VMEMACCM_VARIANT_ID_ALTERNATE : VMEMACCM_VARIANT_ID_STARTUP)
# define VOTAM_SET_ACTIVE_VARIANT()       VOTAM_SET_VARIANT(activeVariantStartup)

/* Macros to set the variant according to the selected swap source/destination partition */
# define VOTAM_SET_SWAP_SOURCE_VARIANT()  VOTAM_SET_VARIANT(vOtaMSwapSourcePartition->Variant)
# define VOTAM_SET_SWAP_DEST_VARIANT()    VOTAM_SET_VARIANT(vOtaMSwapDestPartition->Variant)

/* vOtaM_PartitionInfo is only showing the meta data of currently active variant */
# define vOtaM_PartitionInfo              vOtaM_PartInfo[activeVariantCurrent]
#else
/* Only one variant, macros not needed */
# define VOTAM_SET_VARIANT(v)
# define VOTAM_SET_INACTIVE_VARIANT()
# define VOTAM_SET_ACTIVE_VARIANT()
# define VOTAM_SET_SWAP_SOURCE_VARIANT()
# define VOTAM_SET_SWAP_DEST_VARIANT()
# define vOtaM_PartitionInfo              vOtaM_PartInfo[VMEMACCM_VARIANT_ID_STARTUP]
#endif

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/* Type for buffer used during sync */
typedef struct
{
   uint32 alignDummy;
   uint8 bufferData[vOtaM_GetCopyBufferSize()];
} vOtaM_CopyBufferType;

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define VOTAM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VOTAM_LOCAL VAR(vOtaM_PartitionInfoType, VOTAM_APPL_VAR)       vOtaM_PartInfo[VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS][VOTAM_PARTITION_COUNT];
#define VOTAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VOTAM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VOTAM_LOCAL VAR(vOtaM_StateType, VOTAM_VAR_NOINIT)             vOtaMState;
#if defined( VOTAM_ENABLE_SYNC_PARTITION )
VOTAM_LOCAL VAR(boolean, VOTAM_VAR_NOINIT)                     vOtaMCopyRevision;
#endif /* VOTAM_ENABLE_SYNC_PARTITION */
VOTAM_LOCAL P2VAR(vOtaM_PartitionInfoType, AUTOMATIC, VOTAM_VAR_NOINIT)    vOtaMSwapSourcePartition;
VOTAM_LOCAL P2VAR(vOtaM_PartitionInfoType, AUTOMATIC, VOTAM_VAR_NOINIT)    vOtaMSwapDestPartition; /* PRQA S 3678 */ /* MD_FblvOtaM_3678 */
VOTAM_LOCAL VAR(vMemAccM_AddressAreaIdType, VOTAM_VAR_NOINIT)  backupAddrArea;
#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
VOTAM_LOCAL VAR(vMemAccM_VariantIdType, VOTAM_VAR_NOINIT)      activeVariantStartup;   /**< Active variant, determined by user, constant after startup */
VOTAM_LOCAL VAR(vMemAccM_VariantIdType, VOTAM_VAR_NOINIT)      activeVariantCurrent;   /**< Currently active variant, changes during program execution */
#endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */
#define VOTAM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define VOTAM_START_SEC_COPY_BUFFER_VAR_NOINIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VOTAM_LOCAL VAR(vOtaM_CopyBufferType, VOTAM_VAR_NOINIT)        vOtaMCopyBuffer; /* PRQA S 3218 */ /* MD_FblvOtaM_3218 */
#define VOTAM_STOP_SEC_COPY_BUFFER_VAR_NOINIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( VOTAM_ENABLE_READ_PROCESSING )
# define VOTAM_START_SEC_PROC_BUFFER_VAR_NOINIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VOTAM_LOCAL VAR(vOtaM_CopyBufferType, VOTAM_VAR_NOINIT)        vOtaMProcBuffer; /* PRQA S 3218 */ /* MD_FblvOtaM_3218 */
# define VOTAM_STOP_SEC_PROC_BUFFER_VAR_NOINIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* VOTAM_ENABLE_READ_PROCESSING */

#define VOTAM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vOtaM_GetPartitionById
 *********************************************************************************************************************/
/*! \brief          Returns the partition based on the given ID.
 *  \param[in]      partitionId ID of the partition.
 *  \return         Pointer to the partition of the provided ID.
 *  \pre            vOtaM_Init was called
 *********************************************************************************************************************/
static P2VAR(vOtaM_PartitionInfoType, AUTOMATIC, AUTOMATIC) vOtaM_GetPartitionById(vOtaM_PartitionIdType partitionId);

#if defined( VOTAM_USECASE_EXTENDED )
/**********************************************************************************************************************
 *  vOtaM_Rollback
 *********************************************************************************************************************/
/*! \brief          Executes roll back to previous revision if possible
 *  \details        Function checks if backup partition is usable and executes roll back
 *  \return         E_OK      Roll back was successful
 *  \return         E_NOT_OK  Error during processing
 *  \pre            Only called if swap has failed. If application has requested a roll back, this is
 *                  treated like a swap request
 *********************************************************************************************************************/
static Std_ReturnType vOtaM_Rollback(void);
#endif /* VOTAM_USECASE_EXTENDED */

#if defined( VOTAM_ENABLE_SYNC_PARTITION )
/**********************************************************************************************************************
 *  vOtaM_SyncModule()
 *********************************************************************************************************************/
/*! \brief       Synchronize the given module.
 *  \details     Replaces the instance of the given module in the destination partition, with the one from the
 *               source partition, when the revision is newer. (Handles copying, NV data and verification)
 *  \param[in]   Module               The source module which should be synchronized.
 *  \return      E_OK                 Synchronization of module successful.
 *  \return      E_NOT_OK             Synchronization of module failed.
 *  \pre         vOtaM must be in correct state. (E_NOT_OK, if not)
 *********************************************************************************************************************/
static Std_ReturnType vOtaM_SyncModule(const vOtaM_ModuleInfoType* module);
#endif /* VOTAM_ENABLE_SYNC_PARTITION */

#if defined( VOTAM_ENABLE_PROG_ATTEMPTS )
/**********************************************************************************************************************
 *  vOtaM_IncProgAttempts
 *********************************************************************************************************************/
/*! \brief          Increments the programming attempt counter
 *  \param[in]      partitionId   Partition id.
 *  \param[in]      moduleId      The module id.
 *  \return         E_OK      Operation successful
 *  \return         E_NOT_OK  Operation not successful
 *********************************************************************************************************************/
static Std_ReturnType vOtaM_IncProgAttempts(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);

# if defined( VOTAM_ENABLE_PROG_ATTEMPTS_CHECK )
/**********************************************************************************************************************
 *  vOtaM_CheckProgAttempts
 *********************************************************************************************************************/
/*! \brief          Checks if all programming attempt counters are sufficient for an update
 *  \param[in]      part      The partition to be checked.
 *  \return         E_OK      All programming attempt counters are sufficient
 *  \return         E_NOT_OK  At least one programming attempt counter is not sufficient
 *********************************************************************************************************************/
static Std_ReturnType vOtaM_CheckProgAttempts(const vOtaM_PartitionInfoType * part);
# endif /* VOTAM_ENABLE_PROG_ATTEMPTS_CHECK */
#endif /* VOTAM_ENABLE_PROG_ATTEMPTS */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  vOtaM_GetPartitionById
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
static P2VAR(vOtaM_PartitionInfoType, AUTOMATIC, AUTOMATIC) vOtaM_GetPartitionById(vOtaM_PartitionIdType partitionId)
{
   vOtaM_PartitionIterType partitionIdx;
   P2VAR(vOtaM_PartitionInfoType, AUTOMATIC, AUTOMATIC) partitionPtr = NULL_PTR;

   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if (vOtaM_PartitionInfo[partitionIdx].Id == partitionId)
      {
         partitionPtr = &vOtaM_PartitionInfo[partitionIdx];
      }
   }

   return partitionPtr;
}

#if defined( VOTAM_USECASE_EXTENDED )
/**********************************************************************************************************************
 * vOtaM_Rollback
 *********************************************************************************************************************/
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
static Std_ReturnType vOtaM_Rollback(void)
{
   Std_ReturnType             retVal = E_NOT_OK;
   vOtaM_PartitionIterType    partIdx;
   vOtaM_PartitionInfoType*   vOtaMOriginalSwapSourcePartition;

   /* #10 Check if roll back is possible */
   if (     (VOTAM_PARTITION_COUNT == VOTAM_NUMBER_PARTITIONS_EXTENDED)
         && ((vOtaMSwapSourcePartition->State & VOTAM_PART_STATE_INACTIVE) == VOTAM_PART_STATE_INACTIVE))
   {
      /* Remember inactive partition */
      vOtaMOriginalSwapSourcePartition = vOtaMSwapSourcePartition;

      /* #20 Look for backup partition ID and set it as new source for swap */
      for (partIdx = 0u; partIdx < VOTAM_PARTITION_COUNT; partIdx++)
      {
         if ((partIdx != vOtaMSwapSourcePartition->Id) && (partIdx != vOtaMSwapDestPartition->Id))
         {
            /* Backup partition is the new source partition */
            vOtaMSwapSourcePartition = &vOtaM_PartitionInfo[partIdx];
            break;
         }
      }

      /* Use backup only if valid, otherwise revert to original source */
      if (vOtaMSwapSourcePartition->Validity != VOTAM_VALIDITY_VALID)
      {
         vOtaMSwapSourcePartition = vOtaMOriginalSwapSourcePartition;
      }
      else
      {
# if defined( VOTAM_ENABLE_PROG_ATTEMPTS ) && \
     defined( VOTAM_ENABLE_PROG_ATTEMPTS_CHECK )
         /* Check programming attempt counter */
         retVal = vOtaM_CheckProgAttempts(vOtaMSwapDestPartition);
         if (retVal == E_OK)
# endif /* VOTAM_ENABLE_PROG_ATTEMPTS && VOTAM_ENABLE_PROG_ATTEMPTS_CHECK */
         {
            /* #30 Invalidate and clear activation pending flag of old source partition */
            VOTAM_SWITCH_ADDRESS_AREA(vOtaMOriginalSwapSourcePartition->Id);
            (void)ApplFblInvalidateApp();
            VOTAM_RESTORE_ADDRESS_AREA();
            (void)vOtaM_Appl_SetPartitionState(vOtaMOriginalSwapSourcePartition, (vOtaM_PartitionStateType)(~(VOTAM_PART_STATE_ACTIVATION_PENDING)));

            /* #40 Backup partition valid, mark as new source */
            retVal = vOtaM_Appl_SetPartitionState(vOtaMSwapSourcePartition, VOTAM_PART_STATE_ACTIVATION_PENDING);
         }
      }

      if (retVal == E_OK)
      {
         if (vOtaM_IsPreSwapCheckConfigured()) /* PRQA S 2741 */ /* MD_FblvOtaM_2741_2742_2992_2996 */
         {
            /* #50 Check preconditions if check function is defined */
            retVal = vOtaM_PreSwapCheckFctPtr(vOtaMSwapSourcePartition->Id, vOtaMSwapDestPartition->Id);
         }
      }

      /* #60 Roll back */
      if (retVal == E_OK)
      {
         retVal = vOtaM_Appl_PerformSwap(vOtaMSwapSourcePartition->Id, vOtaMSwapDestPartition->Id);
      }
   }

   return retVal;
}
#endif /* VOTAM_USECASE_EXTENDED */

#if defined( VOTAM_ENABLE_SYNC_PARTITION )
/**********************************************************************************************************************
 *  vOtaM_SyncModule
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
static Std_ReturnType vOtaM_SyncModule(const vOtaM_ModuleInfoType* module)
{
   Std_ReturnType       retVal = E_OK;
   tFblResult           result = kFblFailed;
   tBlockDescriptor     blockDesc;
   tFblAddress          addr;
   tFblLength           length;
   vuint8               blockNr;

   blockNr = vOtaM_GetLogicalBlockNumberOfModule(module->Id);

   /* Get block descriptor of module to sync */
   result = FblLbtGetBlockDescriptorByNr(blockNr, &blockDesc);

   /* #10 Only sync if module is valid */
   if ((module->Validity == VOTAM_VALIDITY_VALID) && (result == kFblOk))
   {
      addr     = blockDesc.blockStartAddress;
      length   = blockDesc.blockLength;

      /* Switch variant for erasing destination */
      VOTAM_SET_SWAP_DEST_VARIANT();

# if defined( VOTAM_ENABLE_PROG_ATTEMPTS )
      /* #20 Increment programming attempt counter */
      retVal = vOtaM_IncProgAttempts(vOtaMSwapDestPartition->Id, module->Id);

      if (retVal == E_OK)
# endif /* VOTAM_ENABLE_PROG_ATTEMPTS */
      {
         /* #20 Invalidate and erase Module */
         (void)vOtaM_InvalidateModuleFctPtr(vOtaMSwapDestPartition->Id, module->Id);
         memSegment = FblMemSegmentNrGet(addr);
         /* Module must be in defined flash block */
         assertFblInternal(memSegment >= 0, kFblSysAssertParameterOutOfRange);

         if (IO_E_OK != MemDriver_REraseAddrAreaSync(vOtaM_GetAddrAreaIdOfPartition(vOtaMSwapDestPartition->Id), length, addr))
         {
            retVal = E_NOT_OK;
         }
         else
         {
            /* Destination module has been invalidated, also reset revision */
            vOtaMSwapDestPartition->Modules[module->Id].Validity = VOTAM_VALIDITY_INVALID;
            vOtaMSwapDestPartition->Modules[module->Id].Revision = 0u;
            FblDiagSetLastErasedBlock(blockDesc.blockNr);
            retVal = E_OK;
         }
      }

      /* #30 Copy module */
      if (retVal == E_OK)
      {
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
         if (ApplFblAdjustLbtBlockData(&blockDesc) != kFblOk)
         {
            retVal = E_NOT_OK;
         }
         if (retVal == E_OK)
# endif /* FBL_ENABLE_PRESENCE_PATTERN */
         {
            /* Values are changed by ApplFblAdjustLbtBlockData */
            addr = blockDesc.blockStartAddress;
            length = blockDesc.blockLength;
            retVal = vOtaM_CopyModule(addr, length, vOtaMSwapSourcePartition->Id, vOtaMSwapDestPartition->Id);
         }
      }

      if (retVal == E_OK)
      {
         if (vOtaM_IsVerifyModuleConfigured()) /* PRQA S 2741, 2742 */ /* MD_FblvOtaM_2741_2742_2992_2996 */
         {
            retVal = vOtaM_VerifyModuleFctPtr(vOtaMSwapDestPartition->Id, module->Id); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
         }
      }

      if (retVal == E_OK)
      {
         /* Switch variant for verification of destination */
         VOTAM_SET_SWAP_DEST_VARIANT();
         /* #40 Verify destination module */
         retVal = vOtaM_ValidateModuleFctPtr(vOtaMSwapDestPartition->Id, module->Id);
      }
   }

   return retVal;
}
#endif /* VOTAM_ENABLE_SYNC_PARTITION */

#if defined( VOTAM_ENABLE_PROG_ATTEMPTS )
/**********************************************************************************************************************
 *  vOtaM_IncProgAttempts
 *********************************************************************************************************************/
static Std_ReturnType vOtaM_IncProgAttempts(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId)
{
   Std_ReturnType retVal = E_NOT_OK;
   vOtaM_ProgAttemptsType progAttempts;

   /* Check if module is actually part of the source partition */
   if (vOtaM_IsModuleInPartition(moduleId, partitionId) == E_OK)
   {
      if (vOtaM_Appl_GetProgAttempts(partitionId, moduleId, &progAttempts) == E_OK)
      {
         progAttempts++;
         retVal = vOtaM_Appl_SetProgAttempts(partitionId, moduleId, progAttempts);
      }

   }

   return retVal;
}

# if defined( VOTAM_ENABLE_PROG_ATTEMPTS_CHECK )
/**********************************************************************************************************************
 *  vOtaM_CheckProgAttempts
 *********************************************************************************************************************/
/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
static Std_ReturnType vOtaM_CheckProgAttempts(const vOtaM_PartitionInfoType * part)
{
   Std_ReturnType          retVal = E_OK;
   vOtaM_ModuleIterType    moduleIdx;
   vOtaM_ProgAttemptsType  progAttempts;
   vOtaM_ProgAttemptsType  maxProgAttempts;
   vOtaM_ProgAttemptsType  progAttemptsThreshold;

   for (moduleIdx = 0u; moduleIdx < VOTAM_MODULE_COUNT; moduleIdx++)
   {
      /* Check if module is actually part of the source partition */
      if (vOtaM_IsModuleInPartition(moduleIdx, part->Id) == E_OK)
      {
         /* Determine threshold level depending on call context */
         if (vOtaMState == vOtaM_State_Rollback)
         {
            progAttemptsThreshold = VOTAM_PROG_ATTEMPTS_THRESHOLD_ROLLBACK;
         }
         else
         {
            progAttemptsThreshold = VOTAM_PROG_ATTEMPTS_THRESHOLD_SWAP;
         }

         /* A threshold of zero is not checked */
         if (progAttemptsThreshold > 0u)
         {
            /* Read prog counter */
            retVal = vOtaM_Appl_GetProgAttempts(vOtaMSwapDestPartition->Id, part->Modules[moduleIdx].Id, &progAttempts);
            if (retVal == E_OK)
            {
               /* Check if logical block does not restrict the number of programming attempts */
               retVal = vOtaM_Appl_GetMaxProgAttempts(vOtaMSwapDestPartition->Id, part->Modules[moduleIdx].Id, &maxProgAttempts);
               if (retVal == E_OK)
               {
                  if (maxProgAttempts != 0u)
                  {
                     /* Check logical block programming attempts */
                     if ((progAttempts + progAttemptsThreshold) >= maxProgAttempts)
                     {
                        /* Logical block cannot be programmed anymore */
                        retVal = E_NOT_OK;
                     }
                  }
               }
            }

            /* Leave loop in case of any error */
            if (retVal != E_OK)
            {
               break;
            }
         }
      }
   }

   return retVal;
}
# endif /* VOTAM_ENABLE_PROG_ATTEMPTS_CHECK */
#endif /* VOTAM_ENABLE_PROG_ATTEMPTS */

/***********************************************************************************************************************
 *  GLOBAL HELPER FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * vOtaM_GetState
 *********************************************************************************************************************/
vOtaM_StateType vOtaM_GetState(void)
{
   return vOtaMState;
}

#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
/**********************************************************************************************************************
 * vOtaM_GetActiveVariant
 *********************************************************************************************************************/
vMemAccM_VariantIdType vOtaM_GetActiveVariant(void)
{
   return activeVariantCurrent;
}

# if defined( VOTAM_ENABLE_SET_VARIANT_API )
/**********************************************************************************************************************
 * vOtaM_SetActiveVariant
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetActiveVariant(vMemAccM_VariantIdType variant)
{
   Std_ReturnType result = E_NOT_OK;

   if (variant < VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS)
   {
      VOTAM_SET_VARIANT(variant);
      result = E_OK;
   }

   return result;
}
# endif /* VOTAM_ENABLE_SET_VARIANT_API */
#endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */

/**********************************************************************************************************************
 * vOtaM_GetSourcePartition
 *********************************************************************************************************************/
vOtaM_PartitionInfoType vOtaM_GetSourcePartition(void)
{
   return *vOtaMSwapSourcePartition;
}

/**********************************************************************************************************************
 * vOtaMGetPartitionByAddrAreaId
 *********************************************************************************************************************/
Std_ReturnType vOtaMGetPartitionByAddrAreaId(vMemAccM_AddressAreaIdType addrAreaId, vOtaM_PartitionInfoType** partition)
{
   Std_ReturnType          retVal = E_NOT_OK;
   vOtaM_PartitionIterType partitionIdx;

   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if (vOtaM_GetAddrAreaIdOfPartition(vOtaM_PartitionInfo[partitionIdx].Id) == addrAreaId)
      {
         *partition = &vOtaM_PartitionInfo[partitionIdx];
         retVal = E_OK;
         break;
      }
   }

   return retVal;
}

/**********************************************************************************************************************
 * vOtaMGetModuleByLogicalBlockNumber
 *********************************************************************************************************************/
Std_ReturnType vOtaMGetModuleByLogicalBlockNumber(tFblLbtBlockNr bn, vOtaM_ModuleIdType* moduleId)
{
   Std_ReturnType       retVal = E_NOT_OK;
   vOtaM_ModuleIterType moduleIdx;

   for (moduleIdx = 0u; moduleIdx < VOTAM_MODULE_COUNT; moduleIdx++)
   {
      if (vOtaM_GetLogicalBlockNumberOfModule(moduleIdx) ==  bn)
      {
         *moduleId = moduleIdx;
         retVal = E_OK;
      }
   }

   return retVal;
}

/**********************************************************************************************************************
 * vOtaM_GetBackupPartitionId
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetBackupPartitionId(vOtaM_PartitionIdType* partitionId)
{
   Std_ReturnType retVal = E_NOT_OK;
   vOtaM_PartitionIterType partitionIdx;

   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if (((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_INACTIVE) != VOTAM_PART_STATE_INACTIVE) &&
          ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_ACTIVE) != VOTAM_PART_STATE_ACTIVE))
      {
         *partitionId = partitionIdx;
         retVal = E_OK;
         break;
      }
   }

   return retVal;
}

/**********************************************************************************************************************
 * vOtaM_GetInactivePartitionId
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetInactivePartitionId(vOtaM_PartitionIdType* partitionId)
{
   Std_ReturnType retVal = E_NOT_OK;
   vOtaM_PartitionIterType partitionIdx;

   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_INACTIVE) == VOTAM_PART_STATE_INACTIVE)
      {
         *partitionId = partitionIdx;
         retVal = E_OK;
         break;
      }
   }

   return retVal;
}

/**********************************************************************************************************************
 * vOtaM_GetActivePartitionId
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetActivePartitionId(vOtaM_PartitionIdType* partitionId)
{
   Std_ReturnType retVal = E_NOT_OK;
   vOtaM_PartitionIterType partitionIdx;

   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_ACTIVE) == VOTAM_PART_STATE_ACTIVE)
      {
         *partitionId = partitionIdx;
         retVal = E_OK;
         break;
      }
   }

   return retVal;
}

/**********************************************************************************************************************
 * vOtaM_IsModuleInPartition
 *********************************************************************************************************************/
Std_ReturnType vOtaM_IsModuleInPartition(vOtaM_ModuleIdType moduleId, vOtaM_PartitionIdType partitionId)
{
   Std_ReturnType retVal = E_NOT_OK;
   vOtaM_PartitionGroupIdxOfPartitionGroupType partGroupStartIdx;
   vOtaM_PartitionGroup2PartitionIterType partGroupIter;
   vOtaM_NumPartitionOfPartitionGroupType partGroupNum;

   /* Get start index and number of partitions for the modules partition group from vOtaM_PartitionGroup2Partition */
   partGroupStartIdx = vOtaM_GetPartitionGroupIdxOfPartitionGroup(vOtaM_GetPartitionGroupIdxOfModule(moduleId));
   partGroupNum = vOtaM_GetNumPartitionOfPartitionGroup(vOtaM_GetPartitionGroupIdxOfModule(moduleId));

   for (partGroupIter = 0u; partGroupIter < partGroupNum; partGroupIter++)
   {
      if (vOtaM_GetPartitionOfPartitionGroup2Partition(partGroupStartIdx + partGroupIter) == partitionId)
      {
         retVal = E_OK;
         break;
      }
   }

   return retVal;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS FOR INITIALIZATION AND TO DETERMINE STATE OF META DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * vOtaM_InitMemory
 *********************************************************************************************************************/
void vOtaM_InitMemory(void)
{
   vOtaM_PartitionIterType partitionIdx;
   vOtaM_ModuleIterType moduleIdx;
   vMemAccM_VariantIdType tempVariant;

#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
   for (tempVariant = VMEMACCM_VARIANT_ID_STARTUP; tempVariant < VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS; tempVariant++)
#else
   tempVariant = VMEMACCM_VARIANT_ID_STARTUP;
#endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */
   {
      VOTAM_SET_VARIANT(tempVariant);
      /* Initialize static partition information and set default values for dynamic fields */
      for (partitionIdx = 0; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
      {
         vOtaM_PartitionInfo[partitionIdx].Id = partitionIdx;
         vOtaM_PartitionInfo[partitionIdx].Variant = tempVariant;
         vOtaM_PartitionInfo[partitionIdx].State = VOTAM_PART_STATE_UNDEFINED;
         vOtaM_PartitionInfo[partitionIdx].Validity = VOTAM_VALIDITY_INVALID;
         vOtaM_PartitionInfo[partitionIdx].Revision = 0u; /* 0 means that the revision couldn't be read. Revision counter starts with 1 */

         /* Initialize static module information and set default values for dynamic fields */
         for (moduleIdx = 0u; moduleIdx < VOTAM_MODULE_COUNT; moduleIdx++)
         {
            vOtaM_PartitionInfo[partitionIdx].Modules[moduleIdx].Id = moduleIdx;
            vOtaM_PartitionInfo[partitionIdx].Modules[moduleIdx].Validity = VOTAM_VALIDITY_INVALID;
            vOtaM_PartitionInfo[partitionIdx].Modules[moduleIdx].Revision = 0u;
         }
      }
   }

   /* Initialize other static variables of module */
   vOtaMState = vOtaM_State_Unintialized;
#if defined( VOTAM_ENABLE_SYNC_PARTITION )
   vOtaMCopyRevision = FALSE; /* Per default increment revisions */
#endif /* VOTAM_ENABLE_SYNC_PARTITION */
#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
   VOTAM_SET_VARIANT(VMEMACCM_VARIANT_ID_STARTUP);
   activeVariantStartup = VMEMACCM_VARIANT_ID_STARTUP;
#endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */
   backupAddrArea = 0u;
   vOtaMSwapSourcePartition = (vOtaM_PartitionInfoType*)0;
   vOtaMSwapDestPartition = (vOtaM_PartitionInfoType*)0;
}

/**********************************************************************************************************************
 * vOtaM_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
Std_ReturnType vOtaM_Init(void)
{
   Std_ReturnType             retVal;
   vOtaM_PartitionIterType    partitionIdx;

   /* #10 Let user determine the state of all configured entities
    * - Validity of modules and their revisions
    * - Validity of partitions and their revisions and partition state
    */
   retVal = vOtaM_Appl_Init(vOtaM_PartitionInfo, VMEMACCM_VARIANT_ID_STARTUP);

#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
   if (retVal == E_OK)
   {
      /* #20 Get meta data of partitions and modules for second variant if configured */
      VOTAM_SET_VARIANT(VMEMACCM_VARIANT_ID_ALTERNATE);
      retVal = vOtaM_Appl_Init(vOtaM_PartInfo[VMEMACCM_VARIANT_ID_ALTERNATE], VMEMACCM_VARIANT_ID_ALTERNATE);
   }

   /* #30 Let user determine the active vMemAccessManager variant
    * and apply chosen variant. */
   if (retVal == E_OK)
   {
      activeVariantStartup = vOtaM_Appl_InitVariant(vOtaM_PartInfo);
   }
#endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */

   /* During regular FBL execution as well as SWAP, we will run in the active variant. No further variant switching necessary. */
   VOTAM_SET_ACTIVE_VARIANT();

   if (retVal == E_OK)
   {
      /* #40 Partition info and variant has been set, loop through all partitions */
      for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
      {
         if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_ACTIVE) == VOTAM_PART_STATE_ACTIVE)
         {
            VOTAM_SWITCH_ADDRESS_AREA(partitionIdx);
            vOtaMSwapDestPartition = &vOtaM_PartitionInfo[partitionIdx];
         }
      }

      vOtaMState = vOtaM_State_Initialized;
      /* #50 Determine if swap/sync has been requested and set swap source partition */
      vOtaM_CheckOtaRequest();
   }

#if defined( FBL_DIAG_ENABLE_SAFE_SWAP )
   vOtaMSafeSwap_CheckpointReached(VOTAMSAFESWAP_DIAGNOSIS, VOTAMSAFESWAP_DIAGNOSIS_RESET);
#endif /* FBL_DIAG_ENABLE_SAFE_SWAP */

   return retVal;
}

/**********************************************************************************************************************
 * vOtaM_CheckOtaRequest
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
void vOtaM_CheckOtaRequest(void)
{
   vOtaM_PartitionIterType       partitionIdx;
   vOtaM_PartitionRevisionType   curPartRev;
   vOtaM_PartitionRevisionType   oldPartRev;
   vOtaM_PartitionInfoType*      part;

   /* #10 Search for VOTAM_PART_STATE_ACTIVATION_PENDING state in all partitions */
   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_ACTIVATION_PENDING) == VOTAM_PART_STATE_ACTIVATION_PENDING)
      {
         if (vOtaMState == vOtaM_State_OtaRequest)
         {
            /* #20 Generally its possible that two partitions have VOTAM_PART_STATE_ACTIVATION_PENDING set:
             * SWAP failed and roll back shall be started. Roll back must have the higher priority.
             * Detect roll back by lower partition revision.
             */
            curPartRev = vOtaM_PartitionInfo[partitionIdx].Revision;
            oldPartRev = vOtaMSwapSourcePartition->Revision;

            if ((curPartRev != 0u) && (curPartRev < oldPartRev))
            {
               vOtaMSwapSourcePartition = &vOtaM_PartitionInfo[partitionIdx];
            }
         }
         else
         {
            vOtaMSwapSourcePartition = &vOtaM_PartitionInfo[partitionIdx];
            vOtaMState = vOtaM_State_OtaRequest;
         }
      }
   }

   if (vOtaMState == vOtaM_State_Initialized)
   {
      /* #30 No pending activation found check if user wants to override this result */
      if (vOtaM_Appl_CheckOtaRequest(vOtaM_PartInfo, &part) == E_OK)
      {
         vOtaMSwapSourcePartition = part;
         vOtaMState = vOtaM_State_OtaRequest;
      }
   }
}

/**********************************************************************************************************************
 * vOtaM_ActivateInactivePartition
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ActivateInactivePartition(vOtaM_PartitionInfoType* part, vuint8 activationState)
{
   Std_ReturnType             result = E_NOT_OK;
   vOtaM_PartitionIterType    partitionIdx;

   /* Find partition marked as inactive and set working address area to its memory area */
   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_INACTIVE) == VOTAM_PART_STATE_INACTIVE)
      {
         result = vOtaM_ActivatePartition(partitionIdx, part, activationState);
         break;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_ActivatePartition
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ActivatePartition(vOtaM_PartitionIdType partId, vOtaM_PartitionInfoType* part, vuint8 activationState)
{
   Std_ReturnType result = E_NOT_OK;
   vOtaM_PartitionInfoType localPart;

   MemDriver_SetAddressArea(vOtaM_GetAddrAreaIdOfPartition(partId));

   localPart = vOtaM_PartitionInfo[partId];

   if (part != NULL_PTR)
   {
      *part = localPart;
   }

   /* User might have to apply additional settings to switch to inactive partition */
   result = vOtaM_Appl_ActivatePartition(&localPart, activationState);

   return result;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS FOR SWAP PROCESSING
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * vOtaM_Main
 *********************************************************************************************************************/
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
/* PRQA S 6010, 6050 1 */  /* MD_MSR_STPTH, MD_MSR_STCAL */
void vOtaM_Main(void)
{
   Std_ReturnType intRetVal = E_NOT_OK;
   vuint8 remainingAttempts = 1u;

   /* #10 Nothing to do if there is no swap/sync request */
   if (vOtaMState == vOtaM_State_OtaRequest)
   {
#if defined( VOTAM_ENABLE_FLASHDRIVER_INIT )
      /* Initialize Flash driver */
      ApplFblSetVfp();
      (void)vOtaM_Appl_InitBuildInFlashDriver();
#endif /* VOTAM_ENABLE_FLASHDRIVER_INIT */

      /* #20 Check remaining swap attempts */
      if (vOtaM_Appl_GetRemainingSwapAttempts(&remainingAttempts) != E_OK)
      {
         remainingAttempts = 1u;
      }

      if (remainingAttempts > 0u)
      {
         if (vOtaM_IsPreSwapCheckConfigured()) /* PRQA S 2741, 2742 */ /* MD_FblvOtaM_2741_2742_2992_2996 */
         {
            /* #30 Check preconditions if check function is defined */
            intRetVal = vOtaM_PreSwapCheckFctPtr(vOtaMSwapSourcePartition->Id, vOtaMSwapDestPartition->Id); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
         }
         else
         {
            intRetVal = E_OK; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
         }
      }
   }

   if (intRetVal == E_OK)
   {
      /* Allow loop entry by setting return to not ok */
      intRetVal = E_NOT_OK;
      /* #40 Start swap/sync, update and roll back are treated the same */
      vOtaMState = vOtaM_State_SwapProcessing;

      while ((remainingAttempts > 0u) && (intRetVal != E_OK))
      {
         /* Decrement number of attempts left */
         remainingAttempts -= 1u;
         (void)vOtaM_Appl_SetRemainingSwapAttempts(remainingAttempts);
         intRetVal = vOtaM_Appl_PerformSwap(vOtaMSwapSourcePartition->Id, vOtaMSwapDestPartition->Id);
      }

#if defined( VOTAM_USECASE_EXTENDED )
      if (intRetVal != E_OK)
      {
         /* #50 Try to roll back if swap/sync was unsuccessful */
         vOtaMState = vOtaM_State_Rollback;
         intRetVal = vOtaM_Rollback();
      }
# if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
      else
      {
         /* #60 Switch variant after reset in case swap/sync was successful */
         intRetVal = vOtaM_Appl_SetActiveVariant((activeVariantStartup == VMEMACCM_VARIANT_ID_STARTUP) ? VMEMACCM_VARIANT_ID_ALTERNATE : VMEMACCM_VARIANT_ID_STARTUP);
      }
# endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */
#endif /* VOTAM_USECASE_EXTENDED */
   }

   if (vOtaMState > vOtaM_State_Initialized)
   {
      /* #70 Remove activation pending state from source partition(s) if swap has been completed or all swap attempts have been used.*/
      if ((intRetVal == E_OK) || (remainingAttempts == 0u))
      {
         /* Remove activation pending */
         (void)vOtaM_Appl_SetPartitionState(vOtaMSwapSourcePartition, (vOtaM_PartitionStateType)(~(VOTAM_PART_STATE_ACTIVATION_PENDING)));

         /* Reset number of attempts */
         (void)vOtaM_Appl_SetRemainingSwapAttempts(VOTAM_SWAP_ATTEMPTS);
      }

      /* #80 Reset ECU after swap/sync processing */
#if defined( VOTAM_ENABLE_FLASHDRIVER_INIT )
      (void)vOtaM_Appl_DeinitBuildInFlashDriver();
      ApplFblResetVfp();
#endif /* VOTAM_ENABLE_FLASHDRIVER_INIT */
      ApplFblReset();
   }
}

#if defined( VOTAM_ENABLE_SYNC_PARTITION )
/**********************************************************************************************************************
 *  vOtaM_SyncPartition
 *********************************************************************************************************************/
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
 */
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
Std_ReturnType vOtaM_SyncPartition(vOtaM_PartitionIdType srcPartitionId, vOtaM_PartitionIdType destPartitionId)
{
   Std_ReturnType          retVal = E_OK;
   vOtaM_ModuleIterType    moduleIdx;

   vOtaMSwapDestPartition = vOtaM_GetPartitionById(destPartitionId);
   vOtaMSwapSourcePartition = vOtaM_GetPartitionById(srcPartitionId);

   if (   (vOtaMSwapDestPartition == NULL_PTR)
       || (vOtaMSwapSourcePartition == NULL_PTR))
   {
      /* Invalid partition IDs provided */
      retVal = E_NOT_OK;
   }
   else
# if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x01u)
   /* #10 Only perform sync if destination partition is invalid or partition revisions are different */
   if (   (vOtaMSwapDestPartition->Validity != VOTAM_VALIDITY_VALID)
       || (vOtaMSwapSourcePartition->Revision != vOtaMSwapDestPartition->Revision))
# endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */
   {
      vOtaMCopyRevision = TRUE;

      /* All regular MIO calls go to the dest partition for this function */
      VOTAM_SWITCH_ADDRESS_AREA(vOtaMSwapDestPartition->Id);
      VOTAM_SET_SWAP_DEST_VARIANT();

# if defined( VOTAM_ENABLE_PROG_ATTEMPTS ) && \
     defined( VOTAM_ENABLE_PROG_ATTEMPTS_CHECK )
      /* #20 Check programming attempt counter of each module */
      retVal = vOtaM_CheckProgAttempts(vOtaMSwapDestPartition);

      if (retVal == E_OK)
# endif /* VOTAM_ENABLE_PROG_ATTEMPTS && VOTAM_ENABLE_PROG_ATTEMPTS_CHECK */
      {
         /* #30 Destination partition must be invalidated first */
         if (vOtaM_InvalidatePartitionFctPtr(vOtaMSwapDestPartition->Id) == E_OK)
         {
            /* #40 Go trough all configured modules of the source partition */
            VOTAM_SET_SWAP_SOURCE_VARIANT();
            for (moduleIdx = 0u; moduleIdx < VOTAM_MODULE_COUNT; moduleIdx++)
            {
               /* Copy only sync modules */
               if (vOtaM_IsSyncModuleOfModule(moduleIdx))
               {
                  /* Only copy module if it is part of the source and destination partition */
                  if (   (vOtaM_IsModuleInPartition(moduleIdx, vOtaMSwapSourcePartition->Id) == E_OK)
                      && (vOtaM_IsModuleInPartition(moduleIdx, vOtaMSwapDestPartition->Id) == E_OK))
                  {
                     if (vOtaM_SyncModule(&vOtaMSwapSourcePartition->Modules[moduleIdx]) != E_OK)
                     {
                        retVal = E_NOT_OK;
                        break;
                     }
                  }
               }
            }
         }
         else
         {
            retVal = E_NOT_OK;
         }
      }

      if (retVal == E_OK)  /* PRQA S 2741 */ /* MD_FblvOtaM_2741_2742_2992_2996 */
      {
         if (vOtaM_IsVerifyPartitionConfigured()) /* PRQA S 2741, 2742, 2880 */ /* MD_FblvOtaM_2741_2742_2992_2996, MD_MSR_Unreachable */
         {
            retVal = vOtaM_VerifyPartitionFctPtr(vOtaMSwapDestPartition->Id); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
         }
      }

      if (retVal == E_OK)
      {
         /* #50 Verify destination partition - Causes update of validity information */
         VOTAM_SET_SWAP_DEST_VARIANT();
         retVal = vOtaM_ValidatePartitionFctPtr(vOtaMSwapDestPartition->Id);
      }

      /* Restore address area */
      VOTAM_RESTORE_ADDRESS_AREA();

      vOtaMCopyRevision = FALSE;
   }
# if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x01u)
   else
   {
      /* No swap required - result already set to OK */
   }
# endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */

   /* Restore active variant */
   VOTAM_SET_ACTIVE_VARIANT();

   return retVal;
}
#endif /* VOTAM_ENABLE_SYNC_PARTITION */

/**********************************************************************************************************************
 * vOtaM_CopyModule
 *********************************************************************************************************************/
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
/* PRQA S 6030, 6010, 6080, 6050 1 */ /* MD_MSR_STCYC, MD_MSR_STPTH, MD_MSR_STMIF, MD_MSR_STCAL */
Std_ReturnType vOtaM_CopyModule(tFblAddress addr, tFblLength length, vOtaM_PartitionIdType srcPartitionId, vOtaM_PartitionIdType destPartitionId)
{
   Std_ReturnType  retVal;
   IO_ErrorType    readResult;
   tFblLength      lengthToProcess;
   tFblAddress     localAddress = addr;
   tFblLength      localLength = length;
#if defined( VOTAM_ENABLE_READ_PROCESSING )
   vOtaM_ProcParam localProcParam;
   tFblAddress     localProcAddress = addr;
   tFblLength      procLength = 0u;
   tFblLength      inLength;
   tFblLength      finalLength;
   vuint16         pageSize = 0u;
   vuint16         inOffset;
   vuint16         outOffset = 0u;
   vuint32         index;
#else
   retVal = E_OK;
#endif /* VOTAM_ENABLE_READ_PROCESSING */

   vOtaMSwapDestPartition = vOtaM_GetPartitionById(destPartitionId);
   vOtaMSwapSourcePartition = vOtaM_GetPartitionById(srcPartitionId);

   if (   (vOtaMSwapDestPartition == NULL_PTR)
       || (vOtaMSwapSourcePartition == NULL_PTR))
   {
      /* Invalid partition IDs provided */
      retVal = E_NOT_OK;
   }
   else
   {
#if defined( VOTAM_ENABLE_READ_PROCESSING )
      localProcParam.key = V_NULL;
      retVal = vOtaM_Appl_InitReadProcessing(&localProcParam);

      if (retVal == E_OK)
      {
#endif /* VOTAM_ENABLE_READ_PROCESSING */
         while (localLength > 0u)
         {
            if (localLength > vOtaM_GetCopyBufferSize())
            {
               lengthToProcess = vOtaM_GetCopyBufferSize();
            }
            else
            {
               lengthToProcess = localLength;
            }

            /* #10 Set variant for reading source module and read chunk of data */
            VOTAM_SET_SWAP_SOURCE_VARIANT();
            memSegment = FblMemSegmentNrGet(localAddress);
            /* Module must be in defined flash block */
            assertFblInternal(memSegment >= 0, kFblSysAssertParameterOutOfRange);
            readResult = MemDriver_RReadAddrAreaSync(vOtaM_GetAddrAreaIdOfPartition(vOtaMSwapSourcePartition->Id), vOtaMCopyBuffer.bufferData, lengthToProcess, localAddress);

            if (readResult == IO_E_OK)
            {
#if defined( VOTAM_ENABLE_READ_PROCESSING )
               /* Take over length that has to be processed */
               inLength = lengthToProcess;
               inOffset = 0u;

               while (inLength > 0u)
               {
                  localProcParam.dataBuffer = &(vOtaMCopyBuffer.bufferData[inOffset]);
                  localProcParam.dataLength = (vuint16)inLength;
                  localProcParam.dataOutBuffer = &(vOtaMProcBuffer.bufferData[outOffset]);
                  localProcParam.dataOutMaxLength = (vuint16)(vOtaM_GetCopyBufferSize() - outOffset);

                  /* Switch variant for processing */
                  VOTAM_SET_SWAP_DEST_VARIANT();

                  /* #20 Process the read out data */
                  if (vOtaM_Appl_ReadProcessing(&localProcParam) == E_OK)
                  {
                     /* #30 Get page size */
                     pageSize = MemDriver_GetSegmentSize(vOtaM_GetAddrAreaIdOfPartition(vOtaMSwapDestPartition->Id), localProcParam.dataOutLength, localProcAddress);

                     /* Calculate length to write */
                     procLength = (tFblLength)(((tFblLength)localProcParam.dataOutLength + (tFblLength)outOffset) & FblInvert16Bit(pageSize - 1u));

                     if (procLength != 0u)
                     {
                        /* #40 Write processed data */
                        memSegment = FblMemSegmentNrGet(localProcAddress);
                        /* Module must be in defined flash block */
                        assertFblInternal(memSegment >= 0, kFblSysAssertParameterOutOfRange);

                        if (MemDriver_RWriteAddrAreaSync(vOtaM_GetAddrAreaIdOfPartition(vOtaMSwapDestPartition->Id), vOtaMProcBuffer.bufferData, procLength, localProcAddress) != IO_E_OK)
                        {
                           retVal = E_NOT_OK;
                        }
                     }
                  }
                  else
                  {
                     retVal = E_NOT_OK;
                  }

                  /* Issue detected - leave loop */
                  if (retVal != E_OK)
                  {
                     break;
                  }

                  /* #50 Prepare next loop */
                  outOffset = (localProcParam.dataOutLength + outOffset) & (pageSize - 1u);
                  inOffset += localProcParam.dataLength;
                  inLength -= localProcParam.dataLength;
                  localProcAddress += procLength;

                  /* Copy unprocessed data to start of processing buffer */
                  (void)MEMCPY(vOtaMProcBuffer.bufferData, &(vOtaMProcBuffer.bufferData[procLength]), outOffset); /* PRQA S 0314 */ /* MD_FblvOtaM_0314_MemCpy */
               }
#else
               /* #60 Switch variant for writing destination module and write data */
               VOTAM_SET_SWAP_DEST_VARIANT();
               memSegment = FblMemSegmentNrGet(localAddress);
               /* Module must be in defined flash block */
               assertFblInternal(memSegment >= 0, kFblSysAssertParameterOutOfRange);

               if (MemDriver_RWriteAddrAreaSync(vOtaM_GetAddrAreaIdOfPartition(vOtaMSwapDestPartition->Id), vOtaMCopyBuffer.bufferData, lengthToProcess, localAddress) != IO_E_OK)
               {
                  retVal = E_NOT_OK;
               }
#endif /* VOTAM_ENABLE_READ_PROCESSING */
            }
            /* #70 Writing chunk is skipped if memory is blank, report error for all other error codes */
            else if (readResult != IO_E_ERASED)
            {
               retVal = E_NOT_OK;
            }
            else
            {
               /* Satisfy MISRA */
            }
            /* Issue detected - leave loop */
            if (retVal != E_OK)
            {
               break;
            }

            /* #80 Prepare next loop */
            localAddress += lengthToProcess;
            localLength -= lengthToProcess;
         }
#if defined( VOTAM_ENABLE_READ_PROCESSING )
      }
      if (retVal == E_OK)
      {
         /* No data should be left */
         localProcParam.dataLength = 0u;
         /* Initialize output parameters */
         localProcParam.dataOutBuffer = &(vOtaMProcBuffer.bufferData[outOffset]);
         localProcParam.dataOutMaxLength = (vuint16)(vOtaM_GetCopyBufferSize() - outOffset);

         /* #90 Deinitialize processing function */
         retVal = vOtaM_Appl_DeinitReadProcessing(&localProcParam);

         if (retVal == E_OK)
         {
            /* Get correct length for last data */
            finalLength = (tFblLength)(((tFblLength)localProcParam.dataOutLength + (tFblLength)outOffset + ((tFblLength)pageSize - 1u)) & FblInvert16Bit(pageSize - 1u));

            if (finalLength > 0u)
            {
               for (index = (vuint32)((vuint32)localProcParam.dataOutLength + (vuint32)outOffset); index < finalLength; index++)
               {
                  vOtaMProcBuffer.bufferData[index] = kFillChar;
               }

               /* Write last processed data */
               VOTAM_SET_SWAP_DEST_VARIANT();
               memSegment = FblMemSegmentNrGet(localProcAddress);
               /* Module must be in defined flash block */
               assertFblInternal(memSegment >= 0, kFblSysAssertParameterOutOfRange);

               if (MemDriver_RWriteAddrAreaSync(vOtaM_GetAddrAreaIdOfPartition(vOtaMSwapDestPartition->Id), vOtaMProcBuffer.bufferData, finalLength, localProcAddress) != IO_E_OK)
               {
                  retVal = E_NOT_OK;
               }
            }
         }
      }
#endif /* VOTAM_ENABLE_READ_PROCESSING */
   }

   return retVal;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS FOR PARTITIONS HANDLING
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * vOtaM_OpenPartition
 *********************************************************************************************************************/
Std_ReturnType vOtaM_OpenPartition(vOtaM_PartitionRoleType role)
{
   Std_ReturnType          result = E_NOT_OK;
   vOtaM_PartitionIdType   partId;

   if (vOtaM_GetPartitionIdByRole(role, &partId) == E_OK)
   {
      MemDriver_SetAddressArea(vOtaM_GetAddrAreaIdOfPartition(partId));
      result = E_OK;
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_IsOpenedPartitionOfRole
 *********************************************************************************************************************/
Std_ReturnType vOtaM_IsOpenedPartitionOfRole(vOtaM_PartitionRoleType role)
{
   Std_ReturnType             result = E_NOT_OK;
   vOtaM_PartitionIdType      partId;

   if (vOtaM_GetPartitionIdByRole(role, &partId) == E_OK)
   {
      /* Get working partition-AddressArea and compare it to partition-AddressArea of selected role */
      if (vOtaM_GetAddrAreaIdOfPartition(partId) == MemDriver_GetAddressArea())
      {
         result = E_OK;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_GetRoleOfOpenedPartition
 *********************************************************************************************************************/
vOtaM_PartitionRoleType vOtaM_GetRoleOfOpenedPartition(void)
{
   vOtaM_PartitionRoleType    role;

   if (vOtaM_IsOpenedPartitionOfRole(vOtaM_Part_Role_Backup) == E_OK)
   {
      role = vOtaM_Part_Role_Backup;
   }
   else if (vOtaM_IsOpenedPartitionOfRole(vOtaM_Part_Role_Inactive) == E_OK)
   {
      role = vOtaM_Part_Role_Inactive;
   }
   else
   {
      role = vOtaM_Part_Role_Active; /* default is always active partition */
   }

   return role;
}

/**********************************************************************************************************************
 * vOtaM_GetPartitionIdByRole
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetPartitionIdByRole(vOtaM_PartitionRoleType role, vOtaM_PartitionIdType* partId)
{
   Std_ReturnType    result;
   *partId = 0x00u; /* default */

   switch (role)
   {
      case vOtaM_Part_Role_Active:
      {
         result = vOtaM_GetActivePartitionId(partId);
         break;
      }
      case vOtaM_Part_Role_Inactive:
      {
         result = vOtaM_GetInactivePartitionId(partId);
         break;
      }
      case vOtaM_Part_Role_Backup:
      {
         result = vOtaM_GetBackupPartitionId(partId);
         break;
      }
      default:
      {
         result = E_NOT_OK;
         break;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetActivePartitionValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
Std_ReturnType vOtaM_SetActivePartitionValid(void)
{
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

   /* #10 Get working partition */
   if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
   {
      /* #20 Validate partition */
      result = vOtaM_SetPartitionValid(part->Id);
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetPartitionValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
Std_ReturnType vOtaM_SetPartitionValid(vOtaM_PartitionIdType partitionId)
{
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

   /* #10 Get partition */
   part = vOtaM_GetPartitionById(partitionId);
   if (part != NULL_PTR)
   {
      /* #20 Validate partition */
      result = vOtaM_Appl_SetPartitionValid(part, VOTAM_VALIDITY_VALID);
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetActivePartitionInvalid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
Std_ReturnType vOtaM_SetActivePartitionInvalid(void)
{
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

   /* #10 Get working partition */
   if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
   {
      /* #20 Invalidate partition */
      result = vOtaM_SetPartitionInvalid(part->Id);
   }

   return result;
}

/**********************************************************************************************************************
* vOtaM_SetPartitionInvalid
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
*/
Std_ReturnType vOtaM_SetPartitionInvalid(vOtaM_PartitionIdType partitionId)
{
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

   /* #10 Get partition */
   part = vOtaM_GetPartitionById(partitionId);
   if (part != NULL_PTR)
   {
      /* #20 Invalidate partition */
      result = vOtaM_Appl_SetPartitionValid(part, VOTAM_VALIDITY_INVALID);
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetNewPartitionRevision
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType vOtaM_SetNewPartitionRevision(void)
{
   vOtaM_PartitionRevisionType   partRev= 0u; /* Initialize with invalid value */
   vOtaM_PartitionRevisionType   tmpPartRev;
   vOtaM_PartitionIterType       partIdx;
   vOtaM_PartitionInfoType*      part;
   Std_ReturnType                result = E_NOT_OK;

#if defined( VOTAM_ENABLE_SYNC_PARTITION )
   /* #10 If swap processing is active, we take over the revision from the source partition */
   if (vOtaMCopyRevision == TRUE)
   {
      VOTAM_SET_SWAP_SOURCE_VARIANT();
      partRev = vOtaMSwapSourcePartition->Revision;
      /* Switch to variant of destination partition for verification */
      VOTAM_SET_SWAP_DEST_VARIANT();
   }
   else
#endif /* VOTAM_ENABLE_SYNC_PARTITION */
   {
      /* #20 Real update - determine next partition revision */
      for (partIdx = 0u; partIdx < VOTAM_PARTITION_COUNT; partIdx++)
      {
         tmpPartRev = vOtaM_PartitionInfo[partIdx].Revision;
         if (tmpPartRev > partRev)
         {
            partRev = tmpPartRev;
         }
      }

      /* New partition revision is latest revision +1 */
      partRev++;
   }

   /* #30 Set default revision number if no valid revision was found */
   if (partRev == 0u)
   {
      partRev = 1u;
   }

   /* #40 Let user store the new partition revision */
   if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
   {
      if (vOtaM_Appl_SetPartitionRevision(part, partRev) == E_OK)
      {
         vOtaM_PartitionInfo[part->Id].Revision = partRev;
         result = E_OK;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetModuleValid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
Std_ReturnType vOtaM_SetModuleValid(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId)
{
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

   /* #10 Set new module revision */
   if (vOtaM_SetNewModuleRevision(moduleId) == E_OK)
   {
      /* #20 Get partition and validate block */
      part = vOtaM_GetPartitionById(partitionId);
      if (part != NULL_PTR)
      {
         result = vOtaM_Appl_SetModuleValid(part, moduleId, VOTAM_VALIDITY_VALID);
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetModuleInvalid
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
Std_ReturnType vOtaM_SetModuleInvalid(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId)
{
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

   /* #10 Get partition and invalidate block */
   part = vOtaM_GetPartitionById(partitionId);
   if (part != NULL_PTR)
   {
      result = vOtaM_Appl_SetModuleValid(part, moduleId, VOTAM_VALIDITY_INVALID);
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SetNewModuleRevision
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
Std_ReturnType vOtaM_SetNewModuleRevision(vOtaM_ModuleIdType moduleId)
{
   vOtaM_ModuleRevisionType moduleRev = 0u; /* Initialize with invalid value */
   vOtaM_ModuleRevisionType tmpModuleRev;
   vOtaM_PartitionIterType  partIdx;
   vOtaM_PartitionInfoType* part;
   Std_ReturnType           result = E_NOT_OK;

#if defined( VOTAM_ENABLE_SYNC_PARTITION )
   /* #10 If swap processing is active, we take over the revision from the source module */
   if (vOtaMCopyRevision == TRUE)
   {
      VOTAM_SET_SWAP_SOURCE_VARIANT();
      moduleRev = vOtaMSwapSourcePartition->Modules[moduleId].Revision;
      /* Further processing is targeted at destination partition */
      VOTAM_SET_SWAP_DEST_VARIANT();
   }
   else
#endif /* VOTAM_ENABLE_SYNC_PARTITION */
   {
      /* #20 Real updates - always new revision
       * Increment the highest module revision of all configured partitions */
      for (partIdx = 0u; partIdx < VOTAM_PARTITION_COUNT; partIdx++)
      {
         tmpModuleRev = vOtaM_PartitionInfo[partIdx].Modules[moduleId].Revision;
         if (tmpModuleRev > moduleRev)
         {
            moduleRev = tmpModuleRev;
         }
      }
      moduleRev++;
   }

   /* #30 Set default revision number if no valid was found before */
   if (moduleRev == 0u)
   {
      moduleRev = 1u;
   }

   /* #40 Let user store the new module revision */
   if (vOtaMGetPartitionByAddrAreaId(MemDriver_GetAddressArea(), &part) == E_OK)
   {
      if (vOtaM_Appl_SetModuleRevision(&vOtaM_PartitionInfo[part->Id].Modules[moduleId], moduleRev) == E_OK)
      {
         vOtaM_PartitionInfo[part->Id].Modules[moduleId].Revision = moduleRev;
         result = E_OK;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_InvalidatePartition()
 *********************************************************************************************************************/
Std_ReturnType vOtaM_InvalidatePartition(vOtaM_PartitionIdType partitionId)
{
   Std_ReturnType           result = E_NOT_OK;

   VOTAM_DUMMY_STATEMENT(partitionId);

   if (ApplFblInvalidateApp() == kFblOk)
   {
      result = E_OK;
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_ValidatePartition()
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ValidatePartition(vOtaM_PartitionIdType partitionId)
{
   Std_ReturnType           result = E_NOT_OK;

   VOTAM_DUMMY_STATEMENT(partitionId);

   if (ApplFblValidateApp() == kFblOk)
   {
      result = E_OK;
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_InvalidateModule()
 *********************************************************************************************************************/
Std_ReturnType vOtaM_InvalidateModule(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId)
{
   Std_ReturnType           result = E_NOT_OK;
   tBlockDescriptor         blockDescriptor;
   vuint8                   blockNr;

   VOTAM_DUMMY_STATEMENT(partitionId);

   blockNr = vOtaM_GetLogicalBlockNumberOfModule(moduleId);

   /* Get block descriptor of module to sync */
   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      if (ApplFblInvalidateBlock(blockDescriptor) == kFblOk)
      {
         result = E_OK;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_ValidateModule()
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ValidateModule(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId)
{
   Std_ReturnType           result = E_NOT_OK;
   tBlockDescriptor         blockDescriptor;
   vuint8                   blockNr;

   VOTAM_DUMMY_STATEMENT(partitionId);

   blockNr = vOtaM_GetLogicalBlockNumberOfModule(moduleId);

   /* Get block descriptor of module to sync */
   if (FblLbtGetBlockDescriptorByNr(blockNr, &blockDescriptor) == kFblOk)
   {
      if (ApplFblValidateBlock(blockDescriptor) == kFblOk)
      {
         result = E_OK;
      }
   }

   return result;
}

/**********************************************************************************************************************
 * vOtaM_SwapPartition()
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SwapPartition(void)
{
   Std_ReturnType             result = E_NOT_OK;
   vOtaM_PartitionIdType      activePartitionId = 0u, inactivePartitionId = 0u;
   boolean                    activePartitionFound = FALSE, inactivePartitionFound = FALSE;
   vOtaM_PartitionIterType    partitionIdx;

   /* Find partitions marked as active and inactive */
   for (partitionIdx = 0u; partitionIdx < VOTAM_PARTITION_COUNT; partitionIdx++)
   {
      if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_ACTIVE) == VOTAM_PART_STATE_ACTIVE)
      {
         /* Store ID of active partition */
         activePartitionId = vOtaM_PartitionInfo[partitionIdx].Id; /* PRQA S 2983 */ /* MD_FblvOtaM_2983 */
         activePartitionFound = TRUE;
      }
      else if ((vOtaM_PartitionInfo[partitionIdx].State & VOTAM_PART_STATE_INACTIVE) == VOTAM_PART_STATE_INACTIVE)
      {
         /* Store ID of inactive partition */
         inactivePartitionId = vOtaM_PartitionInfo[partitionIdx].Id; /* PRQA S 2983 */ /* MD_FblvOtaM_2983 */
         inactivePartitionFound = TRUE; /* PRQA S 2983 */ /* MD_FblvOtaM_2983 */
      }
      else
      {
         /* Nothing to do here */
      }
   }

   /* PRQA S 2992, 2996 1 */ /* MD_FblvOtaM_2741_2742_2992_2996 */
   if ( (activePartitionFound == TRUE) && (inactivePartitionFound == TRUE) )
   {
      /* Perform swap between active and inactive partition */
      result = vOtaM_Appl_PerformSwap(inactivePartitionId, activePartitionId);
   }

   return result;
}

#define VOTAM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  ERROR CHECKS
 **********************************************************************************************************************/

#if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS > 0x02u)
# error "Error: Configurations with more than two variants are currently not supported."
#endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_FblvOtaM_0303_0306:
      Reason:     Addressing memory mapped registers or other hardware specific feature requires casting a pointer type to
                  an integral type. This is a usual pattern for MCAL (Micro Controller Abstraction Layer) software.
      Risk:       Unintended read or write access into memory location.
      Prevention: Code inspection focus on correct access to expected memory location.

   MD_FblvOtaM_2741_2742_2992_2996:
      Reason:     Controlling expression is not constant depending of configuration or usage of the macro.
                  The invariance is intended in this case.
      Risk:       If an expression is always constant, this is an indicator that this is unintended and possibly an error.
      Prevention: No prevention required.

   MD_FblvOtaM_2983:
      Reason:     The result of the operation or assignment is used for the swap operation.
      Risk:       No risk.
      Prevention: No prevention needed.

   MD_FblvOtaM_3218:
      Reason:     Since function scope static variables are discouraged by our coding style and the variable might get too
                  big to store on the stack, a variable with file scope is used.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblvOtaM_3415:
      Reason:     Side effect (conditional execution) is intended.
      Risk:       Unintended side effects.
      Prevention: Code is checked for unintended side effects by code inspection.

   MD_FblvOtaM_3673_3677:
      Reason:     The pointer is used as argument of a call back function. Even though the data is not
                  modified in the current implementation, the user might add code that needs to change the data which the
                  pointer addresses.
      Risk:       The data which the pointer addresses could be misused by user code.
      Prevention: Impact on user code has to be checked carefully.

   MD_FblvOtaM_3678:
      Reason:     Depending on the configuration the pointer is actually modified and can therefore not be a const pointer.
      Risk:       No risk.
      Prevention: No prevention required.

   MD_FblvOtaM_0314_MemCpy:
      Reason:     The copy function have a void pointer as a function parameter.
      Risk:       No risk, because the underlying vuint8 pointer type is known.
      Prevention: No prevention necessary.

   MD_FblvOtaM_0313_WDTriggerFctType:
      Reason:     Security module expects a watchdog handler with return type 'void'. The usage of a wrapper function is
                  avoided due to higher voted requirements for minimized stack and runtime usage applied on the code.
      Risk:       Potentially undefined behavior of the used compiler which usually leads to a warning or error during
                  compilation.
      Prevention: The respective functionality is part of integration testing and will hence be verified before delivery.

*/

/**********************************************************************************************************************
 *  END OF FILE: vOtaM.c
 *********************************************************************************************************************/
