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
/**        \file  vOtaM.h
 *        \brief  vOtaM header file
 *
 *      \details  Header file for public API implementations
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  02.00.00  2019-02-20  visrr   ESCAN00102693 OtaM Extended/Mixed use case
 *  02.01.00  2019-08-12  visdlm  ESCAN00104004 Added support for data processing (decryption)
 *  02.01.01  2019-09-25  visrie  ESCAN00104343 Fixed rollback handling
 *  02.02.00  2019-11-25  visrie  ESCAN00104956 Added programming attempt counter handling
 *                                ESCAN00105034 Moved ReadProcessing functionality to appl code
 *  02.02.01  2020-02-07  visrcn  ESCAN00105233 Variant processing perform incorrectly by the vOtaM.
 *  02.02.02  2020-02-12  visrie  ESCAN00105634 Fixed write length handling in OtaM_CopyModule
 *  02.02.03  2020-02-12  visrie  ESCAN00105787 Fixed ReadProcessing issue
 *  02.03.00  2020-03-31  visrie  FBL-1337      Added getter function for source partition
 *  02.03.01  2020-05-26  visrie  ESCAN00106104 ActivationPending flag not removed for implicit rollback of
 *                                               ActivePartition
 *                                ESCAN00105807 Implicit rollback triggered by failed swap may fail
 *  03.00.00  2020-06-09  visrie  FBL-1363      Extended API vOtaM_SyncPartition, added hooks before partition/module
 *                                               validation.
 *  03.01.00  2020-07-13  visrie  FBL-2021      Corrected behavior for setting new partition/module revision, added
 *                                               support for sync with only two partitions
 *                                ESCAN00106839 Fixed preprocessor switches
 *  03.02.00  2020-07-17  visrie  FBL-1487      Provide default implementation for basic/extended swap
 *  03.03.00  2020-09-24  visrie  FBL-1928      Added support for SMH5
 *  03.04.00  2020-09-29  visrie  FBL-2064      Added new configuration callouts
 *  03.05.00  2020-10-08  visrie  FBL-1611      Added support for Safe-Swap
 *  03.05.01  2021-01-21  visrie  ESCAN00108339 Programming attempt counter is not correctly evaluated
 *  03.06.00  2021-01-28  vistbe  FBL-2836      Implement new function Swap active and inactive partition
 *  03.06.01  2021-04-08  vishor  ESCAN00107836 Modules are not synced
 *                                FBL-3021      Added/adapted MemMap sections
 *  03.06.02  2021-07-14  vishor  ESCAN00109491 Feature remaining swap attempts does not work
 *                                ESCAN00109586 Compiler warning: Incorrect fixed size parameter used
 *  03.06.03  2021-07-15  vishor  ESCAN00109581 Erase/write/read requests might be rejected
 *  03.07.00  2022-07-05  visjdn  FBL-5465      Extend vOtaM_CopyModule API and provide APIs to get active/inactive/backup
 *                                               partition IDs
 *  03.08.00  2022-07-13  vismix  FBL-5385      Support of LbtAccess
 *  03.09.00  2022-07-22  vismix  FBL-4812      Add better support for partition handling
 *  03.09.01  2022-12-10  visjdn  ESCAN00112830 Flash driver is not de-initialized after OTA swap
 *********************************************************************************************************************/

#if !defined (VOTAM_H)
# define VOTAM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vOtaM_Types.h"
# include "vOtaM_CfgTypes.h"
# include "vOtaM_Cfg.h"
# include "vOtaM_Lcfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblLib_vOtaM CQComponent : Implementation */
# define VSOTAM_SW_MAJOR_VERSION             (0x03u)
# define VSOTAM_SW_MINOR_VERSION             (0x09u)
# define VSOTAM_SW_PATCH_VERSION             (0x01u)

/* vSwUpdM_PartitionStateType */
# define VOTAM_PART_STATE_UNDEFINED          (vOtaM_PartitionStateType)(0x00u)     /*!< Partition State: Undefined */
# define VOTAM_PART_STATE_ACTIVE             (vOtaM_PartitionStateType)(1u << 0u)  /*!< Partition State: Active */
# define VOTAM_PART_STATE_INACTIVE           (vOtaM_PartitionStateType)(1u << 1u)  /*!< Partition State: Inactive */
# define VOTAM_PART_STATE_BACKUP_TARGET      (vOtaM_PartitionStateType)(1u << 2u)  /*!< Partition State: Backup target */
# define VOTAM_PART_STATE_BACKUP_SOURCE      (vOtaM_PartitionStateType)(1u << 3u)  /*!< Partition State: Backup source */
# define VOTAM_PART_STATE_ACTIVATION_PENDING (vOtaM_PartitionStateType)(1u << 4u)  /*!< Partition State: Activation pending */

