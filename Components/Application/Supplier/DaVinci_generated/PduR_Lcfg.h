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
 *            Module: PduR
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.h
 *   Generation Time: 2023-07-10 14:36:12
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (PDUR_LCFG_H)
# define PDUR_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"
# include "PduR_Cfg.h"
# include "Os.h"
# include "PduR_PBcfg.h"

/* include headers with symbolic name values */
/* \trace SPEC-2020167 */

#include "CanIf.h"
#include "CanNm.h"
#include "CanTp.h"
#include "Com_Cbk.h"
#include "Dcm_Cbk.h"
#include "IpduM.h"
#include "IpduM_Cbk.h"
#include "SecOC.h"
#include "SecOC_Cbk.h"


/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCDataSwitches  PduR Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_APPLICATIONID2DESTAPPLICATIONMANAGERROM                                                STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_DESTAPPLICATIONMANAGERROMIDXOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                  STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DESTAPPLICATIONMANAGERROMUSEDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                 STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INVALIDHNDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                                    STD_OFF  /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERARRAYRAM                                                                     STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROM                                                                       STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferIndRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_BmTxBufferIndRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                                     STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCERAM                                                                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                       STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BMTXBUFFERINSTANCEROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_BmTxBufferInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERRAM                                                                          STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ALLOCATEDOFBMTXBUFFERRAM                                                               STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                              STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RXLENGTHOFBMTXBUFFERRAM                                                                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BMTXBUFFERROM                                                                          STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_BmTxBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                              STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                             STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                           STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CONFIGID                                                                               STD_ON
#define PDUR_DEFERREDEVENTCACHEARRAYRAM                                                             STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_RMGDESTROMIDXOFDEFERREDEVENTCACHEARRAYRAM                                              STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHERAM                                                                  STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRam' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMREADIDXOFDEFERREDEVENTCACHERAM                               STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMWRITEIDXOFDEFERREDEVENTCACHERAM                              STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMENDIDXOFDEFERREDEVENTCACHEROM                                STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMLENGTHOFDEFERREDEVENTCACHEROM                                STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEARRAYRAMSTARTIDXOFDEFERREDEVENTCACHEROM                              STD_OFF  /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DESTAPPLICATIONMANAGERROM                                                              STD_ON
#define PDUR_INITIALIZEDIDXOFDESTAPPLICATIONMANAGERROM                                              STD_ON
#define PDUR_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                                     STD_ON
#define PDUR_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                            STD_ON
#define PDUR_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                          STD_ON
#define PDUR_RMGDESTROMUSEDOFDESTAPPLICATIONMANAGERROM                                              STD_ON
#define PDUR_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                                     STD_ON
#define PDUR_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                   STD_ON
#define PDUR_EXCLUSIVEAREAROM                                                                       STD_ON
#define PDUR_LOCKOFEXCLUSIVEAREAROM                                                                 STD_ON
#define PDUR_UNLOCKOFEXCLUSIVEAREAROM                                                               STD_ON
#define PDUR_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'PduR_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_FMFIFOELEMENTRAM                                                                       STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                     STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                         STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FMFIFOINSTANCERAM                                                                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                            STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FMFIFOINSTANCEROM                                                                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_FmFifoInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFORAM                                                                              STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FILLLEVELOFFMFIFORAM                                                                   STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                     STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                    STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_PENDINGCONFIRMATIONSOFFMFIFORAM                                                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_TPTXSMSTATEOFFMFIFORAM                                                                 STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FMFIFOROM                                                                              STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_FmFifoRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                                    STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                                    STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LOCKROMIDXOFFMFIFOROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_LOCKROMUSEDOFFMFIFOROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_GENERALPROPERTIESROM                                                                   STD_ON
#define PDUR_SPINLOCKRETRYCOUNTEROFGENERALPROPERTIESROM                                             STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' and Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' */
#define PDUR_HASIFROUTINGOFGENERALPROPERTIESROM                                                     STD_ON
#define PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM                                                      STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'the value of PduR_hasIfTxFifoOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'the value of PduR_hasIfTxFifoOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_HASTPBUFFERULSOURCEOFGENERALPROPERTIESROM                                              STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasTpBufferUlSource' Reason: 'the value of PduR_hasTpBufferUlSourceOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasTpBufferUlSource' Reason: 'the value of PduR_hasTpBufferUlSourceOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'PduR_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITIALIZEDRAM                                                                         STD_ON
#define PDUR_INTERFACEFIFOQUEUEARRAYRAM                                                             STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAM                                                           STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ACTUALLENGTHOFINTERFACEFIFOQUEUEELEMENTRAM                                             STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUERAM                                                                  STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FIFOFULLOFINTERFACEFIFOQUEUERAM                                                        STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMREADIDXOFINTERFACEFIFOQUEUERAM                             STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMWRITEIDXOFINTERFACEFIFOQUEUERAM                            STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_INTERFACEFIFOQUEUEROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_InterfaceFifoQueueRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INTERFACEFIFOQUEUEARRAYRAMENDIDXOFINTERFACEFIFOQUEUEROM                                STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEARRAYRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                              STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMENDIDXOFINTERFACEFIFOQUEUEROM                              STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEELEMENTRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                            STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_MAXPDULENGTHOFINTERFACEFIFOQUEUEROM                                                    STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIDXOFINTERFACEFIFOQUEUEROM                                                    STD_OFF  /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LOCKROM                                                                                STD_ON
#define PDUR_EXCLUSIVEAREAROMIDXOFLOCKROM                                                           STD_ON
#define PDUR_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                          STD_ON
#define PDUR_SPINLOCKRAMIDXOFLOCKROM                                                                STD_OFF  /**< Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_SPINLOCKRAMPARTITIONIDXOFLOCKROM                                                       STD_OFF  /**< Deactivateable: 'PduR_LockRom.SpinlockRamPartitionIdx' Reason: 'the value of PduR_SpinlockRamPartitionIdxOfLockRom is always 'PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_LockRom.SpinlockRamPartitionIdx' Reason: 'the value of PduR_SpinlockRamPartitionIdxOfLockRom is always 'PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM' due to this, the array is deactivated.' */
#define PDUR_SPINLOCKRAMUSEDOFLOCKROM                                                               STD_OFF  /**< Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAM                                                                      STD_OFF  /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERRAM                                                                           STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMPENDINGREADIDXOFMCQBUFFERRAM                                          STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMPENDINGWRITEIDXOFMCQBUFFERRAM                                         STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMREADIDXOFMCQBUFFERRAM                                                 STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMWRITEIDXOFMCQBUFFERRAM                                                STD_OFF  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERROM                                                                           STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMENDIDXOFMCQBUFFERROM                                                  STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMLENGTHOFMCQBUFFERROM                                                  STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERARRAYRAMSTARTIDXOFMCQBUFFERROM                                                STD_OFF  /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MMROM                                                                                  STD_ON
#define PDUR_CANCELRECEIVESUPPORTEDOFMMROM                                                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.ChangeParameterSupported' Reason: 'the value of PduR_ChangeParameterSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.ChangeParameterSupported' Reason: 'the value of PduR_ChangeParameterSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_ON
#define PDUR_LOIFCANCELTRANSMITFCTPTROFMMROM                                                        STD_ON
#define PDUR_LOIFOFMMROM                                                                            STD_ON
#define PDUR_LOIFTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_LOTPCANCELRECEIVEFCTPTROFMMROM                                                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCANCELTRANSMITFCTPTROFMMROM                                                        STD_ON
#define PDUR_LOTPCHANGEPARAMETERFCTPTROFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpChangeParameterFctPtr' Reason: 'the value of PduR_LoTpChangeParameterFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpChangeParameterFctPtr' Reason: 'the value of PduR_LoTpChangeParameterFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPOFMMROM                                                                            STD_ON
#define PDUR_LOTPTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_MASKEDBITSOFMMROM                                                                      STD_ON
#define PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_ON
#define PDUR_UPIFOFMMROM                                                                            STD_ON
#define PDUR_UPIFRXINDICATIONFCTPTROFMMROM                                                          STD_ON
#define PDUR_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                       STD_ON
#define PDUR_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                        STD_ON
#define PDUR_UPTPCOPYRXDATAFCTPTROFMMROM                                                            STD_ON
#define PDUR_UPTPCOPYTXDATAFCTPTROFMMROM                                                            STD_ON
#define PDUR_UPTPOFMMROM                                                                            STD_ON
#define PDUR_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                      STD_ON
#define PDUR_UPTPTPRXINDICATIONFCTPTROFMMROM                                                        STD_ON
#define PDUR_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                      STD_ON
#define PDUR_PARTITIONIDENTIFIERS                                                                   STD_ON
#define PDUR_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                             STD_ON
#define PDUR_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                     STD_ON
#define PDUR_PARTITIONLOOKUPTABLERAM                                                                STD_OFF  /**< Deactivateable: 'PduR_PartitionLookupTableRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_OSAPPLICATIONTOPDUROFPARTITIONLOOKUPTABLERAM                                           STD_OFF  /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_QUEUEFCTPTRROM                                                                         STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_QueueFctPtrRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FLUSHFCTPTROFQUEUEFCTPTRROM                                                            STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_GETFCTPTROFQUEUEFCTPTRROM                                                              STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_GETFILLLEVELFCTPTROFQUEUEFCTPTRROM                                                     STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_PUTFCTPTROFQUEUEFCTPTRROM                                                              STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_REMOVEFCTPTROFQUEUEFCTPTRROM                                                           STD_OFF  /**< Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMBUFFEREDIFPROPERTIESRAM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                                    STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INTERFACEFIFOQUEUEROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                      STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUEFCTPTRROMIDXOFRMBUFFEREDIFPROPERTIESROM                                           STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                         STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMBUFFEREDTPPROPERTIESRAM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                         STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                                STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_METADATALENGTHOFRMBUFFEREDTPPROPERTIESROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' */
#define PDUR_METADATALENGTHUSEDOFRMBUFFEREDTPPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                               STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.QueuedDestCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.QueuedDestCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROM                                                                              STD_ON
#define PDUR_BSWMPDURPRETRANSMITCALLBACKOFRMDESTROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmDestRomLeft.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RmDestRomRight.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                                   STD_ON
#define PDUR_RMDESTRPGROMIDXOFRMDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRomLeft.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRight.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMPARTITIONIDXOFRMDESTROM                                                    STD_OFF  /**< Deactivateable: 'PduR_RmDestRomLeft.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmDestRomRight.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMUSEDOFRMDESTROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRomLeft.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRight.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTROMIDXOFRMDESTROM                                                               STD_ON
#define PDUR_RMSRCROMIDXOFRMDESTROM                                                                 STD_ON
#define PDUR_ROUTINGTYPEOFRMDESTROM                                                                 STD_ON
#define PDUR_RMDESTRPGRAM                                                                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ENABLEDCNTOFRMDESTRPGRAM                                                               STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMDESTRPGROM                                                                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INITIALENABLEDCNTOFRMDESTRPGROM                                                        STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIDXOFRMDESTRPGROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMUSEDOFRMDESTRPGROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMIND                                                                        STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTNTO1INFORAM                                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMDESTROMIDXOFRMGDESTNTO1INFORAM                                                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_TRANSMISSIONACTIVEOFRMGDESTNTO1INFORAM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMGDESTROM                                                                             STD_ON
#define PDUR_DESTAPPLICATIONMANAGERROMIDXOFRMGDESTROM                                               STD_ON
#define PDUR_DESTHNDOFRMGDESTROM                                                                    STD_ON
#define PDUR_DIRECTIONOFRMGDESTROM                                                                  STD_ON
#define PDUR_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRight.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_LOCKROMIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_MAXPDULENGTHOFRMGDESTROM                                                               STD_ON
#define PDUR_MMROMIDXOFRMGDESTROM                                                                   STD_ON
#define PDUR_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                      STD_ON
#define PDUR_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmBufferedIfPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedIfPropertiesRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.RmBufferedIfPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedIfPropertiesRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRight.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmBufferedIfPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedIfPropertiesRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.RmBufferedIfPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedIfPropertiesRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTROMIDXOFRMGDESTROM                                                               STD_ON
#define PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM                                             STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRight.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM                                            STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRight.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                                    STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRight.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_SMGDESTROMIDXOFRMGDESTROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRight.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROMPARTITIONIDXOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRight.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_SMGDESTROMUSEDOFRMGDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomLeft.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRight.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TXIF2UPIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_RMGDESTTPTXSTATERAM                                                                    STD_OFF  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMSRCROM                                                                               STD_ON
#define PDUR_DESTAPPLICATIONMANAGERROMIDXOFRMSRCROM                                                 STD_ON
#define PDUR_LOCKROMIDXOFRMSRCROM                                                                   STD_ON
#define PDUR_MASKEDBITSOFRMSRCROM                                                                   STD_ON
#define PDUR_MMROMIDXOFRMSRCROM                                                                     STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomLeft.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRight.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM                                        STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomLeft.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRight.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                                STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomLeft.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRight.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTROMENDIDXOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMLENGTHOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMSTARTIDXOFRMSRCROM                                                            STD_ON
#define PDUR_SMSRCROMIDXOFRMSRCROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomLeft.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRight.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROMPARTITIONIDXOFRMSRCROM                                                         STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomLeft.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRight.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PDUR_SMSRCROMUSEDOFRMSRCROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomLeft.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRight.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SRCHNDOFRMSRCROM                                                                       STD_ON
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                     STD_ON
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                      STD_ON
#define PDUR_RMTRANSMITFCTPTR                                                                       STD_ON
#define PDUR_RPGEXTIDROM                                                                            STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgExtIdRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INVALIDHNDOFRPGEXTIDROM                                                                STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_RPGROMIDXOFRPGEXTIDROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGROMPARTITIONIDXOFRPGEXTIDROM                                                        STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGROMUSEDOFRPGEXTIDROM                                                                STD_OFF  /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGRAM                                                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ENABLEDOFRPGRAM                                                                        STD_OFF  /**< Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RPGROM                                                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_ENABLEDATINITOFRPGROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDENDIDXOFRPGROM                                                          STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDSTARTIDXOFRPGROM                                                        STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDUSEDOFRPGROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXIF2DEST                                                                              STD_ON
#define PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                                                STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFRXIF2DEST                                                                  STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFRXIF2DEST                                                                 STD_ON
#define PDUR_RXTP2DEST                                                                              STD_ON
#define PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                                              STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST                                          STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFRXTP2DEST                                                                  STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFRXTP2DEST                                                                 STD_ON
#define PDUR_RXTP2SRC                                                                               STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' and Deactivateable: 'PduR_RxTp2Src' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_INVALIDHNDOFRXTP2SRC                                                                   STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' and Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' and Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' and Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_RMDESTROMIDXOFRXTP2SRC                                                                 STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.RmDestRomIdx' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' and Deactivateable: 'PduR_RxTp2Src.RmDestRomIdx' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_SINGLEBUFFERARRAYRAM                                                                   STD_OFF  /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROM                                                              STD_OFF  /**< Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERRAM                                                                        STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ACTUALLENGTHOFSINGLEBUFFERRAM                                                          STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_SINGLEBUFFERROM                                                                        STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_SingleBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_RMDESTROMIDXOFSINGLEBUFFERROM                                                          STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERARRAYRAMENDIDXOFSINGLEBUFFERROM                                            STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERARRAYRAMLENGTHOFSINGLEBUFFERROM                                            STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERARRAYRAMSTARTIDXOFSINGLEBUFFERROM                                          STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROMENDIDXOFSINGLEBUFFERROM                                       STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROMLENGTHOFSINGLEBUFFERROM                                       STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SINGLEBUFFERINITVALUESROMSTARTIDXOFSINGLEBUFFERROM                                     STD_OFF  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SIZEOFDESTAPPLICATIONMANAGERROM                                                        STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROM                                                                 STD_ON
#define PDUR_SIZEOFGENERALPROPERTIESROM                                                             STD_ON
#define PDUR_SIZEOFINITIALIZEDRAM                                                                   STD_ON
#define PDUR_SIZEOFLOCKROM                                                                          STD_ON
#define PDUR_SIZEOFMMROM                                                                            STD_ON
#define PDUR_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define PDUR_SIZEOFRMDESTROM                                                                        STD_ON
#define PDUR_SIZEOFRMGDESTROM                                                                       STD_ON
#define PDUR_SIZEOFRMSRCROM                                                                         STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTR                                                                 STD_ON
#define PDUR_SIZEOFRXIF2DEST                                                                        STD_ON
#define PDUR_SIZEOFRXTP2DEST                                                                        STD_ON
#define PDUR_SIZEOFSRCAPPLICATIONROM                                                                STD_ON
#define PDUR_SIZEOFTX2LO                                                                            STD_ON
#define PDUR_SIZEOFTXIF2UP                                                                          STD_ON
#define PDUR_SIZEOFTXTP2SRC                                                                         STD_ON
#define PDUR_SMDATAPLANEROM                                                                         STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMENDIDXOFSMDATAPLANEROM                                                         STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                                                       STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMUSEDOFSMDATAPLANEROM                                                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                                STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                               STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                            STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAM                                                                               STD_OFF  /**< Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_LEARNEDCONNECTIONIDOFSMFIBRAM                                                          STD_OFF  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTR                                                                    STD_OFF  /**< Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROM                                                                             STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMGDESTROM                                                               STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMGDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMGDESTROM                                                          STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTRIDXOFSMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR                                           STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM                                                   STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                             STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                           STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM                                               STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                       STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                       STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTR                                                                      STD_OFF  /**< Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROM                                                                               STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMSRCROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMSRCROM                                                               STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMSRCROM                                                            STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM                              STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM                             STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTRIDXOFSMSRCROM                                                         STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SPINLOCKRAM                                                                            STD_OFF  /**< Deactivateable: 'PduR_SpinlockRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_COUNTEROFSPINLOCKRAM                                                                   STD_OFF  /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_LOCKVARIABLEOFSPINLOCKRAM                                                              STD_OFF  /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_SRCAPPLICATIONROM                                                                      STD_ON
#define PDUR_DEFERREDEVENTCACHEROMIDXOFSRCAPPLICATIONROM                                            STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                                   STD_ON
#define PDUR_DEFERREDEVENTCACHEROMUSEDOFSRCAPPLICATIONROM                                           STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' */
#define PDUR_MCQBUFFERROMIDXOFSRCAPPLICATIONROM                                                     STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM                                            STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomPartitionIdx' Reason: 'the value of PduR_McQBufferRomPartitionIdxOfSrcApplicationRom is always 'PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomPartitionIdx' Reason: 'the value of PduR_McQBufferRomPartitionIdxOfSrcApplicationRom is always 'PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM' due to this, the array is deactivated.' */
#define PDUR_MCQBUFFERROMUSEDOFSRCAPPLICATIONROM                                                    STD_OFF  /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PDUR_TX2LO                                                                                  STD_ON
#define PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO                                                        STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_CANCELTRANSMITUSEDOFTX2LO                                                              STD_ON
#define PDUR_INVALIDHNDOFTX2LO                                                                      STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFTX2LO                                                                     STD_ON
#define PDUR_RMSRCROMUSEDOFTX2LO                                                                    STD_ON
#define PDUR_RMTRANSMITFCTPTRIDXOFTX2LO                                                             STD_ON
#define PDUR_TXIF2UP                                                                                STD_ON
#define PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                                                STD_OFF  /**< Deactivateable: 'PduR_TxIf2UpLeft.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxIf2UpRight.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXIF2UP                                                                    STD_OFF  /**< Deactivateable: 'PduR_TxIf2UpLeft.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxIf2UpLeft.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxIf2UpRight.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxIf2UpRight.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMGDESTROMIDXOFTXIF2UP                                                                 STD_ON
#define PDUR_TXCONFIRMATIONUSEDOFTXIF2UP                                                            STD_ON
#define PDUR_TXTP2SRC                                                                               STD_ON
#define PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC                                             STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXTP2SRC                                                                   STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMGDESTROMIDXOFTXTP2SRC                                                                STD_ON
#define PDUR_PCCONFIG                                                                               STD_ON
#define PDUR_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'PduR_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'PduR_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_PCPARTITIONCONFIGOFPCCONFIG                                                            STD_ON
#define PDUR_PARTITIONIDENTIFIERSOFPCCONFIG                                                         STD_ON
#define PDUR_SIZEOFPARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define PDUR_PCPARTITIONCONFIG                                                                      STD_ON
#define PDUR_CONFIGIDOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                           STD_ON
#define PDUR_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_GENERALPROPERTIESROMOFPCPARTITIONCONFIG                                                STD_ON
#define PDUR_INITIALIZEDRAMOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_LOCKROMOFPCPARTITIONCONFIG                                                             STD_ON
#define PDUR_MMROMOFPCPARTITIONCONFIG                                                               STD_ON
#define PDUR_RMDESTROMOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_RMGDESTROMOFPCPARTITIONCONFIG                                                          STD_ON
#define PDUR_RMSRCROMOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_RXIF2DESTOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_RXTP2DESTOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_SIZEOFDESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFGENERALPROPERTIESROMOFPCPARTITIONCONFIG                                          STD_ON
#define PDUR_SIZEOFINITIALIZEDRAMOFPCPARTITIONCONFIG                                                STD_ON
#define PDUR_SIZEOFLOCKROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_SIZEOFMMROMOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_SIZEOFRMDESTROMOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFRMGDESTROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_SIZEOFRMSRCROMOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTROFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFRXIF2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFRXTP2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFSRCAPPLICATIONROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_SIZEOFTX2LOOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_SIZEOFTXIF2UPOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_SIZEOFTXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                                   STD_ON
#define PDUR_TX2LOOFPCPARTITIONCONFIG                                                               STD_ON
#define PDUR_TXIF2UPOFPCPARTITIONCONFIG                                                             STD_ON
#define PDUR_TXTP2SRCOFPCPARTITIONCONFIG                                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCNoReferenceDefines  PduR No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define PDUR_NO_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                                  255u
#define PDUR_NO_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                         255u
#define PDUR_NO_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                       255u
#define PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM                                                        255u
#define PDUR_NO_DESTHNDOFRMGDESTROM                                                                 255u
#define PDUR_NO_SRCHNDOFRMSRCROM                                                                    255u
#define PDUR_NO_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                                255u
#define PDUR_NO_RMSRCROMIDXOFTX2LO                                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumExistsDefines  PduR Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM               STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SIMPLE_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_DIRECT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_TRIGGER_TRANSMIT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_FIFO_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                       STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                     STD_ON
#define PDUR_EXISTS_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                     STD_ON
#define PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_IF_UNBUFFERED_UL_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_OFF
#define PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM                                      STD_OFF
#define PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_OFF
#define PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_ON
#define PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_OFF
#define PDUR_EXISTS_RX_DIRECTIONOFRMGDESTROM                                                        STD_ON
#define PDUR_EXISTS_TX_DIRECTIONOFRMGDESTROM                                                        STD_ON
#define PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM                                      STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredReception] and /ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredTransmission] are both disabled. */
#define PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumDefines  PduR Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                            0x02u
#define PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                            0x03u
#define PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x00u
#define PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x01u
#define PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x05u
#define PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x06u
#define PDUR_RX_DIRECTIONOFRMGDESTROM                                                               0x00u
#define PDUR_TX_DIRECTIONOFRMGDESTROM                                                               0x01u
#define PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                            0x01u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMaskedBitDefines  PduR Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM_MASK                                                  0x20u
#define PDUR_LOIFOFMMROM_MASK                                                                       0x10u
#define PDUR_LOTPOFMMROM_MASK                                                                       0x08u
#define PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM_MASK                                                  0x04u
#define PDUR_UPIFOFMMROM_MASK                                                                       0x02u
#define PDUR_UPTPOFMMROM_MASK                                                                       0x01u
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM_MASK                                                0x02u
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM_MASK                                                 0x01u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIsReducedToDefineDefines  PduR Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_INITIALIZEDIDXOFDESTAPPLICATIONMANAGERROM                                        STD_OFF
#define PDUR_ISDEF_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                               STD_OFF
#define PDUR_ISDEF_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                      STD_OFF
#define PDUR_ISDEF_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                    STD_OFF
#define PDUR_ISDEF_RMGDESTROMUSEDOFDESTAPPLICATIONMANAGERROM                                        STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                               STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                             STD_OFF
#define PDUR_ISDEF_LOCKOFEXCLUSIVEAREAROM                                                           STD_OFF
#define PDUR_ISDEF_UNLOCKOFEXCLUSIVEAREAROM                                                         STD_OFF
#define PDUR_ISDEF_HASIFROUTINGOFGENERALPROPERTIESROM                                               STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMIDXOFLOCKROM                                                     STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                    STD_OFF
#define PDUR_ISDEF_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                 STD_OFF
#define PDUR_ISDEF_LOIFCANCELTRANSMITFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_LOIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOIFTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_LOTPCANCELTRANSMITFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_LOTPOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOTPTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFMMROM                                                                STD_OFF
#define PDUR_ISDEF_TPCANCELTRANSMITSUPPORTEDOFMMROM                                                 STD_OFF
#define PDUR_ISDEF_UPIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_UPIFRXINDICATIONFCTPTROFMMROM                                                    STD_OFF
#define PDUR_ISDEF_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                 STD_OFF
#define PDUR_ISDEF_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_UPTPCOPYRXDATAFCTPTROFMMROM                                                      STD_OFF
#define PDUR_ISDEF_UPTPCOPYTXDATAFCTPTROFMMROM                                                      STD_OFF
#define PDUR_ISDEF_UPTPOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                STD_OFF
#define PDUR_ISDEF_UPTPTPRXINDICATIONFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                STD_OFF
#define PDUR_ISDEF_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                       STD_OFF
#define PDUR_ISDEF_PARTITIONSNVOFPARTITIONIDENTIFIERS                                               STD_OFF
#define PDUR_ISDEF_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                             STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFRMDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_ROUTINGTYPEOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMIDXOFRMGDESTROM                                         STD_OFF
#define PDUR_ISDEF_DESTHNDOFRMGDESTROM                                                              STD_OFF
#define PDUR_ISDEF_DIRECTIONOFRMGDESTROM                                                            STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_MAXPDULENGTHOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMGDESTROM                                                             STD_OFF
#define PDUR_ISDEF_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_TXIF2UPIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMIDXOFRMSRCROM                                           STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMSRCROM                                                             STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFRMSRCROM                                                             STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMSRCROM                                                               STD_OFF
#define PDUR_ISDEF_RMDESTROMENDIDXOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMLENGTHOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMSTARTIDXOFRMSRCROM                                                      STD_OFF
#define PDUR_ISDEF_SRCHNDOFRMSRCROM                                                                 STD_OFF
#define PDUR_ISDEF_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                               STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTR                                                                 STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXIF2DEST                                                           STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXTP2DEST                                                           STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                             STD_OFF
#define PDUR_ISDEF_CANCELTRANSMITUSEDOFTX2LO                                                        STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFTX2LO                                                               STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFTX2LO                                                              STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTRIDXOFTX2LO                                                       STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXIF2UP                                                           STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONUSEDOFTXIF2UP                                                      STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXTP2SRC                                                          STD_OFF
#define PDUR_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_OFF
#define PDUR_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_ISDEF_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_ISDEF_GENERALPROPERTIESROMOFPCPARTITIONCONFIG                                          STD_ON
#define PDUR_ISDEF_INITIALIZEDRAMOFPCPARTITIONCONFIG                                                STD_ON
#define PDUR_ISDEF_LOCKROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_ISDEF_MMROMOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_ISDEF_RMDESTROMOFPCPARTITIONCONFIG                                                     STD_OFF
#define PDUR_ISDEF_RMGDESTROMOFPCPARTITIONCONFIG                                                    STD_OFF
#define PDUR_ISDEF_RMSRCROMOFPCPARTITIONCONFIG                                                      STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_ISDEF_RXIF2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_ISDEF_RXTP2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_ISDEF_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_ISDEF_TX2LOOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_ISDEF_TXIF2UPOFPCPARTITIONCONFIG                                                       STD_OFF
#define PDUR_ISDEF_TXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEqualsAlwaysToDefines  PduR Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_INITIALIZEDIDXOFDESTAPPLICATIONMANAGERROM                                          
#define PDUR_EQ2_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                                 
#define PDUR_EQ2_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                        
#define PDUR_EQ2_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                      
#define PDUR_EQ2_RMGDESTROMUSEDOFDESTAPPLICATIONMANAGERROM                                          
#define PDUR_EQ2_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                                 
#define PDUR_EQ2_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                               
#define PDUR_EQ2_LOCKOFEXCLUSIVEAREAROM                                                             
#define PDUR_EQ2_UNLOCKOFEXCLUSIVEAREAROM                                                           
#define PDUR_EQ2_HASIFROUTINGOFGENERALPROPERTIESROM                                                 
#define PDUR_EQ2_EXCLUSIVEAREAROMIDXOFLOCKROM                                                       
#define PDUR_EQ2_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                      
#define PDUR_EQ2_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                   
#define PDUR_EQ2_LOIFCANCELTRANSMITFCTPTROFMMROM                                                    
#define PDUR_EQ2_LOIFOFMMROM                                                                        
#define PDUR_EQ2_LOIFTRANSMITFCTPTROFMMROM                                                          
#define PDUR_EQ2_LOTPCANCELTRANSMITFCTPTROFMMROM                                                    
#define PDUR_EQ2_LOTPOFMMROM                                                                        
#define PDUR_EQ2_LOTPTRANSMITFCTPTROFMMROM                                                          
#define PDUR_EQ2_MASKEDBITSOFMMROM                                                                  
#define PDUR_EQ2_TPCANCELTRANSMITSUPPORTEDOFMMROM                                                   
#define PDUR_EQ2_UPIFOFMMROM                                                                        
#define PDUR_EQ2_UPIFRXINDICATIONFCTPTROFMMROM                                                      
#define PDUR_EQ2_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                   
#define PDUR_EQ2_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                    
#define PDUR_EQ2_UPTPCOPYRXDATAFCTPTROFMMROM                                                        
#define PDUR_EQ2_UPTPCOPYTXDATAFCTPTROFMMROM                                                        
#define PDUR_EQ2_UPTPOFMMROM                                                                        
#define PDUR_EQ2_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                                                  
#define PDUR_EQ2_UPTPTPRXINDICATIONFCTPTROFMMROM                                                    
#define PDUR_EQ2_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                                                  
#define PDUR_EQ2_PCPARTITIONCONFIGIDXOFPARTITIONIDENTIFIERS                                         
#define PDUR_EQ2_PARTITIONSNVOFPARTITIONIDENTIFIERS                                                 
#define PDUR_EQ2_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                               
#define PDUR_EQ2_RMGDESTROMIDXOFRMDESTROM                                                           
#define PDUR_EQ2_RMSRCROMIDXOFRMDESTROM                                                             
#define PDUR_EQ2_ROUTINGTYPEOFRMDESTROM                                                             
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMIDXOFRMGDESTROM                                           
#define PDUR_EQ2_DESTHNDOFRMGDESTROM                                                                
#define PDUR_EQ2_DIRECTIONOFRMGDESTROM                                                              
#define PDUR_EQ2_LOCKROMIDXOFRMGDESTROM                                                             
#define PDUR_EQ2_MAXPDULENGTHOFRMGDESTROM                                                           
#define PDUR_EQ2_MMROMIDXOFRMGDESTROM                                                               
#define PDUR_EQ2_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                  
#define PDUR_EQ2_RMDESTROMIDXOFRMGDESTROM                                                           
#define PDUR_EQ2_TXIF2UPIDXOFRMGDESTROM                                                             
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMIDXOFRMSRCROM                                             
#define PDUR_EQ2_LOCKROMIDXOFRMSRCROM                                                               
#define PDUR_EQ2_MASKEDBITSOFRMSRCROM                                                               
#define PDUR_EQ2_MMROMIDXOFRMSRCROM                                                                 
#define PDUR_EQ2_RMDESTROMENDIDXOFRMSRCROM                                                          
#define PDUR_EQ2_RMDESTROMLENGTHOFRMSRCROM                                                          
#define PDUR_EQ2_RMDESTROMSTARTIDXOFRMSRCROM                                                        
#define PDUR_EQ2_SRCHNDOFRMSRCROM                                                                   
#define PDUR_EQ2_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                 
#define PDUR_EQ2_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                  
#define PDUR_EQ2_RMTRANSMITFCTPTR                                                                   
#define PDUR_EQ2_RMSRCROMIDXOFRXIF2DEST                                                             
#define PDUR_EQ2_RMSRCROMIDXOFRXTP2DEST                                                             
#define PDUR_EQ2_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                               
#define PDUR_EQ2_CANCELTRANSMITUSEDOFTX2LO                                                          
#define PDUR_EQ2_RMSRCROMIDXOFTX2LO                                                                 
#define PDUR_EQ2_RMSRCROMUSEDOFTX2LO                                                                
#define PDUR_EQ2_RMTRANSMITFCTPTRIDXOFTX2LO                                                         
#define PDUR_EQ2_RMGDESTROMIDXOFTXIF2UP                                                             
#define PDUR_EQ2_TXCONFIRMATIONUSEDOFTXIF2UP                                                        
#define PDUR_EQ2_RMGDESTROMIDXOFTXTP2SRC                                                            
#define PDUR_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        
#define PDUR_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     PduR_PartitionIdentifiers
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                       PduR_DestApplicationManagerRom
#define PDUR_EQ2_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                                PduR_ExclusiveAreaRom
#define PDUR_EQ2_GENERALPROPERTIESROMOFPCPARTITIONCONFIG                                            PduR_GeneralPropertiesRom
#define PDUR_EQ2_INITIALIZEDRAMOFPCPARTITIONCONFIG                                                  PduR_InitializedRam.raw
#define PDUR_EQ2_LOCKROMOFPCPARTITIONCONFIG                                                         PduR_LockRom
#define PDUR_EQ2_MMROMOFPCPARTITIONCONFIG                                                           PduR_MmRom
#define PDUR_EQ2_RMDESTROMOFPCPARTITIONCONFIG                                                       
#define PDUR_EQ2_RMGDESTROMOFPCPARTITIONCONFIG                                                      
#define PDUR_EQ2_RMSRCROMOFPCPARTITIONCONFIG                                                        
#define PDUR_EQ2_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                                PduR_RmTransmitFctPtr
#define PDUR_EQ2_RXIF2DESTOFPCPARTITIONCONFIG                                                       PduR_RxIf2Dest
#define PDUR_EQ2_RXTP2DESTOFPCPARTITIONCONFIG                                                       PduR_RxTp2Dest
#define PDUR_EQ2_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                               PduR_SrcApplicationRom
#define PDUR_EQ2_TX2LOOFPCPARTITIONCONFIG                                                           PduR_Tx2Lo
#define PDUR_EQ2_TXIF2UPOFPCPARTITIONCONFIG                                                         
#define PDUR_EQ2_TXTP2SRCOFPCPARTITIONCONFIG                                                        PduR_TxTp2Src
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicNonDereferenciateablePointers  PduR Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define PduR_RxIf2Dest                                                                              ((PduR_RxIf2DestPtrType)(&(PduR_PCPartitionConfigRight)))  /**< Non derefenciateable valid pointer */
#define PduR_RxTp2Dest                                                                              ((PduR_RxTp2DestPtrType)(&(PduR_PCPartitionConfigRight)))  /**< Non derefenciateable valid pointer */
#define PduR_SrcApplicationRom                                                                      ((PduR_SrcApplicationRomPtrType)(&(PduR_PCPartitionConfigRight)))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicInitializationPointers  PduR Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define PduR_Config_Left_Ptr                                                                        &(PduR_PCConfig.Config_Left)  /**< symbolic identifier which shall be used to initialize 'PduR' */
#define PduR_Config_Right_Ptr                                                                       &(PduR_PCConfig.Config_Right)  /**< symbolic identifier which shall be used to initialize 'PduR' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCInitializationSymbols  PduR Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define PduR_Config_Left                                                                            PduR_PCConfig.Config_Left  /**< symbolic identifier which could be used to initialize 'PduR */
#define PduR_Config_Right                                                                           PduR_PCConfig.Config_Right  /**< symbolic identifier which could be used to initialize 'PduR */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGeneral  PduR General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define PDUR_CHECK_INIT_POINTER                                                                     STD_ON  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define PDUR_FINAL_MAGIC_NUMBER                                                                     0x331Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of PduR */
#define PDUR_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'PduR' is not configured to be postbuild capable. */
#define PDUR_INIT_DATA                                                                              PDUR_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define PDUR_INIT_DATA_HASH_CODE                                                                    -765311079  /**< the precompile constant to validate the initialization structure at initialization time of PduR with a hashcode. The seed value is '0x331Eu' */
#define PDUR_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define PDUR_USE_INIT_POINTER                                                                       STD_ON  /**< STD_ON if the init pointer PduR shall be used. */
#define PduR_PartitionIndexOfCSLForCommonSharedMemory                                               0u  /**< internal partition index of the ComStackLib for the partition CommonSharedMemory */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRLTDataSwitches  PduR Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_LTCONFIG                                                                               STD_OFF  /**< Deactivateable: 'PduR_LTConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define PDUR_LTPARTITIONCONFIGOFLTCONFIG                                                            STD_OFF  /**< Deactivateable: 'PduR_LTConfig.LTPartitionConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define PDUR_LTPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'PduR_LTPartitionConfigLeft' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_LTPartitionConfigRight' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/** BroadcastDummy */

