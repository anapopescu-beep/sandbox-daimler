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
/*!        \file  vHsm_Core_SecureBoot.c
 *        \brief  Source file for the core driver
 *
 *      \details  Implements the driver API which provides basic functionalities like secure boot or reading the version
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_CORE_SECUREBOOT_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm_Core.h"
#include "vHsm.h"
#include "vHsm_ApiInternal.h"
#include "vHsm_Nvm.h"
#include "vHsm_KeyM.h"
#include "vHsm_Trace.h"
#include "vHsm_Core_Custom.h"

#include "vHsm_Hal.h"
#include "vHsm_Custom.h"

#include "CryIf_Cfg.h"
#include "vstdlib.h"
#include "vHsm_JobProcessor.h"

#include "SchM_vHsm.h"
#if (VHSM_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif /* (VHSM_DEV_ERROR_DETECT == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#define VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH                        (16u)
#define VHSM_SECUREBOOT_SL_REVISION_LENGTH                            (4u)
#define VHSM_SECUREBOOT_SL_SIGNATURELENGTH_LENGTH                     (4u)
#define VHSM_SECUREBOOT_SL_HEADER_LENGTH                              (VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH + VHSM_SECUREBOOT_SL_REVISION_LENGTH)

#define VHSM_HASH_SIZE                                                (32u)
#define VHSM_CMAC_SIZE                                                (16u)
#define VHSM_SIZE_OF_SEGMENT                                          (10u + VHSM_HASH_SIZE)
#define VHSM_SIZE_OF_SEGMENTS                                         (VHSM_MAX_SEGMENTS_PER_GROUP * VHSM_SIZE_OF_SEGMENT)
#define VHSM_SEGMENT_LIST_INFO                                        (6u)
#define VHSM_MAX_SIZE_OF_SEGMENT_LIST                                 (VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SEGMENT_LIST_INFO + VHSM_SIZE_OF_SEGMENTS)

/* SecureBoot confirmationmode */
#define VHSM_CONFIRMATION_IS_SWAPPED_TRUE                             (TRUE)
#define VHSM_CONFIRMATION_IS_SWAPPED_LENGTH                           (1u)
#define VHSM_SECUREBOOT_SL_GROUPID_LENGTH                             (4u)

#define VHSM_CONFIRMATION_READ_INACTIVE_TRUE                          (1u) /* (TRUE) */
#define VHSM_CONFIRMATION_READ_INACTIVE_LENGTH                        (1u)

/* Get Information of SecureBootGroup */
#define VHSM_SECUREBOOTGROUP_INVALID_VERIFICATIONJOB_PATTERN          (0xFFFFFFFFu)

#define VHSM_SECUREBOOT_ATOMICFLAGS_START                             (1u)
#define VHSM_SECUREBOOT_ATOMICFLAGS_UPDATE                            (2u)
#define VHSM_SECUREBOOT_ATOMICFLAGS_FINISH                            (4u)
#define VHSM_SECUREBOOT_ATOMICFLAGS_SINGLECALL                        (VHSM_SECUREBOOT_ATOMICFLAGS_START|VHSM_SECUREBOOT_ATOMICFLAGS_UPDATE|VHSM_SECUREBOOT_ATOMICFLAGS_FINISH)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if (VHSM_SECURE_BOOT == STD_ON)
typedef struct
{
  uint32  address;
  uint32  length;
  uint8   mode;
  uint8   SLHash[VHSM_HASH_SIZE];
  uint32  hashLength;
}vHsm_SecureBoot_SegmentType;

typedef struct
{
  vHsm_SecureBootSegmentIterType segmentIdx;
  uint8 mode;
  uint8 sanction;
  boolean tagAvailable;
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) tagPtr;
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) address;
  uint32 size;
  uint32 processingLength;
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) processsingPtr;
}vHsm_SecureBoot_SegmentInfoType;

typedef struct
{
  Crypto_OperationModeType state;
  uint32 alreadyProcessed;
  vHsm_SecureBoot_SegmentInfoType currentSegmentInfo;
  vHsm_SecureBoot_SegmentInfoType segmentUsedForTag;
  boolean pendingStart;
  boolean pendingFinish;
  boolean inProgress;
  vHsm_Core_SecureBoot_VerMethodType verMethod;
}vHsm_SecureBootrework_ParallelWorkspaceType;

typedef struct
{
  boolean forceSequential;
  boolean pendingStart;
  boolean pendingFinish;
  uint8 atomicFlags;
  vHsm_SecureBoot_SegmentInfoType segmentInfo;
  vHsm_SecureBoot_SegmentInfoType segmentUsedForTag;
  uint8 computedTag[VHSM_MAX_TAG_SIZE_OR_SHA256];
  uint32 tagLength;
  vHsm_Core_SecureBoot_VerMethodType verMethod;
}vHsm_SecureBoot_SequentialWorkspaceType;

typedef struct
{
  uint32                                    segmentlistRevision;
  uint32                                    groupId;
  uint32                                    revision;
  uint16                                    nSegments;
  boolean                                   isSlValid;
  uint8                                     extSlHash[VHSM_HASH_SIZE];
  vHsm_SecureBoot_SegmentType               segments[VHSM_MAX_SEGMENTS_PER_GROUP];
}vHsm_SecureBoot_ExtSegmentListType;

#endif /* (VHSM_SECURE_BOOT == STD_ON) */

extern const char * string_TagHandling[3];
const char * string_TagHandling[3] =
{
  "VHSM_GROUP_TAG     \0",
  "VHSM_PROCESSING_TAG\0",
  "VHSM_SEGMENT_TAG   \0"
};
extern const char * string_Processing[3];
const char * string_Processing[3] =
{
  "VHSM_NONE      \0",
  "VHSM_PARALLEL  \0",
  "VHSM_SEQUENTIAL\0"
};

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#if (VHSM_SECURE_BOOT == STD_ON)

# define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VHSM_LOCAL VAR(vHsm_SecureBootrework_ParallelWorkspaceType, VHSM_VAR_NOINIT) vHsm_Core_SecureBoot_Workspace;
VAR(vHsm_SecureBootQueueType, VHSM_VAR_NOINIT) vHsm_SecureBootQueue;
# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
VHSM_LOCAL VAR(vHsm_SecureBootGroupIterType, VHSM_VAR_NOINIT)  vHsm_SecureBoot_CurrentCyclicGroupIdx; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
# endif

# if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
VHSM_LOCAL VAR(vHsm_SecureBoot_ExtSegmentListType, VHSM_VAR_NOINIT) vHsm_SecureBoot_ExtSegmentList;
# endif

# define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
#  if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
VHSM_LOCAL VAR(boolean, VHSM_VAR_NOINIT) vHsm_SecureSoftwareDownload_IsFirstUpdate; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
#  endif
# endif

# define VHSM_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_VAR_NOINIT_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VHSM_LOCAL VAR(uint32, VHSM_VAR_NOINIT) vHsm_SecureBoot_GroupId; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
#  if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
VHSM_LOCAL VAR(uint32, VHSM_VAR_NOINIT) vHsm_SecureSoftwareDownload_Address; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
VHSM_LOCAL VAR(uint32, VHSM_VAR_NOINIT) vHsm_SecureSoftwareDownload_Size; /* PRQA S 3218 */ /* MD_VHSM_3218_WORKSPACE_VAR */
#  endif
# endif

# define VHSM_STOP_SEC_VAR_NOINIT_32BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define VHSM_START_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON) || (VHSM_SECURE_BOOT_UPDATE == STD_ON)
/* Group Segment List = External segment list */
VHSM_LOCAL CONST(uint8, VHSM_CONST) vHsm_SecureBoot_GSL_Header_Pattern[VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH] = { 0x56u, 0x45u, 0x43u, 0x5fu, 0x47u, 0x53u, 0x4cu, 0x5fu, 0x48u, 0x53u, 0x4du, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u }; /* PRQA S 3218 */ /* MD_VHSM_ONE_USAGE */

/* Segment List Lookup = List of segment list locations */
/* 0x56u, 0x45u, 0x43u, 0x5fu, 0x53u, 0x4cu, 0x4cu, 0x5fu, 0x48u, 0x53u, 0x4du, 0x00u, 0x00u, 0x00u, 0x00u, 0x01u */
# endif
# define VHSM_STOP_SEC_CONST_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* (VHSM_SECURE_BOOT == STD_ON) */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_SECURE_BOOT == STD_ON)

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_CheckGroupValidity()
 *********************************************************************************************************************/
/*! \brief       Check if secureboot result of group is valid.
 *  \details     -
 *  \param[in]   groupIdx                    Idx of the group.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_CheckGroupValidity(
  vHsm_SecureBootGroupIterType groupIdx);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_IsMemEqual()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Compare memory in a secure manner to prevent timing attacks
 * \details     This function does not break in case a difference is found. It will continue to check all remaining bytes.
 * \param[in]   ptr1     Pointer to an array
 * \param[in]   ptr2     Pointer to an array which shall be compared to the one provided in ptr1
 * \param[in]   length   Number of bytes to compare
 * \return      TRUE if the provided arrays are the same, otherwise FALSE.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Core_SecureBoot_IsMemEqual(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptr1,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptr2,
  uint32 length);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_PerformSanction()
 *********************************************************************************************************************/
/*!
 *
 * \brief       Perform a sanction, when a secure boot slot has been detected as invalid.
 * \details     -
 * \param[in]       segmentIdx               Secure boot segment which shall be searched for a sanction
 * \param[in,out]   vHsm_SecureBootInfoPtr   Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 * \return      E_OK if the sanction has been performed correctly or no sanction was specified. Otherwise E_NOT_OK
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_PerformSanction(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetSegmentInfo()
 *********************************************************************************************************************/
/*! \brief       Get the basic information of a segment needed for secure boot
 *  \details     Segment index has to be provided to the function via the info structure.
 *  \param[in,out]   segmentInfoPtr         Pointer to the segment info structure
 *  \param[in,out]   extSegmentListPtr      Pointer to the external segment list structure to store the parsed data
 *  \param[in]       verMethod              Verification method which is used for this call (CompareInternal or ExternalSegmentList)
 *  \param[in]       processing             Processing mode which is used for this call (Parallel or Sequential)
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetSegmentInfo(
  P2VAR(vHsm_SecureBoot_SegmentInfoType, AUTOMATIC, VHSM_APPL_VAR) segmentInfoPtr,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) extSegmentListPtr,
  vHsm_Core_SecureBoot_VerMethodType verMethod,
  uint8 processing);

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetSegmentInfoPart()
 *********************************************************************************************************************/
/*! \brief       Get a specific key element from a segment
 *  \details     The size is also requested. if the size does not match, E_NOT_OK is returned.
 *  \param[in]   segmentIdx          Idx of the segment
 *  \param[in]   keyElementId        Id of the key element
 *  \param[out]  dataPtr             Pointer where the result shall be stored
 *  \param[in]   dataLength          Length of the requested data
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetSegmentInfoPart(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  uint32 dataLength);
# endif

# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
#  if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON) /* COV_VHSM_COMPARE_INTERNAL_MANDATORY */
#   if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetSegmentSize()
 *********************************************************************************************************************/
/*! \brief       Set size of secureboot segment
 *  \details     -
 *  \param[in]   segmentIdx    Idx of the segment
 *  \param[in]   size          Size the segment is set to
 *  \param[in]   persist       Flag indicating if segment should be persisted
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetSegmentSize(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 size,
  boolean persist);

/**********************************************************************************************************************
 *  vHsm_SecureBoot_PersistSegment()
 *********************************************************************************************************************/
/*! \brief       Persist secure boot segment
 *  \details     -
 *  \param[in]   segmentIdx          Idx of the segment
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_PersistSegment(
  vHsm_SecureBootSegmentIterType segmentIdx);

/**********************************************************************************************************************
 *  vHsm_Core_Secureboot_SSwDl_Finish()
 *********************************************************************************************************************/
/*! \brief       Finish tag calculation of secure software download and verify signature.
 *  \details     -
 *  \param[in]   segmentIdx    Idx of the segment
 *  \param[out]  job           Pointer to the job
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_Secureboot_SSwDl_Finish(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job);
#   endif /* VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON */
#  endif
# endif /* VHSM_SECURE_SOFTWARE_DOWNLOAD== STD_ON */

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
#  if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_PersistHelper()
 *********************************************************************************************************************/
/*! \brief       Persist secure boot segment
 *  \details     -
 *  \param[in]   persist             Flag indicating if segment should be persisted
 *  \param[in]   segmentIdx          Idx of the segment to persist
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_PersistHelper(
  boolean persist, vHsm_SecureBootSegmentIterType segmentIdx);
#  endif

/**********************************************************************************************************************
 *  vHsm_SecureBoot_PersistGroup()
 *********************************************************************************************************************/
/*! \brief       Persist secure boot group
 *  \details     -
 *  \param[in]   groupIdx          Idx of the group
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_PersistGroup(
  vHsm_SecureBootGroupIterType groupIdx);
# endif /* VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM */

# if(VHSM_ALLOW_ADDRESS_CHANGE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetSegmentAddress()
 *********************************************************************************************************************/
/*! \brief       Set address of secureboot segment
 *  \details     -
 *  \param[in]   segmentIdx          Idx of the segment
 *  \param[in]   address             Address the segment is set to
 *  \param[in]   persist             Flag indicating if the segment should be persisted
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetSegmentAddress(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 address,
  boolean persist);

# endif /* VHSM_ALLOW_ADDRESS_CHANGE == STD_ON */

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SetSegmentInfoCsm()
 *********************************************************************************************************************/
/*! \brief       Update a segment with new information stored in Csm
 *  \details     -
 *  \param[in]   segmentIdx          Idx of the segment
 *  \param[in]   segmentInfo         Information about the segment
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         The segment must be within a group which has compare internal Tag configured.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SetSegmentInfoCsm(
  vHsm_SecureBootSegmentIterType segmentIdx,
  vHsm_SecureBoot_SegmentType segmentInfo);
#  endif

#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SetSegmentInfoNvM()
 *********************************************************************************************************************/
/*! \brief       Update a segment with new information stored in NvM
 *  \details     -
 *  \param[in]   segmentIdx          Idx of the segment
 *  \param[in]   segmentInfo         Information about the segment
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         The segment must be within a group which has compare internal Tag configured.
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SetSegmentInfoNvM(
  vHsm_SecureBootSegmentIterType segmentIdx,
  vHsm_SecureBoot_SegmentType segmentInfo);
#  endif
# endif

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON) || (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_BEtoU32()
 *********************************************************************************************************************/
/*! \brief       Convert 4 byte array to uint32
 *  \details     -
 *  \param[in]   src         Big endian array which shall be converted
 *  \return      uint32 representation of the array
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_BEtoU32(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) src);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_BEtoU16()
 *********************************************************************************************************************/
/*! \brief       Convert 2 byte array to uint16
 *  \details     -
 *  \param[in]   src          Big endian array which shall be converted
 *  \return      uint16 representation of the array
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(uint16, VHSM_CODE) vHsm_Core_SecureBoot_BEtoU16(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) src);
# endif

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SBU_CheckGroupSegmentModeConsistency()
 *********************************************************************************************************************/
/*! \brief       Check that processing modes of secureboot group segments are consitent
 *  \details     -
 *  \param[in]   groupIdx        Secureboot group index
 *  \param[in]   maxSegments     Number of all segments in this group
 *  \param[in]   nSegmentsFromSL Number of segments to update
 *  \param[in]   buffer          Buffer containing segment list information
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SBU_CheckGroupSegmentModeConsistency(
  vHsm_SecureBootGroupIterType groupIdx,
  uint32 maxSegments,
  uint16 nSegmentsFromSL,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer);
#  endif /* VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM */

/**********************************************************************************************************************
 *  vHsm_SecureBootUpdate_CalculateTagforSegmentAndValidate()
 *********************************************************************************************************************/
/*! \brief       Calculate tag for secureboot segment
 *  \details     The function performs:
 *               - Tag calculation (segment or group tag)
 *               - Hash over segment generation
 *               - Comparison of the segment Hash against provided hash of the SL
 *  \param[in]        segmentIdx      Index of the segment
 *  \param[out]       segInfo         Information about the secureboot segment
 *  \param[in,out]    seqWorkspace    Contains information for all segments
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootUpdate_CalculateTagforSegmentAndValidate(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(vHsm_SecureBoot_SegmentType, AUTOMATIC, VHSM_APPL_VAR) segInfo,
  P2VAR(vHsm_SecureBoot_SequentialWorkspaceType, AUTOMATIC, VHSM_APPL_VAR) seqWorkspace);
# endif /* VHSM_SECURE_BOOT_UPDATE == STD_ON */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_TagCalculationJob()
 *********************************************************************************************************************/
/*! \brief       Calculate tag for secure boot
 *  \details     -
 *  \param[in]   csmJobId            Id of csm job
 *  \param[in]   service             Service of the job
 *  \param[in]   mode                Indicates which operation mode(s) to perform.
 *  \param[in]   dataPtr             Contains the pointer to the data for which the tag shall be computed.
 *  \param[in]   dataLength          Contains the number of bytes for the tag generation.
 *  \param[out]  resultPtr           Contains the pointer where the computed tag shall be stored.
 *  \param[out]  resultLengthPtr     Contains the number of bytes of tag generation.
 *  \return      E_OK if successful, otherwise E_NOT_OK.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_TagCalculationJob(
  uint32 csmJobId,
  uint8 service,
  Crypto_OperationModeType mode,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_DATA) dataPtr,
  uint32 dataLength,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_HandleComputedTag()
 *********************************************************************************************************************/
/*! \brief       Check the computed CMAC and perform necessary actions
 *  \details     -
 *  \param[in]       segmentIdx               Idx of the segment
 *  \param[in]       computedTag              Tag contained inside the segment
 *  \param[out]      result                   Result of the Tag comparison.
 *  \param[in,out]   vHsm_SecureBootInfoPtr   Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 *  \param[in,out]   extSegmentListPtr        Pointer to the external segment list structure
 *  \param[in]       processing               Processing mode which is used for this call (Parallel or Sequential)
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_HandleComputedTag(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) computedTag,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, VHSM_APPL_VAR) result,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) extSegmentListPtr,
  uint8 processing);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_StartTagCalculation()
 *********************************************************************************************************************/
/*! \brief       Start calculation of secureboot tag.
 *  \details     -
 *  \param[in]   groupIdx               Group index for which the tag should be calculated
 *  \param[in]   processing             Processing mode: parallel or sequential
 *  \param[in]   verMethod              Verification method which is used for this call (CompareInternal or ExternalSegmentList)
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_StartTagCalculation(
  vHsm_SecureBootGroupIterType groupIdx,
  uint8 processing,
  vHsm_Core_SecureBoot_VerMethodType verMethod);
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_EndTagCalculation()
 *********************************************************************************************************************/
/*! \brief       Start calculation of secureboot tag.
 *  \details     -
 *  \param[in]   groupIdx               Group index for which the tag should be calculated
 *  \param[in]   processing             Processing mode: parallel or sequential
 *  \param[out]  tagPtr                 Calculated tag
 *  \param[in]   tagLength              Expected length of the tag
 *  \param[in]   verMethod              Verification method which is used for this call (CompareInternal or ExternalSegmentList)
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_EndTagCalculation(
  vHsm_SecureBootGroupIterType groupIdx,
  uint8 processing,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) tagPtr,
  uint32 tagLength,
  vHsm_Core_SecureBoot_VerMethodType verMethod);

# if (VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_PrintState()
 *********************************************************************************************************************/
/*! \brief       Print the current state of the secure boot and the groups and their segments to the debug console
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_PrintState(void);
# endif /* VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON */

# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_RestartCyclicVerificationGroups()
 *********************************************************************************************************************/
/*! \brief       Start the cyclic verification groups one after another when secure boot has been finished
 *  \details     -
 *  \pre         Secureboot is done and secureboot queue is empty.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_RestartCyclicVerificationGroups(void);
# endif /* VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_QueueAddGroup()
 *********************************************************************************************************************/
/*! \brief       Add a group to the queue.
 *  \details     -
 *  \param[in]   groupIdx                    Idx of the group.
 *  \param[in]   isCyclicVerification        indicates if group shall be verified cyclically.
 *  \param[in]   verMethod                   The verification method with which the group shall be processed.
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_QueueAddGroup(
  vHsm_SecureBootGroupIterType groupIdx,
  boolean isCyclicVerification,
  vHsm_Core_SecureBoot_VerMethodType verMethod);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_QueueRemoveEntry()
 *********************************************************************************************************************/
/*! \brief       Remove first group from the queue.
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_QueueRemoveEntry(void);

/**********************************************************************************************************************
 *  vHsm_SecureBoot_SequentialTagCalculationOfGroup()
 *********************************************************************************************************************/
