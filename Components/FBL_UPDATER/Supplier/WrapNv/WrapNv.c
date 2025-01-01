/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file         WrapNv.c
 *  \brief        Wrapper for NV-memory access
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define WRAPNV_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "WrapNv.h"

#if defined( WRAPNV_USECASE_FEE ) || \
    defined( WRAPNV_USECASE_EA )  || \
    defined( WRAPNV_USECASE_NVM )
# if defined( WRAPNV_USECASE_NVM )
#  include "NvM.h"
# endif /* WRAPNV_USECASE_NVM */

/* Critical sections handled by SchM */
# include "SchM_WrapNv.h"

# if (WRAPNV_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif
#endif

#if defined( WRAPNV_USECASE_DRVEEP )
# include "EepInc.h"
#endif
#if defined( WRAPNV_USECASE_EEPM )
# include "EepMgr_inc.h"
#endif

/***********************************************************************************************************************
 *   VERSION
 **********************************************************************************************************************/

#if ( SYSSERVICE_WRAPPERNV_VERSION != 0x0401u ) || \
    ( SYSSERVICE_WRAPPERNV_RELEASE_VERSION != 0x00u )
# error "Error in WrapNv.c: Source and header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

#if defined( WRAPNV_USECASE_FEE ) || \
    defined( WRAPNV_USECASE_EA )  || \
    defined( WRAPNV_USECASE_NVM )
/** Default value, in case block/data is not available and explicit default value not given */
# if !defined( WRAPNV_DEFAULT_VALUE )
#  define WRAPNV_DEFAULT_VALUE      0xFFu
# endif /* WRAPNV_DEFAULT_VALUE */

# if !defined( STATIC )
#  define STATIC                    static
# endif

/* DET API dependent on AUTOSAR release */
# if ( DET_AR_RELEASE_MAJOR_VERSION == 4u ) && \
     ( DET_AR_RELEASE_MINOR_VERSION >= 3u )
#  define WRAPNV_DET_AR_43
# endif /* DET_AR_RELEASE_<category>_VERSION */

# if (WRAPNV_DEV_ERROR_REPORT == STD_ON)
/* PRQA S 3453 1 */ /* MD_MSR_19.7 */
#  define WrapNv_Det_ReportError(ApiId, ErrorCode)    (void)Det_ReportError(WRAPNV_MODULE_ID, WRAPNV_INSTANCE_ID, (ApiId), (ErrorCode))
# endif

# define WrapNv_EnterCritical()              SchM_Enter_WrapNv_WRAPNV_EXCLUSIVE_AREA_0()
# define WrapNv_LeaveCritical()              SchM_Exit_WrapNv_WRAPNV_EXCLUSIVE_AREA_0()

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Specifies the current state of the operation */
typedef enum
{
   WRAPNV_STATE_IDLE = 0u,             /** No operation in progress */
   WRAPNV_STATE_READ_INIT,             /** Initialize read operation */
   WRAPNV_STATE_READ_PENDING,          /** Wait until read operation has finished */
   WRAPNV_STATE_READ_MODIFY_INIT,      /** Initialize read operation for read-modify-write operation */
   WRAPNV_STATE_READ_MODIFY_PENDING,   /** Wait until read operation has finished */
   WRAPNV_STATE_MODIFY_DATA,           /** Modify data for write operation */
   WRAPNV_STATE_WRITE_INIT,            /** Initialize write operation */
   WRAPNV_STATE_WRITE_PENDING,         /** Wait until write operation has finished */
   WRAPNV_STATE_DELETE_INIT,           /** Initialize delete operation */
   WRAPNV_STATE_DELETE_PENDING,        /** Wait until delete operation has finished */
   WRAPNV_STATE_CANCEL                 /** Process cancel operation */
} tWrapNvState;

/** Defines the current operation which is processed by the WrapNv */
typedef enum
{
   WRAPNV_OPERATION_IDLE = 0u,      /** No operation in progress */
   WRAPNV_OPERATION_READ,           /** Read operation in progress */
   WRAPNV_OPERATION_READPARTIAL,    /** ReadPartial operation in progress */
   WRAPNV_OPERATION_WRITE,          /** Write operation in progress */
   WRAPNV_OPERATION_DELETE          /** Delete operation in progress */
} tWrapNvOperation;

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

# define WRAPNV_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* NV block specific */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvRecordNumber;                 /**< Record ID */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvBlockNumber;                  /**< Number of block */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvBlockDataset;                 /**< Dataset of block */
STATIC VAR(uint8, WRAPNV_VAR_NOINIT)  gWrapNvBlockBuffer[WRAPNV_MAX_BLOCK_LENGTH];  /**< Data buffer for whole NV block */ /* PRQA S 3218 */ /* MD_WrapNv_3218 */
STATIC P2CONST(uint8, AUTOMATIC, WRAPNV_CONST) gWrapNvBlockDefaultValue;   /**< Default value of a NV block, if invalid/not present */
# if defined( WRAPNV_USECASE_NVM )
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvBlockMaxDataset;              /**< Maximum number of datasets of the block */
# endif  /* WRAPNV_USECASE_NVM */

/* Data specific */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvReadDataOffset;               /**< Offset in NV block to the data */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvReadDataLength;               /**< Length of data inside the NV block */
STATIC VAR(tWrapNvRamData, WRAPNV_VAR_NOINIT) gWrapNvReadDataBuffer;       /**< Input buffer from upper layer */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvWriteDataOffset;              /**< Offset in NV block to the data */
STATIC VAR(uint16, WRAPNV_VAR_NOINIT) gWrapNvWriteDataLength;              /**< Length of data inside the NV block */
STATIC VAR(tWrapNvConstData, WRAPNV_VAR_NOINIT) gWrapNvWriteDataBuffer;    /**< Write buffer from upper layer */
STATIC VAR(tWrapNvRamData, WRAPNV_VAR_NOINIT) gWrapNvBlockAccessBuffer;    /**< Buffer used to read and/or write data from/to the NV block */

STATIC VAR(tWrapNvState, WRAPNV_VAR_NOINIT) gWrapNvCurrentState;           /**< Current state of NV access (read/modify/write) */
STATIC VAR(tWrapNvOperation, WRAPNV_VAR_NOINIT) gWrapNvCurrentOperation;   /**< Current operation */

# define WRAPNV_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* WRAPNV_USECASE_* */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define WRAPNV_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined( WRAPNV_USECASE_FEE ) || \
    defined( WRAPNV_USECASE_EA )  || \
    defined( WRAPNV_USECASE_NVM )