#define PDUR_MAX_TRIGGER_TRANSMIT_PDU_SIZE 7

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCGetRootDataMacros  PduR Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define PduR_GetPCPartitionConfigOfPCConfig()                                                       PduR_ConfigDataPtr->PCPartitionConfigOfPCConfig
#define PduR_GetRmDestRomOfPCPartitionConfig()                                                      PduR_GetPCPartitionConfigOfPCConfig()[(0)].RmDestRomOfPCPartitionConfig
#define PduR_GetRmGDestRomOfPCPartitionConfig()                                                     PduR_GetPCPartitionConfigOfPCConfig()[(0)].RmGDestRomOfPCPartitionConfig
#define PduR_GetRmSrcRomOfPCPartitionConfig()                                                       PduR_GetPCPartitionConfigOfPCConfig()[(0)].RmSrcRomOfPCPartitionConfig
#define PduR_GetTxIf2UpOfPCPartitionConfig()                                                        PduR_GetPCPartitionConfigOfPCConfig()[(0)].TxIf2UpOfPCPartitionConfig
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetConstantDuplicatedRootDataMacros  PduR Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define PduR_GetPartitionIdentifiersOfPCConfig()                                                    PduR_PartitionIdentifiers  /**< the pointer to PduR_PartitionIdentifiers */
#define PduR_GetSizeOfPartitionIdentifiersOfPCConfig()                                              1u  /**< the number of accomplishable value elements in PduR_PartitionIdentifiers */
#define PduR_GetConfigIdOfPCPartitionConfig(partitionIndex)                                         0u  /**< DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRConfigurationId */
#define PduR_GetDestApplicationManagerRomOfPCPartitionConfig()                                      PduR_DestApplicationManagerRom  /**< the pointer to PduR_DestApplicationManagerRom */
#define PduR_GetExclusiveAreaRomOfPCPartitionConfig()                                               PduR_ExclusiveAreaRom  /**< the pointer to PduR_ExclusiveAreaRom */
#define PduR_GetGeneralPropertiesRomOfPCPartitionConfig()                                           PduR_GeneralPropertiesRom  /**< the pointer to PduR_GeneralPropertiesRom */
#define PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)                                   PduR_InitializedRam.raw  /**< the pointer to PduR_InitializedRam */
#define PduR_GetLockRomOfPCPartitionConfig()                                                        PduR_LockRom  /**< the pointer to PduR_LockRom */
#define PduR_GetMmRomOfPCPartitionConfig()                                                          PduR_MmRom  /**< the pointer to PduR_MmRom */
#define PduR_GetRmTransmitFctPtrOfPCPartitionConfig()                                               PduR_RmTransmitFctPtr  /**< the pointer to PduR_RmTransmitFctPtr */
#define PduR_GetRxIf2DestOfPCPartitionConfig()                                                      PduR_RxIf2Dest  /**< the pointer to PduR_RxIf2Dest */
#define PduR_GetRxTp2DestOfPCPartitionConfig()                                                      PduR_RxTp2Dest  /**< the pointer to PduR_RxTp2Dest */
#define PduR_GetSizeOfDestApplicationManagerRomOfPCPartitionConfig()                                1u  /**< the number of accomplishable value elements in PduR_DestApplicationManagerRom */
#define PduR_GetSizeOfExclusiveAreaRomOfPCPartitionConfig()                                         1u  /**< the number of accomplishable value elements in PduR_ExclusiveAreaRom */
#define PduR_GetSizeOfGeneralPropertiesRomOfPCPartitionConfig()                                     1u  /**< the number of accomplishable value elements in PduR_GeneralPropertiesRom */
#define PduR_GetSizeOfInitializedRamOfPCPartitionConfig(partitionIndex)                             1u  /**< the number of accomplishable value elements in PduR_InitializedRam */
#define PduR_GetSizeOfLockRomOfPCPartitionConfig()                                                  1u  /**< the number of accomplishable value elements in PduR_LockRom */
#define PduR_GetSizeOfMmRomOfPCPartitionConfig()                                                    7u  /**< the number of accomplishable value elements in PduR_MmRom */
#define PduR_GetSizeOfRmDestRomOfPCPartitionConfig()                                                55u  /**< the number of accomplishable value elements in PduR_RmDestRom */
#define PduR_GetSizeOfRmGDestRomOfPCPartitionConfig()                                               55u  /**< the number of accomplishable value elements in PduR_RmGDestRom */
#define PduR_GetSizeOfRmSrcRomOfPCPartitionConfig()                                                 55u  /**< the number of accomplishable value elements in PduR_RmSrcRom */
#define PduR_GetSizeOfRmTransmitFctPtrOfPCPartitionConfig()                                         2u  /**< the number of accomplishable value elements in PduR_RmTransmitFctPtr */
#define PduR_GetSizeOfRxIf2DestOfPCPartitionConfig()                                                38u  /**< the number of accomplishable value elements in PduR_RxIf2Dest */
#define PduR_GetSizeOfRxTp2DestOfPCPartitionConfig()                                                6u  /**< the number of accomplishable value elements in PduR_RxTp2Dest */
#define PduR_GetSizeOfSrcApplicationRomOfPCPartitionConfig()                                        1u  /**< the number of accomplishable value elements in PduR_SrcApplicationRom */
#define PduR_GetSizeOfTx2LoOfPCPartitionConfig()                                                    11u  /**< the number of accomplishable value elements in PduR_Tx2Lo */
#define PduR_GetSizeOfTxIf2UpOfPCPartitionConfig()                                                  8u  /**< the number of accomplishable value elements in PduR_TxIf2Up */
#define PduR_GetSizeOfTxTp2SrcOfPCPartitionConfig()                                                 3u  /**< the number of accomplishable value elements in PduR_TxTp2Src */
#define PduR_GetSrcApplicationRomOfPCPartitionConfig()                                              PduR_SrcApplicationRom  /**< the pointer to PduR_SrcApplicationRom */
#define PduR_GetTx2LoOfPCPartitionConfig()                                                          PduR_Tx2Lo  /**< the pointer to PduR_Tx2Lo */
#define PduR_GetTxTp2SrcOfPCPartitionConfig()                                                       PduR_TxTp2Src  /**< the pointer to PduR_TxTp2Src */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDataMacros  PduR Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define PduR_GetRmGDestRomStartIdxOfDestApplicationManagerRom(Index)                                (PduR_GetDestApplicationManagerRomOfPCPartitionConfig()[(Index)].RmGDestRomStartIdxOfDestApplicationManagerRom)
#define PduR_GetLockOfExclusiveAreaRom(Index)                                                       (PduR_GetExclusiveAreaRomOfPCPartitionConfig()[(Index)].LockOfExclusiveAreaRom)
#define PduR_GetUnlockOfExclusiveAreaRom(Index)                                                     (PduR_GetExclusiveAreaRomOfPCPartitionConfig()[(Index)].UnlockOfExclusiveAreaRom)
#define PduR_IshasIfRoutingOfGeneralPropertiesRom(Index)                                            ((PduR_GetGeneralPropertiesRomOfPCPartitionConfig()[(Index)].hasIfRoutingOfGeneralPropertiesRom) != FALSE)
#define PduR_IsInitializedRam(Index, partitionIndex)                                                ((PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define PduR_GetExclusiveAreaRomIdxOfLockRom(Index)                                                 (PduR_GetLockRomOfPCPartitionConfig()[(Index)].ExclusiveAreaRomIdxOfLockRom)
#define PduR_GetLoIfCancelTransmitFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoIfCancelTransmitFctPtrOfMmRom)
#define PduR_GetLoIfTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoIfTransmitFctPtrOfMmRom)
#define PduR_GetLoTpCancelTransmitFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoTpCancelTransmitFctPtrOfMmRom)
#define PduR_GetLoTpTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoTpTransmitFctPtrOfMmRom)
#define PduR_GetMaskedBitsOfMmRom(Index)                                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].MaskedBitsOfMmRom)
#define PduR_GetUpIfRxIndicationFctPtrOfMmRom(Index)                                                (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpIfRxIndicationFctPtrOfMmRom)
#define PduR_GetUpIfTriggerTransmitFctPtrOfMmRom(Index)                                             (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpIfTriggerTransmitFctPtrOfMmRom)
#define PduR_GetUpIfTxConfirmationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpIfTxConfirmationFctPtrOfMmRom)
#define PduR_GetUpTpCopyRxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpCopyRxDataFctPtrOfMmRom)
#define PduR_GetUpTpCopyTxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpCopyTxDataFctPtrOfMmRom)
#define PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpStartOfReceptionFctPtrOfMmRom)
#define PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpTpRxIndicationFctPtrOfMmRom)
#define PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpTpTxConfirmationFctPtrOfMmRom)
#define PduR_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (PduR_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define PduR_GetPduLengthHandlingStrategyOfRmDestRom(Index)                                         (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].PduLengthHandlingStrategyOfRmDestRom)
#define PduR_GetRmGDestRomIdxOfRmDestRom(Index)                                                     (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfRmDestRom)
#define PduR_GetRmSrcRomIdxOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RmSrcRomIdxOfRmDestRom)
#define PduR_GetRoutingTypeOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RoutingTypeOfRmDestRom)
#define PduR_GetDestHndOfRmGDestRom(Index)                                                          (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].DestHndOfRmGDestRom)
#define PduR_GetDirectionOfRmGDestRom(Index)                                                        (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].DirectionOfRmGDestRom)
#define PduR_GetLockRomIdxOfRmGDestRom(Index)                                                       (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].LockRomIdxOfRmGDestRom)
#define PduR_GetMaxPduLengthOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MaxPduLengthOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmGDestRom(Index)                                                         (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MmRomIdxOfRmGDestRom)
#define PduR_GetRmDestRomIdxOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].RmDestRomIdxOfRmGDestRom)
#define PduR_GetLockRomIdxOfRmSrcRom(Index)                                                         (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].LockRomIdxOfRmSrcRom)
#define PduR_GetMaskedBitsOfRmSrcRom(Index)                                                         (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].MaskedBitsOfRmSrcRom)
#define PduR_GetMmRomIdxOfRmSrcRom(Index)                                                           (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].MmRomIdxOfRmSrcRom)
#define PduR_GetRmDestRomStartIdxOfRmSrcRom(Index)                                                  (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].RmDestRomStartIdxOfRmSrcRom)
#define PduR_GetSrcHndOfRmSrcRom(Index)                                                             (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].SrcHndOfRmSrcRom)
#define PduR_GetRmTransmitFctPtr(Index)                                                             (PduR_GetRmTransmitFctPtrOfPCPartitionConfig()[(Index)])
#define PduR_IsCancelTransmitUsedOfTx2Lo(Index)                                                     ((PduR_GetTx2LoOfPCPartitionConfig()[(Index)].CancelTransmitUsedOfTx2Lo) != FALSE)
#define PduR_GetRmSrcRomIdxOfTx2Lo(Index)                                                           (PduR_GetTx2LoOfPCPartitionConfig()[(Index)].RmSrcRomIdxOfTx2Lo)
#define PduR_GetRmTransmitFctPtrIdxOfTx2Lo(Index)                                                   (PduR_GetTx2LoOfPCPartitionConfig()[(Index)].RmTransmitFctPtrIdxOfTx2Lo)
#define PduR_GetRmGDestRomIdxOfTxIf2Up(Index)                                                       (PduR_GetTxIf2UpOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfTxIf2Up)
#define PduR_IsTxConfirmationUsedOfTxIf2Up(Index)                                                   ((PduR_GetTxIf2UpOfPCPartitionConfig()[(Index)].TxConfirmationUsedOfTxIf2Up) != FALSE)
#define PduR_GetRmGDestRomIdxOfTxTp2Src(Index)                                                      (PduR_GetTxTp2SrcOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfTxTp2Src)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetBitDataMacros  PduR Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define PduR_IsTpCancelTransmitSupportedOfMmRom(Index)                                              (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM_MASK == (PduR_GetMaskedBitsOfMmRom(Index) & PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM_MASK))  /**< Does the module support the transport protocol CancelTransmit API. */
#define PduR_IsUpIfOfMmRom(Index)                                                                   (PDUR_UPIFOFMMROM_MASK == (PduR_GetMaskedBitsOfMmRom(Index) & PDUR_UPIFOFMMROM_MASK))  /**< Is the module a upper communication interface module. */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDeduplicatedDataMacros  PduR Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define PduR_GetConfigId(partitionIndex)                                                            PduR_GetConfigIdOfPCPartitionConfig(partitionIndex)
#define PduR_GetInitializedIdxOfDestApplicationManagerRom(Index)                                    ((PduR_InitializedIdxOfDestApplicationManagerRomType)((Index)))  /**< the index of the 1:1 relation pointing to one of PduR_InitializedRam */
#define PduR_GetInitializedPartitionIdxOfDestApplicationManagerRom(Index)                           ((PduR_InitializedPartitionIdxOfDestApplicationManagerRomType)((Index)))  /**< the partition index of the 1:1 relation pointing to one of PduR_InitializedRam */
#define PduR_GetRmGDestRomEndIdxOfDestApplicationManagerRom(Index)                                  ((PduR_RmGDestRomEndIdxOfDestApplicationManagerRomType)((((PduR_RmGDestRomEndIdxOfDestApplicationManagerRomType)(Index)) + 55u)))  /**< the end index of the 0:n relation pointing to PduR_RmGDestRom */
#define PduR_IsRmGDestRomUsedOfDestApplicationManagerRom(Index)                                     (((boolean)(PduR_GetRmGDestRomStartIdxOfDestApplicationManagerRom(Index) != PDUR_NO_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to PduR_RmGDestRom */
#define PduR_GetSrcApplicationRomEndIdxOfDestApplicationManagerRom(Index)                           ((PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType)((((PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_SrcApplicationRom */
#define PduR_GetSrcApplicationRomStartIdxOfDestApplicationManagerRom(Index)                         ((PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_SrcApplicationRom */
#define PduR_IsExclusiveAreaRomUsedOfLockRom(Index)                                                 (((boolean)(PduR_GetExclusiveAreaRomIdxOfLockRom(Index) != PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_ExclusiveAreaRom */
#define PduR_IsIfCancelTransmitSupportedOfMmRom(Index)                                              (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x30u)) != FALSE)  /**< Does the module support the Communication Interface CancelTransmit API. */
#define PduR_IsLoIfOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) >= 0x0Du)) != FALSE)  /**< Is the module a lower communication interface module. */
#define PduR_IsLoTpOfMmRom(Index)                                                                   PduR_IsTpCancelTransmitSupportedOfMmRom(Index)  /**< Is the module a lower transport protocol module. */
#define PduR_IsUpTpOfMmRom(Index)                                                                   (((boolean)(PduR_GetMaskedBitsOfMmRom(Index) == 0x01u)) != FALSE)  /**< Is the module a upper transport protocol module. */
#define PduR_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   ((PduR_PCPartitionConfigIdxOfPartitionIdentifiersType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_PCPartitionConfig */
#define PduR_GetDestApplicationManagerRomIdxOfRmGDestRom(Index)                                     PduR_GetLockRomIdxOfRmGDestRom(Index)  /**< the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom */
#define PduR_GetPduRDestPduProcessingOfRmGDestRom(Index)                                            ((PduR_PduRDestPduProcessingOfRmGDestRomType)((PduR_GetLockRomIdxOfRmGDestRom(Index) + 1u)))  /**< Is Processing Type of destination PDU. */
#define PduR_GetTxIf2UpIdxOfRmGDestRom(Index)                                                       PduR_GetLockRomIdxOfRmGDestRom(Index)  /**< TxIf2Up index. */
#define PduR_GetDestApplicationManagerRomIdxOfRmSrcRom(Index)                                       PduR_GetLockRomIdxOfRmSrcRom(Index)  /**< the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom */
#define PduR_GetRmDestRomEndIdxOfRmSrcRom(Index)                                                    ((PduR_RmDestRomEndIdxOfRmSrcRomType)((PduR_GetRmDestRomStartIdxOfRmSrcRom(Index) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_RmDestRom */
#define PduR_GetRmDestRomLengthOfRmSrcRom(Index)                                                    ((PduR_RmDestRomLengthOfRmSrcRomType)((PduR_GetLockRomIdxOfRmSrcRom(Index) + 1u)))  /**< the number of relations pointing to PduR_RmDestRom */
#define PduR_IsTriggerTransmitSupportedOfRmSrcRom(Index)                                            (((boolean)(PduR_GetMaskedBitsOfRmSrcRom(Index) == 0x03u)) != FALSE)
#define PduR_IsTxConfirmationSupportedOfRmSrcRom(Index)                                             (((boolean)(PduR_GetMaskedBitsOfRmSrcRom(Index) != 0x00u)) != FALSE)
#define PduR_GetRmSrcRomIdxOfRxIf2Dest(Index)                                                       ((PduR_RmSrcRomIdxOfRxIf2DestType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
#define PduR_GetRmSrcRomIdxOfRxTp2Dest(Index)                                                       ((PduR_RmSrcRomIdxOfRxTp2DestType)((((PduR_RmSrcRomIdxOfRxTp2DestType)(Index)) + 38u)))  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
#define PduR_GetSizeOfDestApplicationManagerRom()                                                   PduR_GetSizeOfDestApplicationManagerRomOfPCPartitionConfig()
#define PduR_GetSizeOfExclusiveAreaRom()                                                            PduR_GetSizeOfExclusiveAreaRomOfPCPartitionConfig()
#define PduR_GetSizeOfGeneralPropertiesRom()                                                        PduR_GetSizeOfGeneralPropertiesRomOfPCPartitionConfig()
#define PduR_GetSizeOfInitializedRam(partitionIndex)                                                PduR_GetSizeOfInitializedRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfLockRom()                                                                     PduR_GetSizeOfLockRomOfPCPartitionConfig()
#define PduR_GetSizeOfMmRom()                                                                       PduR_GetSizeOfMmRomOfPCPartitionConfig()
#define PduR_GetSizeOfPartitionIdentifiers()                                                        PduR_GetSizeOfPartitionIdentifiersOfPCConfig()
#define PduR_GetSizeOfRmDestRom()                                                                   PduR_GetSizeOfRmDestRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmGDestRom()                                                                  PduR_GetSizeOfRmGDestRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmSrcRom()                                                                    PduR_GetSizeOfRmSrcRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmTransmitFctPtr()                                                            PduR_GetSizeOfRmTransmitFctPtrOfPCPartitionConfig()
#define PduR_GetSizeOfRxIf2Dest()                                                                   PduR_GetSizeOfRxIf2DestOfPCPartitionConfig()
#define PduR_GetSizeOfRxTp2Dest()                                                                   PduR_GetSizeOfRxTp2DestOfPCPartitionConfig()
#define PduR_GetSizeOfSrcApplicationRom()                                                           PduR_GetSizeOfSrcApplicationRomOfPCPartitionConfig()
#define PduR_GetSizeOfTx2Lo()                                                                       PduR_GetSizeOfTx2LoOfPCPartitionConfig()
#define PduR_GetSizeOfTxIf2Up()                                                                     PduR_GetSizeOfTxIf2UpOfPCPartitionConfig()
#define PduR_GetSizeOfTxTp2Src()                                                                    PduR_GetSizeOfTxTp2SrcOfPCPartitionConfig()
#define PduR_GetDeferredEventCacheRomPartitionIdxOfSrcApplicationRom(Index)                         ((PduR_DeferredEventCacheRomPartitionIdxOfSrcApplicationRomType)((Index)))  /**< the partition index of the 0:1 relation pointing to PduR_DeferredEventCacheRom */
#define PduR_IsRmSrcRomUsedOfTx2Lo(Index)                                                           (((boolean)(PduR_GetRmSrcRomIdxOfTx2Lo(Index) != PDUR_NO_RMSRCROMIDXOFTX2LO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmSrcRom */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSetDataMacros  PduR Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define PduR_SetInitializedRam(Index, Value, partitionIndex)                                        PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetAddressOfDataMacros  PduR Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define PduR_GetAddrInitializedRam(Index, partitionIndex)                                           (&(PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)[(Index)]))
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCHasMacros  PduR Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasConfigId(partitionIndex)                                                            (TRUE != FALSE)
#define PduR_HasDestApplicationManagerRom()                                                         (TRUE != FALSE)
#define PduR_HasInitializedIdxOfDestApplicationManagerRom()                                         (TRUE != FALSE)
#define PduR_HasInitializedPartitionIdxOfDestApplicationManagerRom()                                (TRUE != FALSE)
#define PduR_HasRmGDestRomEndIdxOfDestApplicationManagerRom()                                       (TRUE != FALSE)
#define PduR_HasRmGDestRomStartIdxOfDestApplicationManagerRom()                                     (TRUE != FALSE)
#define PduR_HasRmGDestRomUsedOfDestApplicationManagerRom()                                         (TRUE != FALSE)
#define PduR_HasSrcApplicationRomEndIdxOfDestApplicationManagerRom()                                (TRUE != FALSE)
#define PduR_HasSrcApplicationRomStartIdxOfDestApplicationManagerRom()                              (TRUE != FALSE)
#define PduR_HasExclusiveAreaRom()                                                                  (TRUE != FALSE)
#define PduR_HasLockOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasUnlockOfExclusiveAreaRom()                                                          (TRUE != FALSE)
#define PduR_HasGeneralPropertiesRom()                                                              (TRUE != FALSE)
#define PduR_HashasIfRoutingOfGeneralPropertiesRom()                                                (TRUE != FALSE)
#define PduR_HasInitializedRam(partitionIndex)                                                      (TRUE != FALSE)
#define PduR_HasLockRom()                                                                           (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomIdxOfLockRom()                                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomUsedOfLockRom()                                                     (TRUE != FALSE)
#define PduR_HasMmRom()                                                                             (TRUE != FALSE)
#define PduR_HasIfCancelTransmitSupportedOfMmRom()                                                  (TRUE != FALSE)
#define PduR_HasLoIfCancelTransmitFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasLoIfOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoIfTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasLoTpCancelTransmitFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasLoTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoTpTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasMaskedBitsOfMmRom()                                                                 (TRUE != FALSE)
#define PduR_HasTpCancelTransmitSupportedOfMmRom()                                                  (TRUE != FALSE)
#define PduR_HasUpIfOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpIfRxIndicationFctPtrOfMmRom()                                                     (TRUE != FALSE)
#define PduR_HasUpIfTriggerTransmitFctPtrOfMmRom()                                                  (TRUE != FALSE)
#define PduR_HasUpIfTxConfirmationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpCopyRxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpCopyTxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpTpStartOfReceptionFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasUpTpTpRxIndicationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpTpTxConfirmationFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define PduR_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define PduR_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define PduR_HasRmDestRom()                                                                         (PduR_GetRmDestRomOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasPduLengthHandlingStrategyOfRmDestRom()                                              (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfRmDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRoutingTypeOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmGDestRom()                                                                        (PduR_GetRmGDestRomOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasDestApplicationManagerRomIdxOfRmGDestRom()                                          (TRUE != FALSE)
#define PduR_HasDestHndOfRmGDestRom()                                                               (TRUE != FALSE)
#define PduR_HasDirectionOfRmGDestRom()                                                             (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasMaxPduLengthOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmGDestRom()                                                              (TRUE != FALSE)
#define PduR_HasPduRDestPduProcessingOfRmGDestRom()                                                 (TRUE != FALSE)
#define PduR_HasRmDestRomIdxOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasTxIf2UpIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmSrcRom()                                                                          (PduR_GetRmSrcRomOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasDestApplicationManagerRomIdxOfRmSrcRom()                                            (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmSrcRom()                                                              (TRUE != FALSE)
#define PduR_HasMaskedBitsOfRmSrcRom()                                                              (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmSrcRom()                                                                (TRUE != FALSE)
#define PduR_HasRmDestRomEndIdxOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomLengthOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomStartIdxOfRmSrcRom()                                                       (TRUE != FALSE)
#define PduR_HasSrcHndOfRmSrcRom()                                                                  (TRUE != FALSE)
#define PduR_HasTriggerTransmitSupportedOfRmSrcRom()                                                (TRUE != FALSE)
#define PduR_HasTxConfirmationSupportedOfRmSrcRom()                                                 (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtr()                                                                  (TRUE != FALSE)
#define PduR_HasRxIf2Dest()                                                                         (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRxIf2Dest()                                                            (TRUE != FALSE)
#define PduR_HasRxTp2Dest()                                                                         (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRxTp2Dest()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfDestApplicationManagerRom()                                                   (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfGeneralPropertiesRom()                                                        (TRUE != FALSE)
#define PduR_HasSizeOfInitializedRam(partitionIndex)                                                (TRUE != FALSE)
#define PduR_HasSizeOfLockRom()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRom()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRom()                                                                  (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRom()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtr()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfRxIf2Dest()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Dest()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfSrcApplicationRom()                                                           (TRUE != FALSE)
#define PduR_HasSizeOfTx2Lo()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2Up()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2Src()                                                                    (TRUE != FALSE)
#define PduR_HasSrcApplicationRom()                                                                 (TRUE != FALSE)
#define PduR_HasDeferredEventCacheRomPartitionIdxOfSrcApplicationRom()                              (TRUE != FALSE)
#define PduR_HasTx2Lo()                                                                             (TRUE != FALSE)
#define PduR_HasCancelTransmitUsedOfTx2Lo()                                                         (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfTx2Lo()                                                                (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfTx2Lo()                                                               (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrIdxOfTx2Lo()                                                        (TRUE != FALSE)
#define PduR_HasTxIf2Up()                                                                           (PduR_GetTxIf2UpOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasRmGDestRomIdxOfTxIf2Up()                                                            (TRUE != FALSE)
#define PduR_HasTxConfirmationUsedOfTxIf2Up()                                                       (TRUE != FALSE)
#define PduR_HasTxTp2Src()                                                                          (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfTxTp2Src()                                                           (TRUE != FALSE)
#define PduR_HasPCConfig()                                                                          (TRUE != FALSE)
#define PduR_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define PduR_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define PduR_HasPCPartitionConfig()                                                                 (PduR_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define PduR_HasConfigIdOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define PduR_HasDestApplicationManagerRomOfPCPartitionConfig()                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasGeneralPropertiesRomOfPCPartitionConfig()                                           (TRUE != FALSE)
#define PduR_HasInitializedRamOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define PduR_HasLockRomOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define PduR_HasMmRomOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define PduR_HasRmDestRomOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasRmGDestRomOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define PduR_HasRmSrcRomOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasRxIf2DestOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasRxTp2DestOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasSizeOfDestApplicationManagerRomOfPCPartitionConfig()                                (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRomOfPCPartitionConfig()                                         (TRUE != FALSE)
#define PduR_HasSizeOfGeneralPropertiesRomOfPCPartitionConfig()                                     (TRUE != FALSE)
#define PduR_HasSizeOfInitializedRamOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define PduR_HasSizeOfLockRomOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfMmRomOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRomOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRomOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRomOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtrOfPCPartitionConfig()                                         (TRUE != FALSE)
#define PduR_HasSizeOfRxIf2DestOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2DestOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfSrcApplicationRomOfPCPartitionConfig()                                        (TRUE != FALSE)
#define PduR_HasSizeOfTx2LoOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2UpOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2SrcOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSrcApplicationRomOfPCPartitionConfig()                                              (TRUE != FALSE)
#define PduR_HasTx2LoOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define PduR_HasTxIf2UpOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define PduR_HasTxTp2SrcOfPCPartitionConfig()                                                       (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