/*! \brief       Calculate the tag of a group sequential.
 *  \details     -
 *  \param[in]       groupIdx                Idx of the group.
 *  \param[in,out]   seqWorkspace            Workspace for sequential processing containing all necessary information
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SequentialTagCalculationOfGroup(
  vHsm_SecureBootGroupIterType groupIdx,
  P2VAR(vHsm_SecureBoot_SequentialWorkspaceType, AUTOMATIC, VHSM_APPL_VAR) seqWorkspace);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetInputLengthBySplitSize()
 *********************************************************************************************************************/
/*! \brief       Calculate the input length according to the split size.
 *  \details     -
 *  \param[in]   secureBootInfoPtr           Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 *  \return      Length of the input which shall be processed.
  *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetInputLengthBySplitSize(
  P2CONST(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_HandleRetry()
 *********************************************************************************************************************/
/*! \brief       Handle retry flag for secureboot segment.
 *  \details     -
 *  \param[in,out]   secureBootInfoPtr           Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 *  \param[in,out]   loopInc                     Set according to the retry secureboot segment flag.
 *  \return          Length of the input which shall be processed.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE)vHsm_Core_SecureBoot_HandleRetry(
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) loopInc);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ProcessGroupParallel()
 *********************************************************************************************************************/
/*! \brief       Calculate the tag of a group sequential.
 *  \details     -
 *  \param[in]        groupIdx               Idx of the group.
 *  \param[in,out]   secureBootInfoPtr       Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_ProcessGroupParallel(
  vHsm_SecureBootGroupIterType groupIdx,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ProcessGroupSequential()
 *********************************************************************************************************************/
/*! \brief       Calculate the tag of a group sequential.
 *  \details     -
 *  \param[in]   groupIdx                    Idx of the group.
 *  \param[in]   forcedSequential            Indicates if parallel segments should be processed sequentially.
 *  \param[in,out]   secureBootInfoPtr       Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 *  \param[in,out]   extSegmentListPtr       Pointer to the external segment list structure
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_ProcessGroupSequential(
  vHsm_SecureBootGroupIterType groupIdx,
  boolean forcedSequential,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) extSegmentListPtr);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_CheckErrors()
 *********************************************************************************************************************/
/*! \brief       Check the state of secureboot and call sanction callout.
 *  \details     -
 *  \param[in]       groupIdx                    Idx of the group.
 *  \param[in]       retVal                      Status of secureboot.
 *  \param[in,out]   secureBootInfoPtr       Pointer to the secure boot info containing the information if it is a cyclic verification or if the segment shall be retried if it failed
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_CheckErrors(
  vHsm_SecureBootGroupIterType groupIdx,
  Std_ReturnType retVal,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ResetSecurebootResult()
 *********************************************************************************************************************/
/*! \brief       Reset result of secureboot group and its segments.
 *  \details     -
 *  \param[in]   groupIdx                    Idx of the group.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_ResetSecurebootResult(
  vHsm_SecureBootGroupIterType groupIdx);

# if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_InitGroup()
 *********************************************************************************************************************/
/*! \brief       Initialize secureboot group storage.
 *  \details     -
 *  \param[in]   groupIdx                    Idx of the group.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_SecureBootStorage_InitGroup(
  vHsm_SecureBootGroupIterType groupIdx);
# endif /* VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM */

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetElement()
 *********************************************************************************************************************/
/*! \brief       Set secureboot segment data.
 *  \details     -
 *  \param[in]   segmentIdx                  Idx of the segment.
 *  \param[in]   keyElementId                KeyelementId of the segment.
 *  \param[in]   data                        Segment data.
 *  \param[in]   dataLength                  Length of the segment data.
 *  \param[in]   persist                     Flag indicating if segment should be persisted.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetElement(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) data,
  uint32 dataLength,
  boolean persist);
# endif /* VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetVerificationJobId()
 *********************************************************************************************************************/
/*! \brief      Get the referenced verification jobId for the secure boot group.
 *  \details     Return the parallel or sequencial jop depending on the processing mode.
 *  \param[in]   groupIdx                 Index of related group
 *  \param[in]   processing               Parallel or sequencial processing
 *  \param[in]   verMethod                The verification method for which the job is requested.
 *  \return      The job id of the verification job.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetVerificationJobId(
  uint32 groupIdx,
  uint8 processing,
  vHsm_Core_SecureBoot_VerMethodType verMethod);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetVerificationJobService()
 *********************************************************************************************************************/
/*! \brief      Get the referenced verification service for the secure boot group.
 *  \details     -
 *  \param[in]   groupIdx                 Index of related group
 *  \param[in]   verMethod                The verification method for which the job is requested.
 *  \return      The service id of the related crypto service.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(uint8, VHSM_CODE) vHsm_Core_SecureBoot_GetVerificationJobService(
  uint32 groupIdx,
  vHsm_Core_SecureBoot_VerMethodType verMethod);

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_PerformConfirmation()
 *********************************************************************************************************************/
/*! \brief       Iterates over the Segmentlist and checks the hashes of the segments in the codeflash
 *  \details     -
 *  \param[in]   buffer                  SL data
 *  \param[in]   onInactivePartition     Indicates the check on the active or inactive partition
 *  \param[in]   groupIdx                Index of the current group
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_PerformConfirmation(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer,
  boolean onInactivePartition,
  uint32 groupIdx);

#  if (VHSM_PARTITION_LAYOUT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetAddressOfInactivePartition()
 *********************************************************************************************************************/
/*! \brief       Returns the address of the inactive partition based on the given address.
 *  \details     -
 *  \param[in]   address                  requested address
 *  \return      The address on the inactive partition
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR), VHSM_CODE) vHsm_Core_SecureBoot_GetAddressOfInactivePartition(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) address);
#  endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetAddressOfSLOfGroupId()
 *********************************************************************************************************************/
/*! \brief       Returns the address of the segment list of a group.
 *  \details     -
 *  \param[in]   groupId                  The groupId of the secureboot group
 *  \param[out]  ptrToSegmentList         Pointer is set to the address of the segmentlist in the codeflash.
 *  \param[out]  groupIdx                 Index of the secure boot group in configuration.
 *  \return      The length of the segmentlist
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetAddressOfSLOfGroupId(
  uint32 groupId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) ptrToSegmentList,
  P2VAR(vHsm_SecureBootGroupIterType, AUTOMATIC, VHSM_APPL_VAR) groupIdx);
# endif /* VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON */

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON) || (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetLengthOfSlWithHeader()
 *********************************************************************************************************************/
/*! \brief       Get the length of an external segment list
 *  \details     -
 *  \param[in]   ptrToSegmentList                  Pointer to start of segmentlist
 *  \return      The length of the segmentlist
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrToSegmentList);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ParseSl()
 *********************************************************************************************************************/
/*! \brief       Parse the segment list and fill segments which are not defined in the provided segment list with emtpy values
 *  \details     -
 *  \param[in]   ptrToSegmentlistWoHeader          Pointer to start of segmentlist
 *  \param[in]   ptrToSegmentArray[VHSM_MAX_SEGMENTS_PER_GROUP]                 Pointer to structure, where the segmentlist shall be saved.
 *  \return      E_OK if the segmentlist is parsed successfull
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_ParseSl(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrToSegmentlistWoHeader,
  vHsm_SecureBoot_SegmentType ptrToSegmentArray[VHSM_MAX_SEGMENTS_PER_GROUP]);

#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_VerifyExtSl()
 *********************************************************************************************************************/
/*! \brief       Verify the external segment list of a group.
 *  \details     If the Hash in the dataflash matches the one from the segment list, the signature verification is skipped.
 *               Otherwise signature is calculated and the Hash is stored in the data flash to prevent future expensive signature verifications.
 *  \param[in]   groupIdx                         Pointer to start of segmentlist
 *  \param[out]  ptrToStructure                   Target structure, where the verified data is stored
 *  \param[in]   processing                       Signalizes if the processing shall be done sequencial or parallel.
 *  \return      E_OK if the segmentlist was verified and the parsing was successfull
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_VerifyExtSl(
  vHsm_SecureBootGroupIterType groupIdx,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) ptrToStructure,
  uint8 processing);
#  endif
# endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetTagLength()
 *********************************************************************************************************************/
/*! \brief       Calculates the tag length based on the group info and verification method
 *  \details     -
 *  \param[in]   groupIdx                    Valid GroupIdx
 *  \param[in]   verMethod                   requested verification method of the tag
 *  \return      Length of the tag
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetTagLength(
  uint32 groupIdx,
  vHsm_Core_SecureBoot_VerMethodType verMethod);

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetSanction()
 *********************************************************************************************************************/
/*! \brief       Gets the sanction which shall be triggered
 *  \details     -
 *  \param[in]   segmentIdx                 Valid segmentIdx
 *  \param[out]  sanction                   pointer where the sanction shall be stored
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_GetSanction(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) sanction);

# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
#  if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetAddress()
 *********************************************************************************************************************/
/*! \brief       Gets the address of the segment
 *  \details     -
 *  \param[in]   segmentIdx                 Valid segmentIdx
 *  \param[out]  address                    pointer where the address shall be stored
 *  \pre         -
 *  \return      E_OK if successful, otherwise E_NOT_OK
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetAddress(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) address);
#  endif
# endif

#endif /* (VHSM_SECURE_BOOT == STD_ON) */

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_CheckGroupValidity()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_CheckGroupValidity(
  vHsm_SecureBootGroupIterType groupIdx)
{
  vHsm_SecureBootSegmentIterType segmentIter;
  boolean processing = FALSE;
  Crypto_VerifyResultType result = CRYPTO_E_VER_OK;

  /* For all segments inside the group: */
  for (segmentIter = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIter < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIter++)
  {
    /* #21 Check the state of the segment */
    if (vHsm_State.vHsm_SecureBootState.segmentFinished[segmentIter] == FALSE)
    {
      processing = TRUE;
    }
    result |= vHsm_State.vHsm_SecureBootState.segmentResult[segmentIter];
  }
  /* Set the state of the group */
  vHsm_State.vHsm_SecureBootState.groupFinished[groupIdx] = !processing;
  vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] |= result;
  vHsm_State.vHsm_SecureBootResult |= result;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_CheckErrors()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_CheckErrors(
  vHsm_SecureBootGroupIterType groupIdx,
  Std_ReturnType retVal,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr)
{
  /* #10 Check the state of secureboot */
  if (retVal != E_OK)
  {
    vHsm_SecureBootSegmentIterType segmentIter;

    /* #20 Call sanction callout */
    secureBootInfoPtr->sanctionReason = VHSM_SECUREBOOTSANCTION_SECUREBOOT_ERROR;
    secureBootInfoPtr->resultOverwrite = CRYPTO_E_VER_NOT_OK;
    (void)vHsm_Custom_SecureBootSanction_Callout(
      vHsm_GetCryptoKeyIdOfSecureBootSegment(vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx)),
      secureBootInfoPtr);
    for (segmentIter = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIter < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIter++)
    {
      vHsm_State.vHsm_SecureBootState.segmentResult[segmentIter] = secureBootInfoPtr->resultOverwrite;
    }
    vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] = secureBootInfoPtr->resultOverwrite;
  }
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ResetSecurebootResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_ResetSecurebootResult(
  vHsm_SecureBootGroupIterType groupIdx)
{
  vHsm_SecureBootSegmentIterType segmentIdx;
  /* #10 Reset segment results */
  for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIdx++)
  {
    vHsm_State.vHsm_SecureBootState.segmentFinished[segmentIdx] = FALSE;
    vHsm_State.vHsm_SecureBootState.segmentResult[segmentIdx] = CRYPTO_E_VER_OK;
  }
  /* #20 Reset group result */
  vHsm_State.vHsm_SecureBootState.groupFinished[groupIdx] = FALSE;
  vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] = CRYPTO_E_VER_OK;
}

# if (VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_PrintState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_PrintState(void)
{
  vHsm_SecureBootGroupIterType groupIdx;
  vHsm_SecureBootSegmentIterType segmentIdx;

  /* #10 Print the state of all groups and segments to the console */
  vHsm_Trace(VHSM_TRACETYPE_INFO, "SB\n", vHsm_GetSizeOfSecureBootGroup());
  vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: Current State of Secure Boot: Valid=%i\n", (vHsm_State.vHsm_SecureBootResult == CRYPTO_E_VER_OK));

  for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
  {
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB:   Group 0x%08X: Valid=%i Busy=%i\n", vHsm_GetIdOfSecureBootGroup(groupIdx), (vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] == CRYPTO_E_VER_OK), !vHsm_State.vHsm_SecureBootState.groupFinished[groupIdx]);
    for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIdx++)
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB:     Segment %2i: Valid=%i Busy=%i\n", vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx), (vHsm_State.vHsm_SecureBootState.segmentResult[segmentIdx] == CRYPTO_E_VER_OK), !vHsm_State.vHsm_SecureBootState.segmentFinished[segmentIdx]);
    }
  }
}
# endif /* VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON */

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON) || (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_BEtoU32()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_BEtoU32(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) src)
{
  uint32  u32;

  /* #10 Convert BIG endian byte array to U32 */
  u32 = ((uint32)src[0]) << 24;
  u32 |= ((uint32)src[1]) << 16;
  u32 |= ((uint32)src[2]) << 8;
  u32 |= ((uint32)src[3]);

  return u32;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_BEtoU16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(uint16, VHSM_CODE) vHsm_Core_SecureBoot_BEtoU16(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) src)
{
  /* #10 Convert big endian byte array to U16 */
  return (uint16)(((uint16)src[0] << 8) | (uint16)src[1]);
}
# endif

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SBU_CheckGroupSegmentModeConsistency()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SBU_CheckGroupSegmentModeConsistency(
  vHsm_SecureBootGroupIterType groupIdx,
  uint32 maxSegments,
  uint16 nSegmentsFromSL,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer)
{
  Std_ReturnType retVal = E_OK;
  if (vHsm_GetTagHandlingOfSecureBootGroup(groupIdx) == VHSM_GROUP_TAG)
  {
    uint32 segment;
    uint16 segmentProcessingMode = VHSM_NONE;
    boolean modeInitialized = FALSE;

    for (segment = 0u; segment < maxSegments; segment++)
    {
      /* #34 Check if the provided segment list still contains information for a segment */
      if (segment < nSegmentsFromSL)
      {
        uint16 tmpMode;
        /* #40 Parse the information of the segment from the segment list */
        uint32 offset = (VHSM_SEGMENT_LIST_INFO + (segment * VHSM_SIZE_OF_SEGMENT));
        tmpMode = vHsm_Core_SecureBoot_BEtoU16(&buffer[offset + 8u]);
        if (tmpMode == VHSM_NONE)
        {
          /* ignore NONE */
        }
        else if (modeInitialized == FALSE)
        {
          segmentProcessingMode = tmpMode;
          modeInitialized = TRUE;
        }
        else if (segmentProcessingMode == tmpMode)
        {
          /* mode already stored */
        }
        else
        {
          retVal = E_NOT_OK;
        }
      }
    }
  }
  return retVal;
}/* PRQA S 6080 */ /* MD_MSR_STMIF */
#  endif