STATIC FUNC(MemIf_StatusType, WRAPNV_CODE) WrapNv_GetStatus( void );
STATIC FUNC(MemIf_JobResultType, WRAPNV_CODE) WrapNv_GetJobResult( void );
# if defined( WRAPNV_USECASE_NVM )
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_SetDataIndex( void );
# endif  /* WRAPNV_USECASE_NVM */
STATIC FUNC(void, WRAPNV_CODE) WrapNv_InitInternal( void );
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Cancel( void );
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Read( uint16 id, uint16 idx, tWrapNvRamData buffer, tWrapNvAccessType access);
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadAsyncInternal(uint16 id, uint16 idx, tWrapNvRamData buffer,
   tWrapNvOpStatus opStatus, tWrapNvAccessType access);
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartial( uint16 id, uint16 idx, tWrapNvRamData buffer, uint16 offset,
   uint16 length, tWrapNvAccessType access);
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialAsyncInternal(uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length, tWrapNvOpStatus opStatus, tWrapNvAccessType access);
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Delete( uint16 id, uint16 idx );
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Write( uint16 id, uint16 idx, tWrapNvConstData buffer, tWrapNvAccessType access );
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteAsyncInternal(uint16 id, uint16 idx, tWrapNvConstData buffer,
   tWrapNvOpStatus opStatus, tWrapNvAccessType access);
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_MainFunction( void );
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_PollMainFunctions( void );

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  WrapNv_GetStatus
 **********************************************************************************************************************/
/*! \brief       Checks the process state of the NV
 *  \return      MEMIF_IDLE in case job is finished (failed or OK state), otherwise MEMIF_BUSY
 **********************************************************************************************************************/
STATIC FUNC(MemIf_StatusType, WRAPNV_CODE) WrapNv_GetStatus( void )
{
   MemIf_StatusType result;

# if defined( WRAPNV_USECASE_NVM )
   NvM_RequestResultType nvmStatus;

   if (E_OK == NvM_GetErrorStatus(gWrapNvBlockNumber, &nvmStatus))
   {
      /* Check if NVM currently processes a request */
      if (NVM_REQ_PENDING == nvmStatus)
      {
         result = MEMIF_BUSY;
      }
      else
      {
         result = MEMIF_IDLE;
      }
   }
   else
   {
      result = MEMIF_IDLE;
   }
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
   result = WrapNv_MemDrvGetStatus();
# endif /* WRAPNV_USECASE_* */

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_GetJobResult
 **********************************************************************************************************************/
/*! \brief       Checks the result of the last request
 *  \pre         WrapNv_GetStatus has been called and returned MEMIF_IDLE
 *  \return      return MEMIF_JOB_OK in case data could be read successfully
 *                      MEMIF_BLOCK_INCONSISTENT in case data could not be read (e.g. data are corrupt)
 *                      MEMIF_INVALID in case the block has been invalidated previously
 *                      MEMIF_JOB_FAILED otherwise
 **********************************************************************************************************************/
STATIC FUNC(MemIf_JobResultType, WRAPNV_CODE) WrapNv_GetJobResult( void )
{
   MemIf_JobResultType result;

# if defined( WRAPNV_USECASE_NVM )
   NvM_RequestResultType nvmStatus;

   if (E_OK == NvM_GetErrorStatus(gWrapNvBlockNumber, &nvmStatus))
   {
      /* Remap NVM status to MEMIF status */
      switch (nvmStatus)
      {
         case NVM_REQ_OK:
         {
            result = MEMIF_JOB_OK;
            break;
         }
         case NVM_REQ_NOT_OK:
         {
            result = MEMIF_JOB_FAILED;
            break;
         }
         case NVM_REQ_INTEGRITY_FAILED:
         {
            result = MEMIF_BLOCK_INCONSISTENT;
            break;
         }
         case NVM_REQ_NV_INVALIDATED:
         {
            result = MEMIF_BLOCK_INVALID;
            break;
         }
         default:
         {
            /* Unknown state */
            result = MEMIF_JOB_FAILED;
            break;
         }
      }
   }
   else
   {
      result = MEMIF_JOB_FAILED;
   }
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
   result = WrapNv_MemDrvGetJobResult();
# endif /* WRAPNV_USECASE_* */

   return result;
}

# if defined( WRAPNV_USECASE_NVM )
/***********************************************************************************************************************
 *  WrapNv_SetDataIndex
 **********************************************************************************************************************/
/*! \brief       Sets the data index (dataset) of current block
 *  \pre         Global variables (gWrapNvBlockMaxDataset, gWrapNvBlockNumber and gWrapNvBlockDataset) have to be initialized
 *  \return      return WRAPNV_E_OK in case data index could be set or if it must not be set at all (e.g. only one
 *                                  dataset configured/available)
 *                      WRAPNV_E_NOT_OK in case NvM couldn't set data data index
 **********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_SetDataIndex( void )
{
   WrapNv_ReturnType result;

   /* Initialize variables */
   result = WRAPNV_E_OK;

   /* At least two datasets must be configured/available to set the data index for the NVM */
   if (gWrapNvBlockMaxDataset > 1u)
   {
      if (E_OK != NvM_SetDataIndex(gWrapNvBlockNumber, (uint8)(gWrapNvBlockDataset & 0xFFu)))
      {
         result = WRAPNV_E_NOT_OK;
      }
   }

   return result;
}
# endif  /* WRAPNV_USECASE_NVM */

/***********************************************************************************************************************
 *  WrapNv_InitInternal
 **********************************************************************************************************************/
/*! \brief       Initializes internal states/variables
 **********************************************************************************************************************/
STATIC FUNC(void, WRAPNV_CODE) WrapNv_InitInternal( void )
{
   /* Initialize state */
   gWrapNvCurrentState = WRAPNV_STATE_IDLE;
   gWrapNvCurrentOperation = WRAPNV_OPERATION_IDLE;

   /* Initialize variables */
   gWrapNvRecordNumber = 0xFFFFu;
   gWrapNvBlockDataset = 0xFFFFu;
   gWrapNvReadDataOffset = 0xFFFFu;
   gWrapNvReadDataLength = 0xFFFFu;
   gWrapNvReadDataBuffer = NULL_PTR;
   gWrapNvWriteDataBuffer = NULL_PTR;
}

/***********************************************************************************************************************
 *  WrapNv_Cancel
 **********************************************************************************************************************/
/*! \brief       Cancels current pending job
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed
 **********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Cancel( void )
{
   WrapNv_ReturnType result;

   /* Setup the cancel request */
   gWrapNvCurrentState = WRAPNV_STATE_CANCEL;
   result = WrapNv_MainFunction();

   /* Reset internal states */
   WrapNv_InitInternal();

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_Read
 **********************************************************************************************************************/
