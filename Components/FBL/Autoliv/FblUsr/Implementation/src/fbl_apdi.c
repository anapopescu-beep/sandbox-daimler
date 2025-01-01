/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent diagnostic routines
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2017-07-28  viscb                    Initial implementation based on FblKbApi_FrameDiag_DC
 *  02.00.00   2021-01-19  viscb   FBL-2244         - Minor improvements
 *                                                  - Migration to MISRA 2012
 *  02.00.01   2021-02-02  viscb   ESCAN00108449    QM release
 *  02.00.02   2021-05-04  viscb   ESCAN00109251    ApplFblPrepVehicleSystForReprog() expects ony byte too much
 *  02.00.03   2021-12-21  vishor  ESCAN00109451    Routine Control - Prepare Vehicle Systems For Reprogramming (0x0206)
 *                                                   expects a 8 bit routine control parameter only
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (kbFbl_apAPI.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2018-09-14  visrie  ESCAN00100739    Added support for FblLib_NvPattern
 *                                                  Removed unused code
 *                         viscb   ESCAN00101418    Callout function for memory condition check
 *                         visach  ESCAN00101686    Added interface definition for vendor verification routine
 *  02.01.00   2019-02-26  visrie  ESCAN00102257    Added additional callout functions
 *  02.01.01   2019-09-23  visrie  FBL-452          Added support for FrArTp
 *  02.02.00   2019-12-05  visrie  FBL-458          Added FblMio callout functions
 *  02.03.00   2020-05-07  visrie  FBL-1414         Added callout functions for One-Step-Updater
 *  02.03.01   2020-06-02  visjdn  ESCAN00106533    Update to latest MISRA version
 *  02.03.02   2020-09-14  visrcn  FBL-2257         Add MISRA justifications
 *  02.03.03   2020-11-23  visrcn  FBL-2564         Add MISRA justifications
 *  02.03.04   2021-03-19  visjdn  FBL-2916         Add MISRA justifications
 *  02.04.00   2021-05-26  vishor  FBL-3165         MISRA corrections and justifications
 *  02.05.00   2021-06-15  visrie  FBL-3591         Provide default implementation for ApplFbl_DetEntryHandler
 *                                                  Add MISRA justifications
 *  02.06.00   2021-07-15  visjdn  FBL-3381         Re-mapping of EcuM_SetWakeupEvent
 *  02.07.00   2021-07-22  visrie  FBL-3822         Update to QAC9 Helix-2021
 *  02.08.00   2021-09-14  visjdn  FBL-2859         Add MISRA justifications
 *  02.09.00   2021-10-12  vistmo  FBL-3901         Add authentication callbacks
 *  02.10.00   2021-10-15  visrie  FBL-3945         Remove content of ApplFblStartApplication
 *  02.10.01   2021-11-12  vishor  ESCAN00110133    Compiler error: Unknown symbols
 *                                                   ApplFblSave/RestoreStatusSector/Dynamic
 *  02.10.02   2022-06-27  visrie  FBL-4694         Add MISRA justifications
 *  02.10.03   2022-10-20  visjns  FBL-5452         Add MISRA justifications
 *  02.11.00   2022-12-22  vistbe  FBL-5691         Add support for LZSS compression
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2019-03-12  visrie  ESCAN00102454    Added support for LibNvPattern, LibLbtAccess and SecureBoot
 *  02.00.01   2019-04-29  viscb   ESCAN00102998    Clear internal state flag for resume after erase
 *  03.00.00   2020-10-06  viscb   FBL-2177         DRECU2020-01 adaptions, data processing
 *  03.01.00   2021-01-19  viscb   FBL-2244         DRECU2020-01 adaptions
 *                                                    - Simplified updater integration
 *                                                    - Added support for OTA
 *                                                    - Added support for downgrade protection
 *                                                    - Migration to MISRA 2012
 *  03.01.01   2021-02-02  viscb   ESCAN00108447    QM release
 *  03.02.00   2021-04-21  viscb   ESCAN00108550    ReadDataByIdentifier returns incorrect data for requested meta data
 *                                 ESCAN00108549    Fingerprint status is not updated correctly
 *                                 ESCAN00108532    Signature verification of downloaded block fails
 *                                 ESCAN00108591    Application is not started after OFR swap
 *  03.03.00   2021-07-12  vishor  FBL-3567         Add support for Csm-based suspend/resume
 *  03.03.01   2021-08-24  vishor  ESCAN00109880    Resume information from OFR download is not invalidated in
 *                                                  case FBL download is started
 *  03.03.02   2021-08-27  vishor  ESCAN00109972    Compiler error: Incompatible type for
 *                                                  ApplFblNvWriteSegmentCount/ApplFblNvReadSegmentCount
 *  03.03.03   2021-10-19  vistmo  ESCAN00110504    Compiler error: 'SecM_CancelAllJobs' undefined
 *  03.03.04   2021-11-19  visjdn  ESCAN00108780    [XCP] Bootloader does not process XCP messages
 *  03.04.00   2022-03-16  vishor  FBL-4621         MB MMA Rework
 *                                 ESCAN00107629    Compressed and encrypted download stops with NRC 0x72 in service
 *                                                   Request Transfer Exit
 *                                 ESCAN00110835    Compiler error: kEepApplInconsistent not defined
 *                                 ESCAN00110881    Compiler error: identifier "consumedLen" and "producedLen"
 *                                                   are undefined
 *  03.05.00   2022-06-01  vishor  FBL-5094         MB MMA Rework
 *                                 ESCAN00112002    DID 0xEF02 - Standard Bootloader Software Information implemented
 *                                                   with wrong number of bytes
 *  03.05.01   2022-06-23  vishor  ESCAN00112105    AES IV is not extracted from downloaded data
 *                                 ESCAN00112155    Decryption is not correctly finalized during download
 *  03.05.02   2022-08-29  visjns  ESCAN00112404    Missing implementation of DID 0xEF05: Minimum Software Version
 *                                 ESCAN00112298    Programming attempts check fails with OTA update
 *  03.05.03   2022-12-12  vismix  ESCAN00112835    Access to programming attempt counter fails
 **********************************************************************************************************************/


#define FBL_APDI_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "vstdlib.h"
#include "Csm.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLKBAPI_FRAMEDIAG_DAIMLER_VERSION != 0x0200u ) || \
    ( FBLKBAPI_FRAMEDIAG_DAIMLER_RELEASE_VERSION != 0x03u )
# error "Error in FBL_APDI.C: Source and header file are inconsistent!"
#endif


/***********************************************************************************************************************
 *   DEFINES AND DEFINITIONS
 **********************************************************************************************************************/

#define kDiagDataIdMiniumSoftwareVersion                 0xEF05u
#define kDiagDataIdFlashingDIDUnkown                     0xF199u
#define kDiagDataIdReprogrammingCapabilities             0xF130u


/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

static void ApplCopyVectorToAddress(uint8 * destination, uint8 * source, uint8 size);

/***********************************************************************************************************************
 *  ApplFblCheckConditions
 **********************************************************************************************************************/
/*! \brief         Check conditions for diagnostic services
 *  \details       This function is called for each diagnostic service.
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        kFblOk or kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblCheckConditions(vuint8 *pbDiagData, tTpDataType diagReqDataLen)
{
   if ((diagServiceCurrent == kDiagSidSecurityAccess) && (pbDiagData[kDiagLocFmtSubfunction] == kDiagSubRequestSeed))
   {
      /* Cancel active jobs upon SecurityAccess - requestSeed to prevent jobs in crypto stack from being locked */
      SecM_CancelAllJobs();
   }
   return kFblOk;
}

