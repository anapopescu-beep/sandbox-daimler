/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Ssa_RightsM_Basic.h
 *        \brief  Header of Basic Access Control List for the Rights Manager of the Standard Security Architecture (Ssa)
 *
 *      \details  The Basic Access Control List contains the rights for the common diagnostic services.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (SSA_RIGHTSM_BASIC_H)
# define SSA_RIGHTSM_BASIC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
# define RIGHTSM_ACCESSRIGHTS_SIZEOF_EXPORT_DATE_TIME                 (15u)
# define RIGHTSM_ACCESSRIGHTS_SIZEOF_LABEL_REV_HISTORY_CDD            (8u)

# define RIGHTSM_ACCESSRIGHTS_OFFSET_VERSION_FILE_FORMAT              (0x00u)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_EXPORT_DATE_TIME                 (0x01u)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD            (0x10u)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_VARIANT_ID_PATTERN_TABLE_OFFSET  (0x18u)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_SID_TABLE_OFFSET                 (0x1Au)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_SUB_FUNC_TABLE_OFFSET            (0x1Cu)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_ID_TABLE_OFFSET                  (0x1Eu)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_HASH                             (0x22u)
# define RIGHTSM_ACCESSRIGHTS_OFFSET_LENGTH_OF_TABLES                 (0x62u)

# define RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID                       (0xFFFFu)
# define RIGHTSM_ACCESSRIGHTS_SF_INVALID                              ((uint8)0xFFu)
# define RIGHTSM_ACCESSRIGHTS_SIZE_OF_SID                             ((uint16)sizeof(RightsM_AccessRights_SidType))
# define RIGHTSM_ACCESSRIGHTS_SIZE_OF_SF                              ((uint16)sizeof(RightsM_AccessRights_SubFuncType))
# define RIGHTSM_ACCESSRIGHTS_SIZE_OF_ID                              ((uint16)sizeof(RightsM_AccessRights_IdType))
# define RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX                             ((uint16)sizeof(RightsM_AccessRights_IdxType))
# define RIGHTSM_ACCESSRIGHTS_VARIANTIDPATTERNTABLE_SIZE_OF_ROW       ((uint16)sizeof(uint16))
# define RIGHTSM_ACCESSRIGHTS_SIDTABLE_SIZE_OF_ROW                    (RIGHTSM_ACCESSRIGHTS_SIZE_OF_SID+RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX+RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX)
# define RIGHTSM_ACCESSRIGHTS_SUBFUNCTABLE_SIZE_OF_ROW                (RIGHTSM_ACCESSRIGHTS_SIZE_OF_SF+RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX+RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX)
# define RIGHTSM_ACCESSRIGHTS_IDTABLE_SIZE_OF_ROW                     (RIGHTSM_ACCESSRIGHTS_SIZE_OF_ID+RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define RightsM_BasicAccessControlList()                             Ssa_RightsM_BasicAcl  /**< Pointer to the Basic ACL. */

/* It is expected that byte order of all numerical values that are to be extracted from the byte stream are little endian (=LOW_BYTE_FIRST). */
/* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
# define RIGHTSM_GET_UINT8(pFirstByte)                                ((uint8)((pFirstByte)[0]))
# define RIGHTSM_GET_UINT16(pFirstByte)                               ((uint16)(((uint16)((pFirstByte)[0]) << 8) | ((uint16)((pFirstByte)[1]))))
# define RIGHTSM_GET_UINT32(pFirstByte)                               ((uint32)(((uint32)((pFirstByte)[0]) << 24) | ((uint32)((pFirstByte)[1]) << 16) | ((uint32)((pFirstByte)[2]) << 8) | ((uint32)((pFirstByte)[3]))))

/* PRQA S 3453 9 */ /* MD_MSR_FctLikeMacro */
# define RightsM_AccessRights_GetVersionFileFormat(fp)                RIGHTSM_GET_UINT8(&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_VERSION_FILE_FORMAT]))
# define RightsM_AccessRights_GetExportDateTime(fp)                   (&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_EXPORT_DATE_TIME]))
# define RightsM_AccessRights_GetLabelRevHistoryCdd(fp)               (&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD]))
# define RightsM_AccessRights_GetOffsetVariantIdPatternTable(fp)      RIGHTSM_GET_UINT16(&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_VARIANT_ID_PATTERN_TABLE_OFFSET]))
# define RightsM_AccessRights_GetOffsetSidTable(fp)                   RIGHTSM_GET_UINT16(&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_SID_TABLE_OFFSET]))
# define RightsM_AccessRights_GetOffsetSubFuncTable(fp)               RIGHTSM_GET_UINT16(&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_SUB_FUNC_TABLE_OFFSET]))
# define RightsM_AccessRights_GetOffsetIdTable(fp)                    RIGHTSM_GET_UINT32(&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_ID_TABLE_OFFSET]))
# define RightsM_AccessRights_GetHash(fp)                             (&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_HASH]))
# define RightsM_AccessRights_GetLengthOfTables(fp)                   RIGHTSM_GET_UINT32(&((fp)[RIGHTSM_ACCESSRIGHTS_OFFSET_LENGTH_OF_TABLES]))