/*! \brief       Initialize the read operation
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[out]  buffer  Pointer to data buffer
 *  \param[in]   access  Type of access
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Read( uint16 id, uint16 idx, tWrapNvRamData buffer, tWrapNvAccessType access)
{
   WrapNv_ReturnType result;
   uint8 errorId;
   P2CONST(tWrapNvRecordTbl, AUTOMATIC, WRAPNV_CONST) localRecordPtr;
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) localBlockPtr;

   /* Initialize variable */
   result = WRAPNV_E_NOT_OK;
   errorId = WRAPNV_E_NO_ERROR;

   if (WRAPNV_STATE_IDLE != gWrapNvCurrentState)
   {
      errorId = WRAPNV_E_NOT_IDLE;
   }
   /* Check if ID is valid */
   else if (id >= kWrapNvNrOfRecord)
   {
      errorId = WRAPNV_E_PARAM_ID;
   }
   /* Check if dataset is valid */
   else if (   (idx >= kWrapNvRecordTbl[id].recordBlockPtr->blockMaxDatasets)
            || (idx > 0xFFu))
   {
      errorId = WRAPNV_E_PARAM_DATASET;
   }
   else
   {
      localRecordPtr = &kWrapNvRecordTbl[id];
      localBlockPtr = localRecordPtr->recordBlockPtr;

      gWrapNvRecordNumber = id;
      gWrapNvBlockNumber = localBlockPtr->blockNumber;
      gWrapNvBlockDataset = idx;
# if defined( WRAPNV_USECASE_NVM )
      gWrapNvBlockMaxDataset = localBlockPtr->blockMaxDatasets;
# endif  /* WRAPNV_USECASE_NVM */
      gWrapNvBlockDefaultValue = localBlockPtr->blockDefaultValue;

      if (access == WRAPNV_ACCESS_DATAELEMENT)
      {
         gWrapNvReadDataOffset = localRecordPtr->recordDataOffset;
         gWrapNvReadDataLength = localRecordPtr->recordDataLength;
      }
      else
      {
         gWrapNvReadDataOffset = 0u;
         gWrapNvReadDataLength = localBlockPtr->blockLength;
      }

      gWrapNvReadDataBuffer = buffer;

      gWrapNvWriteDataOffset = 0u;
      gWrapNvWriteDataLength = 0u;
      gWrapNvWriteDataBuffer = NULL_PTR;

# if defined( WRAPNV_USECASE_NVM )
      gWrapNvBlockAccessBuffer = gWrapNvBlockBuffer;
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
      gWrapNvBlockAccessBuffer = NULL_PTR;
# endif /* WRAPNV_USECASE_* */

      gWrapNvCurrentState = WRAPNV_STATE_READ_INIT;

      result = WrapNv_MainFunction();
   }

# if (WRAPNV_DEV_ERROR_REPORT == STD_ON)
   if(errorId != WRAPNV_E_NO_ERROR)
   {
      WrapNv_Det_ReportError(WRAPNV_APIID_READ, errorId );
   }
# else
   (void)errorId; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* (WRAPNV_DEV_ERROR_REPORT == STD_ON) */

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_ReadPartial
 **********************************************************************************************************************/
/*! \brief       Initialize operation for reading only partial of the data
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[out]  buffer Pointer to data buffer
 *  \param[in]   offset Offset in the entry to read only partial
 *  \param[in]   length Length of the partial read
 *  \param[in]   access Type of access
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
/* PRQA S 6060, 6080 1 */ /* MD_MSR_STPAR, MD_MSR_STMIF */
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartial( uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length, tWrapNvAccessType access)
{
   WrapNv_ReturnType result;
   uint8 errorId;
   P2CONST(tWrapNvRecordTbl, AUTOMATIC, WRAPNV_CONST) localRecordPtr;
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) localBlockPtr;

   /* Initialize variable */
   result = WRAPNV_E_NOT_OK;
   errorId = WRAPNV_E_NO_ERROR;

   if (WRAPNV_STATE_IDLE != gWrapNvCurrentState)
   {
      errorId = WRAPNV_E_NOT_IDLE;
   }
   /* Check if ID is valid */
   else if (id >= kWrapNvNrOfRecord)
   {
      errorId = WRAPNV_E_PARAM_ID;
   }
   /* Check if dataset is valid */
   else if (   (idx >= kWrapNvRecordTbl[id].recordBlockPtr->blockMaxDatasets)
            || (idx > 0xFFu))
   {
      errorId = WRAPNV_E_PARAM_DATASET;
   }
   else if  ( ( (access == WRAPNV_ACCESS_DATAELEMENT) &&
              ( (offset + length) > kWrapNvRecordTbl[id].recordDataLength) ) ||
              ( (access == WRAPNV_ACCESS_BLOCKELEMENT) &&
              ( (offset + length) > kWrapNvRecordTbl[id].recordBlockPtr->blockLength) ) )
   {
      errorId = WRAPNV_E_PARAM_READ;
   }
   else
   {
      localRecordPtr = &kWrapNvRecordTbl[id];
      localBlockPtr = localRecordPtr->recordBlockPtr;

      gWrapNvRecordNumber = id;
      gWrapNvBlockNumber = localBlockPtr->blockNumber;
      gWrapNvBlockDataset = idx;
# if defined( WRAPNV_USECASE_NVM )
      gWrapNvBlockMaxDataset = localBlockPtr->blockMaxDatasets;
# endif  /* WRAPNV_USECASE_NVM */
      gWrapNvBlockDefaultValue = localBlockPtr->blockDefaultValue;

      if (access == WRAPNV_ACCESS_DATAELEMENT)
      {
         gWrapNvReadDataOffset = localRecordPtr->recordDataOffset + offset;
         gWrapNvReadDataLength = length;
      }
      else
      {
         gWrapNvReadDataOffset = offset;
         gWrapNvReadDataLength = length;
      }

      gWrapNvReadDataBuffer = buffer;

      gWrapNvWriteDataOffset = 0u;
      gWrapNvWriteDataLength = 0u;
      gWrapNvWriteDataBuffer = NULL_PTR;

# if defined( WRAPNV_USECASE_NVM )
      gWrapNvBlockAccessBuffer = gWrapNvBlockBuffer;
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
      gWrapNvBlockAccessBuffer = NULL_PTR;
# endif /* WRAPNV_USECASE_* */

      gWrapNvCurrentState = WRAPNV_STATE_READ_INIT;

      result = WrapNv_MainFunction();
   }

# if (WRAPNV_DEV_ERROR_REPORT == STD_ON)
   if(errorId != WRAPNV_E_NO_ERROR)
   {
      WrapNv_Det_ReportError(WRAPNV_APIID_READPARTIAL, errorId );
   }
# else
   (void)errorId; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* (WRAPNV_DEV_ERROR_REPORT == STD_ON) */

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_Delete
 **********************************************************************************************************************/
/*! \brief       Initialize the delete operation
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Delete( uint16 id, uint16 idx )
{
   WrapNv_ReturnType result;
   uint8 errorId;
   P2CONST(tWrapNvRecordTbl, AUTOMATIC, WRAPNV_CONST) localRecordPtr;
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) localBlockPtr;

   /* Initialize variable */
   result = WRAPNV_E_NOT_OK;
   errorId = WRAPNV_E_NO_ERROR;

   if (WRAPNV_STATE_IDLE != gWrapNvCurrentState)
   {
      errorId = WRAPNV_E_NOT_IDLE;
   }
   /* Check if ID is valid */
   else if (id >= kWrapNvNrOfRecord)
   {
      errorId = WRAPNV_E_PARAM_ID;
   }
   /* Check if dataset is valid */
   else if (   (idx >= kWrapNvRecordTbl[id].recordBlockPtr->blockMaxDatasets)
            || (idx > 0xFFu))
   {
      errorId = WRAPNV_E_PARAM_DATASET;
   }
   else
   {
      localRecordPtr = &kWrapNvRecordTbl[id];
      localBlockPtr = localRecordPtr->recordBlockPtr;

      gWrapNvRecordNumber = id;
      gWrapNvBlockNumber = localBlockPtr->blockNumber;
      gWrapNvBlockDataset = idx;
# if defined( WRAPNV_USECASE_NVM )
      gWrapNvBlockMaxDataset = localBlockPtr->blockMaxDatasets;
# endif  /* WRAPNV_USECASE_NVM */
      gWrapNvBlockDefaultValue = localBlockPtr->blockDefaultValue;

      gWrapNvReadDataOffset = 0u;
      gWrapNvReadDataLength = 0u;
      gWrapNvReadDataBuffer = NULL_PTR;

      gWrapNvWriteDataOffset = 0u;
      gWrapNvWriteDataLength = 0u;
      gWrapNvWriteDataBuffer = NULL_PTR;

      gWrapNvBlockAccessBuffer = NULL_PTR;

      gWrapNvCurrentState = WRAPNV_STATE_DELETE_INIT;

      result = WrapNv_MainFunction();
   }