#define PduR_IsPreInitialized()                     (PduR_PreInitialized != FALSE)
#define PduR_SetPreInitialized(Value)               (PduR_IsPreInitialized()) = (Value)

#define CommonSharedMemory  0u /* Dummy symbolic name value for the shared memory memory section */

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef P2FUNC(void, PDUR_CODE, PduR_LockFunctionType) (void);    /* PRQA S 1336 */ /* MD_PduR_1336 */

/* Communication Interface APIs */

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType);    /* PRQA S 1336 */ /* MD_PduR_1336 */

/* Transport Protocol APIs */
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType, Std_ReturnType);    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType, Std_ReturnType);    /* PRQA S 1336 */ /* MD_PduR_1336 */


#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif
#if (PDUR_CANCELRECEIVESUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelReceiveFctPtrType) (PduIdType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif
#if (PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_ChangeParameterFctPtrType) (PduIdType, TPParameterType, uint16);    /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCIterableTypes  PduR Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate PduR_DestApplicationManagerRom */
typedef uint8_least PduR_DestApplicationManagerRomIterType;

/**   \brief  type used to iterate PduR_ExclusiveAreaRom */
typedef uint8_least PduR_ExclusiveAreaRomIterType;

/**   \brief  type used to iterate PduR_GeneralPropertiesRom */
typedef uint8_least PduR_GeneralPropertiesRomIterType;