/* Variant identification pattern table. */
/* PRQA S 3453 4 */ /* MD_MSR_FctLikeMacro */
# define RightsM_AccessRights_VarIdPatTable(fp)                       (&((fp)[RightsM_AccessRights_GetOffsetVariantIdPatternTable(fp)]))
# define RightsM_AccessRights_VarIdPatTable_GetVarIdPattern_DiagVariant(fp, n) RIGHTSM_GET_UINT8(&(RightsM_AccessRights_VarIdPatTable(fp)[(n)*RIGHTSM_ACCESSRIGHTS_VARIANTIDPATTERNTABLE_SIZE_OF_ROW]))
# define RightsM_AccessRights_VarIdPatTable_GetVarIdPattern_DiagVersion(fp, n) RIGHTSM_GET_UINT8(&(RightsM_AccessRights_VarIdPatTable(fp)[((n)*RIGHTSM_ACCESSRIGHTS_VARIANTIDPATTERNTABLE_SIZE_OF_ROW) + 1u]))
# define RightsM_AccessRights_VarIdPatTable_GetNumItems(fp)           (((uint16)(RightsM_AccessRights_GetOffsetSidTable(fp) - RightsM_AccessRights_GetOffsetVariantIdPatternTable(fp))) / RIGHTSM_ACCESSRIGHTS_VARIANTIDPATTERNTABLE_SIZE_OF_ROW)

/* SID table. */
/* PRQA S 3453 5 */ /* MD_MSR_FctLikeMacro */
# define RightsM_AccessRights_SidTable(fp)                            (&((fp)[RightsM_AccessRights_GetOffsetSidTable(fp)]))
# define RightsM_AccessRights_SidTable_GetSid(fp,n)                   RIGHTSM_GET_UINT8(&(RightsM_AccessRights_SidTable(fp)[(n)*RIGHTSM_ACCESSRIGHTS_SIDTABLE_SIZE_OF_ROW]))
# define RightsM_AccessRights_SidTable_GetStartIdx(fp, n)             RIGHTSM_GET_UINT16(&(RightsM_AccessRights_SidTable(fp)[((n)*RIGHTSM_ACCESSRIGHTS_SIDTABLE_SIZE_OF_ROW) + RIGHTSM_ACCESSRIGHTS_SIZE_OF_SID]))
# define RightsM_AccessRights_SidTable_GetEndIdx(fp, n)               RIGHTSM_GET_UINT16(&(RightsM_AccessRights_SidTable(fp)[((n)*RIGHTSM_ACCESSRIGHTS_SIDTABLE_SIZE_OF_ROW) + RIGHTSM_ACCESSRIGHTS_SIZE_OF_SID + RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX]))
# define RightsM_AccessRights_SidTable_GetNumItems(fp)                (((uint16)(RightsM_AccessRights_GetOffsetSubFuncTable(fp) - RightsM_AccessRights_GetOffsetSidTable(fp))) / RIGHTSM_ACCESSRIGHTS_SIDTABLE_SIZE_OF_ROW)

/* Sub-function table. */
/* PRQA S 3453 4 */ /* MD_MSR_FctLikeMacro */
# define RightsM_AccessRights_SubFuncTable(fp)                        (&((fp)[RightsM_AccessRights_GetOffsetSubFuncTable(fp)]))
# define RightsM_AccessRights_SubFuncTable_GetSubFunc(fp, n)          RIGHTSM_GET_UINT8(&(RightsM_AccessRights_SubFuncTable(fp)[(n)*RIGHTSM_ACCESSRIGHTS_SUBFUNCTABLE_SIZE_OF_ROW]))
# define RightsM_AccessRights_SubFuncTable_GetStartIdx(fp, n)         RIGHTSM_GET_UINT16(&(RightsM_AccessRights_SubFuncTable(fp)[((n)*RIGHTSM_ACCESSRIGHTS_SUBFUNCTABLE_SIZE_OF_ROW) + RIGHTSM_ACCESSRIGHTS_SIZE_OF_SF]))
# define RightsM_AccessRights_SubFuncTable_GetEndIdx(fp, n)           RIGHTSM_GET_UINT16(&(RightsM_AccessRights_SubFuncTable(fp)[((n)*RIGHTSM_ACCESSRIGHTS_SUBFUNCTABLE_SIZE_OF_ROW) + RIGHTSM_ACCESSRIGHTS_SIZE_OF_SF + RIGHTSM_ACCESSRIGHTS_SIZE_OF_IDX]))

/* Id table. */
/* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
# define RightsM_AccessRights_IdTable(fp)                             (&((fp)[RightsM_AccessRights_GetOffsetIdTable(fp)]))
# define RightsM_AccessRights_IdTable_GetId(fp, n)                    RIGHTSM_GET_UINT16(&(RightsM_AccessRights_IdTable(fp)[(n)*RIGHTSM_ACCESSRIGHTS_IDTABLE_SIZE_OF_ROW]))
# define RightsM_AccessRights_IdTable_GetAccessRights(fp, n)          RIGHTSM_GET_UINT16(&(RightsM_AccessRights_IdTable(fp)[((n)*RIGHTSM_ACCESSRIGHTS_IDTABLE_SIZE_OF_ROW) + RIGHTSM_ACCESSRIGHTS_SIZE_OF_ID]))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 RightsM_AccessRights_SidType;
typedef uint8 RightsM_AccessRights_SubFuncType;
typedef uint16 RightsM_AccessRights_IdType;
typedef uint16 RightsM_AccessRights_IdxType;
typedef RightsM_AccessRights_IdxType RightsM_AccessRights_AccessRightsType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
# define Ssa_RightsM_START_SEC_CONST_UNSPECIFIED
# include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/* PRQA S 3684 1 */ /* MD_SSA_CFG_8.12_3684 */
extern CONST(uint8, Ssa_RightsM_CONST) Ssa_RightsM_BasicAcl[];

# define Ssa_RightsM_STOP_SEC_CONST_UNSPECIFIED
# include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ /*lint !e451 */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* SSA_RIGHTSM_BASIC_H */

/**********************************************************************************************************************
 *  END OF FILE: Ssa_RightM_Basic.h
 *********************************************************************************************************************/