# if (WRAPNV_DEV_ERROR_REPORT == STD_ON)
   if(errorId != WRAPNV_E_NO_ERROR)
   {
      WrapNv_Det_ReportError(WRAPNV_APIID_DELETE, errorId );
   }
# else
   (void)errorId; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* (WRAPNV_DEV_ERROR_REPORT == STD_ON) */

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_Write
 **********************************************************************************************************************/
/*! \brief       Initialize the write operation
 *  \param[in]   id Id of record
 *  \param[in]   idx Dataset of block
 *  \param[in]   buffer Pointer to data buffer
 *  \param[in]   access Type of access
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_Write( uint16 id, uint16 idx, tWrapNvConstData buffer, tWrapNvAccessType access)
{
   WrapNv_ReturnType result;
   uint8 errorId;
   P2CONST(tWrapNvRecordTbl, AUTOMATIC, WRAPNV_CONST) localRecordPtr;
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) localBlockPtr;

   /* Initialize variable */
   result = WRAPNV_E_NOT_OK;
   errorId = WRAPNV_E_NO_ERROR;

   if (WRAPNV_STATE_IDLE != gWrapNvCurrentState)
   {
      errorId = WRAPNV_E_NOT_IDLE;
   }
   /* Check if ID is valid */
   else if (id >= kWrapNvNrOfRecord)
   {
      errorId = WRAPNV_E_PARAM_ID;
   }
   /* Check if dataset is valid */
   else if (   (idx >= kWrapNvRecordTbl[id].recordBlockPtr->blockMaxDatasets)
            || (idx > 0xFFu))
   {
      errorId = WRAPNV_E_PARAM_DATASET;
   }
   else
   {
      localRecordPtr = &kWrapNvRecordTbl[id];
      localBlockPtr = localRecordPtr->recordBlockPtr;

      gWrapNvRecordNumber = id;
      gWrapNvBlockNumber = localBlockPtr->blockNumber;
      gWrapNvBlockDataset = idx;
# if defined( WRAPNV_USECASE_NVM )
      gWrapNvBlockMaxDataset = localBlockPtr->blockMaxDatasets;
# endif  /* WRAPNV_USECASE_NVM */
      gWrapNvBlockDefaultValue = localBlockPtr->blockDefaultValue;

      if ( (localBlockPtr->blockDataAccess == WRAPNV_RECORDACCESS_STRUCTURED) &&
          (access == WRAPNV_ACCESS_DATAELEMENT) )
      {
         gWrapNvReadDataOffset = 0u;
         gWrapNvReadDataLength = localBlockPtr->blockLength;
         gWrapNvReadDataBuffer = gWrapNvBlockBuffer;              /* Map the read buffer to the same buffer as the access buffer */

         gWrapNvWriteDataOffset = localRecordPtr->recordDataOffset;
         gWrapNvWriteDataLength = localRecordPtr->recordDataLength;
         gWrapNvWriteDataBuffer = buffer;

         gWrapNvBlockAccessBuffer = gWrapNvBlockBuffer;

         gWrapNvCurrentState = WRAPNV_STATE_READ_MODIFY_INIT;
      }
      else
      {
         gWrapNvReadDataOffset = 0u;
         gWrapNvReadDataLength = 0u;
         gWrapNvReadDataBuffer = NULL_PTR;

         gWrapNvWriteDataOffset = 0u;
         gWrapNvWriteDataLength = 0u;
         gWrapNvWriteDataBuffer = NULL_PTR;

         gWrapNvBlockAccessBuffer = (tWrapNvRamData)buffer;  /* PRQA S 0311 */ /* MD_WrapNv_0311 */

         gWrapNvCurrentState = WRAPNV_STATE_WRITE_INIT;
      }

      result = WrapNv_MainFunction();
   }

# if (WRAPNV_DEV_ERROR_REPORT == STD_ON)
   if(errorId != WRAPNV_E_NO_ERROR)
   {
      WrapNv_Det_ReportError(WRAPNV_APIID_WRITE, errorId );
   }
# else
   (void)errorId; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* (WRAPNV_DEV_ERROR_REPORT == STD_ON) */

   return result;
}

/***********************************************************************************************************************
*  WrapNv_ReadAsyncInternal
**********************************************************************************************************************/
/*! \brief      Reads specific data asynchronously from a NV block
*  \param[in]   id  Id of record
*  \param[in]   idx  Dataset of block
*  \param[out]  buffer  Pointer to data buffer
*  \param[in]   opStatus  Operation status of calling instance
 * \param[in]   access  Type of access
*  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
*                          WRAPNV_E_PENDING if job needs more time
**********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadAsyncInternal(uint16 id, uint16 idx, tWrapNvRamData buffer,
   tWrapNvOpStatus opStatus, tWrapNvAccessType access)
{
   WrapNv_ReturnType result;
   tWrapNvOpStatus currentOpStatus;

   WrapNv_EnterCritical();

   /* Check if WrapNv is idle so it can accept a new request */
   if (WRAPNV_OPERATION_IDLE == gWrapNvCurrentOperation)
   {
      /* Check if new job is canceled */
      if (opStatus == WRAPNV_OPSTATUS_CANCEL)
      {
         currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
      }
      else
      {
         /* Parameters will be stored in WrapNv_Read() call */
         currentOpStatus = WRAPNV_OPSTATUS_INIT;
         gWrapNvCurrentOperation = WRAPNV_OPERATION_READ;
      }
   }
   else
   {
      /* Check if this is a different request to the current pending request */
      if ((id == gWrapNvRecordNumber)
         && (idx == gWrapNvBlockDataset)
         && (buffer == gWrapNvReadDataBuffer)
         && (WRAPNV_OPERATION_READ == gWrapNvCurrentOperation)
         )
      {
         /* Check if the current job should be canceled */
         if (opStatus == WRAPNV_OPSTATUS_CANCEL)
         {
            currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
         }
         else
         {
            /* Process current request */
            currentOpStatus = WRAPNV_OPSTATUS_PENDING;
         }
      }
      else
      {
         /* Wait until other request has been finished */
         currentOpStatus = WRAPNV_OPSTATUS_IDLE;
      }
   }

   WrapNv_LeaveCritical();

   /* Only init and pending states are allowed at this point */
   switch (currentOpStatus)
   {
   case WRAPNV_OPSTATUS_INIT:
   {
      result = WrapNv_Read(id, idx, buffer, access);
      break;
   }
   case WRAPNV_OPSTATUS_PENDING:
   {
      result = WrapNv_MainFunction();
      break;
   }
   case WRAPNV_OPSTATUS_IDLE: /* Used when two instances access the WrapNv */
   {
      result = WRAPNV_E_PENDING;
      break;
   }
   case WRAPNV_OPSTATUS_CANCEL:
   {
      result = WrapNv_Cancel();
      break;
   }
   default:
   { /* PRQA S 2880 1 */ /* MD_MSR_Unreachable */
      result = WRAPNV_E_NOT_OK;
      break;
   }
   }

   /* Check if current operation has finished */
   if ((WRAPNV_E_OK == result)
      || (WRAPNV_E_NOT_OK == result))
   {
      gWrapNvCurrentOperation = WRAPNV_OPERATION_IDLE;
   }

   return result;
}