/**   \brief  type used to iterate PduR_InitializedRam */
typedef uint8_least PduR_InitializedRamIterType;

/**   \brief  type used to iterate PduR_LockRom */
typedef uint8_least PduR_LockRomIterType;

/**   \brief  type used to iterate PduR_MmRom */
typedef uint8_least PduR_MmRomIterType;

/**   \brief  type used to iterate PduR_PartitionIdentifiers */
typedef uint8_least PduR_PartitionIdentifiersIterType;

/**   \brief  type used to iterate PduR_RmDestRom */
typedef uint8_least PduR_RmDestRomIterType;

/**   \brief  type used to iterate PduR_RmGDestRom */
typedef uint8_least PduR_RmGDestRomIterType;

/**   \brief  type used to iterate PduR_RmSrcRom */
typedef uint8_least PduR_RmSrcRomIterType;

/**   \brief  type used to iterate PduR_RmTransmitFctPtr */
typedef uint8_least PduR_RmTransmitFctPtrIterType;

/**   \brief  type used to iterate PduR_RxIf2Dest */
typedef uint8_least PduR_RxIf2DestIterType;

/**   \brief  type used to iterate PduR_RxTp2Dest */
typedef uint8_least PduR_RxTp2DestIterType;

/**   \brief  type used to iterate PduR_SrcApplicationRom */
typedef uint8_least PduR_SrcApplicationRomIterType;

