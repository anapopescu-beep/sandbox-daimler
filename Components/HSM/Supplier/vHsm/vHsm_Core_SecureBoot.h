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
/*!        \file  vHsm_Core_SecureBoot.h
 *        \brief  Header file for the core driver
 *
 *      \details  Defines the public interface of the Core crypto driver.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_CORE_SECUREBOOT_H)
# define VHSM_CORE_SECUREBOOT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Types.h"
# include "vHsm_Cfg.h"
# include "vHsm_Api.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define VHSM_PROCESS_SEGMENT_LIST_EXTENDED_AVAILABLE                 STD_ON
# define VHSM_CORE_SECUREBOOTSLOTCMACSIZE                             (16u)

# if (VHSM_SECURE_BOOT == STD_ON)
#  define VHSM_SECUREBOOT_INVALID_VERJOBID                            (0xFFFFFFFFuL)
#  define vHsm_IsCompInternalOfSecureBootGroup(gIdx)                  ((vHsm_GetVerJobCompInternalOfSecureBootGroup(gIdx)) != VHSM_SECUREBOOT_INVALID_VERJOBID)
#  define vHsm_IsExternalSlOfSecureBootGroup(gIdx)                    ((vHsm_GetVerJobExternalSlOfSecureBootGroup(gIdx)) != VHSM_SECUREBOOT_INVALID_VERJOBID)

#  define vHsm_SecureBoot_GetSegmentPositionWithinGroup(sIdx, gIdx)   ((uint32)sIdx - (uint32)vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(gIdx))

#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
#   define vHsm_SecureBoot_GetStorageSizeOfGroupInfo(gIdx)            ((uint32)vHsm_GetStorageSizeOfSecureBootGroup(gIdx))
#   define vHsm_SecureBoot_GetStorageOfGroupInfo(gIdx)                (&vHsm_GetSecureBootStorage(vHsm_GetSecureBootStorageCrcStartIdxOfSecureBootGroup(gIdx)))
#   define vHsm_SecureBoot_GetCrcOfGroupInfo(gIdx)                    (vHsm_GetSecureBootStorage(vHsm_GetSecureBootStorageCrcStartIdxOfSecureBootGroup(gIdx)))
#   define vHsm_SecureBoot_GetGroupInfoOfGroupInfo(gIdx)              (vHsm_GetSecureBootStorage(vHsm_GetSecureBootStorageGroupInfoStartIdxOfSecureBootGroup(gIdx)))

#   if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
#    define vHsm_SecureBoot_GetSegmentPositionInsideGroup(sIdx)       ((uint32)(sIdx) - (uint32)vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(sIdx)))

#    define vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx)                ((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&vHsm_GetSecureBootStorage(\
                                                                      vHsm_GetSecureBootStorageSegInfoStartIdxOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(sIdx)) \
                                                                      + (3u*vHsm_SecureBoot_GetSegmentPositionInsideGroup(sIdx)) ))

#    define vHsm_SecureBoot_GetTagLengthOfGroupInfo(gIdx)             ((vHsm_GetSecureBootStorageTagEndIdxOfSecureBootGroup(gIdx) - vHsm_GetSecureBootStorageTagStartIdxOfSecureBootGroup(gIdx))*4u)
#    define vHsm_SecureBoot_GetAddressOfSegmentInfo(sIdx)             (*((P2VAR(P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR), AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx))[0]))
#    define vHsm_SecureBoot_GetSizeOfSegmentInfo(sIdx)                (*((P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx))[4]))
#    define vHsm_SecureBoot_GetModeOfSegmentInfo(sIdx)                (*((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx))[8]))
#    define vHsm_SecureBoot_GetSanctionOfSegmentInfo(sIdx)            (*((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx))[10]))
#    define vHsm_SecureBoot_GetReservedOfSegmentInfo(sIdx)            (*((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) )&(vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx))[11]))

#    define VHSM_SECUREBOOT_SEGMENT_INVALID_CRYPTOKEY                 (0xFFFFFFFFuL)
#    define vHsm_IsCryptoKeyOfSecureBootSegmentValid(sIdx)            (vHsm_GetCryptoKeyIdOfSecureBootSegment(sIdx) != VHSM_SECUREBOOT_SEGMENT_INVALID_CRYPTOKEY)

LOCAL_INLINE boolean *vHsm_SecureBoot_GetTagAvailablePtrOfSegmentInfo(uint32 sIdx) /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
{
  boolean *retVal;
  vHsm_SecureBootGroupIterType gIdx = vHsm_GetGroupIdxOfSecureBootSegment(sIdx);
  switch (vHsm_GetTagHandlingOfSecureBootGroup(gIdx))
  {
  case VHSM_GROUP_TAG:
    /* Information about tag availability is stored in first segment of the group */
    retVal = (P2VAR(boolean, AUTOMATIC, VHSM_APPL_VAR))(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(gIdx)))[9])); /* PRQA S 0310 */ /* MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
    break;
  case VHSM_PROCESSING_TAG: /* validation: require two segments when tag per processing! */
    if (vHsm_SecureBoot_GetModeOfSegmentInfo(sIdx) == VHSM_SEQUENTIAL)
    {
      /* Information about sequential tag availability is stored in first segment of the group */
      retVal = (P2VAR(boolean, AUTOMATIC, VHSM_APPL_VAR))(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(gIdx)))[9])); /* PRQA S 0310 */ /* MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
    }
    else
    {
      /* Information about parallel tag availability is stored in second segment of the group */
      retVal = (P2VAR(boolean, AUTOMATIC, VHSM_APPL_VAR))(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem((uint8)(vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(gIdx) + 1u)))[9])); /* PRQA S 0310 */ /* MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
    }
    break;
  default: /* VHSM_SEGMENT_TAG */
    /* Information about tag availability is stored in each segment */
    retVal = (P2VAR(boolean, AUTOMATIC, VHSM_APPL_VAR))(((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&(vHsm_SecureBoot_GetGetSegmentInfoMem(sIdx))[9])); /* PRQA S 0310 */ /* MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
    break;
  }

  return retVal;
}

#    define vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(sIdx)        (*vHsm_SecureBoot_GetTagAvailablePtrOfSegmentInfo(sIdx))

LOCAL_INLINE uint8* vHsm_SecureBoot_GetTagOfSegmentInfo(uint32 sIdx) /* PRQA S 3219 */ /* MD_VHSM_3219_INLINE_FUNCT */
{
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR)  retVal;
  vHsm_SecureBootGroupIterType gIdx = vHsm_GetGroupIdxOfSecureBootSegment(sIdx);

  /* GROUP TAG */
  retVal = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&vHsm_GetSecureBootStorage(vHsm_GetSecureBootStorageTagStartIdxOfSecureBootGroup(gIdx));

  if (vHsm_GetTagHandlingOfSecureBootGroup(gIdx) == VHSM_GROUP_TAG)
  {
    /* already set */
  }
  else if (vHsm_GetTagHandlingOfSecureBootGroup(gIdx) == VHSM_SEGMENT_TAG)
  {
    retVal = &retVal[vHsm_SecureBoot_GetSegmentPositionInsideGroup(sIdx)*vHsm_GetTagLengthOfSecureBootGroup(gIdx)];
  }
  else /* VHSM_PROCESSING_TAG */
  {
    if (vHsm_SecureBoot_GetModeOfSegmentInfo(sIdx) == VHSM_PARALLEL)
    {
      retVal = &retVal[vHsm_GetTagLengthOfSecureBootGroup(gIdx)];
    }
  }

  return retVal;
}
#   endif
#   if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
#    define vHsm_SecureBoot_GetSlHashOfGroupInfo(gIdx)                (&vHsm_GetSecureBootStorage(vHsm_GetSecureBootStorageSlHashStartIdxOfSecureBootGroup(gIdx)))
#    define vHsm_SecureBoot_GetSlInfoOfGroupInfo(gIdx)                (vHsm_GetSecureBootStorage(vHsm_GetSecureBootStorageSlInfoStartIdxOfSecureBootGroup(gIdx)))
#    define VHSMUPD_SECUREBOOT_SL_NO_HASH_AVAILABLE                   (0x00u)
#    define VHSMUPD_SECUREBOOT_SL_HASH_AVAILABLE                      (0x01u)
#   endif
#  endif
# endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
# if(VHSM_SECURE_BOOT == STD_ON)
typedef struct
{
  vHsm_SecureBootGroupIterType groupIdx;
  boolean isCyclicverification;
  boolean recovery;
  vHsm_Core_SecureBoot_VerMethodType verMethod;
}vHsm_Core_SecureBoot_QueueItemType;