/***********************************************************************************************************************
*  WrapNv_ReadPartialAsyncInternal
**********************************************************************************************************************/
/*! \brief      Reads partial data asynchronously from a NV block
*  \param[in]   id  Id of record
*  \param[in]   idx  Dataset of block
*  \param[out]  buffer  Pointer to data buffer
*  \param[in]   offset Offset in the entry to read only partial
*  \param[in]   length Length of the partial read
*  \param[in]   opStatus  Operation status of calling instance
*  \param[in]   access  Type of access
*  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
*                          WRAPNV_E_PENDING if job needs more time
**********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialAsyncInternal(uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length, tWrapNvOpStatus opStatus, tWrapNvAccessType access)
{
   WrapNv_ReturnType result;
   tWrapNvOpStatus currentOpStatus;

   WrapNv_EnterCritical();

   /* Check if WrapNv is idle so it can accept a new request */
   if (WRAPNV_OPERATION_IDLE == gWrapNvCurrentOperation)
   {
      /* Check if new job is canceled */
      if (opStatus == WRAPNV_OPSTATUS_CANCEL)
      {
         currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
      }
      else
      {
         /* Parameters will be stored in WrapNv_ReadPartial() call */
         currentOpStatus = WRAPNV_OPSTATUS_INIT;
         gWrapNvCurrentOperation = WRAPNV_OPERATION_READPARTIAL;
      }
   }
   else
   {
      /* Check if this is a different request to the current pending request */
      if ((id == gWrapNvRecordNumber)
         && (idx == gWrapNvBlockDataset)
         && (buffer == gWrapNvReadDataBuffer)
         && (offset == gWrapNvReadDataOffset)
         && (length == gWrapNvReadDataLength)
         && (WRAPNV_OPERATION_READPARTIAL == gWrapNvCurrentOperation)
         )
      {
         /* Check if the current job should be canceled */
         if (opStatus == WRAPNV_OPSTATUS_CANCEL)
         {
            currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
         }
         else
         {
            /* Process current request */
            currentOpStatus = WRAPNV_OPSTATUS_PENDING;
         }
      }
      else
      {
         /* Wait until other request has been finished */
         currentOpStatus = WRAPNV_OPSTATUS_IDLE;
      }
   }

   WrapNv_LeaveCritical();

   /* Only init and pending states are allowed at this point */
   switch (currentOpStatus)
   {
   case WRAPNV_OPSTATUS_INIT:
   {
      result = WrapNv_ReadPartial(id, idx, buffer, offset, length, access);
      break;
   }
   case WRAPNV_OPSTATUS_PENDING:
   {
      result = WrapNv_MainFunction();
      break;
   }
   case WRAPNV_OPSTATUS_IDLE: /* Used when two instances access the WrapNv */
   {
      result = WRAPNV_E_PENDING;
      break;
   }
   case WRAPNV_OPSTATUS_CANCEL:
   {
      result = WrapNv_Cancel();
      break;
   }
   default:
   { /* PRQA S 2880 1 */ /* MD_MSR_Unreachable */
      result = WRAPNV_E_NOT_OK;
      break;
   }
   }

   /* Check if current operation has finished */
   if ((WRAPNV_E_OK == result)
      || (WRAPNV_E_NOT_OK == result))
   {
      gWrapNvCurrentOperation = WRAPNV_OPERATION_IDLE;
   }

   return result;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/***********************************************************************************************************************
*  WrapNv_WriteAsyncInternal
**********************************************************************************************************************/
/*! \brief      Writes specific data asynchronously to a NV block
*  \param[in]   id  Id of record
*  \param[in]   idx  Dataset of block
*  \param[in]   buffer  Pointer to data buffer
*  \param[in]   opStatus  Operation status of calling instance
*  \param[in]   access  Type of access
*  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
*                          WRAPNV_E_PENDING if job needs more time
**********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteAsyncInternal(uint16 id, uint16 idx, tWrapNvConstData buffer,
   tWrapNvOpStatus opStatus, tWrapNvAccessType access)
{
   WrapNv_ReturnType result;
   tWrapNvOpStatus currentOpStatus;

   WrapNv_EnterCritical();

   /* Check if WrapNv is idle so it can accept a new request */
   if (WRAPNV_OPERATION_IDLE == gWrapNvCurrentOperation)
   {
      /* Check if new job is canceled */
      if (opStatus == WRAPNV_OPSTATUS_CANCEL)
      {
         currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
      }
      else
      {
         /* Parameters will be stored in WrapNv_Write() call */
         currentOpStatus = WRAPNV_OPSTATUS_INIT;
         gWrapNvCurrentOperation = WRAPNV_OPERATION_WRITE;
      }
   }
   else
   {
      /* Check if this is a different request to the current pending request */
      if ((id == gWrapNvRecordNumber)
         && (idx == gWrapNvBlockDataset)
         && ((buffer == gWrapNvWriteDataBuffer) || (buffer == gWrapNvBlockAccessBuffer))
         && (WRAPNV_OPERATION_WRITE == gWrapNvCurrentOperation)
         )
      {
         /* Check if the current job should be canceled */
         if (opStatus == WRAPNV_OPSTATUS_CANCEL)
         {
            currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
         }
         else
         {
            /* Process current request */
            currentOpStatus = WRAPNV_OPSTATUS_PENDING;
         }
      }
      else
      {
         /* Wait until other request has been finished */
         currentOpStatus = WRAPNV_OPSTATUS_IDLE;
      }
   }

   WrapNv_LeaveCritical();

   /* Only init and pending states are allowed at this point */
   switch (currentOpStatus)
   {
   case WRAPNV_OPSTATUS_INIT:
   {
      result = WrapNv_Write(id, idx, buffer, access);
      break;
   }
   case WRAPNV_OPSTATUS_PENDING:
   {
      result = WrapNv_MainFunction();
      break;
   }
   case WRAPNV_OPSTATUS_IDLE: /* Used when two instances access the WrapNv */
   {
      result = WRAPNV_E_PENDING;
      break;
   }
   case WRAPNV_OPSTATUS_CANCEL:
   {
      result = WrapNv_Cancel();
      break;
   }
   default:
   { /* PRQA S 2880 1 */ /* MD_MSR_Unreachable */
      result = WRAPNV_E_NOT_OK;
      break;
   }
   }

   /* Check if current operation has finished */
   if ((WRAPNV_E_OK == result)
      || (WRAPNV_E_NOT_OK == result))
   {
      gWrapNvCurrentOperation = WRAPNV_OPERATION_IDLE;
   }

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_MainFunction
 **********************************************************************************************************************/