/**   \brief  type used to iterate PduR_Tx2Lo */
typedef uint8_least PduR_Tx2LoIterType;

/**   \brief  type used to iterate PduR_TxIf2Up */
typedef uint8_least PduR_TxIf2UpIterType;

/**   \brief  type used to iterate PduR_TxTp2Src */
typedef uint8_least PduR_TxTp2SrcIterType;

/**   \brief  type used to iterate PduR_PCPartitionConfig */
typedef uint8_least PduR_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCValueTypes  PduR Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for PduR_ConfigId */
typedef uint8 PduR_ConfigIdType;

/**   \brief  value based type definition for PduR_InitializedIdxOfDestApplicationManagerRom */
typedef uint8 PduR_InitializedIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_InitializedPartitionIdxOfDestApplicationManagerRom */
typedef uint8 PduR_InitializedPartitionIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_RmGDestRomEndIdxOfDestApplicationManagerRom */
typedef uint8 PduR_RmGDestRomEndIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_RmGDestRomStartIdxOfDestApplicationManagerRom */
typedef uint8 PduR_RmGDestRomStartIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_RmGDestRomUsedOfDestApplicationManagerRom */
typedef boolean PduR_RmGDestRomUsedOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRom */
typedef uint8 PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRom */
typedef uint8 PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_hasIfRoutingOfGeneralPropertiesRom */
typedef boolean PduR_hasIfRoutingOfGeneralPropertiesRomType;