#if defined( FBL_ENABLE_USERSERVICE )
/***********************************************************************************************************************
 *  ApplDiagUserService
 **********************************************************************************************************************/
/*! \brief         Call-back function for user diagnostic services. pbDiagData points to subfunction.
 *  \details       This function is called when a diagnostic service has been received that is not managed by the FBL
 *                 itself -> can be managed by user.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
void ApplDiagUserService( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   if (DiagGetRequestSId() == kDiagSidReadDataByIdentifier)
   {
      ApplFblReadDataByIdentifier(pbDiagData, diagReqDataLen);
   }
   else
   {
      DiagNRCServiceNotSupported();
   }
}
#endif /* FBL_ENABLE_USERSERVICE */

#if defined( FBL_ENABLE_USERSUBFUNCTION )
/***********************************************************************************************************************
 *  ApplDiagUserSubFunction
 **********************************************************************************************************************/
/*! \brief         Call-back function for user diagnostic services. pbDiagData points to subfunction.
 *  \details       This function is called when the bootloader manages the diagnostic service, but the sub-parameter
 *                 is unknown -> subparameter of the service can be managed by user.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!!)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
void ApplDiagUserSubFunction( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* If you want to support different sub functions, comment out this code */
#if 0
   switch (DiagGetRequestSId())
   {
      default:
         DiagNRCSubFunctionNotSupported();
         DiagProcessingDone(0);
   }
#else
   DiagNRCSubFunctionNotSupported();
   DiagProcessingDone(0);
#endif
}
#endif /* FBL_ENABLE_USERSUBFUNCTION */

/***********************************************************************************************************************
 *  ApplFblReadDataByIdentifier
 **********************************************************************************************************************/