/**********************************************************************************************************************
 *  vHsm_SecureBootUpdate_CalculateTagforSegmentAndValidate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootUpdate_CalculateTagforSegmentAndValidate(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(vHsm_SecureBoot_SegmentType, AUTOMATIC, VHSM_APPL_VAR) segInfo,
  P2VAR(vHsm_SecureBoot_SequentialWorkspaceType, AUTOMATIC, VHSM_APPL_VAR) seqWorkspace)
{
  Std_ReturnType retVal;
  uint8  calculatedHash[VHSM_HASH_SIZE] = { 0u };
  uint32 hashLength = VHSM_HASH_SIZE;
  uint8 secureBootAtomicBuffer[VHSM_ATOMIC_BUFFER_SIZE];
  vHsm_SecureBootGroupIterType groupIdx = vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx);
  seqWorkspace->forceSequential = (VHSM_PARALLEL == segInfo->mode);
  seqWorkspace->segmentInfo.segmentIdx = segmentIdx;
  retVal = vHsm_Core_SecureBoot_GetSegmentInfo(&seqWorkspace->segmentInfo, NULL_PTR, seqWorkspace->verMethod, VHSM_SEQUENTIAL); /* PRQA S 2985 */ /* MD_VHSM_2985_SECUREBOOT_ASSIGNMENT_NOT_SAME_IN_OTHER_CONFIGS */

  if (retVal != E_OK)
  {
    segInfo->address = 0u;
    segInfo->length = 0u;
    segInfo->mode = CRYPTO_30_VHSM_MODE_NONE;
    segInfo->hashLength = 0u;
    VStdMemClr(segInfo->SLHash, VHSM_HASH_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }
  else
  {
    seqWorkspace->segmentInfo.mode = (uint8)segInfo->mode;
    /* Indicate that only START shall be performed during the tag calculation*/
    seqWorkspace->atomicFlags = VHSM_SECUREBOOT_ATOMICFLAGS_START;
    retVal |= vHsm_SecureBoot_SequentialTagCalculationOfGroup(groupIdx, seqWorkspace); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */

    /* Calculate the Hash (START) which will be later compared against the segment list */
    retVal |= Csm_Hash(vHsm_GetCsmHashJobReferenceOfSecureBootUpdate(), CRYPTO_OPERATIONMODE_START, NULL_PTR, 0, NULL_PTR, NULL_PTR);
    {
      uint32 remaining = segInfo->length;
      uint32 processed = 0u;
      P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) addrTmp = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))segInfo->address; /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */

      seqWorkspace->segmentInfo.address = secureBootAtomicBuffer; /* PRQA S 3225 */ /* MD_HSM_3225_STACK_VAR_STORAGE_DURATION */

      /* Loop over the data of the segment in small chunks */
      while (remaining != 0u)
      {
        if ((remaining / VHSM_ATOMIC_BUFFER_SIZE) != 0u)
        {
          seqWorkspace->segmentInfo.size = VHSM_ATOMIC_BUFFER_SIZE;
        }
        else
        {
          seqWorkspace->segmentInfo.size = remaining;
        }

        /* Copy the data to a local buffer and provide the buffer to the UPDATE calls of Hash and TagCalculation */
        VStdMemCpy(secureBootAtomicBuffer, &addrTmp[processed], seqWorkspace->segmentInfo.size); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

        /* Indicate that only UPDATE shall be performed during the tag calculation*/
        seqWorkspace->atomicFlags = VHSM_SECUREBOOT_ATOMICFLAGS_UPDATE;
        retVal |= vHsm_SecureBoot_SequentialTagCalculationOfGroup(groupIdx, seqWorkspace); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */

        /* Calculate the Hash (UPDATE) which will be later compared against the segment list */
        retVal |= Csm_Hash(vHsm_GetCsmHashJobReferenceOfSecureBootUpdate(), CRYPTO_OPERATIONMODE_UPDATE,
          vHsm_Hal_GetCodeFlashAddr((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(seqWorkspace->segmentInfo.address)), /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
          seqWorkspace->segmentInfo.size,
          NULL_PTR, NULL_PTR);
        processed += seqWorkspace->segmentInfo.size;
        remaining -= seqWorkspace->segmentInfo.size;
      }

      /* Clear the address, because it is not used anymore. This will prevent passing a pointer to invalid stack in the upper layers. See MD_HSM_3225_STACK_VAR_STORAGE_DURATION */
      seqWorkspace->segmentInfo.address = NULL_PTR;
    }

    /* Indicate that only FINSIH shall be performed during the tag calculation*/
    seqWorkspace->atomicFlags = VHSM_SECUREBOOT_ATOMICFLAGS_FINISH;
    retVal |= vHsm_SecureBoot_SequentialTagCalculationOfGroup(groupIdx, seqWorkspace); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */

    /* Calculate the Hash (FINISH) which will be later compared against the segment list */
    retVal |= Csm_Hash(vHsm_GetCsmHashJobReferenceOfSecureBootUpdate(), CRYPTO_OPERATIONMODE_FINISH,
      NULL_PTR, 0,
      calculatedHash, &hashLength);

    /* Compare the computed HASH against the one provided with the SL */
    if (( hashLength!=VHSM_HASH_SIZE)
      ||(vHsm_Core_SecureBoot_IsMemEqual(calculatedHash, segInfo->SLHash, VHSM_HASH_SIZE) == FALSE)/* PRQA S 3415 */ /* MD_VHSM_3415_NO_SIDE_EFFECTS */
      || (retVal != E_OK))
    {
      /* Hash did not match */
      retVal = E_NOT_OK;

      segInfo->address = 0u;
      segInfo->length = 0u;
      segInfo->mode = CRYPTO_30_VHSM_MODE_NONE;
      segInfo->hashLength = 0u;
      VStdMemClr(segInfo->SLHash, VHSM_HASH_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }
    else
    {
      /* Copy the tag if it was already calculated */
      VStdLib_MemCpy(segInfo->SLHash, seqWorkspace->computedTag, seqWorkspace->tagLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      segInfo->hashLength = seqWorkspace->tagLength;
    }

    if (retVal != E_OK)
    {
      (void)Csm_CancelJob(vHsm_GetCsmHashJobReferenceOfSecureBootUpdate(), CRYPTO_OPERATIONMODE_SINGLECALL);
    }
  }

  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetSegmentInfoPart()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetSegmentInfoPart(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 keyElementId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  uint32 dataLength)
{
  Std_ReturnType retVal = E_NOT_OK;

  uint32 storageLength = dataLength;
  vHsm_Api_KeyStorageIndexType storageIdx;

  /* #10 Get the key element storage index */
  if (vHsm_Api_Local_KeyElementGet(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx), keyElementId, &storageIdx, &storageLength) != E_OK)
  {
    /* retVal already set */
  }
  /* #20 Check if the element has the correct length */
  else if (storageLength != dataLength)
  {
    /* retVal already set */
  }
  else
  {
    /* #30 Copy the key element data to the destination buffer */
    VStdLib_MemCpy(dataPtr, vHsm_Api_GetAddrKeyStorage(storageIdx), storageLength); /* PRQA S 0310, 0315 */ /* MD_VHSM_0310_KEYELEMENT_CONTENT, MD_MSR_VStdLibCopy */
    retVal = E_OK;
  }

  return retVal;
}
# endif

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_PersistGroup()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_PersistGroup(
  vHsm_SecureBootGroupIterType groupIdx)
{
  Std_ReturnType retVal;

  /* #21 Persist the event immediately */
  retVal = NvM_SetRamBlockStatus((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfSecureBootGroup(groupIdx), TRUE);
  retVal |= vHsm_Api_NvM_WriteBlock((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfSecureBootGroup(groupIdx), NULL_PTR);

  return retVal;
}
# endif

# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
#  if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_PersistSegment()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_PersistSegment(
  vHsm_SecureBootSegmentIterType segmentIdx)
{
  Std_ReturnType retVal;
#   if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
  retVal = vHsm_Api_KeyValidSet(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx));
#   else
  /* #10 Persist group */
  retVal = vHsm_SecureBoot_PersistGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
#   endif
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_Secureboot_SSwDl_Finish()
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
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_Secureboot_SSwDl_Finish(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job) /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
{
  Std_ReturnType retVal;
  uint8 SecureBootSlotCmac[VHSM_CORE_SECUREBOOTSLOTCMACSIZE];
  uint32 SecureBootSlotCmacLength;
  Crypto_VerifyResultType signatureResult = CRYPTO_E_VER_NOT_OK;
  vHsm_SecureBootGroupIterType groupIdx = vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx);
  /* #10 Finish the signature verification */
  retVal = Csm_SignatureVerify(vHsm_GetCsmSignatureJobReferenceOfSecureSoftwareDownload(), CRYPTO_OPERATIONMODE_FINISH, vHsm_Hal_GetCodeFlashAddr(job->jobPrimitiveInputOutput.inputPtr),
    job->jobPrimitiveInputOutput.inputLength, job->jobPrimitiveInputOutput.secondaryInputPtr, job->jobPrimitiveInputOutput.secondaryInputLength, &signatureResult);

  /* #20 Finish the TAG generation */
  SecureBootSlotCmacLength = sizeof(SecureBootSlotCmac);
  retVal |= vHsm_Core_SecureBoot_TagCalculationJob(
    vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
    vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
    CRYPTO_OPERATIONMODE_FINISH,
    NULL_PTR, 0u,
    SecureBootSlotCmac, &SecureBootSlotCmacLength);

  /* #30 Check if Signature and TAG returned with E_OK */
  if (retVal == E_OK)
  {
    /* #35 Check if provided Signature was valid */
    if (signatureResult == CRYPTO_E_VER_OK)
    {
      uint32 address = 0u;
      retVal = vHsm_Core_SecureBoot_GetAddress(segmentIdx, &address);

#   if(VHSM_ALLOW_ADDRESS_CHANGE == STD_OFF)
      if (vHsm_SecureSoftwareDownload_Address != address)
      {
        retVal = E_NOT_OK;
      }
#   else
      /* #41 Store the provided address to the secure boot slot */
      retVal |= vHsm_SecureBoot_SetSegmentAddress(segmentIdx, vHsm_SecureSoftwareDownload_Address, FALSE);
#   endif
      if (retVal == E_OK) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
      {
        /* #40 Set the generated TAG to the secure boot slot */
        retVal = vHsm_SecureBoot_SetTag(
          segmentIdx,
          SecureBootSlotCmac,
          sizeof(SecureBootSlotCmac),
          FALSE);

        /* #42 Store the provided size to the secure boot slot */
        retVal |= vHsm_SecureBoot_SetSegmentSize(
          segmentIdx,
          vHsm_SecureSoftwareDownload_Size,
          FALSE);
      }

      /* #50 Store the secure boot slot to valid */
      if (retVal == E_OK) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
      {
        retVal = vHsm_SecureBoot_PersistSegment(segmentIdx);
      }

      /* #60 Set the verification result to CRYPTO_E_VER_OK */
      *job->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_OK;
    }
    else
    {
      /* #70 Set the verification result to CRYPTO_E_VER_NOT_OK if the signature was invalid */
      *job->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;
    }
  }
  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetSegmentSize()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetSegmentSize(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 size,
  boolean persist)
{
  Std_ReturnType retVal;
  /* #10 Set size */
#   if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
  uint32 sizeTmp = size;
  retVal = vHsm_SecureBoot_SetElement(segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&sizeTmp, sizeof(sizeTmp), persist); /* PRQA S 3305 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT */
#   else
  vHsm_SecureBoot_GetSizeOfSegmentInfo(segmentIdx) = size; /* PRQA S 0310, 3305 */ /* MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS, MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT */
  retVal = vHsm_SecureBoot_PersistHelper(persist, segmentIdx);
#   endif
  return retVal;
}
#  endif /* (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON) */
# endif /* (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON) */

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM) && (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_PersistHelper()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_PersistHelper(
  boolean persist, vHsm_SecureBootSegmentIterType segmentIdx)
{
  Std_ReturnType retVal = E_OK;
  if (persist == TRUE)
  {
    /* #10 Persist group */
    retVal = vHsm_SecureBoot_PersistGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
  }
  return retVal;
}
# endif

# if(VHSM_ALLOW_ADDRESS_CHANGE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetSegmentAddress()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetSegmentAddress(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 address,
  boolean persist)
{
  Std_ReturnType retVal;
  /* #10 Set address */
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
  uint32 addressTmp = address;
  retVal = vHsm_SecureBoot_SetElement(segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&addressTmp, sizeof(addressTmp), persist); /* PRQA S 3305 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT */
#  else
  vHsm_SecureBoot_GetAddressOfSegmentInfo(segmentIdx) = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))address; /* PRQA S 0306, 0310, 3305 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS, MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT */
  retVal = vHsm_SecureBoot_PersistHelper(persist, segmentIdx);
#  endif
  return retVal;
}
# endif

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetElement()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetElement(
  vHsm_SecureBootSegmentIterType segmentIdx,
  uint32 keyElementId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) data,
  uint32 dataLength,
  boolean persist)
{
  Std_ReturnType retVal;
  /* #10 Set element data */
  retVal = vHsm_Api_KeyElementSet_Unchecked(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx), keyElementId, data, dataLength);
  if ((persist == TRUE) && (retVal == E_OK))
  {
    retVal = vHsm_Api_KeyValidSet(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx));
  }
  return retVal;
}
# endif

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SetSegmentInfoCsm()
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
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SetSegmentInfoCsm(
  vHsm_SecureBootSegmentIterType segmentIdx,
  vHsm_SecureBoot_SegmentType segmentInfo)
{

  Std_ReturnType retVal;
  uint32 cryptoKeyId = vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx);

  /* #10 Set the size */
  retVal = vHsm_Api_KeyElementSet_Unchecked(cryptoKeyId, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&segmentInfo.length, sizeof(segmentInfo.length));
  /* #20 Set the address */
  retVal |= vHsm_Api_KeyElementSet_Unchecked(cryptoKeyId, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&segmentInfo.address, sizeof(segmentInfo.address));
  /* #30 Set the mode */
  retVal |= vHsm_Api_KeyElementSet_Unchecked(cryptoKeyId, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_MODE, &segmentInfo.mode, sizeof(segmentInfo.mode));
  /* #40 Set the CMAC */
  retVal |= vHsm_Api_KeyElementSet_Unchecked(cryptoKeyId, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC, segmentInfo.SLHash, segmentInfo.hashLength);

  /* #50 Return the result */
  return retVal;
}
#  endif

#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SetSegmentInfoNvM()
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
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SetSegmentInfoNvM(
  vHsm_SecureBootSegmentIterType segmentIdx,
  vHsm_SecureBoot_SegmentType segmentInfo)
{
  Std_ReturnType retVal;

  vHsm_SecureBootGroupIterType groupIdx = vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx);

  /* #10 Set the size */
  vHsm_SecureBoot_GetSizeOfSegmentInfo(segmentIdx) = segmentInfo.length; /* PRQA S 3305, 0310 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */

  /* #20 Set the address */
  vHsm_SecureBoot_GetAddressOfSegmentInfo(segmentIdx) = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))segmentInfo.address; /* PRQA S 0310, 0306, 3305 */ /* MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS, MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST, MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT */

  /* #30 Set the mode */
  vHsm_SecureBoot_GetModeOfSegmentInfo(segmentIdx) = (uint8)segmentInfo.mode;

  if (segmentInfo.hashLength > 0u)
  {
    /* #40 Set the CMAC */
    vHsm_Trace(VHSM_TRACETYPE_NONE, "\n");
    vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentIdx) = TRUE;
    VStdLib_MemCpy(vHsm_SecureBoot_GetTagOfSegmentInfo(segmentIdx), segmentInfo.SLHash, vHsm_GetTagLengthOfSecureBootGroup(groupIdx)); /* PRQA S 0314, 0315 */ /* MD_MSR_VStdLibCopy */
  }

  retVal = E_OK;

  /* #50 Return the result */
  return retVal;
}
#  endif
# endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_IsMemEqual()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(boolean, VHSM_CODE) vHsm_Core_SecureBoot_IsMemEqual(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptr1,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptr2,
  uint32 length)
{
  uint32_least i;
  volatile boolean isEqual = TRUE;
  volatile boolean isEqualDummy = TRUE;

  /* #10 Securely compare memory */
  for (i = 0u; i < length; ++i)
  {
    if ((ptr1[i] != ptr2[i]))
    {
      isEqual = FALSE;
    }
    else
    {
      isEqualDummy = FALSE;
    }
  }

  VHSM_DUMMY_STATEMENT(isEqualDummy); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return isEqual;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetSanction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_GetSanction(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) sanction)
{
# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
  uint32 sanctionLength = 1u;

  /* #10 Try to get the sanction from the key. If an error occurs, use the sanction of the group instead. */
  if(vHsm_Core_SecureBoot_GetSegmentInfoPart(segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SANCTION, sanction, sanctionLength) !=E_OK)
  {
    *sanction = (uint8)vHsm_GetSanctionOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
  }
# else
  *sanction = (uint8)vHsm_GetSanctionOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
# endif
}

# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
#  if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetAddress()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetAddress(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) address)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#   if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
  uint32 addressLength = 4u;

  /* #10 Try to get the address from the key. If an error occurs, use the sanction of the group instead. */
  retVal = vHsm_Core_SecureBoot_GetSegmentInfoPart(segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))address, addressLength);
#   elif (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON) /* COV_VHSM_COMPARE_INTERNAL_MANDATORY */
  retVal = E_OK;
  *address = (uint32)vHsm_SecureBoot_GetAddressOfSegmentInfo(segmentIdx); /* PRQA S 0306, 0310, 3305 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS, MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT */
#   endif
  return retVal;
}
#  endif
# endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_PerformSanction()
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
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_PerformSanction(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr)
{
  Std_ReturnType retVal = E_OK;
  uint8 sanction;

  /* #10 Try to get the sanction for the secure boot slot */
  vHsm_Core_SecureBoot_GetSanction(segmentIdx, &sanction);
    /* #21 Decide which sanction shall be performed */
  switch (sanction)
  {
    /* #30 Check if sanction is none */
  case CRYPTO_30_VHSM_SANCTION_NONE:
    /* #31 Do nothing */
    vHsm_Trace(VHSM_TRACETYPE_INFO, "Secure boot of Group=%i Segment=%i failed. -> Sanction: None\n", segmentIdx, vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
    break;

    /* #40 Check if sanction is software reset */
  case CRYPTO_30_VHSM_SANCTION_RESET:
    vHsm_Trace(VHSM_TRACETYPE_INFO, "Secure boot of Group=%i Segment=%i failed. -> Sanction: Reset\n", segmentIdx, vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
    /* #41 Trigger software reset */
    vHsm_TriggerSoftwareResetWithIpcClearing();
    break;

    /* #50 Check if sanction is done in a custom callout */
  case CRYPTO_30_VHSM_SANCTION_CUSTOM:
    vHsm_Trace(VHSM_TRACETYPE_INFO, "Secure boot of Group=%i Segment=%i Cyclic=%i failed. -> Sanction: Custom Callout\n", segmentIdx, vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx), vHsm_SecureBootInfoPtr->isCyclicVerification);
    retVal = vHsm_Custom_SecureBootSanction_Callout(
      vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx),
      vHsm_SecureBootInfoPtr);
    break;

    /* #60 Check if sanction is halt */
  case CRYPTO_30_VHSM_SANCTION_HALT:
    vHsm_Trace(VHSM_TRACETYPE_INFO, "Secure boot of Group=%i Segment=%i failed. -> Sanction: Halt\n", segmentIdx, vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx));
# if (VHSM_SETTING_ENABLE_API_HALT == STD_ON)
    vHsm_Hal_Halt_Callout();
# else
    while (vHsm_State.vHsm_Loop == TRUE) /* PRQA S 2872 */ /* MD_VHSM_NON_TERMINATING */ /* COV_VHSM_NON_TERMINATING */
    {
      continue;
    }
# endif
    /* Set the value back to TRUE in case it has been cleared, to still stay in the main loop of the vHsm Firmware */
    vHsm_State.vHsm_Loop = TRUE;
    break;

  default: /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
    /* Invalid sanction */
    retVal = E_NOT_OK;
    break;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_TagCalculationJob()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_TagCalculationJob(
  uint32 csmJobId,
  uint8 service,
  Crypto_OperationModeType mode,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_DATA) dataPtr,
  uint32 dataLength,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) resultPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) resultLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #10 Check which crypto service is used for tag calculation */
  if (service == CRYPTO_HASH)
  {
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB:                             |        HASH jobId %i A=0x%0.8x L=%i\n", csmJobId, dataPtr, dataLength);
    retVal = Csm_Hash(csmJobId, mode, dataPtr, dataLength, resultPtr, resultLengthPtr);
  }
  else /* CRYPTO_MACGENERATE */
  {
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB:                             |        MAC  jobId %i A=0x%0.8x L=%i\n", csmJobId, dataPtr, dataLength);
    retVal = Csm_MacGenerate(csmJobId, mode, dataPtr, dataLength, resultPtr, resultLengthPtr);
  }

  if (retVal != E_OK)
  {
    (void)Csm_CancelJob(csmJobId, CRYPTO_OPERATIONMODE_SINGLECALL);
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_VHSM_6060_STPAR */

# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_RestartCyclicVerificationGroups()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_RestartCyclicVerificationGroups(void)
{
  if (vHsm_State.vHsm_CyclicVerificationFlag == FALSE)
  {
    /* Cyclic verification is disabled, do not add a new group */
  }
  else
  {
    /* Start one group after another and begin at the start as soon as all groups have been validated */
    if (vHsm_SecureBoot_CurrentCyclicGroupIdx == vHsm_GetSizeOfSecureBootGroup())
    {
      vHsm_SecureBoot_CurrentCyclicGroupIdx = 0u;
    }

    /* #20 Check if group is cyclic verification */
    if (vHsm_IsCyclicVerificationOfSecureBootGroup(vHsm_SecureBoot_CurrentCyclicGroupIdx) == TRUE)
    {
#  if (VHSM_CUSTOMCALLOUTCYCLIC == STD_ON)
      /* #21 Check if a custom callout shall be called */
      boolean cyclicVerificationAllowed = vHsm_Custom_IsSecureBootAllowCyclicVerification_Callout(vHsm_SecureBoot_CurrentCyclicGroupIdx, vHsm_GetIdOfSecureBootGroup(vHsm_SecureBoot_CurrentCyclicGroupIdx));;

      /* #22 Check if cyclic verification has been granted */
      if (cyclicVerificationAllowed == TRUE)
#  endif
      {
        vHsm_Core_SecureBoot_VerMethodType verMethod;
        vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: Cyclic Verification start of Group 0x%08X\n", vHsm_GetIdOfSecureBootGroup(vHsm_SecureBoot_CurrentCyclicGroupIdx));

        if (vHsm_IsCompInternalOfSecureBootGroup(vHsm_SecureBoot_CurrentCyclicGroupIdx))
        {
          verMethod = VHSM_VERMETHOD_COMPARE_INTERNAL_TAG;
        }
        else
        {
          verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
        }
        SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();
        /* Enqueue the group as parallel and cyclic to ensure that every mode is processed */
        (void)vHsm_Core_SecureBoot_QueueAddGroup(vHsm_SecureBoot_CurrentCyclicGroupIdx, FALSE, verMethod);
        (void)vHsm_Core_SecureBoot_QueueAddGroup(vHsm_SecureBoot_CurrentCyclicGroupIdx, TRUE, verMethod);
        vHsm_SecureBoot_CurrentCyclicGroupIdx++;

        SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
      }
#  if (VHSM_CUSTOMCALLOUTCYCLIC == STD_ON)
      else
      {
        vHsm_SecureBoot_CurrentCyclicGroupIdx++;
      }
#  endif
    }
    else
    {
      vHsm_SecureBoot_CurrentCyclicGroupIdx++;
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
# endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_HandleComputedTag()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_HandleComputedTag(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) computedTag,
  P2VAR(Crypto_VerifyResultType, AUTOMATIC, VHSM_APPL_VAR) result,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBootInfoPtr,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) extSegmentListPtr,
  uint8 processing
  )
{
  Std_ReturnType retVal = E_OK;
  vHsm_SecureBoot_SegmentInfoType segmentInfo;
  segmentInfo.segmentIdx = segmentIdx;

  vHsm_SecureBootInfoPtr->retry = FALSE;
  vHsm_SecureBootInfoPtr->segmentIdx = segmentIdx;

  if (vHsm_Core_SecureBoot_GetSegmentInfo(
    &segmentInfo,
    extSegmentListPtr,
    vHsm_SecureBootInfoPtr->verMethod,
    processing
  ) != E_OK) /* PRQA S 2996, 2992 */ /* MD_VHSM_2996_2992_SECUREBOOT_CONDITION_TRUE_IN_OTHER_CONFIGS */
  {
    retVal = E_NOT_OK;
  }
# if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  else if (vHsm_SecureBootInfoPtr->verMethod == VHSM_VERMETHOD_COMPARE_INTERNAL_TAG) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
  {
    /* #10 Store tag if none is available, this can not happen for external segment lists */
    if (segmentInfo.tagAvailable == FALSE)
    {
#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
      /* Check if there is a recovery from external segment list possible */
      if (vHsm_IsExternalSlOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)))
      {
        if (vHsm_SecureBoot_PerformRecovery_Callout(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx), VHSM_SECUREBOOTRECOVERY_TAG_MISMATCH))
        {
          vHsm_SecureBootInfoPtr->recovery = TRUE;
          /* Trigger execution of ExtSl verification.
          If the memory is identified as invalid at a later point in time, a sanction will be triggered during processing the external segment list.
          If the external segment list was valid, it was ok that we stored the CMAC.
          */
        }
      }
#  endif

      /* No tag for comparison is available. store it */
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: TAG sIdx %2i gId %2i          | Store\n", segmentIdx, vHsm_GetIdOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
      retVal = vHsm_Api_KeyElementSet_Unchecked(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx), CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC, computedTag, vHsm_GetTagLengthOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));
      retVal |= vHsm_Api_KeyValidSet(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx));
#  else
      VStdLib_MemCpy(vHsm_SecureBoot_GetTagOfSegmentInfo(segmentIdx), computedTag, vHsm_GetTagLengthOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx))); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentIdx) = TRUE;
      retVal |= vHsm_SecureBoot_PersistGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */
#  endif

#  if(VHSM_SECURE_BOOT_SEGMENT_SUCCESS_CALLOUT == STD_ON)
      vHsm_SecureBoot_SegmentSuccess_Callout(0u, vHsm_SecureBootInfoPtr);