/* Activation state parameter for vOtaM_ActivateInactivePartition */
# define VOTAM_ACTIVATION_STATE_USE_PARTITION         1u
# define VOTAM_ACTIVATION_STATE_ACTIVATE_PARTITION    2u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

# define vOtaM_OpenPartitionActive()               vOtaM_OpenPartition(vOtaM_Part_Role_Active)
# define vOtaM_OpenPartitionInactive()             vOtaM_OpenPartition(vOtaM_Part_Role_Inactive)
# define vOtaM_OpenPartitionBackup()               vOtaM_OpenPartition(vOtaM_Part_Role_Backup)
# define vOtaM_IsOpenedPartitionOfRoleActive()     vOtaM_IsOpenedPartitionOfRole(vOtaM_Part_Role_Active)
# define vOtaM_IsOpenedPartitionOfRoleInactive()   vOtaM_IsOpenedPartitionOfRole(vOtaM_Part_Role_Inactive)
# define vOtaM_IsOpenedPartitionOfRoleBackup()     vOtaM_IsOpenedPartitionOfRole(vOtaM_Part_Role_Backup)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* vOtaM partition-role definitions */
typedef enum
{
   vOtaM_Part_Role_Active,
   vOtaM_Part_Role_Inactive,
   vOtaM_Part_Role_Backup
} vOtaM_PartitionRoleType;

/* Processing state of module */
typedef enum
{
   vOtaM_State_Unintialized,
   vOtaM_State_Initialized,
   vOtaM_State_OtaRequest,
   vOtaM_State_SwapProcessing,
   vOtaM_State_Rollback
} vOtaM_StateType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VOTAM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * vOtaM_GetState
 *********************************************************************************************************************/
/*! \brief       Returns current vOtaM state.
 *  \return      Current state of vOtaM.
 *  \pre         vOtaM_InitMemory was called
 *********************************************************************************************************************/
vOtaM_StateType vOtaM_GetState(void);

# if (VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS == 0x02u)
/**********************************************************************************************************************
 * vOtaM_GetActiveVariant
 *********************************************************************************************************************/
/*! \brief       Returns currently active vMemAccM variant.
 *  \return      vMemAccM variant which is currently active in vOtaM
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
vMemAccM_VariantIdType vOtaM_GetActiveVariant(void);

#  if defined( VOTAM_ENABLE_SET_VARIANT_API )
/**********************************************************************************************************************
 * vOtaM_SetActiveVariant
 *********************************************************************************************************************/
/*! \brief       Sets active vMemAccM variant.
 *  \details     Warning: changes internal behavior of OtaM. Use with care.
 *  \param[in]   variant       variant id to set
 *  \return      E_OK          variant set successfully
 *  \return      E_NOT_OK      invalid variant id
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetActiveVariant(vMemAccM_VariantIdType variant);
#  endif /* VOTAM_ENABLE_SET_VARIANT_API */
# endif /* VMEMACCM_VARIANT_NROFAVAILABLEVARIANTS */

/**********************************************************************************************************************
 * vOtaM_GetSourcePartition
 *********************************************************************************************************************/
/*! \brief       Returns current source partition.
 *  \return      Source partition used for SWAP/rollback operation.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
vOtaM_PartitionInfoType vOtaM_GetSourcePartition(void);

/**********************************************************************************************************************
 * vOtaMGetPartitionByAddrAreaId()
 *********************************************************************************************************************/
/*! \brief       Returns a partition based on provided address area id
 *  \param[in]   addrAreaId    Address area id.
 *  \param[out]  partition     The partition.
 *  \return      E_OK          partition was found.
 *  \return      E_NOT_OK      partition was not found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaMGetPartitionByAddrAreaId(vMemAccM_AddressAreaIdType addrAreaId, vOtaM_PartitionInfoType** partition);

/**********************************************************************************************************************
 * vOtaMGetModuleByLogicalBlockNumber()
 *********************************************************************************************************************/
/*! \brief       Returns module id based on provided logical block number
 *  \param[in]   bn            Logical block number.
 *  \param[out]  moduleId      The module id.
 *  \return      E_OK          Id was found.
 *  \return      E_NOT_OK      Id was not found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaMGetModuleByLogicalBlockNumber(tFblLbtBlockNr bn, vOtaM_ModuleIdType* moduleId);

/**********************************************************************************************************************
 * vOtaM_GetBackupPartitionId
 *********************************************************************************************************************/