/*! \brief         ReadDataByIdentifier service function.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 **********************************************************************************************************************/
/* PRQA S 2889, 6010, 6030, 6050, 6080 1 */ /* MD_FblKbApi_2889, MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
void ApplFblReadDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   vuint8 diagRespDataLen = 0u;
   vuint16 diagFmtDataId;
   tFblLbtBlockNr blockIdx;
   vuint32 nvModuleId;
   vuint8 status;
   vuint8 idx;
   tFblLbtBlockCount blockCount;
   tFblLbtBlockFilter blockFilter;
   tBlockDescriptor iterBlock;
   uint8 appFpStatus;
   uint8 HSM_Version_au8[3];
   uint8 HSM_Version_length=3;

   /* Check diagnostic request length */
   if (diagReqDataLen != kDiagRqlReadDataByIdentifier)
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }

   /* Preset status variable */
   status = kFblOk;

   diagFmtDataId =  (vuint16)(pbDiagData[0u]) << 8u;
   diagFmtDataId |= (vuint16)(pbDiagData[1u]);

   blockCount = FblLbtGetBlockCount();

   switch (diagFmtDataId)
   {
      /* -- programmingAttemptCounter -- */
      case kDiagDataIdProgrammingAttemptCounter:
      {
         vuint16 progAttempts;
         vuint16 maxProgAttempts;

         /* Send response pending */
         DiagExRCRResponsePending(kForceSendResponsePending);

         FblLbtBlockFilterInit(&blockFilter);
         iterBlock = FblLbtBlockFirst(&blockFilter);
         while (FblLbtBlockDone() == FALSE)
         {
            blockIdx = iterBlock.blockNr;

            maxProgAttempts = iterBlock.maxProgAttempts;
            (void)ApplFblGetProgAttempts(iterBlock, &progAttempts);  

            pbDiagData[2u + (4u * blockIdx)] = (vuint8)(progAttempts >> 8u);
            pbDiagData[3u + (4u * blockIdx)] = (vuint8)(progAttempts);
            pbDiagData[4u + (4u * blockIdx)] = (vuint8)(maxProgAttempts >> 8u);
            pbDiagData[5u + (4u * blockIdx)] = (vuint8)(maxProgAttempts);

            /* Prepare next cycle */
            iterBlock = FblLbtBlockNext();
         }
         /*Get HSM progAttempts*/
         iterBlock.blockNr = 2u; /*Set blockNr to 2, to mock logical block nr 3*/
         (void)ApplFblGetProgAttempts(iterBlock, &progAttempts);  
         pbDiagData[10u] = (vuint8)(progAttempts >> 8u);
         pbDiagData[11u] = (vuint8)(progAttempts);
         pbDiagData[12u] = 0u;
         pbDiagData[13u] = 0u;

         diagRespDataLen = kDiagRslReadDataByIdentifier + (4u * 3);
         break;
      }

#if defined( FBL_ENABLE_DEBUG_STATUS )
      /* -- reprogrammingErrorStatus -- */
      case kDiagDataIdReprogrammingErrorStatus:
      {
         /* FBL version information */
         pbDiagData[2u] = (vuint8)(FBL_VERSION >> 8u);
         pbDiagData[3u] = (vuint8)FBL_VERSION;
         pbDiagData[4u] = (vuint8)FBL_BUGFIX_VERSION;

         /* Error status */
         pbDiagData[5u] = (vuint8)(errStatErrorCode >> 8u);
         pbDiagData[6u] = (vuint8)errStatErrorCode;

         /* FBL state */
         pbDiagData[7u] = (vuint8)(errStatFblStates >> 8u);
         pbDiagData[8u] = (vuint8)errStatFblStates;

         /* Last received service identifier */
         pbDiagData[9u] = errStatLastServiceId;

         /* Logical block information */
         pbDiagData[10u] = errStatDescriptor.blockNr;

         /* Address information */
         pbDiagData[11u] = (vuint8)(errStatDescriptor.blockStartAddress >> 24u);
         pbDiagData[12u] = (vuint8)(errStatDescriptor.blockStartAddress >> 16u);
         pbDiagData[13u] = (vuint8)(errStatDescriptor.blockStartAddress >> 8u);
         pbDiagData[14u] = (vuint8)(errStatDescriptor.blockStartAddress);

         /* Software interlock version information */
         pbDiagData[15u] = errStatFlashDrvVersion[0u];
         pbDiagData[16u] = errStatFlashDrvVersion[1u];
         pbDiagData[17u] = errStatFlashDrvVersion[2u];

         /* Software interlock error status */
         pbDiagData[18u] = (vuint8)(errStatFlashDrvErrorCode >> 8u);
         pbDiagData[19u] = (vuint8)errStatFlashDrvErrorCode;
         diagRespDataLen = kDiagRslReadDataByIdentifier + 18u;
      }
      break;
#endif /* FBL_ENABLE_DEBUG_STATUS */

      /* -- reprogrammingResumeInformation -- */
      case kDiagDataIdReprogrammingResumeInfo:
      {
#if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
         tFblAddress    responseAddress, resumeAddress;
         tFblLbtBlockNr resumeBlockNo;
         vuint8         validityFlags[kEepSizeValidityFlags];

         /* Check if resume information is available for any logical block */
         status = FblDiagGetResumeBlockNo( &resumeBlockNo, &resumeAddress );
         if (status == kFblOk)
         {
            tFblAddress validAddress;

            /* Get last valid address */
            status = FblDiagGetSnapshotInfo( &validAddress );

            if (status == kFblOk)
            {
               tBlockDescriptor blockDescriptor;

               /* Check if address corresponds to end address of logical block */
               status = FblLbtGetBlockDescriptorByNr(resumeBlockNo, &blockDescriptor);
               if (status == kFblOk)
               {
                  /* Adjust logical block in case of PresencePattern or SecureBoot */
                  (void)ApplFblAdjustLbtBlockData(&blockDescriptor);
                  if (validAddress == (blockDescriptor.blockStartAddress + (blockDescriptor.blockLength - 1u)))
                  {
                     resumeAddress = validAddress;
                  }
                  FblDiagSetResumeInfRequested();
               }
            }
            else
            {
               /*
                * If snapshot/address is not available, resumeBlockNo is -1 and the addresses in the response
                * are set to the start address of the corresponding logical block.
                */
            }
         }

# if defined( FBL_ENABLE_PRESENCE_PATTERN )
         for (idx = 0u; idx < sizeof(validityFlags); idx++)
         {
            validityFlags[idx] = 0xFFu;
         }
         FblLbtBlockFilterInit(&blockFilter);
         iterBlock = FblLbtBlockFirst(&blockFilter);
         while (FblLbtBlockDone() == FALSE)
         {
            if (ApplFblChkModulePresence(&iterBlock) == kFblOk)
            {
               /* If present, clear the validity flag (inverse logic!!) */
               validityFlags[(iterBlock.blockNr >> 3u)] &= FblInvert8Bit(1u << (iterBlock.blockNr & 7u));
            }

            /* Prepare next cycle */
            iterBlock = FblLbtBlockNext();
         }

         status = kFblOk;
# else
         /* Read validity status of logical blocks */
         status = ApplFblNvReadValidityFlags(validityFlags);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

         if (status == kFblOk) /* PRQA S 2991, 2995 */ /* MD_FblKbApiOem_2991_2995 */
         {
            /* Prepare response: Set AddressAndLengthFormat identifier */
            pbDiagData[2u] = kDiagFmtAddrValue;

            /* Provide restart address information for each logical block */
            FblLbtBlockFilterInit(&blockFilter);
            iterBlock = FblLbtBlockFirst(&blockFilter);
            while (FblLbtBlockDone() == FALSE)
            {
               blockIdx = iterBlock.blockNr;
               /* Index for validity flags array: blockNo / 8 */
               idx = (vuint8)(blockIdx >> 3u);

               /* If logical block is valid, return end address of logical block */
               if ((validityFlags[idx] & (vuint8)(1u << (blockIdx & 0x07u))) == 0u)
               {
                  /* Return end address of logical block */
                  responseAddress = iterBlock.blockStartAddress + (iterBlock.blockLength - 1u);
               }
               else
               {
                  /* If logical block is not valid, check resume information */
                  if ( blockIdx == resumeBlockNo )
                  {
                     /* Return last valid address */
                     responseAddress = resumeAddress;
                  }
                  else
                  {
                     /* Block is not valid and resume information is not available
                      * Return start address of logical block
                      */
                     responseAddress = iterBlock.blockStartAddress;
                  }
               }

               /* Serialize address into diagnostic response */
               FblMemSetInteger(sizeof(tFblAddress), (vuint32)responseAddress, &pbDiagData[2u + 1u + (blockIdx * kDiagFmtFixedAddrSize) ]);

               /* Prepare next cycle */
               iterBlock = FblLbtBlockNext();
            }
            diagRespDataLen = kDiagRslReadDataByIdentifier + 1u + (blockCount * kDiagFmtFixedAddrSize);
         }
         /* If ApplFblNvReadValidityFlags() returns an error status, an NRC is transmitted (see end of function) */
#else
         /* If resuming of an interrupted download sequence is not supported,
          * the DID 0x0120 is not supported. Send NRC 31h - requestOutOfRange.
          */
         DiagNRCRequestOutOfRange();
#endif

         break;
      }

      /* -- activeDiagnosticInformation -- */
      case kDiagDataIdActiveDiagnosticInformation:
      {
         pbDiagData[2u] = fblCommonData.ActiveDiagnosticInformation[0];   /* Active diagnostic status: 0=Application, 1=Boot */
         pbDiagData[3u] = fblCommonData.ActiveDiagnosticInformation[1];   /* Active diagnostic variant */
         pbDiagData[4u] = fblCommonData.ActiveDiagnosticInformation[2];   /* Active diagnostic version */

         /* Active diagnostic session */
         if (GetDiagProgrammingSession())
         {
            pbDiagData[5u] = kDiagSubProgrammingSession;
         }
         else if (GetDiagExtendedSession())
         {
            pbDiagData[5u] = kDiagSubExtendedDiagSession;
         }
         else
         {
            pbDiagData[5u] = kDiagSubDefaultSession;
         }
         diagRespDataLen = kDiagRslReadDataByIdentifier + 4u;

         break;
      }

      /* -- ECUName -- */
      case kDiagDataIdEcuName:
      {
         idx = 0u;
         while(fblCommonData.EcuName[idx] != (vuint8)('\0'))
         {
            pbDiagData[kDiagRslReadDataByIdentifier+idx] = fblCommonData.EcuName[idx];
            idx++;
         }
         diagRespDataLen = kDiagRslReadDataByIdentifier + idx;

         break;
      }

      /* -- mercedHardwarePartNumber -- */
      case kDiagDataIdMercedHardwarePartNumber:
      {
         ApplCopyVectorToAddress(&pbDiagData[2u], &fblCommonData.EcuHardwarePartNumber[0], 10u);
         
         diagRespDataLen = kDiagRslReadDataByIdentifier + 10u;

         break;
      }

      /* -- mercedSoftwarePartNumber -- */
      case kDiagDataIdMercedSoftwarePartNumber:
      {
         ApplCopyVectorToAddress(&pbDiagData[2u], &fblCommonData.EcuBootSoftwarePartNumber[0], 10u);

         /* Read app fingerprint status from NVM */
         blockIdx = 1u;
         nvModuleId = ApplFblGetNvModuleId(blockIdx);
         status |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &appFpStatus);

         if (kDiagFpStatEraseStarted == appFpStatus)
         {
            /*In case app not valid, put ASCII 'F' everywhere*/
            VStdLib_MemSet(&pbDiagData[12u], 0x46, 10u);

         }
         else
         {
            ApplCopyVectorToAddress(&pbDiagData[12u], &fblCommonData.EcuAppSoftwarePartNumber[0u], 10u);
         }

         ApplCopyVectorToAddress(&pbDiagData[22u], &HSMPartNo, 10u);

         diagRespDataLen = kDiagRslReadDataByIdentifier + 30u;

         break;
      }

      /* -- hardwareVersionInformation -- */
      case kDiagDataIdHardwareVersionInformation:
      {
         ApplFblNvReadNVP_BLOCK_ID_HW_VERSION(&pbDiagData[2u]);
         diagRespDataLen = kDiagRslReadDataByIdentifier + 3u;

         break;
      }

      /* -- softwareVersionInformation -- */
      case kDiagDataIdSoftwareVersionInformation:
      {
         pbDiagData[2u] = fblCommonData.EcuBootSoftwareVersion[0u];  /* Boot SW - year        */
         pbDiagData[3u] = fblCommonData.EcuBootSoftwareVersion[1u];  /* Boot SW - week        */
         pbDiagData[4u] = fblCommonData.EcuBootSoftwareVersion[2u];  /* Boot SW - patch level */  

         /* Read app fingerprint status from NVM */
         blockIdx = 1u;
         nvModuleId = ApplFblGetNvModuleId(blockIdx);
         status |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &appFpStatus);

         if (kDiagFpStatEraseStarted == appFpStatus)
         {
            pbDiagData[5u] = 0xFF; /* Year */
            pbDiagData[6u] = 0xFF; /* Week */
            pbDiagData[7u] = 0xFF; /* Patch level */
         }
         else
         {
            pbDiagData[5u] = fblCommonData.EcuAppSoftwareVersion[0u]; /* Year */
            pbDiagData[6u] = fblCommonData.EcuAppSoftwareVersion[1u]; /* Week */
            pbDiagData[7u] = fblCommonData.EcuAppSoftwareVersion[2u]; /* Patch level */
         }

         Csm_KeyElementGet(CsmConf_CsmKey_CsmKey_vHSM_Custom_HSM_Version, 1u, HSM_Version_au8, &HSM_Version_length);


         pbDiagData[8u] = HSM_Version_au8[0] ; /* Year */
         pbDiagData[9u] =  HSM_Version_au8[1]; /* Week */
         pbDiagData[10u] = HSM_Version_au8[2]; /* Patch level */


         diagRespDataLen = kDiagRslReadDataByIdentifier + 9u;

         // /* Send response pending */
         // DiagExRCRResponsePending(kForceSendResponsePending);

         // for (blockIdx = 0u; blockIdx < blockCount; blockIdx++)
         // {
         //    nvModuleId = ApplFblGetNvModuleId(blockIdx);
         //    status |= ApplFblNvReadSwVersion((WRAPNV_PositionType)nvModuleId, &pbDiagData[2u + (blockIdx * kEepSizeSwVersion)]);
         // }
         // diagRespDataLen = kDiagRslReadDataByIdentifier + (blockIdx * kEepSizeSwVersion);

         break;
      }

      /* -- bootSoftwareVersionInformation -- */
      case kDiagDataIdBootSoftwareVersionInformation:
      {
         pbDiagData[2u] = fblCommonData.EcuBootSoftwareVersion[0u];  /* Boot SW - year        */
         pbDiagData[3u] = fblCommonData.EcuBootSoftwareVersion[1u];  /* Boot SW - week        */
         pbDiagData[4u] = fblCommonData.EcuBootSoftwareVersion[2u];  /* Boot SW - patch level */
         diagRespDataLen = kDiagRslReadDataByIdentifier + 3u;

         break;
      }

      /* -- hardwareSupplierInformation -- */
      case kDiagDataIdHardwareSupplierInformation:
      {
         pbDiagData[2u] = fblCommonData.EcuHardwareSupplierInformation[0u];  /* Hardware Supplier Identification High Byte */
         pbDiagData[3u] = fblCommonData.EcuHardwareSupplierInformation[1u];  /* Hardware Supplier Identification Low Byte  */
         diagRespDataLen = kDiagRslReadDataByIdentifier + 2u;

         break;
      }

      /* -- softwareSupplierInformation -- */
      case kDiagDataIdSoftwareSupplierInformation:
      {
        pbDiagData[2u] = fblCommonData.EcuBootSoftwareSupplierInformation[0];
        pbDiagData[3u] = fblCommonData.EcuBootSoftwareSupplierInformation[1];

        pbDiagData[4u] = fblCommonData.EcuAppSoftwareSupplierInformation[0];
        pbDiagData[5u] = fblCommonData.EcuAppSoftwareSupplierInformation[1];

        pbDiagData[6u] = fblCommonData.EcuBootSoftwareSupplierInformation[0];
        pbDiagData[7u] = fblCommonData.EcuBootSoftwareSupplierInformation[1];

        diagRespDataLen = kDiagRslReadDataByIdentifier + 6u;

         // /* Send response pending */
         // DiagExRCRResponsePending(kForceSendResponsePending);

         // for (blockIdx = 0u; blockIdx < blockCount; blockIdx++)
         // {
         //    nvModuleId = ApplFblGetNvModuleId(blockIdx);
         //    status |= ApplFblNvReadSwSupplierInformation((WRAPNV_PositionType)nvModuleId,
         //       &pbDiagData[kDiagRslReadDataByIdentifier + (blockIdx * kEepSizeSwSupplierInformation)]);
         // }
         // diagRespDataLen = kDiagRslReadDataByIdentifier + (blockIdx * kEepSizeSwSupplierInformation);

         break;
      }

      /* -- readSoftwareFingerprint -- */
      case kDiagDataIdReadSoftwareFingerprint:
      {
         vuint8 fpStatus;                                   /* Fingerprint status   */
# if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
         tFblAddress    resumeAddress;
         tFblLbtBlockNr resumeBlockNo;

         /* Get information about resume status */
         (void)FblDiagGetResumeBlockNo(&resumeBlockNo, &resumeAddress);
# endif

         /* Send response pending */
         DiagExRCRResponsePending(kForceSendResponsePending);

         for (blockIdx = 0u; blockIdx < blockCount; blockIdx++)
         {
            nvModuleId = ApplFblGetNvModuleId(blockIdx);
            /* Read fingerprint status from NVM */
            status |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &fpStatus);

            /* Check if fingerprint is valid */
            /* TODO_CUSTOMER: Check if EEP erased status is 0xFF/0x00 */
            if (fpStatus == 0xFFu)
            {
               /* If fingerprint has not been written before, logical block   *
                * status is programmed, compat. mismatch and block invalid.   *
                * TODO_CUSTOMER: Define initial EEPROM value, determine if flash is    *
                *       erased in this case and set memory status accordingly.*/
               fpStatus = (kDiagFpStatSwSwMismatch | kDiagFpStatSwHwMismatch);
            }
# if defined( FBL_MEM_ENABLE_RESUMABLE_PROGRAMMING )
            else
            {
               /* Check if the reprpgramming process state of current block indicates that the block
                * has been erased, is currently programmed or mem check has been performed,
                * but no resume information is avalable. In this case, the fingerprint status
                * is cleared so that the tester has to perform a full reprogramming of this block.
                */
               if ( (  ((fpStatus & 0xF0u) == kDiagFpStatReprogStarted)
                    || ((fpStatus & 0xF0u) == kDiagFpStatEraseFinished)
                    || ((fpStatus & 0xF0u) == kDiagFpStatMemCheckSucceeded) )
                   && (resumeBlockNo != blockIdx))
               {
                  /* No resume information available for this block; clear reprog. process state */
                  fpStatus = fpStatus & 0x0Fu;
               }
            }
# endif

            /* Read fingerprint from NVM */
            status |= ApplFblNvReadFingerprint((WRAPNV_PositionType)nvModuleId,
               &pbDiagData[(kDiagRslReadDataByIdentifier
               + (blockIdx * (kEepSizeFpStatusInfo + kEepSizeFingerprint))) + kEepSizeFpStatusInfo]);

            pbDiagData[kDiagRslReadDataByIdentifier
               + (blockIdx * (kEepSizeFpStatusInfo + kEepSizeFingerprint))] = fpStatus;
         }

         /*Read HSM fingerprint*/
         status |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)2u, &fpStatus);
         /* Read fingerprint from NVM */
         status |= ApplFblNvReadFingerprint((WRAPNV_PositionType)2u,
                                            &pbDiagData[(kDiagRslReadDataByIdentifier + (2u * (kEepSizeFpStatusInfo + kEepSizeFingerprint))) + kEepSizeFpStatusInfo]);
         pbDiagData[kDiagRslReadDataByIdentifier + (2u * (kEepSizeFpStatusInfo + kEepSizeFingerprint))] = fpStatus;

         diagRespDataLen = kDiagRslReadDataByIdentifier + (3u * (kEepSizeFpStatusInfo + kEepSizeFingerprint));

         break;
      }

      /* -- Standard Bootloader Software Package Information -- */
      case kDiagDataIdStandardBootloaderSoftwareInformation:
      {
         /* FBL SW package version */
         ApplCopyVectorToAddress(&pbDiagData[2u], &fblCommonData.StandardBootloaderSoftwareInformation.Version[0u], 3u);

         /* FBL build version */
         pbDiagData[5] = fblCommonData.StandardBootloaderSoftwareInformation.Build;

         /* uC Identification */
         ApplCopyVectorToAddress(&pbDiagData[6u], &fblCommonData.StandardBootloaderSoftwareInformation.uCIdentification[0u], 10u);

         /* Supplier Identification */
         pbDiagData[16] = fblCommonData.EcuBootSoftwareSupplierInformation[0];
         pbDiagData[17] = fblCommonData.EcuBootSoftwareSupplierInformation[1];

         diagRespDataLen = kDiagRslReadDataByIdentifier + 16u;

         break;
      }

      /* -- Diagnostic Specification Information -- */
      case kDiagDataIdDiagnosticSpecificationInformation:
      {
         /* DDS package release of application software */

          /* Read app fingerprint status from NVM */
         blockIdx = 1u;
         nvModuleId = ApplFblGetNvModuleId(blockIdx);
         status |= ApplFblNvReadFpStatusInfo((WRAPNV_PositionType)nvModuleId, &appFpStatus);

         if (kDiagFpStatEraseStarted == appFpStatus)
         {
            /* Application is valid, read specification version of logical block 0 */
            // ddsPackageField = (ApplFblGetModuleHeaderAddress(0u) + kApplInfoOffsetDDSPackageRelField );
            // (void)FblReadProm(ddsPackageField, &pbDiagData[2u], kApplSizeDDSPackageReleaseAppl);

            /*Application is invalid*/
            pbDiagData[2u]  = 0u;           /* DDS package release year   */
            pbDiagData[3u]  = 0u;           /* DDS package release month  */
         }
         else
         {
            pbDiagData[2u]  = fblCommonData.DDSPackageReleaseInformation.ApplicationSoftware[0];           /* DDS package release year   */
            pbDiagData[3u]  = fblCommonData.DDSPackageReleaseInformation.ApplicationSoftware[1];           /* DDS package release month  */
         }

         /* DDS package release of boot software */
         pbDiagData[4u]  = fblCommonData.DDSPackageReleaseInformation.BootSoftware[0];             /* DDS 2020-01 - year          */
         pbDiagData[5u]  = fblCommonData.DDSPackageReleaseInformation.BootSoftware[1];             /* DDS 2020-01 - month         */
         diagRespDataLen = kDiagRslReadDataByIdentifier + 4u;

         break;
      }