typedef struct
{
  vHsm_Core_SecureBoot_QueueItemType queueItems[vHsm_GetQueueSizeOfSecureBoot()];
  uint32 queueTopIdx;
}vHsm_SecureBootQueueType;

#  define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(vHsm_SecureBootQueueType, VHSM_VAR_NOINIT) vHsm_SecureBootQueue;

#  define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_ProcessAllSegmentsOfGroup()
 *********************************************************************************************************************/
/*! \brief           Process group and all its segments
 *  \details         -
 *  \param[in]       groupIdx            Id of the object
 *  \param[in]       forceSequential     Flag that indicates if parallel segments of the group shall be forced to be processed sequentially
 *  \param[in,out]   infotype            Pointer to the secure boot info containing the information if it is a
 *                                     cyclic verification or if the segment shall be retried if it failed
 *  \return          E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_ProcessAllSegmentsOfGroup(
  vHsm_SecureBootGroupIterType groupIdx,
  boolean forceSequential,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) infotype);

/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureBoot()
 *********************************************************************************************************************/
/*! \brief       Dispatch the command to process a group or a segment
 *  \details     -
 *  \param[in]   objectId            Id of the object
 *  \param[out]  job                 Pointer to the job
 *  \param[in]   mode                Processing mode
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureBoot(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  Crypto_OperationModeType mode);

#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureBootConfirmation()
 *********************************************************************************************************************/