/*! \brief       Returns backup partition Id
 *  \param[out]  partitionId   The backup partition Id.
 *  \return      E_OK          Partition Id was found.
 *  \return      E_NOT_OK      Partition Id was not found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetBackupPartitionId(vOtaM_PartitionIdType* partitionId);

/**********************************************************************************************************************
 * vOtaM_GetInactivePartitionId
 *********************************************************************************************************************/
/*! \brief       Returns inactive partition Id
 *  \param[out]  partitionId   The inactive partition Id.
 *  \return      E_OK          Partition Id was found.
 *  \return      E_NOT_OK      Partition Id was not found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetInactivePartitionId(vOtaM_PartitionIdType* partitionId);

/**********************************************************************************************************************
 * vOtaM_GetActivePartitionId
 *********************************************************************************************************************/
/*! \brief       Returns active partition Id
 *  \param[out]  partitionId   The active partition Id.
 *  \return      E_OK          Partition Id was found.
 *  \return      E_NOT_OK      Partition Id was not found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetActivePartitionId(vOtaM_PartitionIdType* partitionId);

/**********************************************************************************************************************
 * vOtaM_IsModuleInPartition()
 *********************************************************************************************************************/
/*! \brief       Determines if specified module is part of the partition with the given id.
 *  \param[in]   moduleId      The module id of the module which shall be checked.
 *  \param[in]   partitionId   Partition id which shall be checked.
 *  \return      E_OK          Module is part of partition.
 *  \return      E_NOT_OK      Module is not part of partition.
 *  \pre         vOtaM_InitMemory was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_IsModuleInPartition(vOtaM_ModuleIdType moduleId, vOtaM_PartitionIdType partitionId);

/**********************************************************************************************************************
 *  vOtaM_InitMemory
 *********************************************************************************************************************/
/*! \brief       Initialize module memory with default values
 *  \pre         First function to call of this module
 *********************************************************************************************************************/
void vOtaM_InitMemory(void);

/**********************************************************************************************************************
 *  vOtaM_Init
 *********************************************************************************************************************/
/*! \brief       Initialize partition and module states
 *  \details     Determines meta data of partitions and modules. Determines swap and source partition and if
 *               an activation request is pending. Also sets the currently active vMemAccM variant.
 *  \return      E_OK      Initialization was successful
 *  \return      E_NOT_OK  Initialization failed
 *  \pre         vOtaM_InitMemory was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_Init(void);

/**********************************************************************************************************************
 * vOtaM_CheckOtaRequest
 *********************************************************************************************************************/
/*! \brief       Checks whether OTA/activation request is pending
 *  \details     This check loops over configured partitions and their states. If at least one partition was set to
 *               activation pending a later call of vOtaM_Main function will result in partition swap.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
void vOtaM_CheckOtaRequest(void);

/**********************************************************************************************************************
 * vOtaM_ActivateInactivePartition()
 *********************************************************************************************************************/
/*! \brief       Sets the inactive partition as working area for memory operations.
 *  \param[out]  part          the inactive partition.
 *  \param[in]   activationState VOTAM_ACTIVATION_STATE_USE_PARTITION: use inactive partition state
 *  \param[in]   activationState VOTAM_ACTIVATION_STATE_ACTIVATE_PARTITION: activate inactive partition state
 *  \return      E_OK          inactive partition found.
 *  \return      E_NOT_OK      inactive partition could not be found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ActivateInactivePartition(vOtaM_PartitionInfoType* part, vuint8 activationState);

/**********************************************************************************************************************
 * vOtaM_ActivatePartition()
 *********************************************************************************************************************/
/*! \brief       Sets the partition as working area for memory operations.
 *  \param[out]  part          the partition.
 *  \param[in]   activationState VOTAM_ACTIVATION_STATE_USE_PARTITION: use inactive partition state
 *  \param[in]   activationState VOTAM_ACTIVATION_STATE_ACTIVATE_PARTITION: activate inactive partition state
 *  \return      E_OK          partition found.
 *  \return      E_NOT_OK      partition could not be found.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ActivatePartition(vOtaM_PartitionIdType partId, vOtaM_PartitionInfoType* part, vuint8 activationState);

/**********************************************************************************************************************
 * vOtaM_Main
 *********************************************************************************************************************/
/*! \brief       Perfoms a swap/sync if activation pending is set. If sync fails, attempts to roll back
 *  \pre         vOtaM_CheckOtaRequest was called
 *********************************************************************************************************************/
void vOtaM_Main(void);

# if defined( VOTAM_ENABLE_SYNC_PARTITION )
/**********************************************************************************************************************
 *  vOtaM_SyncPartition()
 *********************************************************************************************************************/