#if (FBLCW_CHANGE_PARAMETER == STD_ON)
      /* -- ISO 15765-2 FlowControl Parameter -- */
      case kDiagDataIdIsoTpBlockSizeSTminParameter:
      {
         vuint16 value;
         /* TODO_CUSTOMER */
         (void)FblCw_ReadParameter(TP_BS, &value);
         pbDiagData[2u]  = (vuint8)(value & 0xFFu);       /* Block Size */

         (void)FblCw_ReadParameter(TP_STMIN, &value);
         pbDiagData[3u]  = (vuint8)(value & 0xFFu);       /* STmin      */

         diagRespDataLen = kDiagRslReadDataByIdentifier + 2u;

         break;
      }
#endif
      case kDiagDataIdMiniumSoftwareVersion:
      {
         pbDiagData[2] = fblCommonData.MinimumSoftwareVersion[0];
         pbDiagData[3] = fblCommonData.MinimumSoftwareVersion[1];
         pbDiagData[4] = fblCommonData.MinimumSoftwareVersion[2];
         pbDiagData[5] = fblCommonData.MinimumSoftwareVersion[0];
         pbDiagData[6] = fblCommonData.MinimumSoftwareVersion[1];
         pbDiagData[7] = fblCommonData.MinimumSoftwareVersion[2];
         pbDiagData[8] = fblCommonData.MinimumSoftwareVersion[0];
         pbDiagData[9] = fblCommonData.MinimumSoftwareVersion[1];
         pbDiagData[10] = fblCommonData.MinimumSoftwareVersion[2];
         diagRespDataLen = kDiagRslReadDataByIdentifier + 9u;
         break;
      }

      case kDiagDataIdFlashingDIDUnkown:
      {
         diagRespDataLen = kDiagRslReadDataByIdentifier + 2u;
         pbDiagData[2u] = 0xA1;
         pbDiagData[3u] = 0xB2;
         break;
      }
      case kDiagDataIdReprogrammingCapabilities:
      {
         /*Security Class*/
         pbDiagData[2] = 0x03; /* CCCV2 */         
         
            /* Delta update support */
         pbDiagData[3u] = 0x00; /* Update not supported */

         /* Delta Algorithm */
         pbDiagData[4u] = 0X4E;  /* N */
         pbDiagData[5u] = 0x6F;  /* o */
         pbDiagData[6u] = 0x20;  /*   */
         pbDiagData[7u] = 0x44;  /* D */
         pbDiagData[8u] = 0x65;  /* e */
         pbDiagData[9u] = 0x6C;  /* l */
         pbDiagData[10u] = 0x74;  /* t */
         pbDiagData[11u] = 0x61;  /* a */
         pbDiagData[12u] = 0x20;  /*   */
         pbDiagData[13u] = 0x41;  /* A */
         pbDiagData[14u] = 0x6C; /* l */
         pbDiagData[15u] = 0x67; /* g */
         pbDiagData[16u] = 0x6F; /* o */
         pbDiagData[17u] = 0x72; /* r */
         pbDiagData[18u] = 0x69; /* i */
         pbDiagData[19u] = 0x74; /* t */
         pbDiagData[20u] = 0x68; /* h */
         pbDiagData[21u] = 0x6D; /* m */
         pbDiagData[22u] = 0x20; /*   */
         pbDiagData[23u] = 0x49; /* I */
         pbDiagData[24u] = 0x6D; /* m */
         pbDiagData[25u] = 0x70; /* p */
         pbDiagData[26u] = 0x6C; /* l */
         pbDiagData[27u] = 0x65; /* e */
         pbDiagData[28u] = 0x6D; /* m */
         pbDiagData[29u] = 0x65; /* e */
         pbDiagData[30u] = 0x6E; /* n */
         pbDiagData[31u] = 0x74; /* t */
         pbDiagData[32u] = 0x65; /* e */
         pbDiagData[33u] = 0x64; /* d */

         /* OFR */
         pbDiagData[34u] = 0x00; /* OFR Not supported */

         diagRespDataLen = kDiagRslReadDataByIdentifier + 33u;
         break;

      }

      default:
      {
         DiagNRCRequestOutOfRange();
         break;
      }
   }

   if (status != kFblOk)
   {
      /* Called if some memory access failed */
      DiagNRCConditionsNotCorrect();
   }

   /* Transmit response message:
    * If a negative response has to be transmitted, the length parameter is
    * ignored. In case of a positive response, the length parameter does not
    * include the service id. */
   DiagProcessingDone(diagRespDataLen);
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#if defined( FBL_ENABLE_DEBUG_STATUS )
/***********************************************************************************************************************
 *  ApplFblInitErrStatus
 **********************************************************************************************************************/