/*! \brief       Dispatch the command and perform the secure boot confirmation.
 *  \details     The provided segment list is evaluated, the signature is checked and validated.
 *  \param[in]   objectId            Id of the object
 *  \param[out]  job                 Pointer to the job
 *  \param[in]   mode                Processing mode
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureBootConfirmation(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_OperationModeType mode);
#  endif /* VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON */

#  if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureBootUpdate()
 *********************************************************************************************************************/
/*! \brief       Dispatch the command and perform the secure boot update.
 *  \details     The provided segment list is evaluated, the signature is checked and if valid, the secure boot segments
 *               inside the group will be updated.
 *               If E_OK is returned, the verifyPtr also must be checked which indicates the validity of the request.
 *  \param[in]   objectId            Id of the object
 *  \param[out]  job                 Pointer to the job
 *  \param[in]   mode                Processing mode
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureBootUpdate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  Crypto_OperationModeType mode);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformation()
 *********************************************************************************************************************/
/*! \brief       Process segment list information for secure boot update
 *  \details     -
 *  \param[in]   buffer          Buffer containing segment list information itself. Only segment lists with a size up to VHSM_MAX_SIZE_OF_SEGMENT_LIST are supported.
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformation(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformationExtended()
 *********************************************************************************************************************/
/*! \brief       Process segment list information for secure boot update
 *  \details     -
 *  \param[in]   buffer          Buffer containing segment list information with or without header.
 *  \param[in]   bufferLength    Input length in buffer
 *  \param[in]   isExtSl         Signalizes if the buffer contains a Sl with or without header
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformationExtended(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer,
  uint32 bufferLength,
  boolean isExtSl);
#  endif

#  if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON) && (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureSoftwareDownload()
 *********************************************************************************************************************/
/*! \brief       Dispatch the command and perform the secure software update
 *  \details     The provided data will be used for signature verification and CMAC generation.
 *               If the signature is valid, the information (address, length and cmac) of the segment is updated and persisted.
 *  \param[in]   objectId            Id of the object
 *  \param[out]  job                 Pointer to the job
 *  \param[in]   mode                Processing mode
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureSoftwareDownload(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job,
  Crypto_OperationModeType mode);
#  endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_Init()
 *********************************************************************************************************************/
/*! \brief       Initialize the secure boot
 *  \details     This function writes init values to the key storage after the key storage has been initialized by the
 *               LibCv. Nvm handling will be performed later.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_Init(void);

#  if (VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_AutostartGroups()
 *********************************************************************************************************************/
/*! \brief       Start the secure boot groups which are marked as autostart and where the autostart condition is met.
 *  \details     The sequential secure boot segments are directly processed and will block the startup until completely
 *               processed.
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_AutostartGroups(void);
#  endif

/**********************************************************************************************************************
 *  vHsm_Custom_SecureBootSanction_Callout()
 *********************************************************************************************************************/
/*! \brief       This callout is called when a segment has been detected as invalid and the sanction was specified to
 *               call this function.
 *  \details     -
 *  \param[in]       cryptoKeyId              Key id of the failed segment
 *  \param[in,out]   vHsm_SecureBootInfoPtr   Pointer to the secure boot info containing the information if it is a
 *                                            cyclic verification or if the segment shall be retried if it failed
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Custom_SecureBootSanction_Callout(
  uint32 cryptoKeyId,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr);

/**********************************************************************************************************************
 *  vHsm_Custom_IsSecureBootAllowAutostart_Callout()
 *********************************************************************************************************************/