/**   \brief  value based type definition for PduR_InitializedRam */
typedef boolean PduR_InitializedRamType;

/**   \brief  value based type definition for PduR_ExclusiveAreaRomIdxOfLockRom */
typedef uint8 PduR_ExclusiveAreaRomIdxOfLockRomType;

/**   \brief  value based type definition for PduR_ExclusiveAreaRomUsedOfLockRom */
typedef boolean PduR_ExclusiveAreaRomUsedOfLockRomType;

/**   \brief  value based type definition for PduR_IfCancelTransmitSupportedOfMmRom */
typedef boolean PduR_IfCancelTransmitSupportedOfMmRomType;

/**   \brief  value based type definition for PduR_LoIfOfMmRom */
typedef boolean PduR_LoIfOfMmRomType;

/**   \brief  value based type definition for PduR_LoTpOfMmRom */
typedef boolean PduR_LoTpOfMmRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfMmRom */
typedef uint8 PduR_MaskedBitsOfMmRomType;

/**   \brief  value based type definition for PduR_TpCancelTransmitSupportedOfMmRom */
typedef boolean PduR_TpCancelTransmitSupportedOfMmRomType;

/**   \brief  value based type definition for PduR_UpIfOfMmRom */
typedef boolean PduR_UpIfOfMmRomType;

/**   \brief  value based type definition for PduR_UpTpOfMmRom */
typedef boolean PduR_UpTpOfMmRomType;

/**   \brief  value based type definition for PduR_PCPartitionConfigIdxOfPartitionIdentifiers */
typedef uint8 PduR_PCPartitionConfigIdxOfPartitionIdentifiersType;

/**   \brief  value based type definition for PduR_PartitionSNVOfPartitionIdentifiers */
typedef uint32 PduR_PartitionSNVOfPartitionIdentifiersType;

/**   \brief  value based type definition for PduR_PduLengthHandlingStrategyOfRmDestRom */
typedef uint8 PduR_PduLengthHandlingStrategyOfRmDestRomType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfRmDestRom */
typedef uint8 PduR_RmGDestRomIdxOfRmDestRomType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRmDestRom */
typedef uint8 PduR_RmSrcRomIdxOfRmDestRomType;

/**   \brief  value based type definition for PduR_RoutingTypeOfRmDestRom */
typedef uint8 PduR_RoutingTypeOfRmDestRomType;

/**   \brief  value based type definition for PduR_DestApplicationManagerRomIdxOfRmGDestRom */
typedef uint8 PduR_DestApplicationManagerRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_DestHndOfRmGDestRom */
typedef uint8 PduR_DestHndOfRmGDestRomType;

/**   \brief  value based type definition for PduR_DirectionOfRmGDestRom */
typedef uint8 PduR_DirectionOfRmGDestRomType;

/**   \brief  value based type definition for PduR_LockRomIdxOfRmGDestRom */
typedef uint8 PduR_LockRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MaxPduLengthOfRmGDestRom */
typedef uint16 PduR_MaxPduLengthOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MmRomIdxOfRmGDestRom */
typedef uint8 PduR_MmRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_PduRDestPduProcessingOfRmGDestRom */
typedef uint8 PduR_PduRDestPduProcessingOfRmGDestRomType;

/**   \brief  value based type definition for PduR_RmDestRomIdxOfRmGDestRom */
typedef uint8 PduR_RmDestRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_TxIf2UpIdxOfRmGDestRom */
typedef uint8 PduR_TxIf2UpIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_DestApplicationManagerRomIdxOfRmSrcRom */
typedef uint8 PduR_DestApplicationManagerRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_LockRomIdxOfRmSrcRom */
typedef uint8 PduR_LockRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfRmSrcRom */
typedef uint8 PduR_MaskedBitsOfRmSrcRomType;

/**   \brief  value based type definition for PduR_MmRomIdxOfRmSrcRom */
typedef uint8 PduR_MmRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomEndIdxOfRmSrcRom */
typedef uint8 PduR_RmDestRomEndIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomLengthOfRmSrcRom */
typedef uint8 PduR_RmDestRomLengthOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomStartIdxOfRmSrcRom */
typedef uint8 PduR_RmDestRomStartIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_SrcHndOfRmSrcRom */
typedef uint8 PduR_SrcHndOfRmSrcRomType;

/**   \brief  value based type definition for PduR_TriggerTransmitSupportedOfRmSrcRom */
typedef boolean PduR_TriggerTransmitSupportedOfRmSrcRomType;

/**   \brief  value based type definition for PduR_TxConfirmationSupportedOfRmSrcRom */
typedef boolean PduR_TxConfirmationSupportedOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRxIf2Dest */
typedef uint8 PduR_RmSrcRomIdxOfRxIf2DestType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRxTp2Dest */
typedef uint8 PduR_RmSrcRomIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfDestApplicationManagerRom */
typedef uint8 PduR_SizeOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SizeOfExclusiveAreaRom */
typedef uint8 PduR_SizeOfExclusiveAreaRomType;

/**   \brief  value based type definition for PduR_SizeOfGeneralPropertiesRom */
typedef uint8 PduR_SizeOfGeneralPropertiesRomType;

/**   \brief  value based type definition for PduR_SizeOfInitializedRam */
typedef uint8 PduR_SizeOfInitializedRamType;

/**   \brief  value based type definition for PduR_SizeOfLockRom */
typedef uint8 PduR_SizeOfLockRomType;

/**   \brief  value based type definition for PduR_SizeOfMmRom */
typedef uint8 PduR_SizeOfMmRomType;

/**   \brief  value based type definition for PduR_SizeOfPartitionIdentifiers */
typedef uint8 PduR_SizeOfPartitionIdentifiersType;