/*! \brief       Synchronizes the swappable partitions.
 *  \details     Copies data source and destination partition, manage setting of NV data and verification.
 *  \param[in]   srcPartitionId    Id of the source partition.
 *  \param[in]   destPartitionId   Id of the destination partition.
 *  \return      E_OK          The synchronization succeeded.
 *  \return      E_NOT_OK      The synchronization failed.
 *  \pre         vOtaM must be in correct state. (E_NOT_OK, if not)
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SyncPartition(vOtaM_PartitionIdType srcPartitionId, vOtaM_PartitionIdType destPartitionId);
# endif /* VOTAM_ENABLE_SYNC_PARTITION */

/**********************************************************************************************************************
 *  vOtaM_CopyModule()
 *********************************************************************************************************************/
/*! \brief       Copy one module from source to destination partition.
 *  \param[in]   addr              Virtual address of module to copy
 *  \param[in]   length            Length to copy
 *  \param[in]   srcPartitionId    Id of the source partition.
 *  \param[in]   destPartitionId   Id of the destination partition.
 *  \return      E_OK      Copying successful
 *  \return      E_NOT_OK  Error during copying
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_CopyModule(tFblAddress addr, tFblLength length, vOtaM_PartitionIdType srcPartitionId, vOtaM_PartitionIdType destPartitionId);

/**********************************************************************************************************************
 * vOtaM_OpenPartition()
 *********************************************************************************************************************/
/*! \brief       Opens the partition provided by role.
 *  \param[in]   role          The role of partition to be opened.
 *  \return      E_OK          Partition opened successfully
 *  \return      E_NOT_OK      Partition could not be opened
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_OpenPartition(vOtaM_PartitionRoleType role);

/**********************************************************************************************************************
 * vOtaM_IsOpenedPartitionOfRole()
 *********************************************************************************************************************/
/*! \brief       Checks if currently opened partition is of provided role.
 *  \param[in]   role          The role to be checked if the currently opened partition is part of
 *  \return      E_OK          Currently opened partition is of selected role.
 *  \return      E_NOT_OK      Currently opened partition is not of selected role.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_IsOpenedPartitionOfRole(vOtaM_PartitionRoleType role);

/**********************************************************************************************************************
 * vOtaM_GetRoleOfOpenedPartition()
 *********************************************************************************************************************/
/*! \brief       Provides the role of currently opened partition.
 *  \return      Role of currently opened partition.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
vOtaM_PartitionRoleType vOtaM_GetRoleOfOpenedPartition(void);

/**********************************************************************************************************************
 * vOtaM_GetPartitionIdByRole()
 *********************************************************************************************************************/
/*! \brief       Provides the partition-ID of selected role.
 *  \param[in]   role   The role the partition should have.
 *  \param[out]  partId The partition-ID
 *  \return      E_OK          Getting partition-ID by role was successfully
 *  \return      E_NOT_OK      Getting partition-ID by role was not successfully
 *********************************************************************************************************************/
Std_ReturnType vOtaM_GetPartitionIdByRole(vOtaM_PartitionRoleType role, vOtaM_PartitionIdType* partId);

/**********************************************************************************************************************
 * vOtaM_SetActivePartitionValid()
 *********************************************************************************************************************/
/*! \brief       Validates the active partition.
 *  \return      E_OK          Setting active partition to valid was successful.
 *  \return      E_NOT_OK      Setting active partition to valid failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetActivePartitionValid(void);

/**********************************************************************************************************************
 * vOtaM_SetPartitionValid()
 *********************************************************************************************************************/
/*! \brief       Validates the given partition.
 *  \param[in]   partitionId   Id of the partition.
 *  \return      E_OK          Setting given partition to valid was successful.
 *  \return      E_NOT_OK      Setting given partition to valid failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetPartitionValid(vOtaM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * vOtaM_SetActivePartitionInvalid()
 *********************************************************************************************************************/
/*! \brief       Invalidates the active partition.
 *  \return      E_OK          Setting active partition to invalid was successful.
 *  \return      E_NOT_OK      Setting active partition to invalid failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetActivePartitionInvalid(void);

/**********************************************************************************************************************
 * vOtaM_SetPartitionInvalid()
 *********************************************************************************************************************/
/*! \brief       Invalidates the given partition.
 *  \param[in]   partitionId   Id of the partition.
 *  \return      E_OK          Setting given partition to invalid was successful.
 *  \return      E_NOT_OK      Setting given partition to invalid failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetPartitionInvalid(vOtaM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * vOtaM_SetNewPartitionRevision()
 *********************************************************************************************************************/