/*! \brief       Initialize error status information.
 **********************************************************************************************************************/
void ApplFblInitErrStatus( void )
{
   errStatFlashDrvVersion[0u] = 0u;
   errStatFlashDrvVersion[1u] = 0u;
   errStatFlashDrvVersion[2u] = 0u;
   errStatFlashDrvErrorCode = 0u;
   errStatErrorCode = 0u;
   errStatFblStates = 0u;
   errStatLastServiceId = 0u;
   errStatDescriptor.blockNr = 0u;
   errStatDescriptor.blockStartAddress = 0u;
}
#endif

/***********************************************************************************************************************
 *  ApplFblCheckProgPreconditions
 **********************************************************************************************************************/
/*! \brief         This function is called by the diagnostic module to check the programming preconditions.
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
/* PRQA S 6030 1 */ /* MD_MSR_STCYC */
tFblResult ApplFblCheckProgPreconditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* TODO_CUSTOMER */
   /* Set routine info to successful */
   pbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;
   /* Set Number of Programming Conditions */
   pbDiagData[kDiagLocFmtRoutineStatus] = 0x00u;

   DiagProcessingDone(5u);  /* Always send positive response */
   return kFblOk;
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/***********************************************************************************************************************
 *  ApplFblControlFailSafeReaction
 **********************************************************************************************************************/