#  endif

      *result = CRYPTO_E_VER_OK;
    }
    /* #20 Compare computed and stored tag */
    else if (vHsm_Core_SecureBoot_IsMemEqual(computedTag, segmentInfo.tagPtr, vHsm_Core_SecureBoot_GetTagLength(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx), vHsm_SecureBootInfoPtr->verMethod)) == TRUE)
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: TAG sIdx %2i gId %2i          | Compare: valid\n", segmentIdx, vHsm_GetIdOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));

#  if(VHSM_SECURE_BOOT_SEGMENT_SUCCESS_CALLOUT == STD_ON)
      vHsm_SecureBootInfoPtr->sanctionReason = VHSM_SECUREBOOTSANCTION_NONE;
      vHsm_SecureBoot_SegmentSuccess_Callout(0u, vHsm_SecureBootInfoPtr);
#  endif

      *result = CRYPTO_E_VER_OK;
    }
    else
    {
      /* #30 Invalid tag available */
#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
      boolean surpressSanctionBecauseOfRecovery = FALSE;
      if (vHsm_IsExternalSlOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)))
      {
        if (vHsm_SecureBoot_PerformRecovery_Callout(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx), VHSM_SECUREBOOTRECOVERY_TAG_MISMATCH))
        {
          vHsm_SecureBootInfoPtr->recovery = TRUE;
          /* Trigger execution of ExtSl verification.
          If the memory is identified as invalid at a later point in time, a sanction will be triggered during processing the external segment list.
          If the external segment list was valid, it was ok that we stored the CMAC.
          */
          vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: TAG sIdx %2i gId %2i          | Compare: NOT valid -> Surpress Sanction and start recovery\n", segmentIdx, vHsm_GetIdOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));
          surpressSanctionBecauseOfRecovery = TRUE;
        }
      }

      if (surpressSanctionBecauseOfRecovery == FALSE)
#  endif
      {
        vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: TAG sIdx %2i gId %2i          | Compare: NOT valid\n", segmentIdx, vHsm_GetIdOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));
        /* #40 Perform the sanction if the Tag is not the same */
        vHsm_SecureBootInfoPtr->sanctionReason = VHSM_SECUREBOOTSANCTION_TAG_MISMATCH;
        vHsm_SecureBootInfoPtr->resultOverwrite = CRYPTO_E_VER_NOT_OK;
        retVal |= vHsm_Core_SecureBoot_PerformSanction(segmentIdx, vHsm_SecureBootInfoPtr); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */
        *result = vHsm_SecureBootInfoPtr->resultOverwrite;
      }
    }
  }
# endif
# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  else if (vHsm_SecureBootInfoPtr->verMethod == VHSM_VERMETHOD_EXTERNAL_SL) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
  {
    if (vHsm_Core_SecureBoot_IsMemEqual(computedTag, segmentInfo.tagPtr, vHsm_Core_SecureBoot_GetTagLength(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx), vHsm_SecureBootInfoPtr->verMethod)) == TRUE)
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: TAG sIdx %2i gId %2i          | Compare: valid\n", segmentIdx, vHsm_GetIdOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));

#  if(VHSM_SECURE_BOOT_SEGMENT_SUCCESS_CALLOUT == STD_ON)
      vHsm_SecureBootInfoPtr->sanctionReason = VHSM_SECUREBOOTSANCTION_NONE;
      vHsm_SecureBoot_SegmentSuccess_Callout(0u, vHsm_SecureBootInfoPtr);
#  endif

      *result = CRYPTO_E_VER_OK;
    }
    else
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: TAG sIdx %2i gId %2i          | Compare: NOT valid\n", segmentIdx, vHsm_GetIdOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)));
      /* #40 Perform the sanction if the Tag is not the same */
      vHsm_SecureBootInfoPtr->sanctionReason = VHSM_SECUREBOOTSANCTION_TAG_MISMATCH;
      vHsm_SecureBootInfoPtr->resultOverwrite = CRYPTO_E_VER_NOT_OK;
      retVal |= vHsm_Core_SecureBoot_PerformSanction(segmentIdx, vHsm_SecureBootInfoPtr); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */
      *result = vHsm_SecureBootInfoPtr->resultOverwrite;
    }
  }
# endif
  else
  {
    /* Do nothing */
  }

  return retVal;
} /* PRQA S 6030, 6050, 6060, 6080 */ /* MD_MSR_STCYC */ /* MD_MSR_STCAL */ /* MD_VHSM_6060_STPAR */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetVerificationJobService()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(uint8, VHSM_CODE) vHsm_Core_SecureBoot_GetVerificationJobService(
  uint32 groupIdx,
  vHsm_Core_SecureBoot_VerMethodType verMethod)
{
  uint8 service = 0xFF;
# if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  if (verMethod == VHSM_VERMETHOD_COMPARE_INTERNAL_TAG)
  {
    service = vHsm_GetServiceOfSecureBootGroup(groupIdx);
  }
# endif
# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  /* Set hash as service if the verification method is external segment list */
  if (verMethod == VHSM_VERMETHOD_EXTERNAL_SL)
  {
    service = CRYPTO_HASH;
  }
  VHSM_DUMMY_STATEMENT(groupIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return service;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetVerificationJobId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetVerificationJobId(
  uint32 groupIdx,
  uint8 processing,
  vHsm_Core_SecureBoot_VerMethodType verMethod)
{
  uint32 jobId;
  uint32 verJobIdx = 0u;

  /* Get index of verification job */
# if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  if (verMethod == VHSM_VERMETHOD_COMPARE_INTERNAL_TAG)
  {
    verJobIdx = vHsm_GetVerJobCompInternalOfSecureBootGroup(groupIdx);
  }
# endif
# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  if (verMethod == VHSM_VERMETHOD_EXTERNAL_SL)
  {
    verJobIdx = vHsm_GetVerJobExternalSlOfSecureBootGroup(groupIdx);
  }
  VHSM_DUMMY_STATEMENT(groupIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* Get CSM job according to processing mode */
  if (processing == VHSM_SEQUENTIAL)
  {
    jobId = vHsm_GetCsmJobSequentialRefOfSecureBootVerificationJob(verJobIdx);
  }
  else
  {
    jobId = vHsm_GetCsmJobParallelRefOfSecureBootVerificationJob(verJobIdx);
  }

  return jobId;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_StartTagCalculation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_StartTagCalculation(
  vHsm_SecureBootGroupIterType groupIdx,
  uint8 processing,
  vHsm_Core_SecureBoot_VerMethodType verMethod)
{
  /* #20 Start tag calculation job */
  return vHsm_Core_SecureBoot_TagCalculationJob(
    vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, processing, verMethod),
    vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, verMethod),
    CRYPTO_OPERATIONMODE_START,
    NULL_PTR, 0u,
    NULL_PTR, NULL_PTR);
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetTagLength()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetTagLength(
  uint32 groupIdx,
  vHsm_Core_SecureBoot_VerMethodType verMethod)
{
  uint32 tagLength = 0u;
# if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  if (verMethod == VHSM_VERMETHOD_COMPARE_INTERNAL_TAG)
  {
    tagLength = vHsm_GetTagLengthOfSecureBootGroup(groupIdx);
  }
# endif
# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  if (verMethod == VHSM_VERMETHOD_EXTERNAL_SL)
  {
    tagLength = 32u;
  }
  VHSM_DUMMY_STATEMENT(groupIdx); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return tagLength;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_EndTagCalculation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_EndTagCalculation(
  vHsm_SecureBootGroupIterType groupIdx,
  uint8 processing,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) tagPtr,
  uint32 tagLength,
  vHsm_Core_SecureBoot_VerMethodType verMethod)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 tmpTagLength = tagLength;
  uint32 expectedtagLength;

  expectedtagLength = vHsm_Core_SecureBoot_GetTagLength(groupIdx, verMethod);

  if (tagLength >= expectedtagLength)
  {
    tmpTagLength = expectedtagLength;
  }

  /* #20 Finish tag calculation job */
  if (vHsm_Core_SecureBoot_TagCalculationJob(
    vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, processing, verMethod),
    vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, verMethod),
    CRYPTO_OPERATIONMODE_FINISH,
    NULL_PTR, 0u,
    tagPtr, &tmpTagLength) == E_OK)
  {
    /* Check if size of the tag is correct */
    if (tmpTagLength == expectedtagLength)
    {
      retVal = E_OK;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetSegmentInfo()
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
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetSegmentInfo(
  P2VAR(vHsm_SecureBoot_SegmentInfoType, AUTOMATIC, VHSM_APPL_VAR) segmentInfoPtr,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) extSegmentListPtr, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  vHsm_Core_SecureBoot_VerMethodType verMethod,
  uint8 processing)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)

    Std_ReturnType retValTag;
    uint32 tagLength = vHsm_GetTagLengthOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentInfoPtr->segmentIdx));
    vHsm_Api_KeyStorageIndexType tagIdx;

    /* #10 Get segment information from CSM secureboot storage */
    /* Get the size of the secure boot slot */
    retVal = vHsm_Core_SecureBoot_GetSegmentInfoPart(segmentInfoPtr->segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_SIZE, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&segmentInfoPtr->size, sizeof(uint32));
    /* Get the address of the secure boot slot */
    retVal |= vHsm_Core_SecureBoot_GetSegmentInfoPart(segmentInfoPtr->segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_ADDRESS, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&segmentInfoPtr->address, sizeof(uint32));
    /* Get the mode of the secure boot slot */
    retVal |= vHsm_Core_SecureBoot_GetSegmentInfoPart(segmentInfoPtr->segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_MODE, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))&segmentInfoPtr->mode, sizeof(uint8));
    /* Get the cmac of the secure boot slot */
    retValTag = vHsm_Api_Local_KeyElementGet(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentInfoPtr->segmentIdx), CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_CMAC, &tagIdx, &tagLength);

    /* If fetch of all data was ok: */
    if (retVal == E_OK)
    {
      /* Check if TAG is available */
      if ((retValTag == E_OK) && (tagLength == vHsm_GetTagLengthOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentInfoPtr->segmentIdx))))
      {
        /* Store TAG to the destination buffer */
        segmentInfoPtr->tagPtr = vHsm_Api_GetAddrKeyStorage(tagIdx);

        /* Indicate that a CMAC is available in the segment */
        segmentInfoPtr->tagAvailable = TRUE;
      }
      else
      {
        /* Indicate that a CMAC is not available in the segment */
        segmentInfoPtr->tagAvailable = FALSE;
      }
      retVal = E_OK;
    }
    VHSM_DUMMY_STATEMENT(verMethod); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# else
#  if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  if ((verMethod== VHSM_VERMETHOD_EXTERNAL_SL) && (extSegmentListPtr != NULL_PTR))
  {
    /* #20 Get segment information from external segment list */
    vHsm_SecureBootGroupIterType groupIdx = vHsm_GetGroupIdxOfSecureBootSegment(segmentInfoPtr->segmentIdx);
    if (extSegmentListPtr->isSlValid == FALSE)
    {
      /* retVal can be ignored as we are only interested in the valid flag. If persisting was successful does not matter in this case. */
      (void)vHsm_Core_SecureBoot_VerifyExtSl(groupIdx, extSegmentListPtr, processing);
    }

    if(extSegmentListPtr->isSlValid == TRUE)
    {
      segmentInfoPtr->mode    = extSegmentListPtr->segments[vHsm_SecureBoot_GetSegmentPositionWithinGroup(segmentInfoPtr->segmentIdx, groupIdx)].mode;
      segmentInfoPtr->address = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(extSegmentListPtr->segments[vHsm_SecureBoot_GetSegmentPositionWithinGroup(segmentInfoPtr->segmentIdx, groupIdx)].address); /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
      segmentInfoPtr->size    = extSegmentListPtr->segments[vHsm_SecureBoot_GetSegmentPositionWithinGroup(segmentInfoPtr->segmentIdx, groupIdx)].length;
      segmentInfoPtr->tagPtr  = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(extSegmentListPtr->segments[vHsm_SecureBoot_GetSegmentPositionWithinGroup(segmentInfoPtr->segmentIdx, groupIdx)].SLHash);
      segmentInfoPtr->tagAvailable = TRUE;
      segmentInfoPtr->sanction = (uint8)vHsm_GetSanctionOfSecureBootGroup(groupIdx);
      retVal = E_OK;
    }
  }