/*! \brief       Main task of the NV-Wrapper to get the current status of the read/write operation
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
/* PRQA S 6030, 6080 1 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_MainFunction( void )
{
   WrapNv_ReturnType result;
   uint16_least index;

   result = WRAPNV_E_PENDING;

   switch (gWrapNvCurrentState)
   {
      case WRAPNV_STATE_READ_INIT: /* Intentional fall through */
      case WRAPNV_STATE_READ_MODIFY_INIT:
      {
         if (MEMIF_IDLE == WrapNv_GetStatus())
         {
# if defined( WRAPNV_USECASE_NVM )
            result = WrapNv_SetDataIndex();
            if (WRAPNV_E_OK == result)
            {
               /* PRQA S 0314 1 */ /* MD_WrapNv_0314 */
               result = NvM_ReadBlock(gWrapNvBlockNumber, (P2VAR(void, AUTOMATIC, NVM_APPL_DATA))gWrapNvBlockAccessBuffer);
            }
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
            result = WrapNv_MemDrvRead(gWrapNvBlockNumber | gWrapNvBlockDataset, gWrapNvReadDataOffset, gWrapNvReadDataBuffer, gWrapNvReadDataLength);
# endif /* WRAPNV_USECASE_* */

            /* If read request was successful, remap result to WRAPNV_E_PENDING */
            if (WRAPNV_E_OK == result)
            {
               result = WRAPNV_E_PENDING;

               if (WRAPNV_STATE_READ_INIT == gWrapNvCurrentState)
               {
                  gWrapNvCurrentState = WRAPNV_STATE_READ_PENDING;
               }
               else
               {
                  gWrapNvCurrentState = WRAPNV_STATE_READ_MODIFY_PENDING;
               }
            }
            else
            {
               gWrapNvCurrentState = WRAPNV_STATE_IDLE;
            }
         }
         break;
      }
      case WRAPNV_STATE_READ_PENDING: /* Intentional fall through */
      case WRAPNV_STATE_READ_MODIFY_PENDING:
      {
         if (MEMIF_IDLE == WrapNv_GetStatus())
         {
            switch( WrapNv_GetJobResult() )
            {
               case MEMIF_JOB_OK:
               {
# if defined( WRAPNV_USECASE_NVM )
                  for (index = 0u; index < gWrapNvReadDataLength; index++)
                  {
                     gWrapNvReadDataBuffer[index] = gWrapNvBlockAccessBuffer[gWrapNvReadDataOffset + index];
                  }
# endif /* WRAPNV_USECASE_NVM */

                  result = WRAPNV_E_OK;
                  break;
               }
               case MEMIF_BLOCK_INCONSISTENT:
               case MEMIF_BLOCK_INVALID:
               {
                  if (gWrapNvBlockDefaultValue != NULL_PTR)
                  {
                     for (index = 0u; index < gWrapNvReadDataLength; index++)
                     {
                        gWrapNvReadDataBuffer[index] = gWrapNvBlockDefaultValue[gWrapNvReadDataOffset + index];
                     }
                  }
                  else
                  {
                     /* No explicit default value configured - fill read buffer with default value */
                     for (index = 0u; index < gWrapNvReadDataLength; index++)
                     {
                        gWrapNvReadDataBuffer[index] = WRAPNV_DEFAULT_VALUE;
                     }
                  }
                  result = WRAPNV_E_OK;
                  break;
               }
               default:
               {
                  result = WRAPNV_E_NOT_OK;
                  break;
               }
            }

            if (WRAPNV_STATE_READ_PENDING == gWrapNvCurrentState)
            {
               /* No more action required - reset state */
               gWrapNvCurrentState = WRAPNV_STATE_IDLE;
            }
            else
            {
               if (WRAPNV_E_OK == result)
               {
                  /* This is a read-modify-write operation - remap WRAPNV_E_OK state to WRAPNV_E_PENDING */
                  result = WRAPNV_E_PENDING;
                  gWrapNvCurrentState = WRAPNV_STATE_MODIFY_DATA;
               }
            }
         }
         break;
      }
      case WRAPNV_STATE_MODIFY_DATA:
      {
         /* Modify data with new information */
         for (index = 0u; index < gWrapNvWriteDataLength; index++)
         {
            gWrapNvBlockAccessBuffer[gWrapNvWriteDataOffset + index] = gWrapNvWriteDataBuffer[index];
         }

         gWrapNvCurrentState = WRAPNV_STATE_WRITE_INIT;
         /* Intentional fall through */
      }
      case WRAPNV_STATE_WRITE_INIT: /* PRQA S 2003 */ /* MD_WrapNv_2003 */
      {
         if (MEMIF_IDLE == WrapNv_GetStatus())
         {
# if defined( WRAPNV_USECASE_NVM )
            result = WrapNv_SetDataIndex();
            if (WRAPNV_E_OK == result)
            {
               /* PRQA S 0314 1 */ /* MD_WrapNv_0314 */
               result = NvM_WriteBlock(gWrapNvBlockNumber, (P2CONST(void, AUTOMATIC, NVM_APPL_DATA))gWrapNvBlockAccessBuffer);
            }
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
            result = WrapNv_MemDrvWrite(gWrapNvBlockNumber | gWrapNvBlockDataset, gWrapNvBlockAccessBuffer);
# endif /* WRAPNV_USECASE_* */

            /* If write request was successful, remap result to WRAPNV_E_PENDING */
            if (WRAPNV_E_OK == result)
            {
               result = WRAPNV_E_PENDING;

               gWrapNvCurrentState = WRAPNV_STATE_WRITE_PENDING;
            }
            else
            {
               gWrapNvCurrentState = WRAPNV_STATE_IDLE;
            }
         }
         break;
      }
      case WRAPNV_STATE_DELETE_INIT:
      {
         if (MEMIF_IDLE == WrapNv_GetStatus())
         {
# if defined( WRAPNV_USECASE_NVM )
            result = WrapNv_SetDataIndex();
            if (WRAPNV_E_OK == result)
            {
               result = NvM_InvalidateNvBlock(gWrapNvBlockNumber);
            }
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
            result = WrapNv_MemDrvInvalidateBlock(gWrapNvBlockNumber | gWrapNvBlockDataset);
# endif /* WRAPNV_USECASE_* */

            /* If invalidate request was successful, remap result to WRAPNV_E_PENDING */
            if (WRAPNV_E_OK == result)
            {
               result = WRAPNV_E_PENDING;

               gWrapNvCurrentState = WRAPNV_STATE_DELETE_PENDING;
            }
            else
            {
               gWrapNvCurrentState = WRAPNV_STATE_IDLE;
            }
         }
         break;
      }
      case WRAPNV_STATE_WRITE_PENDING: /* Intentional fall through */
      case WRAPNV_STATE_DELETE_PENDING:
      {
         if (MEMIF_IDLE == WrapNv_GetStatus())
         {
            if (MEMIF_JOB_OK == WrapNv_GetJobResult())
            {
               result = WRAPNV_E_OK;
            }
            else
            {
               result = WRAPNV_E_NOT_OK;
            }

            /* Reset current state */
            gWrapNvCurrentState = WRAPNV_STATE_IDLE;
         }
         break;
      }
      case WRAPNV_STATE_CANCEL:
      {
# if defined( WRAPNV_USECASE_NVM )
         result = WrapNv_SetDataIndex();
         if (WRAPNV_E_OK == result)
         {
            result = NvM_CancelJobs(gWrapNvBlockNumber);
         }
# elif defined( WRAPNV_USECASE_FEE ) || \
       defined( WRAPNV_USECASE_EA )
         WrapNv_MemDrvCancel();
         result = WRAPNV_E_OK;
# endif /* WRAPNV_USECASE_* */

         /* Reset current state */
         gWrapNvCurrentState = WRAPNV_STATE_IDLE;
         break;
      }
      default:
      {
         result = WRAPNV_E_NOT_OK;
         break;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_PollMainFunctions
 **********************************************************************************************************************/
/*! \brief       Function to poll all sub modules
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
STATIC FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_PollMainFunctions( void )
{
   WrapNv_ReturnType result;

   result = WrapNv_MainFunction();

# if (WRAPNV_MAINFUNCTION_POLLING == STD_ON)
   WrapNv_PollMainFunctionsInternalIdle();

   if (WrapNv_TriggerFct_Callout() == WRAPNV_E_OK)
   {
      WrapNv_PollMainFunctionsInternalTimer();
   }
# endif

   return result;
}
#endif /* WRAPNV_USECASE_* */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  WrapNv_Init
 **********************************************************************************************************************/
/*! \brief       Initializes NV-Wrapper to access FEE/EA/NVM/EEPM/DrvEEP
 **********************************************************************************************************************/
FUNC(void, WRAPNV_CODE) WrapNv_Init( void )
{
#if defined( WRAPNV_USECASE_DRVEEP )
   (void)EepromDriver_InitSync(((void *)0));
#elif defined( WRAPNV_USECASE_EEPM )
   (void)EepMgrInitPowerOn(kEepMgrInitFull);
#elif defined( WRAPNV_USECASE_FEE ) || \
      defined( WRAPNV_USECASE_EA )  || \
      defined( WRAPNV_USECASE_NVM )
   WrapNv_InitConfig();
   WrapNv_InitInternal();
#endif /* WRAPNV_USECASE_* */
}

#if defined( WRAPNV_USECASE_FEE ) || \
    defined( WRAPNV_USECASE_EA )  || \
    defined( WRAPNV_USECASE_NVM )
/***********************************************************************************************************************
 *  WrapNv_ReadSync
 **********************************************************************************************************************/
/*! \brief       Reads specific data synchronously from a NV block
 *  \pre         Function must only be called from where MainFunction polling is allowed.
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \return      kFblOk if succeeded, kFblFailed otherwise
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadSync( uint16 id, uint16 idx, tWrapNvRamData buffer )
{
   WrapNv_ReturnType result;

   result = WrapNv_Read(id, idx, buffer, WRAPNV_ACCESS_DATAELEMENT);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
*  WrapNv_ReadBlockSync
**********************************************************************************************************************/
/*! \brief      Reads an entire WrapNv block synchronously from a NV block
*  \pre         Function must only be called from where MainFunction polling is allowed.
*  \param[in]   id  Id of record contained in the block
*  \param[in]   idx  Dataset of block
*  \param[in]   buffer  Pointer to data buffer
*  \return      kFblOk if succeeded, kFblFailed otherwise
**********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadBlockSync(uint16 id, uint16 idx, tWrapNvRamData buffer)
{
   WrapNv_ReturnType result;

   result = WrapNv_Read(id, idx, buffer, WRAPNV_ACCESS_BLOCKELEMENT);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_ReadPartialSync
 **********************************************************************************************************************/
/*! \brief       Reads partial data synchronously from a NV block
 *  \pre         Function must only be called from where MainFunction polling is allowed.
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \param[in]   offset Offset in the entry to read only partial
 *  \param[in]   length Length of the partial read
 *  \return      kFblOk if succeeded, kFblFailed otherwise
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialSync( uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length )
{
   WrapNv_ReturnType result;

   result = WrapNv_ReadPartial(id, idx, buffer, offset, length, WRAPNV_ACCESS_DATAELEMENT);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
*  WrapNv_ReadPartialBlockSync
**********************************************************************************************************************/
/*! \brief      Reads partial block synchronously from a NV block
*  \pre         Function must only be called from where MainFunction polling is allowed.
*  \param[in]   id  Id of record contained in the block
*  \param[in]   idx  Dataset of block
*  \param[in]   buffer  Pointer to data buffer
*  \param[in]   offset Offset in the entry to read only partial
*  \param[in]   length Length of the partial read
*  \return      kFblOk if succeeded, kFblFailed otherwise
**********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialBlockSync(uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length)
{
   WrapNv_ReturnType result;

   result = WrapNv_ReadPartial(id, idx, buffer, offset, length, WRAPNV_ACCESS_BLOCKELEMENT);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_WriteSync
 **********************************************************************************************************************/
/*! \brief       Writes specific data synchronously to a NV block
 *  \pre         Function must only be called from where MainFunction polling is allowed.
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \return      kFblOk if succeeded, kFblFailed otherwise
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteSync( uint16 id, uint16 idx, tWrapNvConstData buffer )
{
   WrapNv_ReturnType result;

   result = WrapNv_Write(id, idx, buffer, WRAPNV_ACCESS_DATAELEMENT);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
*  WrapNv_WriteBlockSync
**********************************************************************************************************************/
/*! \brief      Writes specific block synchronously to a NV block
*  \pre         Function must only be called from where MainFunction polling is allowed.
*  \param[in]   id  Id of record contained in the block
*  \param[in]   idx  Dataset of block
*  \param[in]   buffer  Pointer to data buffer
*  \return      kFblOk if succeeded, kFblFailed otherwise
**********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteBlockSync(uint16 id, uint16 idx, tWrapNvConstData buffer)
{
   WrapNv_ReturnType result;

   result = WrapNv_Write(id, idx, buffer, WRAPNV_ACCESS_BLOCKELEMENT);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_DeleteSync
 **********************************************************************************************************************/
/*! \brief       Delete specific NV block synchronously
 *  \pre         Function must only be called from where MainFunction polling is allowed.
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \return      kFblOk if succeeded, kFblFailed otherwise
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_DeleteSync( uint16 id, uint16 idx )
{
   WrapNv_ReturnType result;

   result = WrapNv_Delete(id, idx);

   while (WRAPNV_E_PENDING == result)
   {
      result = WrapNv_PollMainFunctions();
   }

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_ReadAsync
 **********************************************************************************************************************/
/*! \brief       Reads specific data asynchronously from a NV block
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[out]  buffer  Pointer to data buffer
 *  \param[in]   opStatus  Operation status of calling instance
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadAsync( uint16 id, uint16 idx, tWrapNvRamData buffer,
   tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   result = WrapNv_ReadAsyncInternal(id, idx, buffer, opStatus, WRAPNV_ACCESS_DATAELEMENT);

   return result;
}

/***********************************************************************************************************************
*  WrapNv_ReadBlockAsync
**********************************************************************************************************************/
/*! \brief       Reads specific block asynchronously from a NV block
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \param[in]   opStatus  Operation status of calling instance
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadBlockAsync(uint16 id, uint16 idx, tWrapNvRamData buffer,
   tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   result = WrapNv_ReadAsyncInternal(id, idx, buffer, opStatus, WRAPNV_ACCESS_BLOCKELEMENT);

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_ReadPartialAsync
 **********************************************************************************************************************/
/*! \brief       Reads specific data asynchronously from a NV block
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \param[in]   offset Offset in the entry to read only partial
 *  \param[in]   length Length of the partial read
 *  \param[in]   opStatus  Operation status of calling instance
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialAsync( uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length, tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   result = WrapNv_ReadPartialAsyncInternal(id, idx, buffer, offset, length, opStatus, WRAPNV_ACCESS_DATAELEMENT);

   return result;
}

/***********************************************************************************************************************
*  WrapNv_ReadPartialBlockAsync
**********************************************************************************************************************/
/*! \brief       Reads partial data in WrapNv block asynchronously from a NV block
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \param[in]   offset Offset in the entry to read only partial
 *  \param[in]   length Length of the partial read
 *  \param[in]   opStatus  Operation status of calling instance
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
/* PRQA S 6060 1 */ /* MD_MSR_STPAR */
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_ReadPartialBlockAsync(uint16 id, uint16 idx, tWrapNvRamData buffer,
   uint16 offset, uint16 length, tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   result = WrapNv_ReadPartialAsyncInternal(id, idx, buffer, offset, length, opStatus, WRAPNV_ACCESS_BLOCKELEMENT);

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_WriteAsync
 **********************************************************************************************************************/
/*! \brief       Writes specific data asynchronously to a NV block
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   buffer  Pointer to data buffer
 *  \param[in]   opStatus  Operation status of calling instance
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteAsync( uint16 id, uint16 idx, tWrapNvConstData buffer,
   tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   result = WrapNv_WriteAsyncInternal(id, idx, buffer, opStatus, WRAPNV_ACCESS_DATAELEMENT);

   return result;
}

/***********************************************************************************************************************
*  WrapNv_WriteBlockAsync
**********************************************************************************************************************/
/*! \brief      Writes specific block asynchronously to a NV block
*  \param[in]   id  Id of record
*  \param[in]   idx  Dataset of block
*  \param[in]   buffer  Pointer to data buffer
*  \param[in]   opStatus  Operation status of calling instance
*  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
*                          WRAPNV_E_PENDING if job needs more time
**********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_WriteBlockAsync(uint16 id, uint16 idx, tWrapNvConstData buffer,
   tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   result = WrapNv_WriteAsyncInternal(id, idx, buffer, opStatus, WRAPNV_ACCESS_BLOCKELEMENT);

   return result;
}

/***********************************************************************************************************************
 *  WrapNv_DeleteAsync
 **********************************************************************************************************************/
/*! \brief       Delete specific NV block asynchronously
 *  \param[in]   id  Id of record
 *  \param[in]   idx  Dataset of block
 *  \param[in]   opStatus  Operation status of calling instance
 *  \return      result     WRAPNV_E_OK on job completion, WRAPNV_E_NOT_OK if job execution failed,
 *                          WRAPNV_E_PENDING if job needs more time
 **********************************************************************************************************************/
FUNC(WrapNv_ReturnType, WRAPNV_CODE) WrapNv_DeleteAsync( uint16 id, uint16 idx, tWrapNvOpStatus opStatus)
{
   WrapNv_ReturnType result;
   tWrapNvOpStatus currentOpStatus;

   WrapNv_EnterCritical();

   /* Check if WrapNv is idle so it can accept a new request */
   if (WRAPNV_OPERATION_IDLE == gWrapNvCurrentOperation)
   {
      /* Check if new job is canceled */
      if (opStatus == WRAPNV_OPSTATUS_CANCEL)
      {
         currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
      }
      else
      {
         /* Parameters will be stored in WrapNv_Delete() call */
         currentOpStatus = WRAPNV_OPSTATUS_INIT;
         gWrapNvCurrentOperation = WRAPNV_OPERATION_DELETE;
      }
   }
   else
   {
      /* Check if this is a different request to the current pending request */
      if (   (id == gWrapNvRecordNumber)
          && (idx == gWrapNvBlockDataset)
          && (WRAPNV_OPERATION_DELETE == gWrapNvCurrentOperation)
         )
      {
         /* Check if the current job should be canceled */
         if (opStatus == WRAPNV_OPSTATUS_CANCEL)
         {
            currentOpStatus = WRAPNV_OPSTATUS_CANCEL;
         }
         else
         {
            /* Process current request */
            currentOpStatus = WRAPNV_OPSTATUS_PENDING;
         }
      }
      else
      {
         /* Wait until other request has been finished */
         currentOpStatus = WRAPNV_OPSTATUS_IDLE;
      }
   }

   WrapNv_LeaveCritical();

   /* Only init and pending states are allowed at this point */
   switch (currentOpStatus)
   {
      case WRAPNV_OPSTATUS_INIT:
      {
         result = WrapNv_Delete(id, idx);
         break;
      }
      case WRAPNV_OPSTATUS_PENDING:
      {
         result = WrapNv_MainFunction();
         break;
      }
      case WRAPNV_OPSTATUS_IDLE: /* Used when two instances access the WrapNv */
      {
         result = WRAPNV_E_PENDING;
         break;
      }
      case WRAPNV_OPSTATUS_CANCEL:
      {
         result = WrapNv_Cancel();
         break;
      }
      default:
      { /* PRQA S 2880 1 */ /* MD_MSR_Unreachable */
         result = WRAPNV_E_NOT_OK;
         break;
      }
   }

   /* Check if current operation has finished */
   if (   (WRAPNV_E_OK == result)
       || (WRAPNV_E_NOT_OK == result))
   {
      gWrapNvCurrentOperation = WRAPNV_OPERATION_IDLE;
   }

   return result;
}
#endif /* WRAPNV_USECASE_* */

#define WRAPNV_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_WrapNv_0311:
      Reason:     Provide simplified function interface and reduce stack consumption by avoiding separate pointers for
                  read and write buffer.
      Risk:       The content of the write buffer might be accidentally overwritten.
      Prevention: Covered by code review.

   MD_WrapNv_0314:
      Reason:     API is defined with pointer to void parameter, so pointer has to be casted to or from void.
      Risk:       Wrong data access or undefiend behavior for platforms where the byte alignment is not arbitrary.
      Prevention: Code inspection and test with the target compiler/platform in the component test.

   MD_WrapNv_2003:
      Reason:     Intentionally switch case with out break statement to proceed the next step immediately
      Risk:       No identifiable risk.
      Prevention: Covered by code review.

   MD_WrapNv_3218:
      Reason:     The usage of variables depend on configuration aspects and may be used only once.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV.C
 **********************************************************************************************************************/