/*! \brief         This function is called by the diagnostic module to restart/ suppress the fail safe functionality of an ECU
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        If the fail safe is restart/suppress, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblControlFailSafeReaction( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   /* Set routine info to successful */
   pbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;
   if (pbDiagData[0u] == kDiagSubStartRoutine)
   {
      /* A valid request RoutineControl - StartRoutine - ControlFailSafeReaction is received.
         Because of no fail safe behavior in boot mode there are no further activities than
         sending a positive response
       */
      DiagProcessingDone(4u);
   }
   else if (pbDiagData[0u] == kDiagSubStopRoutine)
   {
      /* A valid request RoutineControl - StopRoutine - ControlFailSafeReaction is received.
         Because of no fail safe behavior in boot mode there are no further activities than
         sending a positive response
       */
      DiagProcessingDone(4u);
   }
   else
   {
      /* Nothing to do here: MISRA */
   }
   /* If kFblFailed is returned, NRC 22h (conditionsNotCorrect) will be sent */
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblPrepVehicleSystForReprog
 **********************************************************************************************************************/
/*! \brief         This function is called to set all ECUs belonging to certain vehicle systems to a defined state
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        If the parameter is supported, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblPrepVehicleSystForReprog( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result;
   vuint16 routineOption;

# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
# endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   routineOption = (vuint16)FblMemGetInteger(sizeof(routineOption), &pbDiagData[kDiagLocFmtRoutineOption]);

   /* Check parameter "Systems to be prepared for reprogramming 
      Bit 0 - High Voltage Systems: 0 = no, 1 = yes
   */
   if ((routineOption & 0xFFFEu) == 0u)
   {
      /* Set routine info to successful */
      pbDiagData[kDiagLocFmtRoutineInfo] = kDiagRoutineInfoSuccessful;
      DiagProcessingDone(4u);
      result = kFblOk;
   }
   else
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }

   return result;
}