/*! \brief       This callout is called to decide if the secure boot group shall be autostarted or not.
 *  \details     The index and Id are given to provide information which secure boot group is currently under decision.
 *  \param[in]   secureBootGroupIndex     Index of the secure boot group
 *  \param[in]   secureBootGroupId        Id of the secure boot group
 *  \return      TRUE  Autostart is allowed.
 *               FALSE Prevent the autostart of the group and its segments.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, VHSM_CODE) vHsm_Custom_IsSecureBootAllowAutostart_Callout(
  vHsm_SecureBootGroupIterType secureBootGroupIndex,
  uint32 secureBootGroupId);

/**********************************************************************************************************************
 *  vHsm_Custom_IsSecureBootAllowCyclicVerification_Callout()
 *********************************************************************************************************************/
/*! \brief       This callout is called to decide if the secure boot group shall be cyclically verified or not.
 *  \details     The index and Id are given to provide information which secure boot group is currently under decision.
 *  \param[in]   secureBootGroupIndex     Index of the secure boot group
 *  \param[in]   secureBootGroupId        Id of the secure boot group
 *  \return      TRUE   Cyclic verification is allowed.
 *               FALSE  Prevent the cyclic verification of the group and its segments.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, VHSM_CODE) vHsm_Custom_IsSecureBootAllowCyclicVerification_Callout(
  vHsm_SecureBootGroupIterType secureBootGroupIndex,
  uint32 secureBootGroupId);

/**********************************************************************************************************************
 *  vHsm_SecureBoot_Revision_Callout()
 *********************************************************************************************************************/
/*! \brief       This callout is called to decide if the segment list is valid with regard to the revision.
 *  \details     Note: Hashes of segments are not already checked for validity, when this callout is called.
 *               There are two locations where a revision is stored:
 *               1. After the Segment List as big endian uint32 when the segment list is not part of a external segment list.
 *               2. Inside the header of the external segment list.
 *
 *               The callout is called during the following situations:
 *               1. During the confirmation mode of a external segment list.
 *               2. During the secure boot update with a segment list.
 *               3. During secure boot when an new external segment list is detected and is verified
 *                  (When verification method of a group is set to CompareInternalTagWithRecovery or ExternalSegmentList)
 *  \param[in]   secureBootGroupId                Id of the secure boot group
 *  \param[in]   lastStoredRevision               Version of the currently stored segment list for the given group. The value is 0 when VHSM_STORAGE_METHOD_NONE is used.
 *  \param[in]   segmentTableStartPtr             Pointer to the start of the segment list
 *  \param[in]   segmentListLength                Length of the segment list
 *  \param[in,out]  newRevisionPtr                Pointer to the revision from the segment list.
 *                                                The value can be changed by the callout.
 *                                                The value will be stored to the data flash during secure boot update.
 *                                                The value will be 0 when there is no revision at the end of the segment list during secure boot update
 *  \return      TRUE   Version of segment table is accepted.
 *               FALSE  Prevent the secure boot update and reject segment table.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_Revision_Callout(
  uint32 secureBootGroupId,
  uint32 lastStoredRevision,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) segmentTableStartPtr,
  uint32 segmentListLength,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) newRevisionPtr);

#  if (VHSM_FIRMWARE_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_IsProcessing()
 *********************************************************************************************************************/
/*! \brief       Check if secure boot is currently processing
 *  \details     -
 *  \return      TRUE if secure boot is processing, otherwise FALSE
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(boolean, VHSM_CODE) vHsm_Core_SecureBoot_IsProcessing(void);
#  endif

#  if(VHSM_SECURE_BOOT_SEGMENT_SUCCESS_CALLOUT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SegmentSuccess_Callout()
 *********************************************************************************************************************/
/*! \brief       Callout which is called when a verification was successful.
 *  \details     -
 *  \param[in]   cryptoKeyId        Id of the successful segment
 *  \param[in,out]   vHsm_SecureBootInfoPtr   Pointer to the secure boot info containing the information if it is a
 *                                            cyclic verification or if the segment shall be retried if it failed
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_SecureBoot_SegmentSuccess_Callout(
  uint32 cryptoKeyId,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr);
#  endif

# endif

# if (VHSM_SECURE_BOOT == STD_ON)
#  if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockReadFromBlock()
 *********************************************************************************************************************/