#  endif
#  if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  if (verMethod == VHSM_VERMETHOD_COMPARE_INTERNAL_TAG)
  {
    /* #30 Get segment information from NvM secureboot storage */
    segmentInfoPtr->address       = vHsm_SecureBoot_GetAddressOfSegmentInfo(segmentInfoPtr->segmentIdx); /* PRQA S 3305, 0310 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
    segmentInfoPtr->size          = vHsm_SecureBoot_GetSizeOfSegmentInfo(segmentInfoPtr->segmentIdx); /* PRQA S 3305, 0310 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
    segmentInfoPtr->mode          = vHsm_SecureBoot_GetModeOfSegmentInfo(segmentInfoPtr->segmentIdx);
    segmentInfoPtr->sanction      = vHsm_SecureBoot_GetSanctionOfSegmentInfo(segmentInfoPtr->segmentIdx);
    segmentInfoPtr->tagPtr        = vHsm_SecureBoot_GetTagOfSegmentInfo(segmentInfoPtr->segmentIdx);
    segmentInfoPtr->tagAvailable  = vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentInfoPtr->segmentIdx);

    retVal = E_OK;
  }
#  endif
# endif

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_OFF)
  VHSM_DUMMY_STATEMENT(extSegmentListPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(processing); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetInputLengthBySplitSize()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetInputLengthBySplitSize(
  P2CONST(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr)
{
  uint32 splitSize;
  uint32 inputLength;

  /* #10 Get split size */
# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
  if (secureBootInfoPtr->isCyclicVerification == TRUE)
  {
    splitSize = VHSM_SECURE_BOOT_CYCLIC_VERIFICATION_SPLIT_SIZE;
  }
  else
# else
  VHSM_DUMMY_STATEMENT(secureBootInfoPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  {
    splitSize = VHSM_SECURE_BOOT_SPLIT_SIZE;
  }

  /* #20 Calculate input length with respect to already processed bytes */
  if ((vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.size - vHsm_Core_SecureBoot_Workspace.alreadyProcessed) > splitSize)
  {
    inputLength = splitSize;
  }
  else
  {
    inputLength = vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.size - vHsm_Core_SecureBoot_Workspace.alreadyProcessed;
  }

  return inputLength;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_HandleRetry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE)vHsm_Core_SecureBoot_HandleRetry(
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) loopInc)
{
  /* #10 Check if retry is set */
  if (secureBootInfoPtr->retry == TRUE)
  {
    /* #20 Reset retry */
    *loopInc = 0u;
    secureBootInfoPtr->retry = FALSE;
  }
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ProcessGroupParallel()
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
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_ProcessGroupParallel(
  vHsm_SecureBootGroupIterType groupIdx,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr)
{
# if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBoot_ExtSegmentListPtr = &vHsm_SecureBoot_ExtSegmentList;
# else
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) vHsm_SecureBoot_ExtSegmentListPtr = NULL_PTR;
# endif

  uint8 loopInc;

  Std_ReturnType retVal = E_OK;
  Crypto_VerifyResultType result = CRYPTO_E_VER_NOT_OK;
  uint8 computedTag[VHSM_MAX_TAG_SIZE_OR_SHA256];
  vHsm_TagHandlingOfSecureBootGroupType tagHandling;

  if (secureBootInfoPtr->verMethod == VHSM_VERMETHOD_EXTERNAL_SL)
  {
    /* External SL verification always uses one hash per segment */
    tagHandling = VHSM_SEGMENT_TAG;
  }
  else
  {
    tagHandling = vHsm_GetTagHandlingOfSecureBootGroup(groupIdx);
  }

  if (vHsm_Core_SecureBoot_Workspace.inProgress == FALSE)
  {
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB:--------------------------------------------------------------------------\n");
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR Init Processing Group %2i %s %s CYC=%i\n", vHsm_GetIdOfSecureBootGroup(groupIdx), string_Processing[VHSM_PARALLEL], string_TagHandling[tagHandling], secureBootInfoPtr->isCyclicVerification);

    /* #10 Get segment start index */
    vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx);
    vHsm_Core_SecureBoot_Workspace.inProgress = TRUE;
  }

  if ((vHsm_Core_SecureBoot_Workspace.state == CRYPTO_OPERATIONMODE_START)
    && (VHSM_SEGMENT_TAG != tagHandling))
  {
    /* Only set some flags */
    vHsm_Core_SecureBoot_Workspace.pendingStart = TRUE;
  }

  /* PRQA S 3415 2 */ /* MD_VHSM_3415_SIDE_EFFECTS */
  if ((vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx < vHsm_GetSizeOfSecureBootSegment())
     && (vHsm_Core_SecureBoot_GetSegmentInfo(&vHsm_Core_SecureBoot_Workspace.currentSegmentInfo, vHsm_SecureBoot_ExtSegmentListPtr, secureBootInfoPtr->verMethod, VHSM_PARALLEL) != E_OK)) /* PRQA S 2996, 2992 */ /* MD_VHSM_2996_2992_SECUREBOOT_CONDITION_TRUE_IN_OTHER_CONFIGS */
  {
    vHsm_State.vHsm_SecureBootState.segmentResult[vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx] = CRYPTO_E_VER_NOT_OK;
    vHsm_State.vHsm_SecureBootState.segmentFinished[vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx] = TRUE;
    vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] = CRYPTO_E_VER_NOT_OK;
    vHsm_State.vHsm_SecureBootState.groupFinished[groupIdx] = TRUE;

    vHsm_Core_SecureBoot_Workspace.inProgress = FALSE;
    vHsm_Core_SecureBoot_Workspace.state = CRYPTO_OPERATIONMODE_START;
    retVal = E_NOT_OK; /* Sanction is performed on error */
  }
  else
  {
    /* #20 Process parallel segments of the group */
    if (vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx))
    {
      loopInc = 0u;
      if ((vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.mode == VHSM_PARALLEL)
        || ((vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.mode == VHSM_SEQUENTIAL) && (secureBootInfoPtr->isCyclicVerification == TRUE)))
      {
        if (((vHsm_Core_SecureBoot_Workspace.state == CRYPTO_OPERATIONMODE_START)
          && (VHSM_SEGMENT_TAG == tagHandling))
          || vHsm_Core_SecureBoot_Workspace.pendingStart)
        {
          vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR sIdx %2i %s | START  Tag\n", vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx, string_Processing[vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.mode]);
          retVal = vHsm_Core_SecureBoot_StartTagCalculation(groupIdx, VHSM_PARALLEL, secureBootInfoPtr->verMethod);
          vHsm_Core_SecureBoot_Workspace.state = CRYPTO_OPERATIONMODE_UPDATE;
          vHsm_Core_SecureBoot_Workspace.pendingStart = FALSE;
          vHsm_Core_SecureBoot_Workspace.pendingFinish = TRUE;
          vHsm_Core_SecureBoot_Workspace.alreadyProcessed = 0u;
          vHsm_Core_SecureBoot_Workspace.segmentUsedForTag = vHsm_Core_SecureBoot_Workspace.currentSegmentInfo;
        }

        if (vHsm_Core_SecureBoot_Workspace.state == CRYPTO_OPERATIONMODE_UPDATE)
        {
          /* #30 Get the splitsize which shall be used to process the segment */
          uint32 inputLength = vHsm_Core_SecureBoot_GetInputLengthBySplitSize(secureBootInfoPtr);

          vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR sIdx %2i %s | UPDATE Tag\n", vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx, string_Processing[vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.mode]);
          retVal |= vHsm_Core_SecureBoot_TagCalculationJob(
            vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_PARALLEL, secureBootInfoPtr->verMethod),
            vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, secureBootInfoPtr->verMethod),
            CRYPTO_OPERATIONMODE_UPDATE,
            vHsm_Hal_GetCodeFlashAddr(&vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.address[vHsm_Core_SecureBoot_Workspace.alreadyProcessed]), inputLength,
            NULL_PTR, NULL_PTR);

          /* #31 Update the number of processed bytes after executing the job */
          vHsm_Core_SecureBoot_Workspace.alreadyProcessed += inputLength;

          if (vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.size == vHsm_Core_SecureBoot_Workspace.alreadyProcessed)
          {
            loopInc = 1u;
            vHsm_Core_SecureBoot_Workspace.alreadyProcessed = 0u;
          }
        }

        /* #40 Finish processing and handle computed segment tag */
        if ((vHsm_Core_SecureBoot_Workspace.state == CRYPTO_OPERATIONMODE_UPDATE)
          && (0u == vHsm_Core_SecureBoot_Workspace.alreadyProcessed))
        {
          if (tagHandling == VHSM_SEGMENT_TAG)
          {
            vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR sIdx %2i %s | FINISH Tag of Segment\n", vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx, string_Processing[vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.mode]);

            retVal |= vHsm_Core_SecureBoot_EndTagCalculation(groupIdx, VHSM_PARALLEL, computedTag, sizeof(computedTag), secureBootInfoPtr->verMethod);
            retVal |= vHsm_Core_SecureBoot_HandleComputedTag(
              vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx,
              computedTag,
              &result,
              secureBootInfoPtr,
              vHsm_SecureBoot_ExtSegmentListPtr,
              VHSM_PARALLEL);
            vHsm_Core_SecureBoot_Workspace.state = CRYPTO_OPERATIONMODE_START;
            vHsm_Core_SecureBoot_Workspace.pendingFinish = FALSE;

            vHsm_Core_SecureBoot_HandleRetry(secureBootInfoPtr, &loopInc);

            vHsm_State.vHsm_SecureBootState.segmentResult[vHsm_Core_SecureBoot_Workspace.segmentUsedForTag.segmentIdx] |= result;
            vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] |= result;
          }

          /* Mark all segments (regardless of tag handling) as processed */
          vHsm_State.vHsm_SecureBootState.segmentFinished[vHsm_Core_SecureBoot_Workspace.segmentUsedForTag.segmentIdx] = TRUE;
        }
      }
      else
      {
        vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR sIdx %2i %s |\n", vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx, string_Processing[vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.mode]);
        loopInc = 1u;
      }
      vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx = (vHsm_SecureBootSegmentIterType)(vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx + loopInc);
    }
    else
    {
      vHsm_Core_SecureBoot_Workspace.inProgress = FALSE;
    }
  }

  /* #50 Finish processing and handle computed group/processing tag */
  if ((tagHandling != VHSM_SEGMENT_TAG)
    && (vHsm_Core_SecureBoot_Workspace.pendingFinish == TRUE)
    && (vHsm_Core_SecureBoot_Workspace.currentSegmentInfo.segmentIdx == vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx)))
  {
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR sIdx %2i %s | FINISH Tag of Group %2i\n", vHsm_Core_SecureBoot_Workspace.segmentUsedForTag.segmentIdx, string_Processing[vHsm_Core_SecureBoot_Workspace.segmentUsedForTag.mode], vHsm_GetIdOfSecureBootGroup(groupIdx));
    vHsm_Core_SecureBoot_Workspace.alreadyProcessed = 0u;
    retVal |= vHsm_Core_SecureBoot_EndTagCalculation(groupIdx, VHSM_PARALLEL, computedTag, sizeof(computedTag), secureBootInfoPtr->verMethod);
    retVal |= vHsm_Core_SecureBoot_HandleComputedTag(
      vHsm_Core_SecureBoot_Workspace.segmentUsedForTag.segmentIdx,
      computedTag,
      &result,
      secureBootInfoPtr,
      vHsm_SecureBoot_ExtSegmentListPtr,
      VHSM_PARALLEL);

    vHsm_Core_SecureBoot_Workspace.inProgress = FALSE;
    vHsm_Core_SecureBoot_Workspace.state = CRYPTO_OPERATIONMODE_START;
    vHsm_Core_SecureBoot_Workspace.pendingFinish = FALSE;
    vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] |= result;
  }

  /* handle errors during processing of secure boot */
  if (retVal != E_OK)
  {
    vHsm_SecureBootSegmentIterType segmentIter;

    /* Set all segments of this group to done because the group will be removed from the queue afterwards */
    for (segmentIter = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIter < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIter++)
    {
      vHsm_State.vHsm_SecureBootState.segmentFinished[segmentIter] = TRUE;
      vHsm_State.vHsm_SecureBootState.segmentResult[segmentIter] = CRYPTO_E_VER_NOT_OK;
    }

    vHsm_State.vHsm_SecureBootState.groupFinished[groupIdx] = TRUE;
    vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] = CRYPTO_E_VER_NOT_OK;

    vHsm_Core_SecureBoot_Workspace.inProgress = FALSE;
    vHsm_Core_SecureBoot_Workspace.state = CRYPTO_OPERATIONMODE_START;
  }

  vHsm_Core_SecureBoot_CheckGroupValidity(groupIdx);
  vHsm_Core_SecureBoot_CheckErrors(groupIdx, retVal, secureBootInfoPtr);

  return retVal;
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH */ /* MD_MSR_STCYC */ /* MD_MSR_STCAL */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ProcessGroupSequential()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_ProcessGroupSequential(
  vHsm_SecureBootGroupIterType groupIdx,
  boolean forcedSequential,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) secureBootInfoPtr,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) extSegmentListPtr)
{
  uint8 loopInc;
  vHsm_SecureBoot_SequentialWorkspaceType seqWorkspace;
  Std_ReturnType retVal;

  do
  {
    Crypto_VerifyResultType result = CRYPTO_E_VER_NOT_OK;
    vHsm_TagHandlingOfSecureBootGroupType tagHandling;

    if (secureBootInfoPtr->verMethod == VHSM_VERMETHOD_EXTERNAL_SL)
    {
      /* External SL verification always uses one hash per segment */
      tagHandling = VHSM_SEGMENT_TAG;
    }
    else
    {
      tagHandling = vHsm_GetTagHandlingOfSecureBootGroup(groupIdx);
    }

    retVal = E_OK;

    seqWorkspace.verMethod = secureBootInfoPtr->verMethod;
    seqWorkspace.forceSequential = forcedSequential;
    /* START (Group,Processing) */
    seqWorkspace.pendingStart = (VHSM_SEGMENT_TAG != tagHandling);
    seqWorkspace.pendingFinish = FALSE;
    seqWorkspace.segmentUsedForTag.mode = CRYPTO_30_VHSM_MODE_NONE;
    seqWorkspace.segmentUsedForTag.segmentIdx = 0u;

    /* Let the internal logic ofvHsm_SecureBoot_SequentialTagCalculationOfGroup() do the START|UPDATE|FINISH handling */
    seqWorkspace.atomicFlags = VHSM_SECUREBOOT_ATOMICFLAGS_SINGLECALL;

    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB:--------------------------------------------------------------------------\n");
    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: SEQ Init Processing Group %2i %s %s FORCE %i\n", vHsm_GetIdOfSecureBootGroup(groupIdx), string_Processing[VHSM_SEQUENTIAL], string_TagHandling[tagHandling], forcedSequential);

    /* #10 Get segment start index */
    seqWorkspace.segmentInfo.segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx);

    /* #20 Process sequential segments of the group */
    while (seqWorkspace.segmentInfo.segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx))
    {
      loopInc = 1u;
      if (vHsm_Core_SecureBoot_GetSegmentInfo(
        &(seqWorkspace.segmentInfo),
        extSegmentListPtr,
        secureBootInfoPtr->verMethod,
        VHSM_SEQUENTIAL) != E_OK) /* PRQA S 2996, 2992 */ /* MD_VHSM_2996_2992_SECUREBOOT_CONDITION_TRUE_IN_OTHER_CONFIGS */
      {
        vHsm_SecureBootSegmentIterType segmentIter;

        secureBootInfoPtr->sanctionReason = VHSM_SECUREBOOTSANCTION_SECUREBOOT_ERROR;
        secureBootInfoPtr->resultOverwrite = CRYPTO_E_VER_NOT_OK;
        retVal = vHsm_Core_SecureBoot_PerformSanction(seqWorkspace.segmentInfo.segmentIdx, secureBootInfoPtr); /* Failed getting of segment info will result in invalid group instead of failed secure boot. */
        /* Set all segments of this group to done and failed when overwrite was not changed intentionally */
        for (segmentIter = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIter < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIter++)
        {
          vHsm_State.vHsm_SecureBootState.segmentFinished[segmentIter] = TRUE;
          vHsm_State.vHsm_SecureBootState.segmentResult[segmentIter] = secureBootInfoPtr->resultOverwrite;
        }
        vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] = secureBootInfoPtr->resultOverwrite;
        vHsm_State.vHsm_SecureBootState.groupFinished[groupIdx] = TRUE;
        break;
      }
      else
      {
        retVal |= vHsm_SecureBoot_SequentialTagCalculationOfGroup(groupIdx, &seqWorkspace);

        vHsm_State.vHsm_SecureBootState.segmentFinished[seqWorkspace.segmentInfo.segmentIdx] = TRUE;

        /* #30 Finish processing and handle computed segment tag */
        if (seqWorkspace.tagLength > 0u)
        {
          retVal |= vHsm_Core_SecureBoot_HandleComputedTag(seqWorkspace.segmentInfo.segmentIdx,
            (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))(seqWorkspace.computedTag),
            &result,
            secureBootInfoPtr,
            extSegmentListPtr,
            VHSM_SEQUENTIAL);

          vHsm_Core_SecureBoot_HandleRetry(secureBootInfoPtr, &loopInc);

          vHsm_State.vHsm_SecureBootState.segmentResult[seqWorkspace.segmentInfo.segmentIdx] |= result;
        }
      }
      seqWorkspace.segmentInfo.segmentIdx = (vHsm_SecureBootSegmentIterType)(seqWorkspace.segmentInfo.segmentIdx+loopInc);
    }

    /* #40 Finish processing and handle computed group/processing tag */
    if ((tagHandling != VHSM_SEGMENT_TAG)
      && (seqWorkspace.pendingFinish == TRUE))
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: SEQ sIdx %2i %s | FINISH Tag of Group %2i\n",
        seqWorkspace.segmentUsedForTag.segmentIdx,
        string_Processing[seqWorkspace.segmentUsedForTag.mode],
        vHsm_GetIdOfSecureBootGroup(groupIdx));

      retVal |= vHsm_Core_SecureBoot_EndTagCalculation(groupIdx, VHSM_SEQUENTIAL, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(seqWorkspace.computedTag), sizeof(seqWorkspace.computedTag), secureBootInfoPtr->verMethod);
      retVal |= vHsm_Core_SecureBoot_HandleComputedTag(seqWorkspace.segmentUsedForTag.segmentIdx,
        (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(seqWorkspace.computedTag),
        &result,
        secureBootInfoPtr,
        extSegmentListPtr,
        VHSM_SEQUENTIAL);

      vHsm_State.vHsm_SecureBootState.groupResult[groupIdx] |= result;
    }
    vHsm_Core_SecureBoot_CheckGroupValidity(groupIdx);
  } while ((retVal == E_OK) && (secureBootInfoPtr->retry == TRUE));

  vHsm_Core_SecureBoot_CheckErrors(groupIdx, retVal, secureBootInfoPtr);
  return retVal;
}/* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vHsm_SecureBoot_SequentialTagCalculationOfGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SequentialTagCalculationOfGroup(
  vHsm_SecureBootGroupIterType groupIdx,
  P2VAR(vHsm_SecureBoot_SequentialWorkspaceType, AUTOMATIC, VHSM_APPL_VAR) seqWorkspace)
{
  Std_ReturnType retVal = E_OK;

  vHsm_TagHandlingOfSecureBootGroupType tagHandling;

  if (seqWorkspace->verMethod == VHSM_VERMETHOD_EXTERNAL_SL)
  {
    /* External SL verification always uses one hash per segment */
    tagHandling = VHSM_SEGMENT_TAG;
  }
  else
  {
    tagHandling = vHsm_GetTagHandlingOfSecureBootGroup(groupIdx);
  }
  seqWorkspace->tagLength = 0u;

  if (seqWorkspace->segmentInfo.mode == VHSM_NONE)
  {
    /* #40 Handle none type segment processing */
    vHsm_State.vHsm_SecureBootState.segmentFinished[seqWorkspace->segmentInfo.segmentIdx] = TRUE;

    vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: SEQ sIdx %2i %s |\n", seqWorkspace->segmentInfo.segmentIdx, string_Processing[seqWorkspace->segmentInfo.mode]);
  }
  else if (((seqWorkspace->segmentInfo.mode == VHSM_SEQUENTIAL) && (seqWorkspace->forceSequential == FALSE))
    || ((seqWorkspace->segmentInfo.mode == VHSM_PARALLEL) && (seqWorkspace->forceSequential == TRUE) ))
  {
    /* #10 Start the segment */
    if (((tagHandling == VHSM_SEGMENT_TAG)
      || (seqWorkspace->pendingStart == TRUE))
      && ((seqWorkspace->atomicFlags & VHSM_SECUREBOOT_ATOMICFLAGS_START) == VHSM_SECUREBOOT_ATOMICFLAGS_START))
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: SEQ sIdx %2i %s | START  Tag\n", seqWorkspace->segmentInfo.segmentIdx, string_Processing[seqWorkspace->segmentInfo.mode]);
      retVal = vHsm_Core_SecureBoot_StartTagCalculation(groupIdx, VHSM_SEQUENTIAL, seqWorkspace->verMethod);
      seqWorkspace->pendingStart = FALSE;
      seqWorkspace->pendingFinish = TRUE;
      seqWorkspace->segmentUsedForTag = seqWorkspace->segmentInfo;
    }

    /* #20 Update the segment */
    if ((seqWorkspace->atomicFlags & VHSM_SECUREBOOT_ATOMICFLAGS_UPDATE) == VHSM_SECUREBOOT_ATOMICFLAGS_UPDATE)
    {
      seqWorkspace->segmentInfo.processsingPtr = seqWorkspace->segmentInfo.address;
      seqWorkspace->segmentInfo.processingLength = seqWorkspace->segmentInfo.size;
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: SEQ sIdx %2i %s | UPDATE Tag\n", seqWorkspace->segmentInfo.segmentIdx, string_Processing[seqWorkspace->segmentInfo.mode]);
      retVal |= vHsm_Core_SecureBoot_TagCalculationJob(
        vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, seqWorkspace->verMethod),
        vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, seqWorkspace->verMethod),
        CRYPTO_OPERATIONMODE_UPDATE,
        vHsm_Hal_GetCodeFlashAddr(seqWorkspace->segmentInfo.processsingPtr), seqWorkspace->segmentInfo.processingLength,
        NULL_PTR, NULL_PTR);
    }

    /* #30 Finish sequential segment processing with segment tag */
    if ((tagHandling == VHSM_SEGMENT_TAG)
      && ((seqWorkspace->atomicFlags & VHSM_SECUREBOOT_ATOMICFLAGS_FINISH) == VHSM_SECUREBOOT_ATOMICFLAGS_FINISH))
    {
      vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: SEQ sIdx %2i %s | FINISH Tag of Segment\n", seqWorkspace->segmentInfo.segmentIdx, string_Processing[seqWorkspace->segmentInfo.mode]);
      retVal |= vHsm_Core_SecureBoot_EndTagCalculation(groupIdx, VHSM_SEQUENTIAL, (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(seqWorkspace->computedTag), sizeof(seqWorkspace->computedTag), seqWorkspace->verMethod);
      seqWorkspace->tagLength = vHsm_Core_SecureBoot_GetTagLength(groupIdx, seqWorkspace->verMethod);
    }
  }
  else
  {
    /* Do nothing */
  }
  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_QueueRemoveEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_QueueRemoveEntry(void)
{
  uint32 queueIdx;

  SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();

  /* #10 Remove first queue item and move all other entries up. */
  for (queueIdx = 0u; queueIdx < vHsm_SecureBootQueue.queueTopIdx; queueIdx++)
  {
    vHsm_SecureBootQueue.queueItems[queueIdx] = vHsm_SecureBootQueue.queueItems[queueIdx + 1u];
  }

  if (vHsm_SecureBootQueue.queueTopIdx != 0u)
  {
    vHsm_SecureBootQueue.queueTopIdx--;
  }

  SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_QueueAddGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_QueueAddGroup(
  vHsm_SecureBootGroupIterType groupIdx,
  boolean isCyclicVerification,
  vHsm_Core_SecureBoot_VerMethodType verMethod)
{
  Std_ReturnType retVal = E_NOT_OK;

  SchM_Enter_vHsm_VHSM_EXCLUSIVE_AREA_0();

  if (vHsm_SecureBootQueue.queueTopIdx < vHsm_GetQueueSizeOfSecureBoot())
  {
    /* #10 Add all segments of the group to the queue */
    vHsm_SecureBootQueue.queueItems[vHsm_SecureBootQueue.queueTopIdx].groupIdx = groupIdx;
    vHsm_SecureBootQueue.queueItems[vHsm_SecureBootQueue.queueTopIdx].isCyclicverification = isCyclicVerification;
    vHsm_SecureBootQueue.queueItems[vHsm_SecureBootQueue.queueTopIdx].verMethod = verMethod;
    vHsm_SecureBootQueue.queueItems[vHsm_SecureBootQueue.queueTopIdx].recovery = FALSE;
    vHsm_SecureBootQueue.queueTopIdx++;
    retVal = E_OK;
  }
  else
  {
    vHsm_Trace(VHSM_TRACETYPE_ERROR, "Too many secure boot slots requested (max is %i) or group already in Queue\n", vHsm_GetQueueSizeOfSecureBoot());
    /* retVal already set */
  }

  SchM_Exit_vHsm_VHSM_EXCLUSIVE_AREA_0();
  return retVal;
}

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_PerformConfirmation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_PerformConfirmation(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer,
  boolean onInactivePartition,
  uint32 groupIdx)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint16 nSegmentsFromSL;
  uint32 segment;
  uint32 hashLength = VHSM_HASH_SIZE;
  uint8  calculatedHash[VHSM_HASH_SIZE] = { 0u };

  vHsm_SecureBoot_SegmentType segments[VHSM_MAX_SEGMENTS_PER_GROUP];
  VStdLib_MemClr(segments, sizeof(segment)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* Check the magic pattern */
  if (vHsm_Core_SecureBoot_IsMemEqual(vHsm_SecureBoot_GSL_Header_Pattern, buffer, VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH) == TRUE)
  {
    /* get number of segments in SL */
    nSegmentsFromSL = vHsm_Core_SecureBoot_BEtoU16(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SECUREBOOT_SL_GROUPID_LENGTH]);

    vHsm_Core_SecureBoot_ParseSl(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH], segments);

    /* recalculate the addresses in the received segmentlist and check the hash values. */
    for (segment = 0u; segment < nSegmentsFromSL; segment++)
    {
#  if (VHSM_PARTITION_LAYOUT == STD_ON)
      if (onInactivePartition == TRUE)
      {
        /* recalculate address with offset */
        P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) addressTmp = vHsm_Core_SecureBoot_GetAddressOfInactivePartition((P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR))segments[segment].address); /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
        segments[segment].address = (uint32)addressTmp; /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
      }
#  endif
      if (Csm_Hash(vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, VHSM_VERMETHOD_EXTERNAL_SL),
        CRYPTO_OPERATIONMODE_SINGLECALL,
        vHsm_Hal_GetCodeFlashAddr((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))segments[segment].address), /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
        segments[segment].length,
        calculatedHash,
        &hashLength) != E_OK)
      {
        retVal = E_NOT_OK;
      }
      else if (vHsm_Core_SecureBoot_IsMemEqual(calculatedHash, segments[segment].SLHash, VHSM_HASH_SIZE) == FALSE)
      {
        retVal = E_NOT_OK;
      }
      else
      {
        retVal = E_OK;
      }

      if (retVal != E_OK)
      {
        break;
      }
    }
  }

  if (retVal == E_OK)
  {
    uint32 lengthOfSegmentlist = (vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer) - VHSM_SECUREBOOT_SL_HEADER_LENGTH);
    uint32 bufferForNewVersionToStore = vHsm_Core_SecureBoot_BEtoU32(&buffer[VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH]);

    retVal = vHsm_SecureBoot_Revision_Callout(
      vHsm_Core_SecureBoot_BEtoU32(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH]),
#  if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
      vHsm_SecureBoot_GetGroupInfoOfGroupInfo(groupIdx),
#  else
      0u,
#  endif
      &buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH],
      lengthOfSegmentlist,
      &bufferForNewVersionToStore);
  }