/*Static function used to copy vectors to an address*/
static void ApplCopyVectorToAddress(uint8 * destination, uint8 * source, uint8 size)
{
   uint8 i;
   
   if((NULL_PTR != destination) && (NULL_PTR != source))
   {
        for(i = 0; i < size; i++)
        {
            destination[i]=source[i];
        }
   }
}

/* module specific MISRA deviations:

   MD_FblKbApi_2889:
      Reason:     Multiple return paths are used to reduce code complexity, increase readability and reducing nesting level.
      Risk:       Some operations intended to conclude the function (e.g. states cleaning) can be unintentionally jumped.
      Prevention: Code inspection and runtime tests.

   MD_FblKbApi_3201:
      Reason: Configuration or platform specific dependent unreachable code.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3218_FileScopeStatic:
      Reason: Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk: Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApi_3325:
      Reason: This control expression is always true or false depend on configuration aspect and used platform specific
              implementation.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3353:
      Reason: Variable is set in an other function via call-by-reference.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3673:
      Reason: Function is part of the bootloader API which provides the possibility to influence the bootloader behavior
              by modifying the output parameters. The provided default implementation of the function doesn't
              necessarily make use of all available parameters.
      Risk: The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
      Prevention: Provide detailed information about the API and its usage in the user documentation.

   MD_FblKbApiOem_0313:
      Reason:     The watchdog trigger function is stored as void pointers as actual type
      Risk:       Function signature not compatible with expected type.
      Prevention: No prevention required.

   MD_FblKbApiOem_0314:
      Reason:     Type conversion to void * is necessary to use the standard MEMCPY API
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_0314_VoidPtrTypedPtr:
      Reason:     SecM uses untyped void pointers for context.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_2741_4558:
      Reason:     Assertion macros have to be disabled in production code and are used only for development.
      Risk:       Assertion code may be enabled in production code unintentionally. If a assertion condition is unexpectedly
                  false, the code is active. A problem may occur if the Macro is additionally changed from single statement
                  to multiple statement.
      Prevention: Macro is not allowed to be changed without review. Development code is automatically disabled via
                  configuration of project state "Production".

   MD_FblKbApiOem_2742:
      Reason:     Compiler related constand expression to check actual size.
      Risk:       No risk.
      Prevention: No prevention required. (Note: assertions are disabled in production software).

   MD_FblKbApiOem_2985:
      Reason:     Macro SetReprogProcessState clears the reprogramming process state flags and then
                  assigns a value of 0.
      Risk:       No identifiable risk
      Prevention: No prevention required.

   MD_FblKbApiOem_2987_EmptyFunction:
      Reason:     Function is empty depending on configuration aspects and platform specific implementation.
      Risk:       Function implementation missing.
      Prevention: Code inspection and test in the component test.

   MD_FblKbApiOem_2991_2995:
      Reason:     Code is shared between different configurations. In other configurations,
                  the result of the comparison/logical operation is not invariant.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3218_FileScopeStatic:
      Reason:     Configuration constants/tables are kept at a central location for a better overview and maintenance.
      Risk:       Unintended use of object in wrong scope.
      Prevention: Architectural pattern supports prevention of incorrect use of objects in wrong context.
                  Code inspection focus on correct use of objects.

   MD_FblKbApiOem_3425:
      Reason:     The WrapNv call uses the ternary operator to remap the return value of IO_E_OK to kFblOk.As both of
                  them are defined to the value zero the remapping has no side affects.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_4342_4521_ConfigurationEnumLengthCast:
      Reason:     The last element of an enum is used to determine the number of entries. This is required for
                  configurable code. The enum must have more than one entry - therefore it is always possible to
                  determine the last (length - 1) one.
      Risk:       No identifiable risk.
      Prevention: No prevention required.


*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_APDI.C
 **********************************************************************************************************************/