/*! \brief     Copy the buffer provided by the NvM to the secure boot storage data memory.
 *  \details     -
 *  \param[in]   groupId        Id of the secureboot group
 *  \param[in]   NvMBuffer       Buffer of the NvM
 *  \return      E_OK if operation succeeded, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockReadFromBlock(
  vHsm_IdOfSecureBootGroupType groupId,
  P2CONST(void, AUTOMATIC, VHSM_APPL_DATA) NvMBuffer);

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockWriteToBlock()
 *********************************************************************************************************************/
/*! \brief     Copy secure boot storage data to the buffer provided by the NvM.
 *  \details     -
 *  \param[in]       groupId        Id of the secureboot group
 *  \param[in,out]   NvMBuffer       Buffer of the NvM
 *  \return          E_OK if operation succeeded, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockWriteToBlock(
  vHsm_IdOfSecureBootGroupType groupId,
  P2VAR(void, AUTOMATIC, VHSM_APPL_VAR) NvMBuffer);

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockInit()
 *********************************************************************************************************************/
/*! \brief       Initializes the secureboot storage.
 *  \details     -
 *  \param[in]   groupId        Id of the secureboot group
 *  \return      E_OK if operation succeeded, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockInit(
  vHsm_IdOfSecureBootGroupType groupId);

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockCallback()
 *********************************************************************************************************************/
 /*! \brief     Called by NvM in order to notify the Crypto driver that an
 *              asynchronous single block request has been finished.
 *  \details     -
 *  \param[in]   groupId        Id of the secureboot group
 *  \param[in]   ServiceId       Id of the service
 *  \param[in]   JobResult       Result of the operation
 *  \return      E_OK if operation succeeded, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockCallback(
  vHsm_IdOfSecureBootGroupType groupId,
  uint8 ServiceId,
  NvM_RequestResultType JobResult);
#  endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_MainFunction()
 *********************************************************************************************************************/
/*! \brief     Handles processing of parallel groups, cyclic verification and finish secureboot procedure.
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_MainFunction(void);

#  if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON) || (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetTag()
 *********************************************************************************************************************/
/*! \brief      Sets the tag of a secureboot segment.
 *  \details     Copies the provided tag to the destination segment. Also the tag available flag is set.
 *  \param[in]   segmentIdx        Index of the secureboot segment
 *  \param[in]   tag               Tag to copy
 *  \param[in]   tagLength         Length of tag to copy
 *  \param[in]   persist           If TRUE segment will be persisted.
 *  \return      E_OK if tag was successfully set, otherwise E_NOT_OK
 *  \pre         Only call this function for segments which are located in a group with compare internal tag.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetTag(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) tag,
  uint32 tagLength,
  boolean persist);
#  endif

#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/***********************************************************************************************************************
 *  vHsm_SecureBoot_CacheClearing_Callout()
 **********************************************************************************************************************/
/*! \brief       Callout to perform clearing of the cache of a specific memory location
 *  \details     This callout is called during confirmationCheck.
 *               At this point, the code flash my be modified and no reset happened in between.
 *               On some platforms clearing the cache manually from HSM before reading the contents may be needed
 *               because this may not be possible by the application core after modifying the flash.
 *  \param[in]     address              Address from where the cache shall be cleared
 *  \param[in]     length               Length of how many bytes shall be cleared.
 *                                      Otherwise value is 0xFFFFFFFF when the whole cache shall be cleared or if the address points to a segment list.
 *                                      If the address points to a segment list, the segment list can be used to check how many bytes shall be cleared.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_SecureBoot_CacheClearing_Callout(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) address,
  uint32 length);

/***********************************************************************************************************************
 *  vHsm_SecureBoot_PerformRecovery_Callout()
 **********************************************************************************************************************/
/*! \brief       Callout to check if recovery shall be performed by checking the external segment list of the group
 *  \details     This can either happen when no tag is available like on the first startup, or when the tag does not match the one currently stored in the data flash.
 *  \param[in]     groupIdx             GroupIdx which is checked
 *  \param[in]     recoveryReason       Reason why a check with an external segment list might be needed
 *  \pre         -
 *  \return      TRUE if recovery shall be performed, otherwise FALSE
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(boolean, VHSM_CODE) vHsm_SecureBoot_PerformRecovery_Callout(
  uint32 groupIdx,
  vHsm_SecureBootRecoveryReasonType recoveryReason);

#  endif

# endif /* (VHSM_SECURE_BOOT == STD_ON) */

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_CORE_SECUREBOOT_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Core_SecureBoot.h
 *********************************************************************************************************************/