/**   \brief  value based type definition for PduR_SizeOfRmDestRom */
typedef uint8 PduR_SizeOfRmDestRomType;

/**   \brief  value based type definition for PduR_SizeOfRmGDestRom */
typedef uint8 PduR_SizeOfRmGDestRomType;

/**   \brief  value based type definition for PduR_SizeOfRmSrcRom */
typedef uint8 PduR_SizeOfRmSrcRomType;

/**   \brief  value based type definition for PduR_SizeOfRmTransmitFctPtr */
typedef uint8 PduR_SizeOfRmTransmitFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfRxIf2Dest */
typedef uint8 PduR_SizeOfRxIf2DestType;

/**   \brief  value based type definition for PduR_SizeOfRxTp2Dest */
typedef uint8 PduR_SizeOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfSrcApplicationRom */
typedef uint8 PduR_SizeOfSrcApplicationRomType;

/**   \brief  value based type definition for PduR_SizeOfTx2Lo */
typedef uint8 PduR_SizeOfTx2LoType;

/**   \brief  value based type definition for PduR_SizeOfTxIf2Up */
typedef uint8 PduR_SizeOfTxIf2UpType;

/**   \brief  value based type definition for PduR_SizeOfTxTp2Src */
typedef uint8 PduR_SizeOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_DeferredEventCacheRomPartitionIdxOfSrcApplicationRom */
typedef uint8 PduR_DeferredEventCacheRomPartitionIdxOfSrcApplicationRomType;

/**   \brief  value based type definition for PduR_CancelTransmitUsedOfTx2Lo */
typedef boolean PduR_CancelTransmitUsedOfTx2LoType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfTx2Lo */
typedef uint8 PduR_RmSrcRomIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmSrcRomUsedOfTx2Lo */
typedef boolean PduR_RmSrcRomUsedOfTx2LoType;

/**   \brief  value based type definition for PduR_RmTransmitFctPtrIdxOfTx2Lo */
typedef uint8 PduR_RmTransmitFctPtrIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfTxIf2Up */
typedef uint8 PduR_RmGDestRomIdxOfTxIf2UpType;

/**   \brief  value based type definition for PduR_TxConfirmationUsedOfTxIf2Up */
typedef boolean PduR_TxConfirmationUsedOfTxIf2UpType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfTxTp2Src */
typedef uint8 PduR_RmGDestRomIdxOfTxTp2SrcType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_RmTransmitFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */

/* Queue abstraction layer */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_QAL_PutFctPtrType)          (PduR_RmGDestRomIterType, PduR_RmDestRomIterType, PduLengthType, SduDataPtrType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_QAL_GetFctPtrType)          (PduR_RmGDestRomIterType, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void,           PDUR_APPL_CODE, PduR_QAL_RemoveFctPtrType)       (PduR_RmGDestRomIterType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(uint16,         PDUR_APPL_CODE, PduR_QAL_GetFillLevelFctPtrType) (PduR_RmGDestRomIterType);    /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void,           PDUR_APPL_CODE, PduR_QAL_FlushFctPtrType)        (PduR_RmGDestRomIterType);    /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef P2FUNC(void, PDUR_CODE, PduR_RmIf_TxConfirmation_StateHandler_FctPtrType) (PduR_RmGDestRomIterType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_CODE, PduR_RmIf_FifoHandling_StateHandler_FctPtrType) (PduR_RmDestRomIterType, PduR_RmGDestRomIdxOfRmDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));  /* PRQA S 1336 */ /* MD_PduR_1336 */

typedef uint8 PduR_MemIdxType;

#if(PDUR_SMDATAPLANEROM == STD_ON)
typedef uint8 PduR_FilterReturnType;
# define PDUR_FILTER_PASS  0u
# define PDUR_FILTER_BLOCK 1u

typedef uint32 PduR_SmSaType;
typedef uint32 PduR_SmTaType;