#  if (VHSM_PARTITION_LAYOUT == STD_OFF)
  VHSM_DUMMY_STATEMENT(onInactivePartition); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#  if (VHSM_PARTITION_LAYOUT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetAddressOfInactivePartition()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR), VHSM_CODE) vHsm_Core_SecureBoot_GetAddressOfInactivePartition(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) address)
{
  uint32 resultAddress = (uint32)(address);   /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
  vHsm_PartitionGroupIterType partGroupIdx;
  vHsm_PartitionIterType partIdx;
  boolean found = FALSE;

  /* Iterate over all partition groups */
  for (partGroupIdx = 0u; partGroupIdx < vHsm_GetSizeOfPartitionGroup(); partGroupIdx++) /* COV_VHSM_BREAK_LOOP */
  {
    /* Iterate over both partitions of the group */
    for (partIdx = vHsm_GetPartitionRefIndStartIdxOfPartitionGroup(partGroupIdx); partIdx < vHsm_GetPartitionRefIndEndIdxOfPartitionGroup(partGroupIdx); partIdx++) /* COV_VHSM_BREAK_LOOP */
    {
      uint32 partStartAddr = vHsm_GetStartAddressOfPartition(vHsm_GetPartitionRef(partIdx));
      uint32 partLength = vHsm_GetLengthOfPartition(vHsm_GetPartitionRef(partIdx));

      /* Check if the partition contains the passed address */
      if ((resultAddress >= partStartAddr)
        && (resultAddress < (partStartAddr + partLength)))
      {
        found = TRUE;
        break;
      }
    }

    if (found) /* COV_VHSM_PARTITION_ALWAYS_FOUND */
    {
      /* Check if address is contained in first partition of the group */
      if (partIdx == vHsm_GetPartitionRefIndStartIdxOfPartitionGroup(partGroupIdx))
      {
        /* Substract the address of the first partition and add the address of the second partition to the passed address -> Add the offset */
        resultAddress = resultAddress - vHsm_GetStartAddressOfPartition(vHsm_GetPartitionRef(partIdx)) + vHsm_GetStartAddressOfPartition(vHsm_GetPartitionRef(partIdx + 1u));
      }
      else
      {
        /* Substract the address of the second partition and add the address of the first partition to the passed address -> Add the offset */
        resultAddress = resultAddress - vHsm_GetStartAddressOfPartition(vHsm_GetPartitionRef(partIdx)) + vHsm_GetStartAddressOfPartition(vHsm_GetPartitionRef(partIdx - 1u));
      }
      break;
    }
  }

  /* Return the modified address */
  return (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(resultAddress); /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
}
#  endif /* VHSM_PARTITION_LAYOUT == STD_ON */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetAddressOfSLOfGroupId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_GetAddressOfSLOfGroupId(
  uint32 groupId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) ptrToSegmentList,
  P2VAR(vHsm_SecureBootGroupIterType, AUTOMATIC, VHSM_APPL_VAR) groupIdx)
{
  Std_ReturnType retVal = E_NOT_OK;
  vHsm_SecureBootGroupIterType groupIndex;

  /* Get the index of the secureboot groupId */
  for (groupIndex = 0u; groupIndex < vHsm_GetSizeOfSecureBootGroup(); groupIndex++)
  {
    /* Find secureboot group in defined groups */
    if (vHsm_GetIdOfSecureBootGroup(groupIndex) == groupId)
    {
      /* Check if the verification method external segmentlist is used */
      if (vHsm_GetVerJobExternalSlOfSecureBootGroup(groupIndex) != VHSM_SECUREBOOTGROUP_INVALID_VERIFICATIONJOB_PATTERN )
      {
        *ptrToSegmentList = vHsm_GetSlLocationOfSecureBootGroup(groupIndex);
        *groupIdx = groupIndex;
        retVal = E_OK;
      }
      break;
    }
  }

  return retVal;
}
# endif /* (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON) */

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON) || (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_GetLengthOfSlWithHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(uint32, VHSM_CODE) vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrToSegmentList)
{
  uint16 nSegmentsFromSL;
  uint32 lengthOfSL;

  nSegmentsFromSL = vHsm_Core_SecureBoot_BEtoU16(&ptrToSegmentList[VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SECUREBOOT_SL_GROUPID_LENGTH]);
  lengthOfSL = VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SEGMENT_LIST_INFO + ((uint32)nSegmentsFromSL * VHSM_SIZE_OF_SEGMENT);

  return lengthOfSL;
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_ParseSl()
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
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_ParseSl(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrToSegmentlistWoHeader,
  vHsm_SecureBoot_SegmentType ptrToSegmentArray[VHSM_MAX_SEGMENTS_PER_GROUP])
{
  uint32 offset;
  uint16 currentSegment;
  uint16 nSegments;

  /* parse header */
  nSegments = vHsm_Core_SecureBoot_BEtoU16(&ptrToSegmentlistWoHeader[VHSM_SECUREBOOT_SL_GROUPID_LENGTH]);

  /* Check if the space in the structer matches */
  if (nSegments <= VHSM_MAX_SEGMENTS_PER_GROUP)
  {
    /* Parse the single segments */
    for (currentSegment = 0u; currentSegment < VHSM_MAX_SEGMENTS_PER_GROUP; currentSegment++)
    {
      if (currentSegment < nSegments)
      {
        offset = (uint32)(VHSM_SEGMENT_LIST_INFO + ((uint32)(currentSegment) * VHSM_SIZE_OF_SEGMENT));
        ptrToSegmentArray[currentSegment].address     = vHsm_Core_SecureBoot_BEtoU32(&ptrToSegmentlistWoHeader[offset]);
        ptrToSegmentArray[currentSegment].length      = vHsm_Core_SecureBoot_BEtoU32(&ptrToSegmentlistWoHeader[offset + 4u]);
        /* Mode is provided as uint16 but stored and processed as uint8 */
        ptrToSegmentArray[currentSegment].mode        = (uint8)(vHsm_Core_SecureBoot_BEtoU16(&ptrToSegmentlistWoHeader[offset + 8u]));
        ptrToSegmentArray[currentSegment].hashLength  = 0u;

        /* copy hash value of segment */
        VStdMemCpy(ptrToSegmentArray[currentSegment].SLHash, &ptrToSegmentlistWoHeader[offset + 10u], VHSM_HASH_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      }
      /* clear unused segments */
      else
      {
        ptrToSegmentArray[currentSegment].address     = 0u;
        ptrToSegmentArray[currentSegment].length      = 0u;
        ptrToSegmentArray[currentSegment].hashLength  = 0u;
        ptrToSegmentArray[currentSegment].mode        = CRYPTO_30_VHSM_MODE_NONE;
        VStdMemClr(ptrToSegmentArray[currentSegment].SLHash, VHSM_HASH_SIZE); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      }

    }
  }
}
# endif

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_VerifyExtSl()
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_VerifyExtSl(
  vHsm_SecureBootGroupIterType groupIdx,
  P2VAR(vHsm_SecureBoot_ExtSegmentListType, AUTOMATIC, VHSM_APPL_VAR) ptrToStructure,
  uint8 processing)
{
  Std_ReturnType retVal = E_NOT_OK;
#  if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
  uint32 hashLength = VHSM_HASH_SIZE;
  uint8 calculatedHash[VHSM_HASH_SIZE];
#  endif

  /* Get Pointer to segmentlist */
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrToSl = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)) (vHsm_GetSlLocationOfSecureBootGroup(groupIdx)); /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */

  /* Set structure invalid */
  ptrToStructure->isSlValid = FALSE;

  /* Check magic pattern */
  if (vHsm_Core_SecureBoot_IsMemEqual(vHsm_SecureBoot_GSL_Header_Pattern, vHsm_Hal_GetCodeFlashAddr(ptrToSl), VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH) == TRUE)
  {
    uint32 calculatedLengthOfSL;
    uint8 buffer[VHSM_MAX_SIZE_OF_SEGMENT_LIST];

    /* Calculate Length of SL */
    calculatedLengthOfSL = vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(vHsm_Hal_GetCodeFlashAddr(ptrToSl));

    if (calculatedLengthOfSL <= VHSM_MAX_SIZE_OF_SEGMENT_LIST)
    {
      /* Read segment list to local buffer */
      VStdMemCpy(buffer, vHsm_Hal_GetCodeFlashAddr(ptrToSl), calculatedLengthOfSL); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

      ptrToStructure->revision  = vHsm_Core_SecureBoot_BEtoU32(&buffer[VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH]);
      ptrToStructure->groupId   = vHsm_Core_SecureBoot_BEtoU32(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH]);
      ptrToStructure->nSegments = vHsm_Core_SecureBoot_BEtoU16(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SECUREBOOT_SL_GROUPID_LENGTH]);

      if (ptrToStructure->nSegments > ((uint16)vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx) - (uint16)vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx)))
      {
        /* External Segment List contains more segments than configured in the Config. Additional segments would not be checked, therefore return error */
        retVal = E_NOT_OK;
      }
      else
      {
        /* parse the inner segmentlist */
        vHsm_Core_SecureBoot_ParseSl(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH], ptrToStructure->segments);
#  if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
        if (vHsm_SecureBoot_GetSlInfoOfGroupInfo(groupIdx) == VHSMUPD_SECUREBOOT_SL_HASH_AVAILABLE)
        {
          /* Calculate hash about segmentlist */
          retVal = Csm_Hash(
            vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, processing, VHSM_VERMETHOD_EXTERNAL_SL),
            CRYPTO_OPERATIONMODE_SINGLECALL,
            buffer,
            vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer),
            calculatedHash,
            &hashLength);

          /* Compare to stored hash */
          if (retVal == E_OK)
          {
            if (vHsm_Core_SecureBoot_IsMemEqual(
              (P2CONST(uint8, AUTOMATIC, VHSM_APPL_DATA))(calculatedHash),
              (P2CONST(uint8, AUTOMATIC, VHSM_APPL_DATA))(vHsm_SecureBoot_GetSlHashOfGroupInfo(groupIdx)),
              VHSM_HASH_SIZE) == TRUE)
            {
              ptrToStructure->isSlValid = TRUE;
            }
            else
            {
              retVal = E_NOT_OK;
            }
          }
        }
#  endif
        if (retVal != E_OK) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
        {
          uint32 signatureLength = vHsm_Core_SecureBoot_BEtoU32(&ptrToSl[vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer)]);
          uint32 lengthOfSegmentlistWoHeader = (vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer) - VHSM_SECUREBOOT_SL_HEADER_LENGTH);
          Crypto_VerifyResultType signatureResult = CRYPTO_E_VER_NOT_OK;
          uint32 signatureJobId = 0u;

          if (processing == VHSM_SEQUENTIAL)
          {
            signatureJobId = vHsm_GetCsmJobSequentialRefOfSecureBootVerificationJob(vHsm_GetSigJobExternalSlOfSecureBootGroup(groupIdx));
          }
          else if (processing == VHSM_PARALLEL)
          {
            signatureJobId = vHsm_GetCsmJobParallelRefOfSecureBootVerificationJob(vHsm_GetSigJobExternalSlOfSecureBootGroup(groupIdx));
          }
          else
          {
            /* Misra compliant */
          }

          retVal = Csm_SignatureVerify(signatureJobId,
            CRYPTO_OPERATIONMODE_SINGLECALL,
            buffer,
            vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer),
            &ptrToSl[vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer) + VHSM_SECUREBOOT_SL_SIGNATURELENGTH_LENGTH],
            signatureLength,
            &signatureResult);

          retVal |= vHsm_SecureBoot_Revision_Callout(
            vHsm_Core_SecureBoot_BEtoU32(&buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH]),
#  if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
            vHsm_SecureBoot_GetGroupInfoOfGroupInfo(groupIdx),
#  else
            0u,
#  endif
            &buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH],
            lengthOfSegmentlistWoHeader,
            &ptrToStructure->revision);

          if ((retVal == E_OK) && (signatureResult == CRYPTO_E_VER_OK))
          {
            ptrToStructure->isSlValid = TRUE;
#  if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
            /* Calculate hash about segmentlist */
            hashLength = VHSM_HASH_SIZE;

            retVal = Csm_Hash(
              vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, processing, VHSM_VERMETHOD_EXTERNAL_SL),
              CRYPTO_OPERATIONMODE_SINGLECALL,
              buffer,
              vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer),
              calculatedHash,
              &hashLength);

            if (retVal == E_OK)
            {
              /* Set revision */
              vHsm_SecureBoot_GetGroupInfoOfGroupInfo(groupIdx) = ptrToStructure->revision;

              /* Set Hash available */
              vHsm_SecureBoot_GetSlInfoOfGroupInfo(groupIdx) = VHSMUPD_SECUREBOOT_SL_HASH_AVAILABLE;

              /* Set new hash value */
              /* PRQA S 0315 4 */ /* MD_MSR_VStdLibCopy */
              VStdMemCpy(
                vHsm_SecureBoot_GetSlHashOfGroupInfo(groupIdx),
                calculatedHash,
                hashLength);

              retVal = vHsm_SecureBoot_PersistGroup(groupIdx);
            }
#  endif
          }
          else
          {
            retVal = E_NOT_OK;
          }
        }
      }
    }
  }
  return retVal;
} /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC */ /* MD_MSR_STCAL */ /* MD_MSR_STMIF */
# endif /* VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON */
#endif /* VHSM_SECURE_BOOT == STD_ON */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#if (VHSM_SECURE_BOOT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_ProcessAllSegmentsOfGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_ProcessAllSegmentsOfGroup(
  vHsm_SecureBootGroupIterType groupIdx,
  boolean forceSequential,
  P2VAR(vHsm_SecureBootInfoType, AUTOMATIC, VHSM_APPL_VAR) infotype)
{
  Std_ReturnType retVal = E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  boolean forceSequentialTmp = forceSequential;
  vHsm_SecureBoot_ExtSegmentListType vHsm_SecureBoot_ExtSegmentList_Sequential = { 0u };
  vHsm_SecureBoot_ExtSegmentList_Sequential.isSlValid = FALSE;

  vHsm_Core_SecureBoot_ResetSecurebootResult(groupIdx);
  infotype->retry = FALSE;
  infotype->recovery = FALSE;

# if (VHSM_SECURE_BOOT_FORCED_SEQUENTIAL_PROCESSING_ON_FIRST_VERIFICATION == STD_ON)
  /* Check if internal tag is used for this group */
  if (infotype->verMethod == VHSM_VERMETHOD_COMPARE_INTERNAL_TAG)
  {
    vHsm_SecureBootSegmentIterType segmentIdx;
    boolean doBreak = FALSE;

    /* Iterate over all segments inside the group */
    for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIdx++)
    {
      vHsm_SecureBoot_SegmentInfoType segmentInfo;
      segmentInfo.segmentIdx = segmentIdx;
      if (vHsm_Core_SecureBoot_GetSegmentInfo(
        &segmentInfo,
        NULL_PTR,
        infotype->verMethod,
        VHSM_NONE) == E_OK) /* PRQA S 2995, 2991, 2996, 2992 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */ /* MD_VHSM_2996_2992_SECUREBOOT_CONDITION_TRUE_IN_OTHER_CONFIGS */
      {
        /* Check if the tag is available */
        if (segmentInfo.tagAvailable == FALSE)
        {
          forceSequentialTmp = TRUE;
          doBreak = TRUE;
        }
      }
      else
      {
        retVal = E_NOT_OK;
        forceSequentialTmp = TRUE;
        doBreak = TRUE;
      }

      if (doBreak == TRUE) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
      {
        break;
      }
    }
  }
# endif

  /* #10 Process sequential segments */
  retVal |= vHsm_Core_SecureBoot_ProcessGroupSequential( /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */
    groupIdx,
    FALSE,
    infotype,
    &vHsm_SecureBoot_ExtSegmentList_Sequential);
  if (forceSequentialTmp == TRUE)
  {
    infotype->retry = FALSE;
    /* #20 Process parallel segments sequentially */
    retVal |= vHsm_Core_SecureBoot_ProcessGroupSequential(
      groupIdx,
      forceSequentialTmp,
      infotype,
      &vHsm_SecureBoot_ExtSegmentList_Sequential);
  }
  else
  {
    /* #30 Process parallel segments */
    retVal |= vHsm_Core_SecureBoot_QueueAddGroup(groupIdx, FALSE, infotype->verMethod);
  }

  return retVal;
}

# if (VHSM_FIRMWARE_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_IsProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(boolean, VHSM_CODE) vHsm_Core_SecureBoot_IsProcessing(void)
{
  boolean retVal;

  /* #10 Check if queue is empty */
  if (vHsm_SecureBootQueue.queueTopIdx == 0u)
  {
    /* No parallel jobs available. All sequential jobs have been processed earlier */
    retVal = FALSE;
  }
  /* #30 Else: */
  else
  {
    /* #31 Queue has not been processed completely -> secure boot ongoing */
    retVal = TRUE;
  }
  return retVal;
}
# endif

# if (VHSM_ENABLE_SECURE_BOOT_AUTOSTART == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_AutostartGroups()
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
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_AutostartGroups(void)
{
  Std_ReturnType retVal = E_OK;
  vHsm_SecureBootGroupIterType groupIdx;

  vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: Autostart of %i Groups\n", vHsm_GetSizeOfSecureBootGroup());

  /* #10 For all groups: */
  for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
  {
    /* #20 Check if group is autostarted */
    if (vHsm_IsAutostartOfSecureBootGroup(groupIdx) == TRUE)
    {
#  if (VHSM_CUSTOMCALLOUT == STD_ON)
      boolean autostartAllowed = TRUE;
      /* #21 Check if a custom callout shall be called */
      if (vHsm_IsCustomCalloutUsedOfSecureBootGroup(groupIdx) == TRUE)
      {
        autostartAllowed = vHsm_Custom_IsSecureBootAllowAutostart_Callout(groupIdx, vHsm_GetIdOfSecureBootGroup(groupIdx));
      }

      /* #22 Check if autostart has been granted */
      if (autostartAllowed == TRUE)
#  endif
      {
        vHsm_SecureBootInfoType secureBootInfo;

        /* #30 Start the group */
        vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: Autostart of Group 0x%08X\n", vHsm_GetIdOfSecureBootGroup(groupIdx));

        secureBootInfo.isCyclicVerification = FALSE;

        if (vHsm_IsCompInternalOfSecureBootGroup(groupIdx))
        {
          secureBootInfo.verMethod = VHSM_VERMETHOD_COMPARE_INTERNAL_TAG;
          retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, FALSE, &secureBootInfo);
#  if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
          if (secureBootInfo.recovery == TRUE)
          {
            secureBootInfo.verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
            retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, FALSE, &secureBootInfo);
          }
#  endif
        }
        else
        {
          secureBootInfo.verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
          retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, FALSE, &secureBootInfo);
        }
      }
    }
  }

  vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: Autostart of %i Groups finished\n", vHsm_GetSizeOfSecureBootGroup());

  /* #70 Print the current state of the secure boot to the console */
  vHsm_Core_SecureBoot_PrintState();

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
# endif

# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureBootConfirmation()
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
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureBootConfirmation(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal = E_OK;
  uint8 buffer[VHSM_MAX_SIZE_OF_SEGMENT_LIST];
  uint32 groupId;
  vHsm_SecureBootGroupIterType groupIdx;
  uint32 segmentlistAddress = 0u;
  uint32 signatureLength;
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) segmentlistPtr;
  boolean readOnInactivePartition = FALSE;
  Crypto_VerifyResultType signatureResult = CRYPTO_E_VER_NOT_OK;

  if (mode == CRYPTO_OPERATIONMODE_FINISH)
  {
    /* check if length is long enough for header and group id */
    if (job->jobPrimitiveInputOutput.inputLength < (VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SECUREBOOT_SL_GROUPID_LENGTH))
    {
      retVal = E_NOT_OK;
    }
    else if (vHsm_Core_SecureBoot_IsMemEqual(vHsm_SecureBoot_GSL_Header_Pattern, job->jobPrimitiveInputOutput.inputPtr, VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH) == FALSE)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* check for SL with header */
      groupId = vHsm_Core_SecureBoot_BEtoU32(&job->jobPrimitiveInputOutput.inputPtr[VHSM_SECUREBOOT_SL_HEADER_LENGTH]);

      if (vHsm_Core_SecureBoot_GetAddressOfSLOfGroupId(groupId, &segmentlistAddress, &groupIdx) == E_OK)
      {
        segmentlistPtr = (P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)) (segmentlistAddress); /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */

        /* check if the addresses must be recalculated */
        if (job->jobPrimitiveInputOutput.secondaryInputLength == VHSM_CONFIRMATION_READ_INACTIVE_LENGTH)
        {
#  if (VHSM_PARTITION_LAYOUT == STD_ON)
          if (*(job->jobPrimitiveInputOutput.secondaryInputPtr) == VHSM_CONFIRMATION_READ_INACTIVE_TRUE)
          {
            /* recalculate the addresses of  segmentlist */
            readOnInactivePartition = TRUE;
            segmentlistPtr = vHsm_Core_SecureBoot_GetAddressOfInactivePartition(segmentlistPtr);
          }
#  endif /* VHSM_PARTITION_LAYOUT == STD_ON */
        }
        else
        {
          retVal = E_NOT_OK;
        }
        /* As cache may prevent reading valid code flash where the segment list is located, it is not possible to parse the segment list and provide a valid length to clear. A more elaborate logic can still be implemented in the callout */
        vHsm_SecureBoot_CacheClearing_Callout(segmentlistPtr, VHSM_CLEAR_WHOLE_CACHE);

        segmentlistPtr = vHsm_Hal_GetCodeFlashAddr(segmentlistPtr);

        /* Get signature Length from header */
        signatureLength = vHsm_Core_SecureBoot_BEtoU32(&job->jobPrimitiveInputOutput.inputPtr[vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(segmentlistPtr)]);

        /* Copy the SL from codeflash to buffer */
        VStdMemCpy(buffer, segmentlistPtr, vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(segmentlistPtr)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

        /* Check if the signature is valid: */
        retVal |= Csm_SignatureVerify(vHsm_GetCsmJobSequentialRefOfSecureBootVerificationJob(vHsm_GetSigJobExternalSlOfSecureBootGroup(groupIdx)),
          CRYPTO_OPERATIONMODE_SINGLECALL,
          buffer, vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(segmentlistPtr),
          &segmentlistPtr[vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(segmentlistPtr) + VHSM_SECUREBOOT_SL_SIGNATURELENGTH_LENGTH],
          signatureLength,
          &signatureResult);

        *job->jobPrimitiveInputOutput.verifyPtr = signatureResult;

        if ((retVal == E_OK) && (signatureResult == CRYPTO_E_VER_OK))
        {
          if (vHsm_Core_SecureBoot_PerformConfirmation(buffer, readOnInactivePartition, groupIdx) != E_OK)
          {
            *job->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;
          }
        }
      }
      else
      {
        retVal = E_NOT_OK;
      }
    }
  }
  else
  {
    retVal = E_OK;
  }

  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* PRQA S 6050,6080 */ /* MD_MSR_STCAL */ /* MD_MSR_STMIF */