/*! \brief       Returns next valid partition revision for requested partition
 *  \details     There are different use cases for next revision number:
 *               - Download new software                 - Revision must be increased
 *               - Synchronization with other partitions - Partition number sahll be synchronized
 *  \param[in]   PartitionId     Identifier of the partition.
 *  \return      E_OK          new revision set successfully.
 *  \return      E_NOT_OK      revision could not be set.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetNewPartitionRevision(void);

/**********************************************************************************************************************
 * vOtaM_SetModuleValid()
 *********************************************************************************************************************/
/*! \brief       Validates the given module in the given partition.
 *  \param[in]   partitionId   Id of the partition.
 *  \param[in]   moduleId      Id of the module.
 *  \return      E_OK          Setting given module to valid was successful.
 *  \return      E_NOT_OK      Setting given module to valid failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetModuleValid(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);

/**********************************************************************************************************************
 * vOtaM_SetModuleInvalid()
 *********************************************************************************************************************/
/*! \brief       Invalidates the given module in the given partition.
 *  \param[in]   partitionId   Id of the partition.
 *  \param[in]   moduleId      Id of the module.
 *  \return      E_OK          Setting given module to invalid was successful.
 *  \return      E_NOT_OK      Setting given module to invalid failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetModuleInvalid(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);

/**********************************************************************************************************************
 * vOtaM_SetNewModuleRevision()
 *********************************************************************************************************************/
/*! \brief       Sets next valid module revision for requested module in a given partition
 *  \details     There are different use cases for next revision number:
 *               - Download new software                 - Revision must be increased
 *               - Synchronization with other partitions - Partition number shall be synchronized
 *  \param[in]   moduleId      Identifier of the module.
 *  \return      E_OK          new revision set successfully.
 *  \return      E_NOT_OK      revision could not be set.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SetNewModuleRevision(vOtaM_ModuleIdType moduleId);

/**********************************************************************************************************************
 * vOtaM_InvalidatePartition()
 *********************************************************************************************************************/
/*! \brief       Invalidates the given partition.
 *  \details     This is a default implementation, which uses the Bootloader API ApplFblInvalidateApp.
 *  \param[in]   partitionId   Id of the partition.
 *  \return      E_OK          Invalidation the module was successful.
 *  \return      E_NOT_OK      Invalidating the module failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_InvalidatePartition(vOtaM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * vOtaM_ValidatePartition()
 *********************************************************************************************************************/
/*! \brief       Validates the given partition.
 *  \details     This is a default implementation, which uses the Bootloader API ApplFblValidateApp.
 *  \param[in]   partitionId   Id of the partition.
 *  \return      E_OK          Validation the partition was successful.
 *  \return      E_NOT_OK      Validating the partition failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ValidatePartition(vOtaM_PartitionIdType partitionId);

/**********************************************************************************************************************
 * vOtaM_InvalidateModule()
 *********************************************************************************************************************/
/*! \brief       Invalidates the given module.
 *  \details     This is a default implementation, which uses the Bootloader API ApplFblInvalidateBlock.
 *  \param[in]   partitionId   Id of the partition.
 *  \param[in]   moduleId      Id of the module.
 *  \return      E_OK          Invalidation the module was successful.
 *  \return      E_NOT_OK      Invalidating the module failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_InvalidateModule(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);

/**********************************************************************************************************************
 * vOtaM_ValidateModule()
 *********************************************************************************************************************/
/*! \brief       Validates the given module.
 *  \details     This is a default implementation, which uses the Bootloader API ApplFblValidateBlock.
 *  \param[in]   partitionId   Id of the partition.
 *  \param[in]   moduleId      Id of the module.
 *  \return      E_OK          Validation the module was successful.
 *  \return      E_NOT_OK      Validating the module failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_ValidateModule(vOtaM_PartitionIdType partitionId, vOtaM_ModuleIdType moduleId);

/**********************************************************************************************************************
 * vOtaM_SwapPartition()
 *********************************************************************************************************************/
/*! \brief       Swaps active and inactive partitions.
 *  \details     This functions perform a swap between the active and inactive partition by either
 *               - Performing a hardware swap (basic use-case) or
 *               - Copying the inactive partition into the active partition (extended use-case)
 *  \return      E_OK          Partition swapping was successful.
 *  \return      E_NOT_OK      Partition swapping failed.
 *  \pre         vOtaM_Init was called
 *********************************************************************************************************************/
Std_ReturnType vOtaM_SwapPartition(void);

# define VOTAM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* VOTAM_H */

/**********************************************************************************************************************
 *  END OF FILE: vOtaM.h
 *********************************************************************************************************************/