#define PDUR_SM_UNLEARNED_CONNECTION 0u
typedef P2FUNC(PduR_SmSaType, PDUR_CODE, PduR_Sm_LinearTaToSaCalculationStrategy_GetSaFctPtrType) (PduR_SmLinearTaToSaCalculationStrategyRomIterType, uint32, PduR_MemIdxType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(void, PDUR_CODE, PduR_Sm_SrcFilterFctPtrType) (PduR_SmSrcRomIdxOfRmSrcRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduR_MemIdxType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
typedef P2FUNC(PduR_FilterReturnType, PDUR_CODE, PduR_Sm_DestFilterFctPtrType) (PduR_SmGDestRomIdxOfRmGDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduR_MemIdxType);  /* PRQA S 1336 */ /* MD_PduR_1336 */
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCStructTypes  PduR Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in PduR_DestApplicationManagerRom */
typedef struct sPduR_DestApplicationManagerRomType
{
  PduR_RmGDestRomStartIdxOfDestApplicationManagerRomType RmGDestRomStartIdxOfDestApplicationManagerRom;  /**< the start index of the 0:n relation pointing to PduR_RmGDestRom */
} PduR_DestApplicationManagerRomType;

/**   \brief  type used in PduR_ExclusiveAreaRom */
typedef struct sPduR_ExclusiveAreaRomType
{
  PduR_LockFunctionType LockOfExclusiveAreaRom;  /**< Lock function */
  PduR_LockFunctionType UnlockOfExclusiveAreaRom;  /**< Unlock function */
} PduR_ExclusiveAreaRomType;

/**   \brief  type used in PduR_GeneralPropertiesRom */
typedef struct sPduR_GeneralPropertiesRomType
{
  PduR_hasIfRoutingOfGeneralPropertiesRomType hasIfRoutingOfGeneralPropertiesRom;
} PduR_GeneralPropertiesRomType;

/**   \brief  type used in PduR_LockRom */
typedef struct sPduR_LockRomType
{
  PduR_ExclusiveAreaRomIdxOfLockRomType ExclusiveAreaRomIdxOfLockRom;  /**< the index of the 0:1 relation pointing to PduR_ExclusiveAreaRom */
} PduR_LockRomType;

/**   \brief  type used in PduR_MmRom */
typedef struct sPduR_MmRomType
{
  PduR_MaskedBitsOfMmRomType MaskedBitsOfMmRom;  /**< contains bitcoded the boolean data of PduR_IfCancelTransmitSupportedOfMmRom, PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_TpCancelTransmitSupportedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom */
  PduR_CancelTransmitFctPtrType LoIfCancelTransmitFctPtrOfMmRom;  /**< Lower layer cancel transmit function pointers. */
  PduR_CancelTransmitFctPtrType LoTpCancelTransmitFctPtrOfMmRom;  /**< Lower layer cancel transmit function pointers. */
  PduR_CopyRxDataFctPtrType UpTpCopyRxDataFctPtrOfMmRom;  /**< Transport protocol CopyRxData function pointers */
  PduR_CopyTxDataFctPtrType UpTpCopyTxDataFctPtrOfMmRom;  /**< Transport protocol CopyTxData function pointers */
  PduR_IfRxIndicationType UpIfRxIndicationFctPtrOfMmRom;  /**< Upper layer communication interface Rx indication function pointers. */
  PduR_IfTxConfirmationFctPtrType UpIfTxConfirmationFctPtrOfMmRom;  /**< Upper layer communication interface Tx confimation function pointers */
  PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFctPtrOfMmRom;  /**< Transport protocol StartOfReception function pointers */
  PduR_TpRxIndicationFctPtrType UpTpTpRxIndicationFctPtrOfMmRom;  /**< Transport protocol TpRxIndication function pointers */
  PduR_TpTxConfirmationFctPtrType UpTpTpTxConfirmationFctPtrOfMmRom;  /**< Transport protocol TpTxConfimation function pointers */
  PduR_TransmitFctPtrType LoIfTransmitFctPtrOfMmRom;  /**< Lower layer If transmit function pointers */
  PduR_TransmitFctPtrType LoTpTransmitFctPtrOfMmRom;  /**< Lower layer Tp transmit function pointers */
  PduR_TriggerTransmitFctPtrType UpIfTriggerTransmitFctPtrOfMmRom;  /**< Upper layer trigger transmit function pointers */
} PduR_MmRomType;

/**   \brief  type used in PduR_PartitionIdentifiers */
typedef struct sPduR_PartitionIdentifiersType
{
  PduR_PartitionSNVOfPartitionIdentifiersType PartitionSNVOfPartitionIdentifiers;
} PduR_PartitionIdentifiersType;

/**   \brief  type used in PduR_RmDestRom */
typedef struct sPduR_RmDestRomType
{
  PduR_PduLengthHandlingStrategyOfRmDestRomType PduLengthHandlingStrategyOfRmDestRom;  /**< The strategy how larger than configured If Pdus are handled. */
  PduR_RmGDestRomIdxOfRmDestRomType RmGDestRomIdxOfRmDestRom;  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
  PduR_RmSrcRomIdxOfRmDestRomType RmSrcRomIdxOfRmDestRom;  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
  PduR_RoutingTypeOfRmDestRomType RoutingTypeOfRmDestRom;  /**< Type of the Routing (API Forwarding, Gateway). */
} PduR_RmDestRomType;

/**   \brief  type used in PduR_RmGDestRom */
typedef struct sPduR_RmGDestRomType
{
  PduR_MaxPduLengthOfRmGDestRomType MaxPduLengthOfRmGDestRom;  /**< Configured PduLength + metadata length. */
  PduR_DestHndOfRmGDestRomType DestHndOfRmGDestRom;  /**< handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call. */
  PduR_DirectionOfRmGDestRomType DirectionOfRmGDestRom;  /**< Direction of this Pdu: Rx or Tx */
  PduR_LockRomIdxOfRmGDestRomType LockRomIdxOfRmGDestRom;  /**< the index of the 1:1 relation pointing to PduR_LockRom */
  PduR_MmRomIdxOfRmGDestRomType MmRomIdxOfRmGDestRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_RmDestRomIdxOfRmGDestRomType RmDestRomIdxOfRmGDestRom;  /**< the index of the 1:1 relation pointing to PduR_RmDestRom */
} PduR_RmGDestRomType;

/**   \brief  type used in PduR_RmSrcRom */
typedef struct sPduR_RmSrcRomType
{
  PduR_LockRomIdxOfRmSrcRomType LockRomIdxOfRmSrcRom;  /**< the index of the 1:1 relation pointing to PduR_LockRom */
  PduR_MaskedBitsOfRmSrcRomType MaskedBitsOfRmSrcRom;  /**< contains bitcoded the boolean data of PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom */
  PduR_MmRomIdxOfRmSrcRomType MmRomIdxOfRmSrcRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_RmDestRomStartIdxOfRmSrcRomType RmDestRomStartIdxOfRmSrcRom;  /**< the start index of the 1:n relation pointing to PduR_RmDestRom */
  PduR_SrcHndOfRmSrcRomType SrcHndOfRmSrcRom;  /**< handle to be used as parameter for the TxConfirmation or TriggerTransmit function call. */
} PduR_RmSrcRomType;

/**   \brief  type used in PduR_RxIf2Dest */
typedef struct sPduR_RxIf2DestType
{
  uint8 PduR_RxIf2DestNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_RxIf2DestType;

/**   \brief  type used in PduR_RxTp2Dest */
typedef struct sPduR_RxTp2DestType
{
  uint8 PduR_RxTp2DestNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_RxTp2DestType;

/**   \brief  type used in PduR_SrcApplicationRom */
typedef struct sPduR_SrcApplicationRomType
{
  uint8 PduR_SrcApplicationRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_SrcApplicationRomType;

/**   \brief  type used in PduR_Tx2Lo */
typedef struct sPduR_Tx2LoType
{
  PduR_CancelTransmitUsedOfTx2LoType CancelTransmitUsedOfTx2Lo;  /**< TRUE if the routing can use the CancelTransmit API */
  PduR_RmSrcRomIdxOfTx2LoType RmSrcRomIdxOfTx2Lo;  /**< the index of the 0:1 relation pointing to PduR_RmSrcRom */
  PduR_RmTransmitFctPtrIdxOfTx2LoType RmTransmitFctPtrIdxOfTx2Lo;  /**< the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr */
} PduR_Tx2LoType;

/**   \brief  type used in PduR_TxIf2Up */
typedef struct sPduR_TxIf2UpType
{
  PduR_TxConfirmationUsedOfTxIf2UpType TxConfirmationUsedOfTxIf2Up;  /**< True, if any of the source PduRDestPdus uses a TxConfirmation. */
  PduR_RmGDestRomIdxOfTxIf2UpType RmGDestRomIdxOfTxIf2Up;  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
} PduR_TxIf2UpType;

/**   \brief  type used in PduR_TxTp2Src */
typedef struct sPduR_TxTp2SrcType
{
  PduR_RmGDestRomIdxOfTxTp2SrcType RmGDestRomIdxOfTxTp2Src;  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
} PduR_TxTp2SrcType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicStructTypes  PduR Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to PduR_InitializedRam in the predefined variant Left in the partition context  */
typedef struct PduR_InitializedRamLeftStructSTag
{
  PduR_InitializedRamType PduRSinglePartitionDummy;
} PduR_InitializedRamLeftStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_InitializedRam in the predefined variant Right in the partition context  */
typedef struct PduR_InitializedRamRightStructSTag
{
  PduR_InitializedRamType PduRSinglePartitionDummy;
} PduR_InitializedRamRightStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCUnionIndexAndSymbolTypes  PduR Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access PduR_InitializedRam in an index and symbol based style. */
typedef union PduR_InitializedRamUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  PduR_InitializedRamType raw[1];
  PduR_InitializedRamLeftStructSType strLeft;
  PduR_InitializedRamRightStructSType strRight;
} PduR_InitializedRamUType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootPointerTypes  PduR Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to PduR_DestApplicationManagerRom */
typedef P2CONST(PduR_DestApplicationManagerRomType, TYPEDEF, PDUR_CONST) PduR_DestApplicationManagerRomPtrType;

/**   \brief  type used to point to PduR_ExclusiveAreaRom */
typedef P2CONST(PduR_ExclusiveAreaRomType, TYPEDEF, PDUR_CONST) PduR_ExclusiveAreaRomPtrType;

/**   \brief  type used to point to PduR_GeneralPropertiesRom */
typedef P2CONST(PduR_GeneralPropertiesRomType, TYPEDEF, PDUR_CONST) PduR_GeneralPropertiesRomPtrType;

/**   \brief  type used to point to PduR_InitializedRam */
typedef P2VAR(PduR_InitializedRamType, TYPEDEF, PDUR_VAR_NO_INIT) PduR_InitializedRamPtrType;

/**   \brief  type used to point to PduR_LockRom */
typedef P2CONST(PduR_LockRomType, TYPEDEF, PDUR_CONST) PduR_LockRomPtrType;

/**   \brief  type used to point to PduR_MmRom */
typedef P2CONST(PduR_MmRomType, TYPEDEF, PDUR_CONST) PduR_MmRomPtrType;

/**   \brief  type used to point to PduR_PartitionIdentifiers */
typedef P2CONST(PduR_PartitionIdentifiersType, TYPEDEF, PDUR_CONST) PduR_PartitionIdentifiersPtrType;

/**   \brief  type used to point to PduR_RmDestRom */
typedef P2CONST(PduR_RmDestRomType, TYPEDEF, PDUR_CONST) PduR_RmDestRomPtrType;

/**   \brief  type used to point to PduR_RmGDestRom */
typedef P2CONST(PduR_RmGDestRomType, TYPEDEF, PDUR_CONST) PduR_RmGDestRomPtrType;

/**   \brief  type used to point to PduR_RmSrcRom */
typedef P2CONST(PduR_RmSrcRomType, TYPEDEF, PDUR_CONST) PduR_RmSrcRomPtrType;

/**   \brief  type used to point to PduR_RmTransmitFctPtr */
typedef P2CONST(PduR_RmTransmitFctPtrType, TYPEDEF, PDUR_CONST) PduR_RmTransmitFctPtrPtrType;

/**   \brief  type used to point to PduR_RxIf2Dest */
typedef P2CONST(PduR_RxIf2DestType, TYPEDEF, PDUR_CONST) PduR_RxIf2DestPtrType;

/**   \brief  type used to point to PduR_RxTp2Dest */
typedef P2CONST(PduR_RxTp2DestType, TYPEDEF, PDUR_CONST) PduR_RxTp2DestPtrType;

/**   \brief  type used to point to PduR_SrcApplicationRom */
typedef P2CONST(PduR_SrcApplicationRomType, TYPEDEF, PDUR_CONST) PduR_SrcApplicationRomPtrType;

/**   \brief  type used to point to PduR_Tx2Lo */
typedef P2CONST(PduR_Tx2LoType, TYPEDEF, PDUR_CONST) PduR_Tx2LoPtrType;

/**   \brief  type used to point to PduR_TxIf2Up */
typedef P2CONST(PduR_TxIf2UpType, TYPEDEF, PDUR_CONST) PduR_TxIf2UpPtrType;

/**   \brief  type used to point to PduR_TxTp2Src */
typedef P2CONST(PduR_TxTp2SrcType, TYPEDEF, PDUR_CONST) PduR_TxTp2SrcPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCPartitionRootPointer  PduR Partition Root Pointer (PRE_COMPILE)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/**   \brief  type used in PduR_PCPartitionConfig */
typedef struct sPduR_PCPartitionConfigType
{
  PduR_RmDestRomPtrType RmDestRomOfPCPartitionConfig;  /**< the pointer to PduR_RmDestRom */
  PduR_RmGDestRomPtrType RmGDestRomOfPCPartitionConfig;  /**< the pointer to PduR_RmGDestRom */
  PduR_RmSrcRomPtrType RmSrcRomOfPCPartitionConfig;  /**< the pointer to PduR_RmSrcRom */
  PduR_TxIf2UpPtrType TxIf2UpOfPCPartitionConfig;  /**< the pointer to PduR_TxIf2Up */
} PduR_PCPartitionConfigType;

/**   \brief  type used to point to PduR_PCPartitionConfig */
typedef P2CONST(PduR_PCPartitionConfigType, TYPEDEF, PDUR_CONST) PduR_PCPartitionConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootValueTypes  PduR Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in PduR_PCConfig */
typedef struct sPduR_PCConfigType
{
  PduR_PCPartitionConfigPtrType PCPartitionConfigOfPCConfig;  /**< the pointer to PduR_PCPartitionConfig */
} PduR_PCConfigType;

typedef PduR_PCConfigType PduR_PBConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/**   \brief  type to access PduR_PCConfig in a symbol based style. */
typedef struct sPduR_PCConfigsType
{
  PduR_PCConfigType Config_Left;  /**< [Config_Left] */
  PduR_PCConfigType Config_Right;  /**< [Config_Right] */
} PduR_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_DestApplicationManagerRom
**********************************************************************************************************************/
/** 
  \var    PduR_DestApplicationManagerRom
  \brief  Destination Application Manager
  \details
  Element               Description
  RmGDestRomStartIdx    the start index of the 0:n relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_DestApplicationManagerRomType, PDUR_CONST) PduR_DestApplicationManagerRom[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_ExclusiveAreaRom
**********************************************************************************************************************/
/** 
  \var    PduR_ExclusiveAreaRom
  \brief  PduR Exclusive Area Locks
  \details
  Element    Description
  Lock       Lock function
  Unlock     Unlock function
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_GeneralPropertiesRom
**********************************************************************************************************************/
/** 
  \var    PduR_GeneralPropertiesRom
  \brief  General Properties Switches of the PduR.
  \details
  Element         Description
  hasIfRouting
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_GeneralPropertiesRomType, PDUR_CONST) PduR_GeneralPropertiesRom[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_LockRom
**********************************************************************************************************************/
/** 
  \var    PduR_LockRom
  \brief  PduR Lock Manager Table
  \details
  Element                Description
  ExclusiveAreaRomIdx    the index of the 0:1 relation pointing to PduR_ExclusiveAreaRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_LockRomType, PDUR_CONST) PduR_LockRom[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                       Description
  MaskedBits                    contains bitcoded the boolean data of PduR_IfCancelTransmitSupportedOfMmRom, PduR_LoIfOfMmRom, PduR_LoTpOfMmRom, PduR_TpCancelTransmitSupportedOfMmRom, PduR_UpIfOfMmRom, PduR_UpTpOfMmRom
  LoIfCancelTransmitFctPtr      Lower layer cancel transmit function pointers.
  LoTpCancelTransmitFctPtr      Lower layer cancel transmit function pointers.
  UpTpCopyRxDataFctPtr          Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr          Transport protocol CopyTxData function pointers
  UpIfRxIndicationFctPtr        Upper layer communication interface Rx indication function pointers.
  UpIfTxConfirmationFctPtr      Upper layer communication interface Tx confimation function pointers
  UpTpStartOfReceptionFctPtr    Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr      Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr    Transport protocol TpTxConfimation function pointers
  LoIfTransmitFctPtr            Lower layer If transmit function pointers
  LoTpTransmitFctPtr            Lower layer Tp transmit function pointers
  UpIfTriggerTransmitFctPtr     Upper layer trigger transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[7];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    PduR_PartitionIdentifiers
  \brief  the partition context in Config_Left
  \details
  Element         Description
  PartitionSNV
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PartitionIdentifiersType, PDUR_CONST) PduR_PartitionIdentifiers[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRomLeft
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomLeft
  \brief  PduR RoutingPathManager destPdu Table
  \details
  Element                      Description
  PduLengthHandlingStrategy    The strategy how larger than configured If Pdus are handled.
  RmGDestRomIdx                the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx                  the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType                  Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomLeft[55];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRomRight
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomRight
  \brief  PduR RoutingPathManager destPdu Table
  \details
  Element                      Description
  PduLengthHandlingStrategy    The strategy how larger than configured If Pdus are handled.
  RmGDestRomIdx                the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx                  the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType                  Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomRight[55];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomLeft
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomLeft
  \brief  PduR RoutingPathManager global destPdu Table
  \details
  Element         Description
  MaxPduLength    Configured PduLength + metadata length.
  DestHnd         handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction       Direction of this Pdu: Rx or Tx
  LockRomIdx      the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx        the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomLeft[55];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomRight
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomRight
  \brief  PduR RoutingPathManager global destPdu Table
  \details
  Element         Description
  MaxPduLength    Configured PduLength + metadata length.
  DestHnd         handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction       Direction of this Pdu: Rx or Tx
  LockRomIdx      the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx        the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomRight[55];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomLeft
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomLeft
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MaskedBits           contains bitcoded the boolean data of PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomLeft[55];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomRight
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomRight
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MaskedBits           contains bitcoded the boolean data of PduR_TriggerTransmitSupportedOfRmSrcRom, PduR_TxConfirmationSupportedOfRmSrcRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomRight[55];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all information to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  CancelTransmitUsed     TRUE if the routing can use the CancelTransmit API
  RmSrcRomIdx            the index of the 0:1 relation pointing to PduR_RmSrcRom
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[11];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2UpLeft
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2UpLeft
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element               Description
  TxConfirmationUsed    True, if any of the source PduRDestPdus uses a TxConfirmation.
  RmGDestRomIdx         the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2UpLeft[8];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2UpRight
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2UpRight
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element               Description
  TxConfirmationUsed    True, if any of the source PduRDestPdus uses a TxConfirmation.
  RmGDestRomIdx         the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2UpRight[8];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxTp2Src
**********************************************************************************************************************/
/** 
  \var    PduR_TxTp2Src
  \brief  This table contains all routing information to perform the Tx handling of a transport protocol routing, Used in the &lt;LoTp&gt;_CopyTxData and &lt;LoTp&gt;_TxConfirmation
  \details
  Element          Description
  RmGDestRomIdx    the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_TxTp2SrcType, PDUR_CONST) PduR_TxTp2Src[3];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_InitializedRam
**********************************************************************************************************************/
/** 
  \var    PduR_InitializedRam
  \brief  Initialized status of each partition the PduR runs on.
*/ 
#define PDUR_START_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(PduR_InitializedRamUType, PDUR_VAR_NO_INIT) PduR_InitializedRam;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define PDUR_STOP_SEC_VAR_NO_INIT_8
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCConfig
**********************************************************************************************************************/
/** 
  \var    PduR_PCConfig
  \details
  Element              Description
  PCPartitionConfig    the pointer to PduR_PCPartitionConfig
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PCConfigsType, PDUR_CONST) PduR_PCConfig;
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigLeft
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigLeft
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  TxIf2Up       the pointer to PduR_TxIf2Up
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigLeft[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigRight
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigRight
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  TxIf2Up       the pointer to PduR_TxIf2Up
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigRight[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_USE_INIT_POINTER == STD_ON)
extern P2CONST(PduR_PBConfigType, PDUR_VAR_CLEARED, PDUR_PBCFG) PduR_ConfigDataPtr;
#endif

#define PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#define PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

extern VAR(boolean, PDUR_VAR_NO_INIT) PduR_PreInitialized;

#define PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * LOCAL GEN FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL GEN FUNCTIONS
 *********************************************************************************************************************/

#endif  /* PDUR_LCFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.h
 *********************************************************************************************************************/