# endif /* (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON) */

# if (VHSM_SECURE_BOOT_UPDATE == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureBootUpdate()
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
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureBootUpdate(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal = E_NOT_OK;
  boolean isExtSl = FALSE;

  /* #10 Check if the mode is FINISH */
  if (mode == CRYPTO_OPERATIONMODE_FINISH)
  {
    uint8 buffer[VHSM_MAX_SIZE_OF_SEGMENT_LIST] = { 0u };
    uint32 bufferLen = 0u;
    uint32 signatureLength = 0u;

    Crypto_VerifyResultType signatureResult = CRYPTO_E_VER_NOT_OK;
    uint32 nSegments;
    uint32 calculatedLength;

    /* Check for magic pattern */
    /* PRQA S 3415 2 */ /* MD_VHSM_3415_NO_SIDE_EFFECTS */
    if ((job->jobPrimitiveInputOutput.inputLength > VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH)
      && (vHsm_Core_SecureBoot_IsMemEqual(vHsm_SecureBoot_GSL_Header_Pattern, job->jobPrimitiveInputOutput.inputPtr, VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH) == TRUE))
    {

      nSegments = vHsm_Core_SecureBoot_BEtoU16(&job->jobPrimitiveInputOutput.inputPtr[VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SECUREBOOT_SL_GROUPID_LENGTH]);
      signatureLength = vHsm_Core_SecureBoot_BEtoU32(&job->jobPrimitiveInputOutput.inputPtr[vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(job->jobPrimitiveInputOutput.inputPtr)]);
      calculatedLength = (VHSM_SECUREBOOT_SL_HEADER_LENGTH + VHSM_SEGMENT_LIST_INFO + (nSegments * VHSM_SIZE_OF_SEGMENT) + VHSM_SECUREBOOT_SL_SIGNATURELENGTH_LENGTH + signatureLength);

      /* Check if the inputlength is plausible */
      if (job->jobPrimitiveInputOutput.inputLength == calculatedLength)
      {
        bufferLen = vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(job->jobPrimitiveInputOutput.inputPtr);
        isExtSl = TRUE;
        retVal = E_OK;
      }
    }
    else
    {
      nSegments = vHsm_Core_SecureBoot_BEtoU16(&job->jobPrimitiveInputOutput.inputPtr[VHSM_SECUREBOOT_SL_GROUPID_LENGTH]);
      calculatedLength = (VHSM_SEGMENT_LIST_INFO + (nSegments * VHSM_SIZE_OF_SEGMENT));

      /* Check if the input length is plausible */
      if ((job->jobPrimitiveInputOutput.inputLength == calculatedLength)
        || (job->jobPrimitiveInputOutput.inputLength == (calculatedLength + VHSM_SECUREBOOT_SL_REVISION_LENGTH)))
      {
        bufferLen = job->jobPrimitiveInputOutput.inputLength;
        isExtSl = FALSE;
        retVal = E_OK;
      }
    }

    if (retVal == E_OK)
    {
      /* #20 Check if the provided segment list is not too big */
      if (bufferLen > VHSM_MAX_SIZE_OF_SEGMENT_LIST)
      {
        retVal = E_OK;
        *job->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;
      }
      else
      {
        /* #21 Copy the provided segment list to a local buffer */
        VStdMemCpy(buffer, job->jobPrimitiveInputOutput.inputPtr, bufferLen); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

        if (isExtSl == TRUE)
        {
          retVal = Csm_SignatureVerify(
            vHsm_GetCsmSignatureJobReferenceOfSecureBootUpdate(),
            CRYPTO_OPERATIONMODE_SINGLECALL,
            buffer,
            bufferLen,
            &job->jobPrimitiveInputOutput.inputPtr[vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer) + VHSM_SECUREBOOT_SL_SIGNATURELENGTH_LENGTH],
            signatureLength,
            &signatureResult);
        }
        else
        {
          retVal = Csm_SignatureVerify(
            vHsm_GetCsmSignatureJobReferenceOfSecureBootUpdate(),
            CRYPTO_OPERATIONMODE_SINGLECALL,
            buffer,
            bufferLen,
            job->jobPrimitiveInputOutput.secondaryInputPtr,
            job->jobPrimitiveInputOutput.secondaryInputLength,
            &signatureResult);
        }

        /* Store result of signature verification */
        *job->jobPrimitiveInputOutput.verifyPtr = signatureResult;

        /* #23 Check if the signature is valid: */
        if ((retVal == E_OK) && (signatureResult == CRYPTO_E_VER_OK))
        {
          if (vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformationExtended(buffer, bufferLen, isExtSl) != E_OK)
          {
            *job->jobPrimitiveInputOutput.verifyPtr = CRYPTO_E_VER_NOT_OK;
          }
        }
      }
    }
  }
  else
  {
    /* START and UPDATE */
    retVal = E_OK;
  }

  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
}/* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformation(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer)
{
  return vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformationExtended(
    buffer,
    VHSM_MAX_SIZE_OF_SEGMENT_LIST,
    FALSE);
}

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformationExtended()
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
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_SecureBoot_SBU_ProcessSegmentListInformationExtended(
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR)buffer,
  uint32 bufferLength,
  boolean isExtSl)
{
  Std_ReturnType retVal;
  vHsm_SecureBootGroupIterType groupIdx;
  uint32 groupFromSL;
  uint16 nSegmentsFromSL;
  uint32 segment;
  vHsm_SecureBootSegmentIterType segmentIdx;
  uint32 maxSegments;
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) ptrToSL = buffer;
  vHsm_SecureBoot_SegmentType segments[VHSM_MAX_SEGMENTS_PER_GROUP];
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
#   if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  uint32 hashLength = VHSM_HASH_SIZE;
  uint8  calculatedHash[VHSM_HASH_SIZE] = { 0u };
#   endif
#  endif

  if (isExtSl == TRUE)
  {
    ptrToSL = &buffer[VHSM_SECUREBOOT_SL_HEADER_LENGTH];
  }

  groupFromSL = vHsm_Core_SecureBoot_BEtoU32(&ptrToSL[0]);
  nSegmentsFromSL = vHsm_Core_SecureBoot_BEtoU16(&ptrToSL[4]);

  /* #30 For each group */
  for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
  {
    retVal = E_NOT_OK;

    /* #31 Check if the group is found in the segment list */
    if ((((uint32)groupFromSL) == (vHsm_GetIdOfSecureBootGroup(groupIdx)))
      && (vHsm_IsCompInternalOfSecureBootGroup(groupIdx)))
    {
      maxSegments = (uint32)(((uint32)(vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx))) - ((uint32)(vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx))));

      /* #32 Check if group has enough segments */
      if (nSegmentsFromSL <= maxSegments)
      {
        /* Prevent old segment tables to override newer ones */
        uint32 newVersiontoStore;
        uint32 segmetTableSize = (VHSM_SIZE_OF_SEGMENT * (uint32)nSegmentsFromSL) + (uint32)(sizeof(uint32) + sizeof(uint16));

#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
        if (isExtSl == TRUE)
        {
          newVersiontoStore = vHsm_Core_SecureBoot_BEtoU32(&buffer[VHSM_SECUREBOOT_SL_MAGICPATTERN_LENGTH]);
        }
        else if ((bufferLength - segmetTableSize) == VHSM_SECUREBOOT_SL_REVISION_LENGTH)
        {
          newVersiontoStore = vHsm_Core_SecureBoot_BEtoU32(&buffer[segmetTableSize]);
        }
        else
        {
          newVersiontoStore = 0u;
        }
#  else
        VHSM_DUMMY_STATEMENT(bufferLength); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
        newVersiontoStore = 0u;
#  endif

        vHsm_Trace(VHSM_TRACETYPE_INFO, "SBU: Group=%i is valid\n", groupFromSL);
        segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx);

        /* Prevent old segment tables to override newer ones */
        retVal = vHsm_SecureBoot_Revision_Callout(
          groupFromSL,
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
          vHsm_SecureBoot_GetGroupInfoOfGroupInfo(groupIdx),
#  else
          0u,
#  endif
          ptrToSL,
          segmetTableSize,
          &newVersiontoStore);

#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
        /* Prevent segment lists which contains different modes for a group which has only one tag */
        retVal |= vHsm_Core_SecureBoot_SBU_CheckGroupSegmentModeConsistency(
          groupIdx,
          maxSegments,
          nSegmentsFromSL,
          ptrToSL);
#  endif

        if (retVal == E_OK)
        {
          vHsm_SecureBoot_SequentialWorkspaceType seqWorkspace;
          vHsm_TagHandlingOfSecureBootGroupType tagHandling = vHsm_GetTagHandlingOfSecureBootGroup(groupIdx);

          seqWorkspace.pendingStart = TRUE;
          seqWorkspace.pendingFinish = FALSE;
          seqWorkspace.segmentUsedForTag.mode = CRYPTO_30_VHSM_MODE_NONE;
          seqWorkspace.segmentUsedForTag.segmentIdx = 0u;
          seqWorkspace.verMethod = VHSM_VERMETHOD_COMPARE_INTERNAL_TAG;

          vHsm_Core_SecureBoot_ParseSl(ptrToSL, segments);

          /* #33 For each segment in the group: */
          for (segment = 0u; segment < nSegmentsFromSL; segment++)
          {

            /* #43 Calculate the TAG for the segment */
            retVal = vHsm_SecureBootUpdate_CalculateTagforSegmentAndValidate(segmentIdx,
              &segments[segment],
              &seqWorkspace);

            if (retVal != E_OK)
            {
              vHsm_Trace(VHSM_TRACETYPE_INFO, "SBU: Segment list for Group=%i could not be processed\n", vHsm_GetIdOfSecureBootGroup(groupIdx));
              break;
            }
            else
            {
              vHsm_Trace(VHSM_TRACETYPE_INFO, "SBU: Group=%i Seg=%i Key=%i has been updated\n", vHsm_GetIdOfSecureBootGroup(groupIdx), segmentIdx, vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx));
              segmentIdx++;
            }
          }

          /* Calculate Group Tag */
          if ((tagHandling != VHSM_SEGMENT_TAG)
            && (seqWorkspace.pendingFinish == TRUE))
          {
            if (retVal == E_OK)
            {
              uint32 tagSegmentIdx = (uint32)seqWorkspace.segmentUsedForTag.segmentIdx - (uint32)vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx);

              vHsm_Trace(VHSM_TRACETYPE_INFO, "SBU: SEQ sIdx %2i %s |FINISH Tag of Group %2i\n",
                seqWorkspace.segmentUsedForTag.segmentIdx,
                string_Processing[seqWorkspace.segmentUsedForTag.mode],
                vHsm_GetIdOfSecureBootGroup(groupIdx));

              retVal |= vHsm_Core_SecureBoot_EndTagCalculation(groupIdx, VHSM_SEQUENTIAL, segments[tagSegmentIdx].SLHash, sizeof(segments[tagSegmentIdx].SLHash), VHSM_VERMETHOD_COMPARE_INTERNAL_TAG); /* PRQA S 2986 */ /* MD_VHSM_2986_SECUREBOOT_REDUNDANT_OP */
              if (retVal == E_OK)
              {
                segments[tagSegmentIdx].hashLength = vHsm_GetTagLengthOfSecureBootGroup(groupIdx);
              }
              else
              {
                segments[tagSegmentIdx].hashLength = 0u;
              }
            }
            else
            {
              /* Cancel the Tag generation job when a error happened earlier, because FINISH will not be called. */
              (void)Csm_CancelJob(vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
                CRYPTO_OPERATIONMODE_SINGLECALL);
            }
          }
        }

        /* #60 If fetching all segment information of the group was successful: */
        if (retVal == E_OK)
        {
          /* #61 Persist all segments of the group */
          for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIdx++)
          {
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
            if (vHsm_Core_SecureBoot_SetSegmentInfoCsm(segmentIdx, segments[vHsm_SecureBoot_GetSegmentPositionWithinGroup(segmentIdx, groupIdx)]) == E_OK) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */ /*lint !e644 */
            {
              retVal |= vHsm_Api_KeyValidSet(vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx));
            }
#  else
            if (vHsm_Core_SecureBoot_SetSegmentInfoNvM(segmentIdx, segments[vHsm_SecureBoot_GetSegmentPositionWithinGroup(segmentIdx, groupIdx)]) == E_OK) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */ /*lint !e644 */
            {
              /* Do nothing */
            }
#  endif
            else
            {
              /* SetSegmentInfo failed */
              retVal |= E_NOT_OK;
            }
          }
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
#   if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
          if (vHsm_IsExternalSlOfSecureBootGroup(groupIdx) && (isExtSl == TRUE))
          {
            /* The result of this hash calculation doesn't matter. If it fails, it leads to a signature verification on the next secure boot processing,
               which just costs some runtime */
            if(Csm_Hash(
              vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, VHSM_VERMETHOD_EXTERNAL_SL),
              CRYPTO_OPERATIONMODE_SINGLECALL,
              buffer,
              vHsm_Core_SecureBoot_GetLengthOfSlWithHeader(buffer),
              calculatedHash,
              &hashLength) == E_OK)
            {

              /* Set new hash value */
              /* PRQA S 0315 4 */ /* MD_MSR_VStdLibCopy */
              VStdMemCpy(
                vHsm_SecureBoot_GetSlHashOfGroupInfo(groupIdx),
                calculatedHash,
                hashLength);

              /* Set Hash available */
              vHsm_SecureBoot_GetSlInfoOfGroupInfo(groupIdx) = VHSMUPD_SECUREBOOT_SL_HASH_AVAILABLE;
            }
          }
          if (retVal == E_OK) /* PRQA S 2995, 2991 */ /* MD_VHSM_2995_2991_SECUREBOOT_CONDITION_FALSE_IN_OTHER_CONFIGS */
#   endif /* VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON */
          {
            vHsm_SecureBoot_GetGroupInfoOfGroupInfo(groupIdx) = newVersiontoStore;
            retVal = vHsm_SecureBoot_PersistGroup(groupIdx);
          }
#  endif /* VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM */
        }
      }
      else
      {
        vHsm_Trace(VHSM_TRACETYPE_ERROR, "SBU: Group=%i does not have enough segments\n", groupFromSL);
      }
      break;
    }
  }
  return retVal;
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH */ /* MD_MSR_STCYC */ /* MD_MSR_STCAL */ /* MD_MSR_STMIF */
# endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_Core_SecureBoot_Init(void)
{
  vHsm_SecureBootVerificationJobIterType verificationJobIdx;
# if (VHSM_SECUREBOOTPROTECTEDCHANNELS == STD_ON)
  vHsm_SecureBootProtectedChannelsIterType protectedChannelsIdx;
# endif
# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
  vHsm_SecureBoot_CurrentCyclicGroupIdx = 0u;
# endif

  vHsm_SecureBootQueue.queueTopIdx = 0u;
  vHsm_Core_SecureBoot_Workspace.state = CRYPTO_OPERATIONMODE_START;

  vHsm_State.vHsm_SecureBootDoneFlag = FALSE;
  vHsm_State.vHsm_SecureBootEndIndicationFlag = FALSE;

  /* #20 Restrict all CryIfChannels to internal only usage which are used for parallel secure boot processing */
  for (verificationJobIdx = 0u; verificationJobIdx < vHsm_GetSizeOfSecureBootVerificationJob(); verificationJobIdx++)
  {
    vHsm_JoinUsageRestrictionOfJobObjects(vHsm_GetParallelChannelRefOfSecureBootVerificationJob(verificationJobIdx), VHSM_DEACTIVATEJOBOBJECTS_RESTRICTCHANNEL);
  }
# if (VHSM_SECUREBOOTPROTECTEDCHANNELS == STD_ON)
  /* Restrict all CryIfChannels to internal only usage which are configured in vhsm_securebootprotectedchannels */
  for (protectedChannelsIdx = 0u; protectedChannelsIdx < vHsm_GetSizeOfSecureBootProtectedChannels(); protectedChannelsIdx++)
  {
    vHsm_JoinUsageRestrictionOfJobObjects(vHsm_GetSecureBootProtectedChannels(protectedChannelsIdx), VHSM_DEACTIVATEJOBOBJECTS_SECUREBOOT);
  }
# endif

# if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  VStdMemClr(&vHsm_SecureBoot_ExtSegmentList, sizeof(vHsm_SecureBoot_ExtSegmentList)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  vHsm_SecureBoot_ExtSegmentList.isSlValid = FALSE;
# endif

}

/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureBoot()
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
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureBoot(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal = E_NOT_OK;
  boolean vHsm_SecureBoot_UseGroupIdFromData;
  /* #10 Decide if the algorithm shall be processed */
  if (job->jobPrimitiveInfo->primitiveInfo->algorithm.family == CRYPTO_ALGOFAM_CUSTOM_VHSM_SECURE_BOOT)
  {
    if (mode == CRYPTO_OPERATIONMODE_FINISH)
    {
      if ((job->jobPrimitiveInputOutput.inputPtr != NULL_PTR)
        && (job->jobPrimitiveInputOutput.inputLength == sizeof(uint32)))
      {
        VStdMemCpy(&vHsm_SecureBoot_GroupId, job->jobPrimitiveInputOutput.inputPtr, sizeof(uint32)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        vHsm_SecureBoot_UseGroupIdFromData = TRUE;
      }
      else
      {
        vHsm_SecureBoot_UseGroupIdFromData = FALSE;
      }

      /* #30 Check if secure boot is not finished yet */
      if (vHsm_State.vHsm_SecureBootEndIndicationFlag == FALSE)
      {
        vHsm_SecureBootInfoType secureBootInfo;

        if ( (vHsm_SecureBoot_UseGroupIdFromData == TRUE)
# if (VHSM_SECUREBOOTGROUPOFKEYINFO == STD_ON)
          || (vHsm_IsSecureBootGroupOfKeyInfo(job->jobPrimitiveInfo->cryIfKeyId))
# endif
          )
        {
          /* Find the correct group for the key */
          vHsm_SecureBootGroupIterType groupIdx;

          for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
          {
            if ( (
# if (VHSM_SECUREBOOTGROUPOFKEYINFO == STD_ON)
              (vHsm_SecureBoot_UseGroupIdFromData == TRUE) &&
# endif
              (vHsm_SecureBoot_GroupId == vHsm_GetIdOfSecureBootGroup(groupIdx)))
# if (VHSM_SECUREBOOTGROUPOFKEYINFO == STD_ON)
              || ( (vHsm_SecureBoot_UseGroupIdFromData == FALSE)
                && (job->cryptoKeyId == vHsm_GetCryptoKeyIdOfSecureBootGroup(groupIdx)))
# endif
              )
            {
              /* Trigger the processing of all segments in the group */
              boolean forceSequential = (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_SECURE_BOOT_FORCE_SEQUENTIAL);
              secureBootInfo.isCyclicVerification = FALSE;
              if (vHsm_IsCompInternalOfSecureBootGroup(groupIdx))
              {
                secureBootInfo.verMethod = VHSM_VERMETHOD_COMPARE_INTERNAL_TAG;
                retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, forceSequential, &secureBootInfo);
# if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
                if (secureBootInfo.recovery == TRUE)
                {
                  secureBootInfo.verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
                  retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, forceSequential, &secureBootInfo);
                }
# endif
              }
              else
              {
                secureBootInfo.verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
                retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, forceSequential, &secureBootInfo);
              }

              *job->jobPrimitiveInputOutput.verifyPtr = vHsm_State.vHsm_SecureBootState.groupResult[groupIdx];
              break;
            }
          }
        }
# if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
        else if(vHsm_IsSecureBootSegmentOfKeyInfo(job->jobPrimitiveInfo->cryIfKeyId) == TRUE)
        {
          vHsm_SecureBootGroupIterType groupIdx;
          vHsm_SecureBootSegmentIterType segmentIdx;
          boolean breakloop = FALSE;

          /* Find the correct cryptoKeyId for the CMAC operation */
          for (groupIdx = 0u; (groupIdx < vHsm_GetSizeOfSecureBootGroup()) && (breakloop == FALSE); groupIdx++) /* COV_VHSM_BREAK_LOOP */
          {
            for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); (segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx)) && (breakloop == FALSE); segmentIdx++) /* COV_VHSM_BREAK_LOOP */
            {
              if (vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdx) == job->cryptoKeyId)
              {
                boolean forceSequential = (job->jobPrimitiveInfo->primitiveInfo->algorithm.mode == CRYPTO_ALGOMODE_CUSTOM_SECURE_BOOT_FORCE_SEQUENTIAL);
                secureBootInfo.isCyclicVerification = FALSE;
                if (vHsm_IsCompInternalOfSecureBootGroup(groupIdx))
                {
                  secureBootInfo.verMethod = VHSM_VERMETHOD_COMPARE_INTERNAL_TAG;
                  retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, forceSequential, &secureBootInfo);
#  if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
                  if (secureBootInfo.recovery == TRUE)
                  {
                    secureBootInfo.verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
                    retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, forceSequential, &secureBootInfo);
                  }
#  endif
                }
                else
                {
                  secureBootInfo.verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
                  retVal = vHsm_SecureBoot_ProcessAllSegmentsOfGroup(groupIdx, forceSequential, &secureBootInfo);
                }

                *job->jobPrimitiveInputOutput.verifyPtr = vHsm_State.vHsm_SecureBootState.groupResult[groupIdx];
                breakloop = TRUE;
              }
            }
          }
        }
# endif
        else
        {
          /* Key is not referenced as secure boot segment */
          retVal = E_NOT_OK;
        }
      }
      else
      {
        vHsm_Trace(VHSM_TRACETYPE_ERROR, "Secure boot is already finished with %i. No more secure boot slots can be checked.\n", vHsm_State.vHsm_SecureBootResult);
        retVal = E_NOT_OK;
      }
    }
    else
    {
      /* CRYPTO_OPERATIONMODE_START, CRYPTO_OPERATIONMODE_UPDATE */
      retVal = E_OK;
    }
  }

  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC */ /* MD_MSR_STMIF */

# if (VHSM_SECURE_SOFTWARE_DOWNLOAD == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Core_DispatchSecureSoftwareDownload()
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
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Core_DispatchSecureSoftwareDownload(
  uint32 objectId,
  P2VAR(Crypto_JobType, AUTOMATIC, VHSM_APPL_VAR) job, /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
  Crypto_OperationModeType mode)
{
  Std_ReturnType retVal = E_NOT_OK;
#  if (VHSM_SECUREBOOTSEGMENTOFKEYINFO == STD_ON)
  Crypto_OperationModeType tmpMode = mode;
  vHsm_SecureBootSegmentIterType segmentIdx = 0u;
  vHsm_SecureBootSegmentIterType segmentIdxTmp;
  vHsm_SecureBootGroupIterType groupIdx = 0u;
  vHsm_TagHandlingOfSecureBootGroupType tagHandling;
  if (vHsm_IsSecureBootSegmentOfKeyInfo(job->jobPrimitiveInfo->cryIfKeyId) == TRUE)
  {
    for (segmentIdxTmp = 0u; segmentIdxTmp < vHsm_GetSizeOfSecureBootSegment(); segmentIdxTmp++) /* COV_VHSM_BREAK_LOOP */
    {
      if (vHsm_GetCryptoKeyIdOfSecureBootSegment(segmentIdxTmp) == job->cryptoKeyId) /* COV_VHSM_SECUREBOOT_KEY_CHECK */
      {
        segmentIdx = segmentIdxTmp;
        groupIdx = vHsm_GetGroupIdxOfSecureBootSegment(segmentIdxTmp);
        break;
      }
    }

    /* check if securesoftware download is performed on secureboot group with segment tag processing */
    tagHandling = vHsm_GetTagHandlingOfSecureBootGroup(groupIdx);
    if (tagHandling != VHSM_SEGMENT_TAG)
    {
      /* invalidate mode */
      tmpMode = 0xff;
    }

    if (vHsm_IsCompInternalOfSecureBootGroup(groupIdx) == FALSE)
    {
      /* invalidate mode */
      tmpMode = 0xff;
    }

    /* #110 Check if mode is START */
    if (tmpMode == CRYPTO_OPERATIONMODE_START)
    {
      vHsm_SecureSoftwareDownload_IsFirstUpdate = TRUE;
      vHsm_SecureSoftwareDownload_Size = 0u;

      retVal = Csm_SignatureVerify(vHsm_GetCsmSignatureJobReferenceOfSecureSoftwareDownload(), CRYPTO_OPERATIONMODE_START, NULL_PTR, 0u, NULL_PTR, 0u, NULL_PTR);

      /* #130 Start the CMAC generation */
      retVal |= vHsm_Core_SecureBoot_TagCalculationJob(
        vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
        vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
        CRYPTO_OPERATIONMODE_START,
        NULL_PTR, 0u,
        NULL_PTR, NULL_PTR);
    }
    /* #140 Check if mode is UPDATE */
    else if (tmpMode == CRYPTO_OPERATIONMODE_UPDATE)
    {
      if (vHsm_SecureSoftwareDownload_IsFirstUpdate == TRUE)
      {
        vHsm_SecureSoftwareDownload_Address = (uint32)job->jobPrimitiveInputOutput.inputPtr; /* PRQA S 0306 */ /* MD_VHSM_0306_API_SPECIFIC_CAST */
        vHsm_SecureSoftwareDownload_IsFirstUpdate = FALSE;
      }

      vHsm_SecureSoftwareDownload_Size += job->jobPrimitiveInputOutput.inputLength;

      {
        uint32 remaining = job->jobPrimitiveInputOutput.inputLength;
        uint32 processed = 0u;
        uint32 length;
        uint8 secureBootAtomicBuffer[VHSM_ATOMIC_BUFFER_SIZE];
        P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) addrTmp = job->jobPrimitiveInputOutput.inputPtr; /* PRQA S 0306 */ /* MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */

        while (remaining != 0u)
        {
          if ((remaining / VHSM_ATOMIC_BUFFER_SIZE) != 0u)
          {
            length = VHSM_ATOMIC_BUFFER_SIZE;
          }
          else
          {
            length = remaining;
          }

          VStdMemCpy(secureBootAtomicBuffer, vHsm_Hal_GetCodeFlashAddr(&addrTmp[processed]), length); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

          /* #150 Provided more data to the signature verification */
          retVal = Csm_SignatureVerify(vHsm_GetCsmSignatureJobReferenceOfSecureSoftwareDownload(), CRYPTO_OPERATIONMODE_UPDATE,
            secureBootAtomicBuffer, length, NULL_PTR, 0u, NULL_PTR);

          /* #160 Provided more data to the CMAC generation */
          retVal |= vHsm_Core_SecureBoot_TagCalculationJob(
            vHsm_Core_SecureBoot_GetVerificationJobId(groupIdx, VHSM_SEQUENTIAL, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
            vHsm_Core_SecureBoot_GetVerificationJobService(groupIdx, VHSM_VERMETHOD_COMPARE_INTERNAL_TAG),
            CRYPTO_OPERATIONMODE_UPDATE,
            secureBootAtomicBuffer, length,
            NULL_PTR, NULL_PTR);

          processed += length;
          remaining -= length;
        }
      }

    }
    /* #170 Check if mode is FINISH */
    else if(tmpMode == CRYPTO_OPERATIONMODE_FINISH)/* (mode == CRYPTO_OPERATIONMODE_FINISH) */
    {
      retVal = vHsm_Core_Secureboot_SSwDl_Finish(segmentIdx, job);
    }
    else
    {
      /* SecureSoftwareDownload performed on segment in secureboot group with group tag! */
      vHsm_Trace(VHSM_TRACETYPE_ERROR, "Secure software download: The secureboot group groupIdx=%i of segment idx=%i has non segment tag processing.\n", groupIdx, segmentIdx);
    }

    /* Cancel all jobs when an error occurred to free the driver object */
    if (retVal != E_OK)
    {
      (void) Csm_CancelJob(vHsm_GetCsmSignatureJobReferenceOfSecureSoftwareDownload(), CRYPTO_OPERATIONMODE_SINGLECALL);
      (void) Csm_CancelJob(vHsm_GetCsmJobSequentialRefOfSecureBootVerificationJob(vHsm_GetVerJobCompInternalOfSecureBootGroup(groupIdx)), CRYPTO_OPERATIONMODE_SINGLECALL);
    }
  }
#  else
  VHSM_DUMMY_STATEMENT(job); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  VHSM_DUMMY_STATEMENT(objectId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return retVal;
} /* PRQA S 6030,6050,6080,6010 */ /* MD_MSR_STCYC */ /* MD_MSR_STCAL */ /* MD_MSR_STMIF */ /* MD_MSR_STPTH */
# endif

# if(VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_NVM)
/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_InitGroup()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, VHSM_CODE) vHsm_SecureBootStorage_InitGroup(
  vHsm_SecureBootGroupIterType groupIdx)
{
  /* #10 Init the secure boot storage */
  vHsm_SecureBoot_GetCrcOfGroupInfo(groupIdx) = vHsm_GetCrcOfSecureBootGroup(groupIdx);
  vHsm_SecureBoot_GetGroupInfoOfGroupInfo(groupIdx) = 0u;

#  if(VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON)
  if (vHsm_IsCompInternalOfSecureBootGroup(groupIdx))
  {
    vHsm_SecureBootSegmentIterType segmentIdx;
    for (segmentIdx = vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(groupIdx); segmentIdx < vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(groupIdx); segmentIdx++)
    {
      if (vHsm_IsSecureBootSegmentInitValuesUsedOfSecureBootSegment(segmentIdx) == TRUE)
      {
        vHsm_SecureBoot_GetAddressOfSegmentInfo(segmentIdx) = (P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))vHsm_GetAddressOfSecureBootSegmentInitValues(vHsm_GetSecureBootSegmentInitValuesIdxOfSecureBootSegment(segmentIdx)); /* PRQA S 3305, 0310, 0306 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS, MD_VHSM_0306_SECUREBOOT_SPECIFIC_CAST */
        vHsm_SecureBoot_GetSizeOfSegmentInfo(segmentIdx) = vHsm_GetLengthOfSecureBootSegmentInitValues(vHsm_GetSecureBootSegmentInitValuesIdxOfSecureBootSegment(segmentIdx)); /* PRQA S 3305, 0310 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
        vHsm_SecureBoot_GetModeOfSegmentInfo(segmentIdx) = (uint8)vHsm_GetModeOfSecureBootSegmentInitValues(vHsm_GetSecureBootSegmentInitValuesIdxOfSecureBootSegment(segmentIdx));
        vHsm_SecureBoot_GetSanctionOfSegmentInfo(segmentIdx) = (uint8)vHsm_GetSanctionOfSecureBootSegmentInitValues(vHsm_GetSecureBootSegmentInitValuesIdxOfSecureBootSegment(segmentIdx));
        vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentIdx) = FALSE;
        VStdLib_MemSet(vHsm_SecureBoot_GetTagOfSegmentInfo(segmentIdx), 0u, vHsm_GetTagLengthOfSecureBootGroup(groupIdx)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      }
      else
      {
        vHsm_SecureBoot_GetAddressOfSegmentInfo(segmentIdx) = NULL_PTR; /* PRQA S  3305, 0310  */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
        vHsm_SecureBoot_GetSizeOfSegmentInfo(segmentIdx) = 0u; /* PRQA S 3305, 0310 */ /* MD_VHSM_3305_SECUREBOOT_STRICTER_ALIGNMENT, MD_VHSM_0310_SECUREBOOT_MEMORY_ACCESS */
        vHsm_SecureBoot_GetModeOfSegmentInfo(segmentIdx) = CRYPTO_30_VHSM_MODE_NONE;
        vHsm_SecureBoot_GetSanctionOfSegmentInfo(segmentIdx) = VHSM_SANCTION_NONE;
        vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentIdx) = FALSE;
        VStdLib_MemSet(vHsm_SecureBoot_GetTagOfSegmentInfo(segmentIdx), 0u, vHsm_GetTagLengthOfSecureBootGroup(groupIdx)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      }
    }
  }
#  endif

#  if(VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
  if (vHsm_IsExternalSlOfSecureBootGroup(groupIdx))
  {
    vHsm_SecureBoot_GetSlInfoOfGroupInfo(groupIdx) = 0u;
    VStdLib_MemSet(vHsm_SecureBoot_GetSlHashOfGroupInfo(groupIdx), 0u, 32u); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }
#  endif
}

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockReadFromBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockReadFromBlock(
  vHsm_IdOfSecureBootGroupType groupId,
  P2CONST(void, AUTOMATIC, VHSM_APPL_DATA) NvMBuffer)
{
  vHsm_SecureBootGroupIterType groupIdx;

  for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
  {
    if (vHsm_GetIdOfSecureBootGroup(groupIdx) == groupId)
    {
      uint32 crc;
      VStdLib_MemCpy(&crc, NvMBuffer, sizeof(uint32)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      if (crc == vHsm_GetCrcOfSecureBootGroup(groupIdx))
      {
        VStdMemCpy(vHsm_SecureBoot_GetStorageOfGroupInfo(groupIdx), NvMBuffer, vHsm_SecureBoot_GetStorageSizeOfGroupInfo(groupIdx)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
      }
      else
      {
        vHsm_SecureBootStorage_InitGroup(groupIdx);
      }

    }
  }
  return E_OK;
}

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockWriteToBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockWriteToBlock(
  vHsm_IdOfSecureBootGroupType groupId,
  P2VAR(void, AUTOMATIC, VHSM_APPL_VAR) NvMBuffer)
{
  vHsm_SecureBootGroupIterType groupIdx;

  for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
  {
    if (vHsm_GetIdOfSecureBootGroup(groupIdx) == groupId)
    {
      VStdMemCpy(NvMBuffer, vHsm_SecureBoot_GetStorageOfGroupInfo(groupIdx), vHsm_SecureBoot_GetStorageSizeOfGroupInfo(groupIdx)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    }
  }
  return E_OK;
}

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockInit(
  vHsm_IdOfSecureBootGroupType groupId)
{
  Std_ReturnType retVal = E_OK;
  vHsm_SecureBootGroupIterType groupIdx;

  for (groupIdx = 0u; groupIdx < vHsm_GetSizeOfSecureBootGroup(); groupIdx++)
  {
    if (vHsm_GetIdOfSecureBootGroup(groupIdx) == groupId)
    {
      /* #10 Init the secure boot storage */
      vHsm_SecureBootStorage_InitGroup(groupIdx);
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_SecureBootStorage_NvBlockCallback()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBootStorage_NvBlockCallback(
  vHsm_IdOfSecureBootGroupType groupId,
  uint8 ServiceId,
  NvM_RequestResultType JobResult)
{
  VHSM_DUMMY_STATEMENT(groupId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(ServiceId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(JobResult); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */

  /* #10 Always return E_OK */
  return E_OK;
}
# endif

/**********************************************************************************************************************
 *  vHsm_Core_SecureBoot_MainFunction()
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
 */
FUNC(void, VHSM_CODE)  vHsm_Core_SecureBoot_MainFunction(void)
{
  if (vHsm_SecureBootQueue.queueTopIdx != 0u)
  {
    /* #10 Process parallel group */
    vHsm_SecureBootInfoType secureBootInfo;
    secureBootInfo.isCyclicVerification = vHsm_SecureBootQueue.queueItems[0u].isCyclicverification;
    secureBootInfo.retry = FALSE;
    secureBootInfo.verMethod = vHsm_SecureBootQueue.queueItems[0u].verMethod;
    secureBootInfo.recovery = vHsm_SecureBootQueue.queueItems[0u].recovery;

    /* All error handling is done inside the funtion. RetVal can be ignored in this case */
    (void)vHsm_Core_SecureBoot_ProcessGroupParallel(vHsm_SecureBootQueue.queueItems[0u].groupIdx, &secureBootInfo);

    if (vHsm_Core_SecureBoot_Workspace.inProgress == FALSE)
    {
      if (secureBootInfo.retry == TRUE)
      {
        /* Do not remove the group from the queue. Group will be started again. */
        vHsm_Trace(VHSM_TRACETYPE_INFO, "SB: PAR Retry of gID %2i |\n", vHsm_GetIdOfSecureBootGroup(vHsm_SecureBootQueue.queueItems[0u].groupIdx));
      }
# if (VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE == STD_ON)
      else if (secureBootInfo.recovery == TRUE)
      {
        /* Do not remove the group from the queue but change verification method. Group will be started again. */
        vHsm_SecureBootQueue.queueItems[0u].verMethod = VHSM_VERMETHOD_EXTERNAL_SL;
      }
# endif
      else
      {
        vHsm_Core_SecureBoot_QueueRemoveEntry();
      }
    }
  }
  else if (vHsm_State.vHsm_SecureBootDoneFlag == TRUE)
  {
    /* #20 Perform cyclic verification */
# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
    vHsm_Core_SecureBoot_RestartCyclicVerificationGroups();
# endif
  }
  else
  {
    /* 30 Finish secure boot */
    if (vHsm_State.vHsm_SecureBootEndIndicationFlag == TRUE)
    {
      vHsm_SecureBootVerificationJobIterType verificationJobIdx;
# if (VHSM_SECUREBOOTPROTECTEDCHANNELS == STD_ON)
      vHsm_SecureBootProtectedChannelsIterType protectedChannelsIdx;
# endif

      /* #31 Marks secure boot as done */
      vHsm_State.vHsm_SecureBootDoneFlag = TRUE;
      if (vHsm_State.vHsm_SecureBootResult == CRYPTO_E_VER_OK)
      {
        /* #32 Restore the valid states of the secure protected keys */
        vHsm_KeyM_RestoreSecureProtectedKeyStates();
      }

      /* #33 Remove channel restriction of parallel secure boot channels to make them usable from the host core */
      /* There is a DaVinci Cfg5 validation in place to not allow Channels used for cyclic verification to be acessible by the host core */
      for (verificationJobIdx = 0u; verificationJobIdx < vHsm_GetSizeOfSecureBootVerificationJob(); verificationJobIdx++)
      {
        vHsm_DeleteUsageRestrictionOfJobObjects(vHsm_GetParallelChannelRefOfSecureBootVerificationJob(verificationJobIdx), VHSM_DEACTIVATEJOBOBJECTS_RESTRICTCHANNEL);
      }
# if (VHSM_SECUREBOOTPROTECTEDCHANNELS == STD_ON)
      /* Remove channel restriction of CryIfChannels which are configured in vhsm_securebootprotectedchannels */
      for (protectedChannelsIdx = 0u; protectedChannelsIdx < vHsm_GetSizeOfSecureBootProtectedChannels(); protectedChannelsIdx++)
      {
        vHsm_DeleteUsageRestrictionOfJobObjects(vHsm_GetSecureBootProtectedChannels(protectedChannelsIdx), VHSM_DEACTIVATEJOBOBJECTS_SECUREBOOT);
      }
# endif

      /* #34 Enable cyclic verification */
# if(VHSM_CYCLIC_VERIFICATION_AVAILABLE == STD_ON)
      vHsm_State.vHsm_CyclicVerificationFlag = TRUE;
# endif
    }
  }
} /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

# if (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON) || (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
/**********************************************************************************************************************
 *  vHsm_SecureBoot_SetTag()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_SecureBoot_SetTag(
  vHsm_SecureBootSegmentIterType segmentIdx,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) tag,
  uint32 tagLength,
  boolean persist)
{
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
#  if (VHSM_SECURE_BOOT_STORAGE_METHOD == VHSM_STORAGE_IN_CSM)
  retVal = vHsm_SecureBoot_SetElement(segmentIdx, CRYPTO_KE_CUSTOM_VHSM_SECURE_BOOT_SLOT_TAG, tag, tagLength, persist);
#  elif (VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE == STD_ON) /* COV_VHSM_COMPARE_INTERNAL_MANDATORY */
  /* #10 Copy provided tag to secureboot segment */
  VStdLib_MemCpy(vHsm_SecureBoot_GetTagOfSegmentInfo(segmentIdx), tag, tagLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  /* #20 Set Tag available */
  if (tagLength == vHsm_GetTagLengthOfSecureBootGroup(vHsm_GetGroupIdxOfSecureBootSegment(segmentIdx)))
  {
    vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentIdx) = TRUE;
  }
  else
  {
    vHsm_SecureBoot_GetTagAvailableOfSegmentInfo(segmentIdx) = FALSE;
  }
  /* #30 Persist information */
  retVal = vHsm_SecureBoot_PersistHelper(persist, segmentIdx);
#  endif
  return retVal;
}
# endif

#endif /* (VHSM_SECURE_BOOT == STD_ON) */

#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Core_SecureBoot.c
 *********************************************************************************************************************/
