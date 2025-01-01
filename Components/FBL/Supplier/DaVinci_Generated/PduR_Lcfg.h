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
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.h
 *   Generation Time: 2023-07-05 16:23:59
 *           Project: CBD2000614_FblCan - Version 1.0
 *          Delivery: CBD2200332_D02
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

#include "CanTp.h"
#include "Dcm_Cbk.h"


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
#define PDUR_GENERALPROPERTIESROM                                                                   STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_GeneralPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_SPINLOCKRETRYCOUNTEROFGENERALPROPERTIESROM                                             STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' and Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' */
#define PDUR_HASIFROUTINGOFGENERALPROPERTIESROM                                                     STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfRouting' Reason: 'No Communication Interface BswModule active.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfRouting' Reason: 'No Communication Interface BswModule active.' */
#define PDUR_HASIFTXFIFOOFGENERALPROPERTIESROM                                                      STD_OFF  /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'No Communication Interface BswModule active.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'No Communication Interface BswModule active.' */
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
#define PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM                                                        STD_ON
#define PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_LOIFCANCELTRANSMITFCTPTROFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOIFOFMMROM                                                                            STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_LOIFTRANSMITFCTPTROFMMROM                                                              STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCANCELRECEIVEFCTPTROFMMROM                                                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCANCELTRANSMITFCTPTROFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCHANGEPARAMETERFCTPTROFMMROM                                                       STD_ON
#define PDUR_LOTPOFMMROM                                                                            STD_ON
#define PDUR_LOTPTRANSMITFCTPTROFMMROM                                                              STD_ON
#define PDUR_MASKEDBITSOFMMROM                                                                      STD_ON
#define PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_UPIFOFMMROM                                                                            STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_UPIFRXINDICATIONFCTPTROFMMROM                                                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_UPIFTRIGGERTRANSMITFCTPTROFMMROM                                                       STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_UPIFTXCONFIRMATIONFCTPTROFMMROM                                                        STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
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
#define PDUR_RMBUFFEREDIFPROPERTIESRAM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                                    STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_INTERFACEFIFOQUEUEROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                      STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_QUEUEFCTPTRROMIDXOFRMBUFFEREDIFPROPERTIESROM                                           STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_SINGLEBUFFERROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                         STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
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
#define PDUR_BSWMPDURPRETRANSMITCALLBACKOFRMDESTROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RmDestRomRBTM_FR.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                                   STD_ON
#define PDUR_RMDESTRPGROMIDXOFRMDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMPARTITIONIDXOFRMDESTROM                                                    STD_OFF  /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMUSEDOFRMDESTROM                                                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
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
#define PDUR_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_LOCKROMIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_MAXPDULENGTHOFRMGDESTROM                                                               STD_ON
#define PDUR_MMROMIDXOFRMGDESTROM                                                                   STD_ON
#define PDUR_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                      STD_ON
#define PDUR_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMDESTROMIDXOFRMGDESTROM                                                               STD_ON
#define PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM                                             STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM                                            STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                                    STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_SMGDESTROMIDXOFRMGDESTROM                                                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROMPARTITIONIDXOFRMGDESTROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PDUR_SMGDESTROMUSEDOFRMGDESTROM                                                             STD_OFF  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TXIF2UPIDXOFRMGDESTROM                                                                 STD_ON
#define PDUR_RMGDESTTPTXSTATERAM                                                                    STD_OFF  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                                   STD_OFF  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMSRCROM                                                                               STD_ON
#define PDUR_DESTAPPLICATIONMANAGERROMIDXOFRMSRCROM                                                 STD_ON
#define PDUR_LOCKROMIDXOFRMSRCROM                                                                   STD_ON
#define PDUR_MMROMIDXOFRMSRCROM                                                                     STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM                                        STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                                STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTROMENDIDXOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMLENGTHOFRMSRCROM                                                              STD_ON
#define PDUR_RMDESTROMSTARTIDXOFRMSRCROM                                                            STD_ON
#define PDUR_SMSRCROMIDXOFRMSRCROM                                                                  STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROMPARTITIONIDXOFRMSRCROM                                                         STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PDUR_SMSRCROMUSEDOFRMSRCROM                                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SRCHNDOFRMSRCROM                                                                       STD_ON
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                     STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' */
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                      STD_OFF  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' */
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
#define PDUR_RXIF2DEST                                                                              STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                                                STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_INVALIDHNDOFRXIF2DEST                                                                  STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_RMSRCROMIDXOFRXIF2DEST                                                                 STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_RXTP2DEST                                                                              STD_ON
#define PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                                              STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST                                          STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFRXTP2DEST                                                                  STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFRXTP2DEST                                                                 STD_ON
#define PDUR_RXTP2SRC                                                                               STD_ON
#define PDUR_INVALIDHNDOFRXTP2SRC                                                                   STD_OFF  /**< Deactivateable: 'PduR_RxTp2SrcRBTM_FL.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FL.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FR.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FR.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMDESTROMIDXOFRXTP2SRC                                                                 STD_ON
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
#define PDUR_SIZEOFINITIALIZEDRAM                                                                   STD_ON
#define PDUR_SIZEOFLOCKROM                                                                          STD_ON
#define PDUR_SIZEOFMMROM                                                                            STD_ON
#define PDUR_SIZEOFPARTITIONIDENTIFIERS                                                             STD_ON
#define PDUR_SIZEOFRMDESTROM                                                                        STD_ON
#define PDUR_SIZEOFRMGDESTROM                                                                       STD_ON
#define PDUR_SIZEOFRMSRCROM                                                                         STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTR                                                                 STD_ON
#define PDUR_SIZEOFRXTP2DEST                                                                        STD_ON
#define PDUR_SIZEOFRXTP2SRC                                                                         STD_ON
#define PDUR_SIZEOFSRCAPPLICATIONROM                                                                STD_ON
#define PDUR_SIZEOFTX2LO                                                                            STD_ON
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
#define PDUR_CANCELTRANSMITUSEDOFTX2LO                                                              STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' and Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' */
#define PDUR_INVALIDHNDOFTX2LO                                                                      STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFTX2LO                                                                     STD_ON
#define PDUR_RMSRCROMUSEDOFTX2LO                                                                    STD_ON
#define PDUR_RMTRANSMITFCTPTRIDXOFTX2LO                                                             STD_ON
#define PDUR_TXIF2UP                                                                                STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_TxIf2Up' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                                                STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXIF2UP                                                                    STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_RMGDESTROMIDXOFTXIF2UP                                                                 STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXCONFIRMATIONUSEDOFTXIF2UP                                                            STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' and Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' */
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
#define PDUR_INITIALIZEDRAMOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_LOCKROMOFPCPARTITIONCONFIG                                                             STD_ON
#define PDUR_MMROMOFPCPARTITIONCONFIG                                                               STD_ON
#define PDUR_RMDESTROMOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_RMGDESTROMOFPCPARTITIONCONFIG                                                          STD_ON
#define PDUR_RMSRCROMOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_RXTP2DESTOFPCPARTITIONCONFIG                                                           STD_ON
#define PDUR_RXTP2SRCOFPCPARTITIONCONFIG                                                            STD_ON
#define PDUR_SIZEOFDESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_SIZEOFEXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFINITIALIZEDRAMOFPCPARTITIONCONFIG                                                STD_ON
#define PDUR_SIZEOFLOCKROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_SIZEOFMMROMOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_SIZEOFRMDESTROMOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFRMGDESTROMOFPCPARTITIONCONFIG                                                    STD_ON
#define PDUR_SIZEOFRMSRCROMOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTROFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_SIZEOFRXTP2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_SIZEOFRXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SIZEOFSRCAPPLICATIONROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_SIZEOFTX2LOOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_SIZEOFTXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
#define PDUR_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                                   STD_ON
#define PDUR_TX2LOOFPCPARTITIONCONFIG                                                               STD_ON
#define PDUR_TXTP2SRCOFPCPARTITIONCONFIG                                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMinNumericValueDefines  PduR Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define PDUR_MIN_BMTXBUFFERARRAYRAM                                                                 0u
#define PDUR_MIN_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                   0u
#define PDUR_MIN_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                          0u
#define PDUR_MIN_RXLENGTHOFBMTXBUFFERRAM                                                            0u
#define PDUR_MIN_RMGDESTROMIDXOFDEFERREDEVENTCACHEARRAYRAM                                          0u
#define PDUR_MIN_DEFERREDEVENTCACHEARRAYRAMREADIDXOFDEFERREDEVENTCACHERAM                           0u
#define PDUR_MIN_DEFERREDEVENTCACHEARRAYRAMWRITEIDXOFDEFERREDEVENTCACHERAM                          0u
#define PDUR_MIN_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                 0u
#define PDUR_MIN_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                     0u
#define PDUR_MIN_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                        0u
#define PDUR_MIN_FILLLEVELOFFMFIFORAM                                                               0u
#define PDUR_MIN_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                 0u
#define PDUR_MIN_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                0u
#define PDUR_MIN_INTERFACEFIFOQUEUEARRAYRAM                                                         0u
#define PDUR_MIN_ACTUALLENGTHOFINTERFACEFIFOQUEUEELEMENTRAM                                         0u
#define PDUR_MIN_INTERFACEFIFOQUEUEELEMENTRAMREADIDXOFINTERFACEFIFOQUEUERAM                         0u
#define PDUR_MIN_INTERFACEFIFOQUEUEELEMENTRAMWRITEIDXOFINTERFACEFIFOQUEUERAM                        0u
#define PDUR_MIN_MCQBUFFERARRAYRAM                                                                  0u
#define PDUR_MIN_MCQBUFFERARRAYRAMPENDINGREADIDXOFMCQBUFFERRAM                                      0u
#define PDUR_MIN_MCQBUFFERARRAYRAMPENDINGWRITEIDXOFMCQBUFFERRAM                                     0u
#define PDUR_MIN_MCQBUFFERARRAYRAMREADIDXOFMCQBUFFERRAM                                             0u
#define PDUR_MIN_MCQBUFFERARRAYRAMWRITEIDXOFMCQBUFFERRAM                                            0u
#define PDUR_MIN_OSAPPLICATIONTOPDUROFPARTITIONLOOKUPTABLERAM                                       0u
#define PDUR_MIN_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                     0u
#define PDUR_MIN_ENABLEDCNTOFRMDESTRPGRAM                                                           0u
#define PDUR_MIN_RMDESTROMIDXOFRMGDESTNTO1INFORAM                                                   0u
#define PDUR_MIN_SINGLEBUFFERARRAYRAM                                                               0u
#define PDUR_MIN_ACTUALLENGTHOFSINGLEBUFFERRAM                                                      0u
#define PDUR_MIN_LEARNEDCONNECTIONIDOFSMFIBRAM                                                      0u
#define PDUR_MIN_LOCKVARIABLEOFSPINLOCKRAM                                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMaxNumericValueDefines  PduR Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define PDUR_MAX_BMTXBUFFERARRAYRAM                                                                 255u
#define PDUR_MAX_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                   4294967295u
#define PDUR_MAX_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                                          4294967295u
#define PDUR_MAX_RXLENGTHOFBMTXBUFFERRAM                                                            65535u
#define PDUR_MAX_RMGDESTROMIDXOFDEFERREDEVENTCACHEARRAYRAM                                          255u
#define PDUR_MAX_DEFERREDEVENTCACHEARRAYRAMREADIDXOFDEFERREDEVENTCACHERAM                           255u
#define PDUR_MAX_DEFERREDEVENTCACHEARRAYRAMWRITEIDXOFDEFERREDEVENTCACHERAM                          255u
#define PDUR_MAX_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                 255u
#define PDUR_MAX_RMDESTROMIDXOFFMFIFOELEMENTRAM                                                     255u
#define PDUR_MAX_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                        255u
#define PDUR_MAX_FILLLEVELOFFMFIFORAM                                                               65535u
#define PDUR_MAX_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                                                 255u
#define PDUR_MAX_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                                                255u
#define PDUR_MAX_INTERFACEFIFOQUEUEARRAYRAM                                                         255u
#define PDUR_MAX_ACTUALLENGTHOFINTERFACEFIFOQUEUEELEMENTRAM                                         65535u
#define PDUR_MAX_INTERFACEFIFOQUEUEELEMENTRAMREADIDXOFINTERFACEFIFOQUEUERAM                         255u
#define PDUR_MAX_INTERFACEFIFOQUEUEELEMENTRAMWRITEIDXOFINTERFACEFIFOQUEUERAM                        255u
#define PDUR_MAX_MCQBUFFERARRAYRAM                                                                  255u
#define PDUR_MAX_MCQBUFFERARRAYRAMPENDINGREADIDXOFMCQBUFFERRAM                                      4294967295u
#define PDUR_MAX_MCQBUFFERARRAYRAMPENDINGWRITEIDXOFMCQBUFFERRAM                                     4294967295u
#define PDUR_MAX_MCQBUFFERARRAYRAMREADIDXOFMCQBUFFERRAM                                             4294967295u
#define PDUR_MAX_MCQBUFFERARRAYRAMWRITEIDXOFMCQBUFFERRAM                                            4294967295u
#define PDUR_MAX_OSAPPLICATIONTOPDUROFPARTITIONLOOKUPTABLERAM                                       255u
#define PDUR_MAX_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                     255u
#define PDUR_MAX_ENABLEDCNTOFRMDESTRPGRAM                                                           65535u
#define PDUR_MAX_RMDESTROMIDXOFRMGDESTNTO1INFORAM                                                   255u
#define PDUR_MAX_SINGLEBUFFERARRAYRAM                                                               255u
#define PDUR_MAX_ACTUALLENGTHOFSINGLEBUFFERRAM                                                      65535u
#define PDUR_MAX_LEARNEDCONNECTIONIDOFSMFIBRAM                                                      255u
#define PDUR_MAX_LOCKVARIABLEOFSPINLOCKRAM                                                          4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCNoReferenceDefines  PduR No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define PDUR_NO_DESTAPPLICATIONMANAGERROMIDXOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM               255u
#define PDUR_NO_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM                                    4294967295u
#define PDUR_NO_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                                  255u
#define PDUR_NO_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                         255u
#define PDUR_NO_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                       255u
#define PDUR_NO_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                                                  255u
#define PDUR_NO_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM                                         255u
#define PDUR_NO_LOCKROMIDXOFFMFIFOROM                                                               255u
#define PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM                                                        255u
#define PDUR_NO_SPINLOCKRAMIDXOFLOCKROM                                                             255u
#define PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM                                                    255u
#define PDUR_NO_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                                 255u
#define PDUR_NO_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                       255u
#define PDUR_NO_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM                                      255u
#define PDUR_NO_RMDESTRPGROMIDXOFRMDESTROM                                                          255u
#define PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM                                                 255u
#define PDUR_NO_INITIALENABLEDCNTOFRMDESTRPGROM                                                     255u
#define PDUR_NO_RMDESTROMIDXOFRMDESTRPGROM                                                          255u
#define PDUR_NO_RMDESTROMIDXOFRMGDESTNTO1INFORAM                                                    255u
#define PDUR_NO_DESTHNDOFRMGDESTROM                                                                 255u
#define PDUR_NO_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                    255u
#define PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM                                           255u
#define PDUR_NO_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                            255u
#define PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM                                   255u
#define PDUR_NO_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                   255u
#define PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM                                          255u
#define PDUR_NO_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                  255u
#define PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM                                         255u
#define PDUR_NO_SMGDESTROMIDXOFRMGDESTROM                                                           255u
#define PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM                                                  255u
#define PDUR_NO_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                              255u
#define PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM                                     255u
#define PDUR_NO_SMSRCROMIDXOFRMSRCROM                                                               255u
#define PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM                                                      255u
#define PDUR_NO_SRCHNDOFRMSRCROM                                                                    255u
#define PDUR_NO_RPGROMIDXOFRPGEXTIDROM                                                              255u
#define PDUR_NO_RPGROMPARTITIONIDXOFRPGEXTIDROM                                                     255u
#define PDUR_NO_RMDESTRPGROMINDENDIDXOFRPGROM                                                       255u
#define PDUR_NO_RMDESTRPGROMINDSTARTIDXOFRPGROM                                                     255u
#define PDUR_NO_SMFIBRAMENDIDXOFSMDATAPLANEROM                                                      255u
#define PDUR_NO_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                                                    255u
#define PDUR_NO_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                             255u
#define PDUR_NO_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                         255u
#define PDUR_NO_CONNECTIONIDOFSMGDESTROM                                                            255u
#define PDUR_NO_METADATALENGTHOFSMGDESTROM                                                          255u
#define PDUR_NO_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                          255u
#define PDUR_NO_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                        255u
#define PDUR_NO_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                    4294967295u
#define PDUR_NO_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                255u
#define PDUR_NO_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                    4294967295u
#define PDUR_NO_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                255u
#define PDUR_NO_CONNECTIONIDOFSMSRCROM                                                              255u
#define PDUR_NO_METADATALENGTHOFSMSRCROM                                                            255u
#define PDUR_NO_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM                           255u
#define PDUR_NO_DEFERREDEVENTCACHEROMIDXOFSRCAPPLICATIONROM                                         255u
#define PDUR_NO_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                                255u
#define PDUR_NO_MCQBUFFERROMIDXOFSRCAPPLICATIONROM                                                  255u
#define PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM                                         255u
#define PDUR_NO_RMSRCROMIDXOFTX2LO                                                                  255u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumExistsDefines  PduR Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM               STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_SIMPLE_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                 STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_DIRECT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_TRIGGER_TRANSMIT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_SINGLE_BUFFER_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                              STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_FIFO_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                       STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                    STD_OFF
#define PDUR_EXISTS_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                     STD_OFF
#define PDUR_EXISTS_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                     STD_ON
#define PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_OFF  /**< No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface */
#define PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_OFF  /**< No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface */
#define PDUR_EXISTS_IF_UNBUFFERED_UL_API_FWD_ROUTINGTYPEOFRMDESTROM                                 STD_OFF
#define PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM                                      STD_OFF  /**< No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface */
#define PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM                                              STD_OFF  /**< No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface */
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
#define PDUR_RM_TX_IDLE_TPTXSMSTATEOFFMFIFORAM                                                      0x00u
#define PDUR_RM_TX_RECEPTION_ACTIVE_TPTXSMSTATEOFFMFIFORAM                                          0x01u
#define PDUR_RM_TX_TRANSMISSION_FINISHED_TPTXSMSTATEOFFMFIFORAM                                     0x02u
#define PDUR_RM_TX_RECEPTION_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM                             0x03u
#define PDUR_RM_TX_RECEPTION_FINISHED_TRANSMISSION_ACTIVE_TPTXSMSTATEOFFMFIFORAM                    0x04u
#define PDUR_RM_TX_IDLE_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                                        0x00u
#define PDUR_RM_TX_ACTIVE_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                                      0x01u
#define PDUR_SINGLE_BUFFER_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                      0x00u
#define PDUR_SIMPLE_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                        0x01u
#define PDUR_SHARED_FIFO_QUEUE_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                        0x02u
#define PDUR_DIRECT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                               0x00u
#define PDUR_TRIGGER_TRANSMIT_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                     0x01u
#define PDUR_SINGLE_BUFFER_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                     0x00u
#define PDUR_FIFO_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                              0x01u
#define PDUR_RM_RX_IDLE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                      0x00u
#define PDUR_RM_RX_ACTIVE_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                    0x01u
#define PDUR_RM_RX_ABORTED_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                                   0x02u
#define PDUR_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                           0x00u
#define PDUR_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                           0x01u
#define PDUR_IGNORE_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                            0x02u
#define PDUR_UNUSED_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                            0x03u
#define PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x00u
#define PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x01u
#define PDUR_IF_UNBUFFERED_UL_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x02u
#define PDUR_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM                                             0x03u
#define PDUR_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM                                                     0x04u
#define PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x05u
#define PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM                                        0x06u
#define PDUR_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM                                                     0x07u
#define PDUR_RX_DIRECTIONOFRMGDESTROM                                                               0x00u
#define PDUR_TX_DIRECTIONOFRMGDESTROM                                                               0x01u
#define PDUR_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM                                             0x00u
#define PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM                                            0x01u
#define PDUR_RM_TXINST_IDLE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                    0x00u
#define PDUR_RM_TXINST_ACTIVE_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                  0x01u
#define PDUR_RM_TXINST_WAITING_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                 0x02u
#define PDUR_RM_TXINST_ABORTED_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                                 0x03u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMaskedBitDefines  PduR Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM_MASK                                                   0x04u
#define PDUR_LOTPOFMMROM_MASK                                                                       0x02u
#define PDUR_UPTPOFMMROM_MASK                                                                       0x01u
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIsReducedToDefineDefines  PduR Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMIDXOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM            STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMUSEDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM           STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                              STD_OFF
#define PDUR_ISDEF_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                               STD_OFF
#define PDUR_ISDEF_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                          STD_OFF
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                          STD_OFF
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                          STD_OFF
#define PDUR_ISDEF_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                        STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                       STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                     STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEARRAYRAMENDIDXOFDEFERREDEVENTCACHEROM                          STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEARRAYRAMLENGTHOFDEFERREDEVENTCACHEROM                          STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEARRAYRAMSTARTIDXOFDEFERREDEVENTCACHEROM                        STD_OFF
#define PDUR_ISDEF_INITIALIZEDIDXOFDESTAPPLICATIONMANAGERROM                                        STD_OFF
#define PDUR_ISDEF_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                               STD_OFF
#define PDUR_ISDEF_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                      STD_OFF
#define PDUR_ISDEF_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                    STD_OFF
#define PDUR_ISDEF_RMGDESTROMUSEDOFDESTAPPLICATIONMANAGERROM                                        STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                               STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                             STD_OFF
#define PDUR_ISDEF_LOCKOFEXCLUSIVEAREAROM                                                           STD_OFF
#define PDUR_ISDEF_UNLOCKOFEXCLUSIVEAREAROM                                                         STD_OFF
#define PDUR_ISDEF_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                  STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                              STD_OFF
#define PDUR_ISDEF_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                STD_OFF
#define PDUR_ISDEF_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                              STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFFMFIFOROM                                                            STD_OFF
#define PDUR_ISDEF_LOCKROMUSEDOFFMFIFOROM                                                           STD_OFF
#define PDUR_ISDEF_SPINLOCKRETRYCOUNTEROFGENERALPROPERTIESROM                                       STD_OFF
#define PDUR_ISDEF_HASIFROUTINGOFGENERALPROPERTIESROM                                               STD_OFF
#define PDUR_ISDEF_HASIFTXFIFOOFGENERALPROPERTIESROM                                                STD_OFF
#define PDUR_ISDEF_HASTPBUFFERULSOURCEOFGENERALPROPERTIESROM                                        STD_OFF
#define PDUR_ISDEF_INTERFACEFIFOQUEUEARRAYRAMENDIDXOFINTERFACEFIFOQUEUEROM                          STD_OFF
#define PDUR_ISDEF_INTERFACEFIFOQUEUEARRAYRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                        STD_OFF
#define PDUR_ISDEF_INTERFACEFIFOQUEUEELEMENTRAMENDIDXOFINTERFACEFIFOQUEUEROM                        STD_OFF
#define PDUR_ISDEF_INTERFACEFIFOQUEUEELEMENTRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                      STD_OFF
#define PDUR_ISDEF_MAXPDULENGTHOFINTERFACEFIFOQUEUEROM                                              STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFINTERFACEFIFOQUEUEROM                                              STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMIDXOFLOCKROM                                                     STD_OFF
#define PDUR_ISDEF_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                    STD_OFF
#define PDUR_ISDEF_SPINLOCKRAMIDXOFLOCKROM                                                          STD_OFF
#define PDUR_ISDEF_SPINLOCKRAMPARTITIONIDXOFLOCKROM                                                 STD_OFF
#define PDUR_ISDEF_SPINLOCKRAMUSEDOFLOCKROM                                                         STD_OFF
#define PDUR_ISDEF_MCQBUFFERARRAYRAMENDIDXOFMCQBUFFERROM                                            STD_OFF
#define PDUR_ISDEF_MCQBUFFERARRAYRAMLENGTHOFMCQBUFFERROM                                            STD_OFF
#define PDUR_ISDEF_MCQBUFFERARRAYRAMSTARTIDXOFMCQBUFFERROM                                          STD_OFF
#define PDUR_ISDEF_CANCELRECEIVESUPPORTEDOFMMROM                                                    STD_OFF
#define PDUR_ISDEF_CHANGEPARAMETERSUPPORTEDOFMMROM                                                  STD_OFF
#define PDUR_ISDEF_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                 STD_OFF
#define PDUR_ISDEF_LOIFCANCELTRANSMITFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_LOIFOFMMROM                                                                      STD_OFF
#define PDUR_ISDEF_LOIFTRANSMITFCTPTROFMMROM                                                        STD_OFF
#define PDUR_ISDEF_LOTPCANCELRECEIVEFCTPTROFMMROM                                                   STD_OFF
#define PDUR_ISDEF_LOTPCANCELTRANSMITFCTPTROFMMROM                                                  STD_OFF
#define PDUR_ISDEF_LOTPCHANGEPARAMETERFCTPTROFMMROM                                                 STD_OFF
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
#define PDUR_ISDEF_FLUSHFCTPTROFQUEUEFCTPTRROM                                                      STD_OFF
#define PDUR_ISDEF_GETFCTPTROFQUEUEFCTPTRROM                                                        STD_OFF
#define PDUR_ISDEF_GETFILLLEVELFCTPTROFQUEUEFCTPTRROM                                               STD_OFF
#define PDUR_ISDEF_PUTFCTPTROFQUEUEFCTPTRROM                                                        STD_OFF
#define PDUR_ISDEF_REMOVEFCTPTROFQUEUEFCTPTRROM                                                     STD_OFF
#define PDUR_ISDEF_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                    STD_OFF
#define PDUR_ISDEF_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                              STD_OFF
#define PDUR_ISDEF_INTERFACEFIFOQUEUEROMUSEDOFRMBUFFEREDIFPROPERTIESROM                             STD_OFF
#define PDUR_ISDEF_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                STD_OFF
#define PDUR_ISDEF_QUEUEFCTPTRROMIDXOFRMBUFFEREDIFPROPERTIESROM                                     STD_OFF
#define PDUR_ISDEF_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                             STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                    STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                   STD_OFF
#define PDUR_ISDEF_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                          STD_OFF
#define PDUR_ISDEF_METADATALENGTHOFRMBUFFEREDTPPROPERTIESROM                                        STD_OFF
#define PDUR_ISDEF_METADATALENGTHUSEDOFRMBUFFEREDTPPROPERTIESROM                                    STD_OFF
#define PDUR_ISDEF_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                         STD_OFF
#define PDUR_ISDEF_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                           STD_OFF
#define PDUR_ISDEF_BSWMPDURPRETRANSMITCALLBACKOFRMDESTROM                                           STD_OFF
#define PDUR_ISDEF_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                             STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMIDXOFRMDESTROM                                                       STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMPARTITIONIDXOFRMDESTROM                                              STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMUSEDOFRMDESTROM                                                      STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFRMDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_ROUTINGTYPEOFRMDESTROM                                                           STD_OFF
#define PDUR_ISDEF_INITIALENABLEDCNTOFRMDESTRPGROM                                                  STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRMDESTRPGROM                                                       STD_OFF
#define PDUR_ISDEF_RMDESTROMUSEDOFRMDESTRPGROM                                                      STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMIND                                                                  STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMIDXOFRMGDESTROM                                         STD_OFF
#define PDUR_ISDEF_DESTHNDOFRMGDESTROM                                                              STD_OFF
#define PDUR_ISDEF_DIRECTIONOFRMGDESTROM                                                            STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                 STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM                                        STD_OFF
#define PDUR_ISDEF_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_MAXPDULENGTHOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMGDESTROM                                                             STD_OFF
#define PDUR_ISDEF_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                         STD_OFF
#define PDUR_ISDEF_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM                                STD_OFF
#define PDUR_ISDEF_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                STD_OFF
#define PDUR_ISDEF_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM                                       STD_OFF
#define PDUR_ISDEF_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                                               STD_OFF
#define PDUR_ISDEF_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                               STD_OFF
#define PDUR_ISDEF_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM                                      STD_OFF
#define PDUR_ISDEF_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                              STD_OFF
#define PDUR_ISDEF_SMGDESTROMIDXOFRMGDESTROM                                                        STD_OFF
#define PDUR_ISDEF_SMGDESTROMPARTITIONIDXOFRMGDESTROM                                               STD_OFF
#define PDUR_ISDEF_SMGDESTROMUSEDOFRMGDESTROM                                                       STD_OFF
#define PDUR_ISDEF_TXIF2UPIDXOFRMGDESTROM                                                           STD_OFF
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMIDXOFRMSRCROM                                           STD_OFF
#define PDUR_ISDEF_LOCKROMIDXOFRMSRCROM                                                             STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMSRCROM                                                               STD_OFF
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                           STD_OFF
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM                                  STD_OFF
#define PDUR_ISDEF_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                          STD_OFF
#define PDUR_ISDEF_RMDESTROMENDIDXOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMLENGTHOFRMSRCROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMSTARTIDXOFRMSRCROM                                                      STD_OFF
#define PDUR_ISDEF_SMSRCROMIDXOFRMSRCROM                                                            STD_OFF
#define PDUR_ISDEF_SMSRCROMPARTITIONIDXOFRMSRCROM                                                   STD_OFF
#define PDUR_ISDEF_SMSRCROMUSEDOFRMSRCROM                                                           STD_OFF
#define PDUR_ISDEF_SRCHNDOFRMSRCROM                                                                 STD_OFF
#define PDUR_ISDEF_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                               STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTR                                                                 STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFRPGEXTIDROM                                                          STD_OFF
#define PDUR_ISDEF_RPGROMIDXOFRPGEXTIDROM                                                           STD_OFF
#define PDUR_ISDEF_RPGROMPARTITIONIDXOFRPGEXTIDROM                                                  STD_OFF
#define PDUR_ISDEF_RPGROMUSEDOFRPGEXTIDROM                                                          STD_OFF
#define PDUR_ISDEF_ENABLEDATINITOFRPGROM                                                            STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMINDENDIDXOFRPGROM                                                    STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMINDSTARTIDXOFRPGROM                                                  STD_OFF
#define PDUR_ISDEF_RMDESTRPGROMINDUSEDOFRPGROM                                                      STD_OFF
#define PDUR_ISDEF_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                                          STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFRXIF2DEST                                                            STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXIF2DEST                                                           STD_OFF
#define PDUR_ISDEF_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                                        STD_OFF
#define PDUR_ISDEF_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST                                    STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFRXTP2DEST                                                            STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXTP2DEST                                                           STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFRXTP2SRC                                                             STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRXTP2SRC                                                           STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERINITVALUESROM                                                        STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFSINGLEBUFFERROM                                                    STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERARRAYRAMENDIDXOFSINGLEBUFFERROM                                      STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERARRAYRAMLENGTHOFSINGLEBUFFERROM                                      STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERARRAYRAMSTARTIDXOFSINGLEBUFFERROM                                    STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERINITVALUESROMENDIDXOFSINGLEBUFFERROM                                 STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERINITVALUESROMLENGTHOFSINGLEBUFFERROM                                 STD_OFF
#define PDUR_ISDEF_SINGLEBUFFERINITVALUESROMSTARTIDXOFSINGLEBUFFERROM                               STD_OFF
#define PDUR_ISDEF_SMFIBRAMENDIDXOFSMDATAPLANEROM                                                   STD_OFF
#define PDUR_ISDEF_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                                                 STD_OFF
#define PDUR_ISDEF_SMFIBRAMUSEDOFSMDATAPLANEROM                                                     STD_OFF
#define PDUR_ISDEF_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                          STD_OFF
#define PDUR_ISDEF_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                         STD_OFF
#define PDUR_ISDEF_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                      STD_OFF
#define PDUR_ISDEF_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                     STD_OFF
#define PDUR_ISDEF_SMGDESTFILTERFCTPTR                                                              STD_OFF
#define PDUR_ISDEF_CONNECTIONIDOFSMGDESTROM                                                         STD_OFF
#define PDUR_ISDEF_METADATALENGTHOFSMGDESTROM                                                       STD_OFF
#define PDUR_ISDEF_SMDATAPLANEROMIDXOFSMGDESTROM                                                    STD_OFF
#define PDUR_ISDEF_SMGDESTFILTERFCTPTRIDXOFSMGDESTROM                                               STD_OFF
#define PDUR_ISDEF_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR                                     STD_OFF
#define PDUR_ISDEF_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                       STD_OFF
#define PDUR_ISDEF_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                     STD_OFF
#define PDUR_ISDEF_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                 STD_OFF
#define PDUR_ISDEF_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                             STD_OFF
#define PDUR_ISDEF_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                 STD_OFF
#define PDUR_ISDEF_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                             STD_OFF
#define PDUR_ISDEF_SMSRCFILTERFCTPTR                                                                STD_OFF
#define PDUR_ISDEF_CONNECTIONIDOFSMSRCROM                                                           STD_OFF
#define PDUR_ISDEF_METADATALENGTHOFSMSRCROM                                                         STD_OFF
#define PDUR_ISDEF_SMDATAPLANEROMIDXOFSMSRCROM                                                      STD_OFF
#define PDUR_ISDEF_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM                        STD_OFF
#define PDUR_ISDEF_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM                       STD_OFF
#define PDUR_ISDEF_SMSRCFILTERFCTPTRIDXOFSMSRCROM                                                   STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEROMIDXOFSRCAPPLICATIONROM                                      STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                             STD_OFF
#define PDUR_ISDEF_DEFERREDEVENTCACHEROMUSEDOFSRCAPPLICATIONROM                                     STD_OFF
#define PDUR_ISDEF_MCQBUFFERROMIDXOFSRCAPPLICATIONROM                                               STD_OFF
#define PDUR_ISDEF_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM                                      STD_OFF
#define PDUR_ISDEF_MCQBUFFERROMUSEDOFSRCAPPLICATIONROM                                              STD_OFF
#define PDUR_ISDEF_BSWMPDURTRANSMITCALLBACKOFTX2LO                                                  STD_OFF
#define PDUR_ISDEF_CANCELTRANSMITUSEDOFTX2LO                                                        STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFTX2LO                                                                STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFTX2LO                                                               STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFTX2LO                                                              STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTRIDXOFTX2LO                                                       STD_OFF
#define PDUR_ISDEF_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                                          STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFTXIF2UP                                                              STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXIF2UP                                                           STD_OFF
#define PDUR_ISDEF_TXCONFIRMATIONUSEDOFTXIF2UP                                                      STD_OFF
#define PDUR_ISDEF_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC                                       STD_OFF
#define PDUR_ISDEF_INVALIDHNDOFTXTP2SRC                                                             STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXTP2SRC                                                          STD_OFF
#define PDUR_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                       STD_OFF
#define PDUR_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                       STD_OFF
#define PDUR_ISDEF_PCPARTITIONCONFIGOFPCCONFIG                                                      STD_OFF
#define PDUR_ISDEF_PARTITIONIDENTIFIERSOFPCCONFIG                                                   STD_ON
#define PDUR_ISDEF_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                     STD_ON
#define PDUR_ISDEF_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_ISDEF_INITIALIZEDRAMOFPCPARTITIONCONFIG                                                STD_ON
#define PDUR_ISDEF_LOCKROMOFPCPARTITIONCONFIG                                                       STD_ON
#define PDUR_ISDEF_MMROMOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_ISDEF_RMDESTROMOFPCPARTITIONCONFIG                                                     STD_OFF
#define PDUR_ISDEF_RMGDESTROMOFPCPARTITIONCONFIG                                                    STD_OFF
#define PDUR_ISDEF_RMSRCROMOFPCPARTITIONCONFIG                                                      STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                              STD_ON
#define PDUR_ISDEF_RXTP2DESTOFPCPARTITIONCONFIG                                                     STD_ON
#define PDUR_ISDEF_RXTP2SRCOFPCPARTITIONCONFIG                                                      STD_OFF
#define PDUR_ISDEF_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                             STD_ON
#define PDUR_ISDEF_TX2LOOFPCPARTITIONCONFIG                                                         STD_ON
#define PDUR_ISDEF_TXTP2SRCOFPCPARTITIONCONFIG                                                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEqualsAlwaysToDefines  PduR Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMIDXOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM              
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMUSEDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM             
#define PDUR_EQ2_INVALIDHNDOFAPPLICATIONID2DESTAPPLICATIONMANAGERROM                                
#define PDUR_EQ2_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                                                 
#define PDUR_EQ2_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                                            
#define PDUR_EQ2_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                                            
#define PDUR_EQ2_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                                            
#define PDUR_EQ2_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                                          
#define PDUR_EQ2_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM                                         
#define PDUR_EQ2_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM                                       
#define PDUR_EQ2_DEFERREDEVENTCACHEARRAYRAMENDIDXOFDEFERREDEVENTCACHEROM                            
#define PDUR_EQ2_DEFERREDEVENTCACHEARRAYRAMLENGTHOFDEFERREDEVENTCACHEROM                            
#define PDUR_EQ2_DEFERREDEVENTCACHEARRAYRAMSTARTIDXOFDEFERREDEVENTCACHEROM                          
#define PDUR_EQ2_INITIALIZEDIDXOFDESTAPPLICATIONMANAGERROM                                          
#define PDUR_EQ2_INITIALIZEDPARTITIONIDXOFDESTAPPLICATIONMANAGERROM                                 
#define PDUR_EQ2_RMGDESTROMENDIDXOFDESTAPPLICATIONMANAGERROM                                        
#define PDUR_EQ2_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                                      
#define PDUR_EQ2_RMGDESTROMUSEDOFDESTAPPLICATIONMANAGERROM                                          
#define PDUR_EQ2_SRCAPPLICATIONROMENDIDXOFDESTAPPLICATIONMANAGERROM                                 
#define PDUR_EQ2_SRCAPPLICATIONROMSTARTIDXOFDESTAPPLICATIONMANAGERROM                               
#define PDUR_EQ2_LOCKOFEXCLUSIVEAREAROM                                                             
#define PDUR_EQ2_UNLOCKOFEXCLUSIVEAREAROM                                                           
#define PDUR_EQ2_FMFIFOROMIDXOFFMFIFOINSTANCEROM                                                    
#define PDUR_EQ2_BMTXBUFFERINDROMENDIDXOFFMFIFOROM                                                  
#define PDUR_EQ2_BMTXBUFFERINDROMLENGTHOFFMFIFOROM                                                  
#define PDUR_EQ2_BMTXBUFFERINDROMSTARTIDXOFFMFIFOROM                                                
#define PDUR_EQ2_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                                                  
#define PDUR_EQ2_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                                                  
#define PDUR_EQ2_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                                                
#define PDUR_EQ2_LOCKROMIDXOFFMFIFOROM                                                              
#define PDUR_EQ2_LOCKROMUSEDOFFMFIFOROM                                                             
#define PDUR_EQ2_SPINLOCKRETRYCOUNTEROFGENERALPROPERTIESROM                                         
#define PDUR_EQ2_HASIFROUTINGOFGENERALPROPERTIESROM                                                 
#define PDUR_EQ2_HASIFTXFIFOOFGENERALPROPERTIESROM                                                  
#define PDUR_EQ2_HASTPBUFFERULSOURCEOFGENERALPROPERTIESROM                                          
#define PDUR_EQ2_INTERFACEFIFOQUEUEARRAYRAMENDIDXOFINTERFACEFIFOQUEUEROM                            
#define PDUR_EQ2_INTERFACEFIFOQUEUEARRAYRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                          
#define PDUR_EQ2_INTERFACEFIFOQUEUEELEMENTRAMENDIDXOFINTERFACEFIFOQUEUEROM                          
#define PDUR_EQ2_INTERFACEFIFOQUEUEELEMENTRAMSTARTIDXOFINTERFACEFIFOQUEUEROM                        
#define PDUR_EQ2_MAXPDULENGTHOFINTERFACEFIFOQUEUEROM                                                
#define PDUR_EQ2_RMDESTROMIDXOFINTERFACEFIFOQUEUEROM                                                
#define PDUR_EQ2_EXCLUSIVEAREAROMIDXOFLOCKROM                                                       
#define PDUR_EQ2_EXCLUSIVEAREAROMUSEDOFLOCKROM                                                      
#define PDUR_EQ2_SPINLOCKRAMIDXOFLOCKROM                                                            
#define PDUR_EQ2_SPINLOCKRAMPARTITIONIDXOFLOCKROM                                                   
#define PDUR_EQ2_SPINLOCKRAMUSEDOFLOCKROM                                                           
#define PDUR_EQ2_MCQBUFFERARRAYRAMENDIDXOFMCQBUFFERROM                                              
#define PDUR_EQ2_MCQBUFFERARRAYRAMLENGTHOFMCQBUFFERROM                                              
#define PDUR_EQ2_MCQBUFFERARRAYRAMSTARTIDXOFMCQBUFFERROM                                            
#define PDUR_EQ2_CANCELRECEIVESUPPORTEDOFMMROM                                                      
#define PDUR_EQ2_CHANGEPARAMETERSUPPORTEDOFMMROM                                                    
#define PDUR_EQ2_IFCANCELTRANSMITSUPPORTEDOFMMROM                                                   
#define PDUR_EQ2_LOIFCANCELTRANSMITFCTPTROFMMROM                                                    
#define PDUR_EQ2_LOIFOFMMROM                                                                        
#define PDUR_EQ2_LOIFTRANSMITFCTPTROFMMROM                                                          
#define PDUR_EQ2_LOTPCANCELRECEIVEFCTPTROFMMROM                                                     
#define PDUR_EQ2_LOTPCANCELTRANSMITFCTPTROFMMROM                                                    
#define PDUR_EQ2_LOTPCHANGEPARAMETERFCTPTROFMMROM                                                   
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
#define PDUR_EQ2_FLUSHFCTPTROFQUEUEFCTPTRROM                                                        
#define PDUR_EQ2_GETFCTPTROFQUEUEFCTPTRROM                                                          
#define PDUR_EQ2_GETFILLLEVELFCTPTROFQUEUEFCTPTRROM                                                 
#define PDUR_EQ2_PUTFCTPTROFQUEUEFCTPTRROM                                                          
#define PDUR_EQ2_REMOVEFCTPTROFQUEUEFCTPTRROM                                                       
#define PDUR_EQ2_IMPLEMENTATIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                      
#define PDUR_EQ2_INTERFACEFIFOQUEUEROMIDXOFRMBUFFEREDIFPROPERTIESROM                                
#define PDUR_EQ2_INTERFACEFIFOQUEUEROMUSEDOFRMBUFFEREDIFPROPERTIESROM                               
#define PDUR_EQ2_QUEUEDATAPROVISIONTYPEOFRMBUFFEREDIFPROPERTIESROM                                  
#define PDUR_EQ2_QUEUEFCTPTRROMIDXOFRMBUFFEREDIFPROPERTIESROM                                       
#define PDUR_EQ2_QUEUETYPEOFRMBUFFEREDIFPROPERTIESROM                                               
#define PDUR_EQ2_SINGLEBUFFERROMIDXOFRMBUFFEREDIFPROPERTIESROM                                      
#define PDUR_EQ2_SINGLEBUFFERROMUSEDOFRMBUFFEREDIFPROPERTIESROM                                     
#define PDUR_EQ2_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                                            
#define PDUR_EQ2_METADATALENGTHOFRMBUFFEREDTPPROPERTIESROM                                          
#define PDUR_EQ2_METADATALENGTHUSEDOFRMBUFFEREDTPPROPERTIESROM                                      
#define PDUR_EQ2_QUEUEDDESTCNTOFRMBUFFEREDTPPROPERTIESROM                                           
#define PDUR_EQ2_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                                             
#define PDUR_EQ2_BSWMPDURPRETRANSMITCALLBACKOFRMDESTROM                                             
#define PDUR_EQ2_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                                               
#define PDUR_EQ2_RMDESTRPGROMIDXOFRMDESTROM                                                         
#define PDUR_EQ2_RMDESTRPGROMPARTITIONIDXOFRMDESTROM                                                
#define PDUR_EQ2_RMDESTRPGROMUSEDOFRMDESTROM                                                        
#define PDUR_EQ2_RMGDESTROMIDXOFRMDESTROM                                                           
#define PDUR_EQ2_RMSRCROMIDXOFRMDESTROM                                                             
#define PDUR_EQ2_ROUTINGTYPEOFRMDESTROM                                                             
#define PDUR_EQ2_INITIALENABLEDCNTOFRMDESTRPGROM                                                    
#define PDUR_EQ2_RMDESTROMIDXOFRMDESTRPGROM                                                         
#define PDUR_EQ2_RMDESTROMUSEDOFRMDESTRPGROM                                                        
#define PDUR_EQ2_RMDESTRPGROMIND                                                                    
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMIDXOFRMGDESTROM                                           
#define PDUR_EQ2_DESTHNDOFRMGDESTROM                                                                
#define PDUR_EQ2_DIRECTIONOFRMGDESTROM                                                              
#define PDUR_EQ2_FMFIFOINSTANCEROMIDXOFRMGDESTROM                                                   
#define PDUR_EQ2_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM                                          
#define PDUR_EQ2_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                                                  
#define PDUR_EQ2_LOCKROMIDXOFRMGDESTROM                                                             
#define PDUR_EQ2_MAXPDULENGTHOFRMGDESTROM                                                           
#define PDUR_EQ2_MMROMIDXOFRMGDESTROM                                                               
#define PDUR_EQ2_PDURDESTPDUPROCESSINGOFRMGDESTROM                                                  
#define PDUR_EQ2_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                                           
#define PDUR_EQ2_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM                                  
#define PDUR_EQ2_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                                          
#define PDUR_EQ2_RMDESTROMIDXOFRMGDESTROM                                                           
#define PDUR_EQ2_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                                                  
#define PDUR_EQ2_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM                                         
#define PDUR_EQ2_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                                                 
#define PDUR_EQ2_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                                                 
#define PDUR_EQ2_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM                                        
#define PDUR_EQ2_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                                                
#define PDUR_EQ2_SMGDESTROMIDXOFRMGDESTROM                                                          
#define PDUR_EQ2_SMGDESTROMPARTITIONIDXOFRMGDESTROM                                                 
#define PDUR_EQ2_SMGDESTROMUSEDOFRMGDESTROM                                                         
#define PDUR_EQ2_TXIF2UPIDXOFRMGDESTROM                                                             
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMIDXOFRMSRCROM                                             
#define PDUR_EQ2_LOCKROMIDXOFRMSRCROM                                                               
#define PDUR_EQ2_MMROMIDXOFRMSRCROM                                                                 
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                                             
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM                                    
#define PDUR_EQ2_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                                            
#define PDUR_EQ2_RMDESTROMENDIDXOFRMSRCROM                                                          
#define PDUR_EQ2_RMDESTROMLENGTHOFRMSRCROM                                                          
#define PDUR_EQ2_RMDESTROMSTARTIDXOFRMSRCROM                                                        
#define PDUR_EQ2_SMSRCROMIDXOFRMSRCROM                                                              
#define PDUR_EQ2_SMSRCROMPARTITIONIDXOFRMSRCROM                                                     
#define PDUR_EQ2_SMSRCROMUSEDOFRMSRCROM                                                             
#define PDUR_EQ2_SRCHNDOFRMSRCROM                                                                   
#define PDUR_EQ2_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                                                 
#define PDUR_EQ2_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                                                  
#define PDUR_EQ2_RMTRANSMITFCTPTR                                                                   
#define PDUR_EQ2_INVALIDHNDOFRPGEXTIDROM                                                            
#define PDUR_EQ2_RPGROMIDXOFRPGEXTIDROM                                                             
#define PDUR_EQ2_RPGROMPARTITIONIDXOFRPGEXTIDROM                                                    
#define PDUR_EQ2_RPGROMUSEDOFRPGEXTIDROM                                                            
#define PDUR_EQ2_ENABLEDATINITOFRPGROM                                                              
#define PDUR_EQ2_RMDESTRPGROMINDENDIDXOFRPGROM                                                      
#define PDUR_EQ2_RMDESTRPGROMINDSTARTIDXOFRPGROM                                                    
#define PDUR_EQ2_RMDESTRPGROMINDUSEDOFRPGROM                                                        
#define PDUR_EQ2_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                                            
#define PDUR_EQ2_INVALIDHNDOFRXIF2DEST                                                              
#define PDUR_EQ2_RMSRCROMIDXOFRXIF2DEST                                                             
#define PDUR_EQ2_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                                          
#define PDUR_EQ2_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST                                      
#define PDUR_EQ2_INVALIDHNDOFRXTP2DEST                                                              
#define PDUR_EQ2_RMSRCROMIDXOFRXTP2DEST                                                             
#define PDUR_EQ2_INVALIDHNDOFRXTP2SRC                                                               
#define PDUR_EQ2_RMDESTROMIDXOFRXTP2SRC                                                             
#define PDUR_EQ2_SINGLEBUFFERINITVALUESROM                                                          
#define PDUR_EQ2_RMDESTROMIDXOFSINGLEBUFFERROM                                                      
#define PDUR_EQ2_SINGLEBUFFERARRAYRAMENDIDXOFSINGLEBUFFERROM                                        
#define PDUR_EQ2_SINGLEBUFFERARRAYRAMLENGTHOFSINGLEBUFFERROM                                        
#define PDUR_EQ2_SINGLEBUFFERARRAYRAMSTARTIDXOFSINGLEBUFFERROM                                      
#define PDUR_EQ2_SINGLEBUFFERINITVALUESROMENDIDXOFSINGLEBUFFERROM                                   
#define PDUR_EQ2_SINGLEBUFFERINITVALUESROMLENGTHOFSINGLEBUFFERROM                                   
#define PDUR_EQ2_SINGLEBUFFERINITVALUESROMSTARTIDXOFSINGLEBUFFERROM                                 
#define PDUR_EQ2_SMFIBRAMENDIDXOFSMDATAPLANEROM                                                     
#define PDUR_EQ2_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                                                   
#define PDUR_EQ2_SMFIBRAMUSEDOFSMDATAPLANEROM                                                       
#define PDUR_EQ2_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                            
#define PDUR_EQ2_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                           
#define PDUR_EQ2_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM                        
#define PDUR_EQ2_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM                       
#define PDUR_EQ2_SMGDESTFILTERFCTPTR                                                                
#define PDUR_EQ2_CONNECTIONIDOFSMGDESTROM                                                           
#define PDUR_EQ2_METADATALENGTHOFSMGDESTROM                                                         
#define PDUR_EQ2_SMDATAPLANEROMIDXOFSMGDESTROM                                                      
#define PDUR_EQ2_SMGDESTFILTERFCTPTRIDXOFSMGDESTROM                                                 
#define PDUR_EQ2_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR                                       
#define PDUR_EQ2_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                         
#define PDUR_EQ2_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM                                       
#define PDUR_EQ2_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   
#define PDUR_EQ2_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                               
#define PDUR_EQ2_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                                   
#define PDUR_EQ2_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM                               
#define PDUR_EQ2_SMSRCFILTERFCTPTR                                                                  
#define PDUR_EQ2_CONNECTIONIDOFSMSRCROM                                                             
#define PDUR_EQ2_METADATALENGTHOFSMSRCROM                                                           
#define PDUR_EQ2_SMDATAPLANEROMIDXOFSMSRCROM                                                        
#define PDUR_EQ2_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM                          
#define PDUR_EQ2_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM                         
#define PDUR_EQ2_SMSRCFILTERFCTPTRIDXOFSMSRCROM                                                     
#define PDUR_EQ2_DEFERREDEVENTCACHEROMIDXOFSRCAPPLICATIONROM                                        
#define PDUR_EQ2_DEFERREDEVENTCACHEROMPARTITIONIDXOFSRCAPPLICATIONROM                               
#define PDUR_EQ2_DEFERREDEVENTCACHEROMUSEDOFSRCAPPLICATIONROM                                       
#define PDUR_EQ2_MCQBUFFERROMIDXOFSRCAPPLICATIONROM                                                 
#define PDUR_EQ2_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM                                        
#define PDUR_EQ2_MCQBUFFERROMUSEDOFSRCAPPLICATIONROM                                                
#define PDUR_EQ2_BSWMPDURTRANSMITCALLBACKOFTX2LO                                                    
#define PDUR_EQ2_CANCELTRANSMITUSEDOFTX2LO                                                          
#define PDUR_EQ2_INVALIDHNDOFTX2LO                                                                  
#define PDUR_EQ2_RMSRCROMIDXOFTX2LO                                                                 
#define PDUR_EQ2_RMSRCROMUSEDOFTX2LO                                                                
#define PDUR_EQ2_RMTRANSMITFCTPTRIDXOFTX2LO                                                         
#define PDUR_EQ2_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                                            
#define PDUR_EQ2_INVALIDHNDOFTXIF2UP                                                                
#define PDUR_EQ2_RMGDESTROMIDXOFTXIF2UP                                                             
#define PDUR_EQ2_TXCONFIRMATIONUSEDOFTXIF2UP                                                        
#define PDUR_EQ2_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC                                         
#define PDUR_EQ2_INVALIDHNDOFTXTP2SRC                                                               
#define PDUR_EQ2_RMGDESTROMIDXOFTXTP2SRC                                                            
#define PDUR_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                         
#define PDUR_EQ2_INITDATAHASHCODEOFPCCONFIG                                                         
#define PDUR_EQ2_PCPARTITIONCONFIGOFPCCONFIG                                                        
#define PDUR_EQ2_PARTITIONIDENTIFIERSOFPCCONFIG                                                     PduR_PartitionIdentifiers
#define PDUR_EQ2_DESTAPPLICATIONMANAGERROMOFPCPARTITIONCONFIG                                       PduR_DestApplicationManagerRom
#define PDUR_EQ2_EXCLUSIVEAREAROMOFPCPARTITIONCONFIG                                                PduR_ExclusiveAreaRom
#define PDUR_EQ2_INITIALIZEDRAMOFPCPARTITIONCONFIG                                                  PduR_InitializedRam.raw
#define PDUR_EQ2_LOCKROMOFPCPARTITIONCONFIG                                                         PduR_LockRom
#define PDUR_EQ2_MMROMOFPCPARTITIONCONFIG                                                           PduR_MmRom
#define PDUR_EQ2_RMDESTROMOFPCPARTITIONCONFIG                                                       
#define PDUR_EQ2_RMGDESTROMOFPCPARTITIONCONFIG                                                      
#define PDUR_EQ2_RMSRCROMOFPCPARTITIONCONFIG                                                        
#define PDUR_EQ2_RMTRANSMITFCTPTROFPCPARTITIONCONFIG                                                PduR_RmTransmitFctPtr
#define PDUR_EQ2_RXTP2DESTOFPCPARTITIONCONFIG                                                       PduR_RxTp2Dest
#define PDUR_EQ2_RXTP2SRCOFPCPARTITIONCONFIG                                                        
#define PDUR_EQ2_SRCAPPLICATIONROMOFPCPARTITIONCONFIG                                               PduR_SrcApplicationRom
#define PDUR_EQ2_TX2LOOFPCPARTITIONCONFIG                                                           PduR_Tx2Lo
#define PDUR_EQ2_TXTP2SRCOFPCPARTITIONCONFIG                                                        PduR_TxTp2Src
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicNonDereferenciateablePointers  PduR Symbolic Non Dereferenciateable Pointers (PRE_COMPILE)
  \brief  Symbolic non dereferenciateable pointers to be used if all values are optimized to a defined and to return a correct value for has macros in variants.
  \{
*/ 
#define PduR_RxTp2Dest                                                                              ((PduR_RxTp2DestPtrType)(&(PduR_PCPartitionConfigRBTM_FR)))  /**< Non derefenciateable valid pointer */
#define PduR_SrcApplicationRom                                                                      ((PduR_SrcApplicationRomPtrType)(&(PduR_PCPartitionConfigRBTM_FR)))  /**< Non derefenciateable valid pointer */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicInitializationPointers  PduR Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define PduR_Config_RBTM_FL_Ptr                                                                     &(PduR_PCConfig.Config_RBTM_FL)  /**< symbolic identifier which shall be used to initialize 'PduR' */
#define PduR_Config_RBTM_FR_Ptr                                                                     &(PduR_PCConfig.Config_RBTM_FR)  /**< symbolic identifier which shall be used to initialize 'PduR' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCInitializationSymbols  PduR Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define PduR_Config_RBTM_FL                                                                         PduR_PCConfig.Config_RBTM_FL  /**< symbolic identifier which could be used to initialize 'PduR */
#define PduR_Config_RBTM_FR                                                                         PduR_PCConfig.Config_RBTM_FR  /**< symbolic identifier which could be used to initialize 'PduR */
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
#define PDUR_LTPARTITIONCONFIG                                                                      STD_OFF  /**< Deactivateable: 'PduR_LTPartitionConfigRBTM_FL' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_LTPartitionConfigRBTM_FR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRLTIsReducedToDefineDefines  PduR Is Reduced To Define Defines (LINK)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_LTPARTITIONCONFIGOFLTCONFIG                                                      STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  PduRLTEqualsAlwaysToDefines  PduR Equals Always To Defines (LINK)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_LTPARTITIONCONFIGOFLTCONFIG                                                        
/** 
  \}
*/ 



/** BroadcastDummy */

#define PDUR_MAX_TRIGGER_TRANSMIT_PDU_SIZE 1

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
#define PduR_GetFinalMagicNumberOfPCConfig()                                                          /**< Deactivateable: 'PduR_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_GetInitDataHashCodeOfPCConfig()                                                          /**< Deactivateable: 'PduR_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_GetPCPartitionConfigOfPCConfig()                                                       PduR_ConfigDataPtr->PCPartitionConfigOfPCConfig
#define PduR_GetRmDestRomOfPCPartitionConfig()                                                      PduR_GetPCPartitionConfigOfPCConfig()[(0)].RmDestRomOfPCPartitionConfig
#define PduR_GetRmGDestRomOfPCPartitionConfig()                                                     PduR_GetPCPartitionConfigOfPCConfig()[(0)].RmGDestRomOfPCPartitionConfig
#define PduR_GetRmSrcRomOfPCPartitionConfig()                                                       PduR_GetPCPartitionConfigOfPCConfig()[(0)].RmSrcRomOfPCPartitionConfig
#define PduR_GetRxTp2SrcOfPCPartitionConfig()                                                       PduR_GetPCPartitionConfigOfPCConfig()[(0)].RxTp2SrcOfPCPartitionConfig
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
#define PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)                                   PduR_InitializedRam.raw  /**< the pointer to PduR_InitializedRam */
#define PduR_GetLockRomOfPCPartitionConfig()                                                        PduR_LockRom  /**< the pointer to PduR_LockRom */
#define PduR_GetMmRomOfPCPartitionConfig()                                                          PduR_MmRom  /**< the pointer to PduR_MmRom */
#define PduR_GetRmTransmitFctPtrOfPCPartitionConfig()                                               PduR_RmTransmitFctPtr  /**< the pointer to PduR_RmTransmitFctPtr */
#define PduR_GetRxTp2DestOfPCPartitionConfig()                                                      PduR_RxTp2Dest  /**< the pointer to PduR_RxTp2Dest */
#define PduR_GetSizeOfDestApplicationManagerRomOfPCPartitionConfig()                                1u  /**< the number of accomplishable value elements in PduR_DestApplicationManagerRom */
#define PduR_GetSizeOfExclusiveAreaRomOfPCPartitionConfig()                                         1u  /**< the number of accomplishable value elements in PduR_ExclusiveAreaRom */
#define PduR_GetSizeOfInitializedRamOfPCPartitionConfig(partitionIndex)                             1u  /**< the number of accomplishable value elements in PduR_InitializedRam */
#define PduR_GetSizeOfLockRomOfPCPartitionConfig()                                                  1u  /**< the number of accomplishable value elements in PduR_LockRom */
#define PduR_GetSizeOfMmRomOfPCPartitionConfig()                                                    2u  /**< the number of accomplishable value elements in PduR_MmRom */
#define PduR_GetSizeOfRmDestRomOfPCPartitionConfig()                                                9u  /**< the number of accomplishable value elements in PduR_RmDestRom */
#define PduR_GetSizeOfRmGDestRomOfPCPartitionConfig()                                               9u  /**< the number of accomplishable value elements in PduR_RmGDestRom */
#define PduR_GetSizeOfRmSrcRomOfPCPartitionConfig()                                                 9u  /**< the number of accomplishable value elements in PduR_RmSrcRom */
#define PduR_GetSizeOfRmTransmitFctPtrOfPCPartitionConfig()                                         1u  /**< the number of accomplishable value elements in PduR_RmTransmitFctPtr */
#define PduR_GetSizeOfRxTp2DestOfPCPartitionConfig()                                                6u  /**< the number of accomplishable value elements in PduR_RxTp2Dest */
#define PduR_GetSizeOfRxTp2SrcOfPCPartitionConfig()                                                 6u  /**< the number of accomplishable value elements in PduR_RxTp2Src */
#define PduR_GetSizeOfSrcApplicationRomOfPCPartitionConfig()                                        1u  /**< the number of accomplishable value elements in PduR_SrcApplicationRom */
#define PduR_GetSizeOfTx2LoOfPCPartitionConfig()                                                    3u  /**< the number of accomplishable value elements in PduR_Tx2Lo */
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
#define PduR_GetDestApplicationManagerRomIdxOfApplicationId2DestApplicationManagerRom(Index)          /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsDestApplicationManagerRomUsedOfApplicationId2DestApplicationManagerRom(Index)          /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsInvalidHndOfApplicationId2DestApplicationManagerRom(Index)                             /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_GetBmTxBufferArrayRam(Index, partitionIndex)                                             /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferRomIdxOfBmTxBufferIndRom(Index, partitionIndex)                             /**< Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, partitionIndex)               /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetBmTxBufferRomIdxOfBmTxBufferInstanceRom(Index, partitionIndex)                        /**< Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsAllocatedOfBmTxBufferRam(Index, partitionIndex)                                        /**< Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, partitionIndex)                      /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetRxLengthOfBmTxBufferRam(Index, partitionIndex)                                        /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetBmTxBufferArrayRamEndIdxOfBmTxBufferRom(Index, partitionIndex)                        /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferArrayRamLengthOfBmTxBufferRom(Index, partitionIndex)                        /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferArrayRamStartIdxOfBmTxBufferRom(Index, partitionIndex)                      /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(Index, partitionIndex)                     /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(Index, partitionIndex)                   /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmGDestRomIdxOfDeferredEventCacheArrayRam(Index, partitionIndex)                      /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(Index, partitionIndex)       /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(Index, partitionIndex)      /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetDeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRom(Index, partitionIndex)        /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetDeferredEventCacheArrayRamLengthOfDeferredEventCacheRom(Index, partitionIndex)        /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetDeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRom(Index, partitionIndex)      /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetRmGDestRomStartIdxOfDestApplicationManagerRom(Index)                                (PduR_GetDestApplicationManagerRomOfPCPartitionConfig()[(Index)].RmGDestRomStartIdxOfDestApplicationManagerRom)
#define PduR_GetLockOfExclusiveAreaRom(Index)                                                       (PduR_GetExclusiveAreaRomOfPCPartitionConfig()[(Index)].LockOfExclusiveAreaRom)
#define PduR_GetUnlockOfExclusiveAreaRom(Index)                                                     (PduR_GetExclusiveAreaRomOfPCPartitionConfig()[(Index)].UnlockOfExclusiveAreaRom)
#define PduR_GetBmTxBufferRomIdxOfFmFifoElementRam(Index, partitionIndex)                             /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetRmDestRomIdxOfFmFifoElementRam(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, partitionIndex)                    /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetFmFifoRomIdxOfFmFifoInstanceRom(Index, partitionIndex)                                /**< Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetFillLevelOfFmFifoRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetFmFifoElementRamReadIdxOfFmFifoRam(Index, partitionIndex)                             /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetFmFifoElementRamWriteIdxOfFmFifoRam(Index, partitionIndex)                            /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetPendingConfirmationsOfFmFifoRam(Index, partitionIndex)                                /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetTpTxSmStateOfFmFifoRam(Index, partitionIndex)                                         /**< Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetBmTxBufferIndRomEndIdxOfFmFifoRom(Index, partitionIndex)                              /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferIndRomLengthOfFmFifoRom(Index, partitionIndex)                              /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetBmTxBufferIndRomStartIdxOfFmFifoRom(Index, partitionIndex)                            /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetFmFifoElementRamEndIdxOfFmFifoRom(Index, partitionIndex)                              /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetFmFifoElementRamLengthOfFmFifoRom(Index, partitionIndex)                              /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetFmFifoElementRamStartIdxOfFmFifoRom(Index, partitionIndex)                            /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetLockRomIdxOfFmFifoRom(Index, partitionIndex)                                          /**< Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IsLockRomUsedOfFmFifoRom(Index, partitionIndex)                                          /**< Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetSpinlockRetryCounterOfGeneralPropertiesRom(Index)                                     /**< Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' and Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' */
#define PduR_IshasIfRoutingOfGeneralPropertiesRom(Index)                                              /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfRouting' Reason: 'No Communication Interface BswModule active.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfRouting' Reason: 'No Communication Interface BswModule active.' */
#define PduR_IshasIfTxFifoOfGeneralPropertiesRom(Index)                                               /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'No Communication Interface BswModule active.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'No Communication Interface BswModule active.' */
#define PduR_IshasTpBufferUlSourceOfGeneralPropertiesRom(Index)                                       /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasTpBufferUlSource' Reason: 'the value of PduR_hasTpBufferUlSourceOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasTpBufferUlSource' Reason: 'the value of PduR_hasTpBufferUlSourceOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' */
#define PduR_IsInitializedRam(Index, partitionIndex)                                                ((PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)[(Index)]) != FALSE)
#define PduR_GetInterfaceFifoQueueArrayRam(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetActualLengthOfInterfaceFifoQueueElementRam(Index, partitionIndex)                     /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IsFifoFullOfInterfaceFifoQueueRam(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(Index, partitionIndex)     /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(Index, partitionIndex)    /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetInterfaceFifoQueueArrayRamEndIdxOfInterfaceFifoQueueRom(Index, partitionIndex)        /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetInterfaceFifoQueueArrayRamStartIdxOfInterfaceFifoQueueRom(Index, partitionIndex)      /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetInterfaceFifoQueueElementRamEndIdxOfInterfaceFifoQueueRom(Index, partitionIndex)      /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetInterfaceFifoQueueElementRamStartIdxOfInterfaceFifoQueueRom(Index, partitionIndex)    /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetMaxPduLengthOfInterfaceFifoQueueRom(Index, partitionIndex)                            /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmDestRomIdxOfInterfaceFifoQueueRom(Index, partitionIndex)                            /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetExclusiveAreaRomIdxOfLockRom(Index)                                                 (PduR_GetLockRomOfPCPartitionConfig()[(Index)].ExclusiveAreaRomIdxOfLockRom)
#define PduR_GetSpinlockRamIdxOfLockRom(Index)                                                        /**< Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetSpinlockRamPartitionIdxOfLockRom(Index)                                               /**< Deactivateable: 'PduR_LockRom.SpinlockRamPartitionIdx' Reason: 'the value of PduR_SpinlockRamPartitionIdxOfLockRom is always 'PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_LockRom.SpinlockRamPartitionIdx' Reason: 'the value of PduR_SpinlockRamPartitionIdxOfLockRom is always 'PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM' due to this, the array is deactivated.' */
#define PduR_IsSpinlockRamUsedOfLockRom(Index)                                                        /**< Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRam(Index, partitionIndex)                                              /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(Index, partitionIndex)                  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(Index, partitionIndex)                 /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamReadIdxOfMcQBufferRam(Index, partitionIndex)                         /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamWriteIdxOfMcQBufferRam(Index, partitionIndex)                        /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamEndIdxOfMcQBufferRom(Index, partitionIndex)                          /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamLengthOfMcQBufferRom(Index, partitionIndex)                          /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferArrayRamStartIdxOfMcQBufferRom(Index, partitionIndex)                        /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IsCancelReceiveSupportedOfMmRom(Index)                                                   /**< Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_IsIfCancelTransmitSupportedOfMmRom(Index)                                                /**< Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_GetLoIfCancelTransmitFctPtrOfMmRom(Index)                                                /**< Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_IsLoIfOfMmRom(Index)                                                                     /**< Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_GetLoIfTransmitFctPtrOfMmRom(Index)                                                      /**< Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_GetLoTpCancelReceiveFctPtrOfMmRom(Index)                                                 /**< Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_GetLoTpCancelTransmitFctPtrOfMmRom(Index)                                                /**< Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_GetLoTpChangeParameterFctPtrOfMmRom(Index)                                             (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoTpChangeParameterFctPtrOfMmRom)
#define PduR_GetLoTpTransmitFctPtrOfMmRom(Index)                                                    (PduR_GetMmRomOfPCPartitionConfig()[(Index)].LoTpTransmitFctPtrOfMmRom)
#define PduR_GetMaskedBitsOfMmRom(Index)                                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].MaskedBitsOfMmRom)
#define PduR_IsTpCancelTransmitSupportedOfMmRom(Index)                                                /**< Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_IsUpIfOfMmRom(Index)                                                                     /**< Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_GetUpIfRxIndicationFctPtrOfMmRom(Index)                                                  /**< Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_GetUpIfTriggerTransmitFctPtrOfMmRom(Index)                                               /**< Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_GetUpIfTxConfirmationFctPtrOfMmRom(Index)                                                /**< Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_GetUpTpCopyRxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpCopyRxDataFctPtrOfMmRom)
#define PduR_GetUpTpCopyTxDataFctPtrOfMmRom(Index)                                                  (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpCopyTxDataFctPtrOfMmRom)
#define PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpStartOfReceptionFctPtrOfMmRom)
#define PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(Index)                                              (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpTpRxIndicationFctPtrOfMmRom)
#define PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(Index)                                            (PduR_GetMmRomOfPCPartitionConfig()[(Index)].UpTpTpTxConfirmationFctPtrOfMmRom)
#define PduR_GetPartitionSNVOfPartitionIdentifiers(Index)                                           (PduR_GetPartitionIdentifiersOfPCConfig()[(Index)].PartitionSNVOfPartitionIdentifiers)
#define PduR_GetOsApplicationToPduROfPartitionLookupTableRam(Index)                                   /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetFlushFctPtrOfQueueFctPtrRom(Index)                                                    /**< Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetGetFctPtrOfQueueFctPtrRom(Index)                                                      /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetGetFillLevelFctPtrOfQueueFctPtrRom(Index)                                             /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetPutFctPtrOfQueueFctPtrRom(Index)                                                      /**< Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRemoveFctPtrOfQueueFctPtrRom(Index)                                                   /**< Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetIfSmStateOfRmBufferedIfPropertiesRam(Index, partitionIndex)                           /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetImplementationTypeOfRmBufferedIfPropertiesRom(Index, partitionIndex)                  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetInterfaceFifoQueueRomIdxOfRmBufferedIfPropertiesRom(Index, partitionIndex)            /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_IsInterfaceFifoQueueRomUsedOfRmBufferedIfPropertiesRom(Index, partitionIndex)            /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetQueueDataProvisionTypeOfRmBufferedIfPropertiesRom(Index, partitionIndex)              /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetQueueFctPtrRomIdxOfRmBufferedIfPropertiesRom(Index, partitionIndex)                   /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetQueueTypeOfRmBufferedIfPropertiesRom(Index, partitionIndex)                           /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetSingleBufferRomIdxOfRmBufferedIfPropertiesRom(Index, partitionIndex)                  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_IsSingleBufferRomUsedOfRmBufferedIfPropertiesRom(Index, partitionIndex)                  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, partitionIndex)                 /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetTpRxSmStateOfRmBufferedTpPropertiesRam(Index, partitionIndex)                         /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetFmFifoRomIdxOfRmBufferedTpPropertiesRom(Index, partitionIndex)                        /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetMetaDataLengthOfRmBufferedTpPropertiesRom(Index, partitionIndex)                      /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' */
#define PduR_IsMetaDataLengthUsedOfRmBufferedTpPropertiesRom(Index, partitionIndex)                   /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetQueuedDestCntOfRmBufferedTpPropertiesRom(Index, partitionIndex)                       /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.QueuedDestCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.QueuedDestCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetTpThresholdOfRmBufferedTpPropertiesRom(Index, partitionIndex)                         /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsBswMPduRPreTransmitCallbackOfRmDestRom(Index)                                          /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RmDestRomRBTM_FR.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' */
#define PduR_GetPduLengthHandlingStrategyOfRmDestRom(Index)                                         (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].PduLengthHandlingStrategyOfRmDestRom)
#define PduR_GetRmDestRpgRomIdxOfRmDestRom(Index)                                                     /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmDestRpgRomPartitionIdxOfRmDestRom(Index)                                            /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' */
#define PduR_IsRmDestRpgRomUsedOfRmDestRom(Index)                                                     /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmGDestRomIdxOfRmDestRom(Index)                                                     (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfRmDestRom)
#define PduR_GetRmSrcRomIdxOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RmSrcRomIdxOfRmDestRom)
#define PduR_GetRoutingTypeOfRmDestRom(Index)                                                       (PduR_GetRmDestRomOfPCPartitionConfig()[(Index)].RoutingTypeOfRmDestRom)
#define PduR_GetEnabledCntOfRmDestRpgRam(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetInitialEnabledCntOfRmDestRpgRom(Index, partitionIndex)                                /**< Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmDestRomIdxOfRmDestRpgRom(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsRmDestRomUsedOfRmDestRpgRom(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmDestRpgRomInd(Index, partitionIndex)                                                /**< Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmDestRomIdxOfRmGDestNto1InfoRam(Index, partitionIndex)                               /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IsTransmissionActiveOfRmGDestNto1InfoRam(Index, partitionIndex)                          /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetDestHndOfRmGDestRom(Index)                                                          (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].DestHndOfRmGDestRom)
#define PduR_GetDirectionOfRmGDestRom(Index)                                                        (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].DirectionOfRmGDestRom)
#define PduR_GetFmFifoInstanceRomIdxOfRmGDestRom(Index)                                               /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetFmFifoInstanceRomPartitionIdxOfRmGDestRom(Index)                                      /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_IsFmFifoInstanceRomUsedOfRmGDestRom(Index)                                               /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetLockRomIdxOfRmGDestRom(Index)                                                       (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].LockRomIdxOfRmGDestRom)
#define PduR_GetMaxPduLengthOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MaxPduLengthOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmGDestRom(Index)                                                         (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].MmRomIdxOfRmGDestRom)
#define PduR_GetRmBufferedIfPropertiesRomIdxOfRmGDestRom(Index)                                       /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetRmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom(Index)                              /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_IsRmBufferedIfPropertiesRomUsedOfRmGDestRom(Index)                                       /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_GetRmDestRomIdxOfRmGDestRom(Index)                                                     (PduR_GetRmGDestRomOfPCPartitionConfig()[(Index)].RmDestRomIdxOfRmGDestRom)
#define PduR_GetRmGDestNto1InfoRamIdxOfRmGDestRom(Index)                                              /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmGDestNto1InfoRamPartitionIdxOfRmGDestRom(Index)                                     /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_IsRmGDestNto1InfoRamUsedOfRmGDestRom(Index)                                              /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmGDestTpTxStateRamIdxOfRmGDestRom(Index)                                             /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmGDestTpTxStateRamPartitionIdxOfRmGDestRom(Index)                                    /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_IsRmGDestTpTxStateRamUsedOfRmGDestRom(Index)                                             /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetSmGDestRomIdxOfRmGDestRom(Index)                                                      /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmGDestRomPartitionIdxOfRmGDestRom(Index)                                             /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_IsSmGDestRomUsedOfRmGDestRom(Index)                                                      /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetTpTxInstSmStateOfRmGDestTpTxStateRam(Index, partitionIndex)                           /**< Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetLockRomIdxOfRmSrcRom(Index)                                                         (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].LockRomIdxOfRmSrcRom)
#define PduR_GetMmRomIdxOfRmSrcRom(Index)                                                           (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].MmRomIdxOfRmSrcRom)
#define PduR_GetRmBufferedTpPropertiesRomIdxOfRmSrcRom(Index)                                         /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom(Index)                                /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PduR_IsRmBufferedTpPropertiesRomUsedOfRmSrcRom(Index)                                         /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_GetRmDestRomStartIdxOfRmSrcRom(Index)                                                  (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].RmDestRomStartIdxOfRmSrcRom)
#define PduR_GetSmSrcRomIdxOfRmSrcRom(Index)                                                          /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmSrcRomPartitionIdxOfRmSrcRom(Index)                                                 /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PduR_IsSmSrcRomUsedOfRmSrcRom(Index)                                                          /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSrcHndOfRmSrcRom(Index)                                                             (PduR_GetRmSrcRomOfPCPartitionConfig()[(Index)].SrcHndOfRmSrcRom)
#define PduR_IsTriggerTransmitSupportedOfRmSrcRom(Index)                                              /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' */
#define PduR_IsTxConfirmationSupportedOfRmSrcRom(Index)                                               /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' */
#define PduR_GetRmTransmitFctPtr(Index)                                                             (PduR_GetRmTransmitFctPtrOfPCPartitionConfig()[(Index)])
#define PduR_IsInvalidHndOfRpgExtIdRom(Index)                                                         /**< Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_GetRpgRomIdxOfRpgExtIdRom(Index)                                                         /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRpgRomPartitionIdxOfRpgExtIdRom(Index)                                                /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsRpgRomUsedOfRpgExtIdRom(Index)                                                         /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsEnabledOfRpgRam(Index, partitionIndex)                                                 /**< Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IsEnabledAtInitOfRpgRom(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmDestRpgRomIndEndIdxOfRpgRom(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetRmDestRpgRomIndStartIdxOfRpgRom(Index, partitionIndex)                                /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsRmDestRpgRomIndUsedOfRpgRom(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsBswMPduRRxIndicationCallbackOfRxIf2Dest(Index)                                         /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_IsInvalidHndOfRxIf2Dest(Index)                                                           /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_GetRmSrcRomIdxOfRxIf2Dest(Index)                                                         /**< Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_IsBswMPduRTpRxIndicationCallbackOfRxTp2Dest(Index)                                       /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PduR_IsBswMPduRTpStartOfReceptionCallbackOfRxTp2Dest(Index)                                   /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PduR_IsInvalidHndOfRxTp2Dest(Index)                                                           /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PduR_IsInvalidHndOfRxTp2Src(Index)                                                            /**< Deactivateable: 'PduR_RxTp2SrcRBTM_FL.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FL.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FR.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FR.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PduR_GetRmDestRomIdxOfRxTp2Src(Index)                                                       (PduR_GetRxTp2SrcOfPCPartitionConfig()[(Index)].RmDestRomIdxOfRxTp2Src)
#define PduR_GetSingleBufferArrayRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferInitValuesRom(Index, partitionIndex)                                      /**< Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetActualLengthOfSingleBufferRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_GetRmDestRomIdxOfSingleBufferRom(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferArrayRamEndIdxOfSingleBufferRom(Index, partitionIndex)                    /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferArrayRamLengthOfSingleBufferRom(Index, partitionIndex)                    /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferArrayRamStartIdxOfSingleBufferRom(Index, partitionIndex)                  /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferInitValuesRomEndIdxOfSingleBufferRom(Index, partitionIndex)               /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferInitValuesRomLengthOfSingleBufferRom(Index, partitionIndex)               /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSingleBufferInitValuesRomStartIdxOfSingleBufferRom(Index, partitionIndex)             /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetSmFibRamEndIdxOfSmDataPlaneRom(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmFibRamStartIdxOfSmDataPlaneRom(Index, partitionIndex)                               /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_IsSmFibRamUsedOfSmDataPlaneRom(Index, partitionIndex)                                    /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmLinearTaToSaCalculationStrategyRomIdxOfSmDataPlaneRom(Index, partitionIndex)        /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_IsSmLinearTaToSaCalculationStrategyRomUsedOfSmDataPlaneRom(Index, partitionIndex)        /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmSaTaFromMetaDataCalculationStrategyRomIdxOfSmDataPlaneRom(Index, partitionIndex)    /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_IsSmSaTaFromMetaDataCalculationStrategyRomUsedOfSmDataPlaneRom(Index, partitionIndex)    /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetLearnedConnectionIdOfSmFibRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmGDestFilterFctPtr(Index, partitionIndex)                                            /**< Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetConnectionIdOfSmGDestRom(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetMetaDataLengthOfSmGDestRom(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmDataPlaneRomIdxOfSmGDestRom(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmGDestFilterFctPtrIdxOfSmGDestRom(Index, partitionIndex)                             /**< Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmLinearTaToSaCalculationStrategyGetSaFctPtr(Index, partitionIndex)                   /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetMaskOfSmLinearTaToSaCalculationStrategyRom(Index, partitionIndex)                     /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetOffsetOfSmLinearTaToSaCalculationStrategyRom(Index, partitionIndex)                   /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSaMaskOfSmSaTaFromMetaDataCalculationStrategyRom(Index, partitionIndex)               /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSaStartBitOfSmSaTaFromMetaDataCalculationStrategyRom(Index, partitionIndex)           /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetTaMaskOfSmSaTaFromMetaDataCalculationStrategyRom(Index, partitionIndex)               /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetTaStartBitOfSmSaTaFromMetaDataCalculationStrategyRom(Index, partitionIndex)           /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmSrcFilterFctPtr(Index, partitionIndex)                                              /**< Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetConnectionIdOfSmSrcRom(Index, partitionIndex)                                         /**< Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetMetaDataLengthOfSmSrcRom(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmDataPlaneRomIdxOfSmSrcRom(Index, partitionIndex)                                    /**< Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmLinearTaToSaCalculationStrategyGetSaFctPtrIdxOfSmSrcRom(Index, partitionIndex)      /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_IsSmLinearTaToSaCalculationStrategyGetSaFctPtrUsedOfSmSrcRom(Index, partitionIndex)      /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetSmSrcFilterFctPtrIdxOfSmSrcRom(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_GetCounterOfSpinlockRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetLockVariableOfSpinlockRam(Index, partitionIndex)                                      /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetDeferredEventCacheRomIdxOfSrcApplicationRom(Index)                                    /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_IsDeferredEventCacheRomUsedOfSrcApplicationRom(Index)                                    /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' */
#define PduR_GetMcQBufferRomIdxOfSrcApplicationRom(Index)                                             /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetMcQBufferRomPartitionIdxOfSrcApplicationRom(Index)                                    /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomPartitionIdx' Reason: 'the value of PduR_McQBufferRomPartitionIdxOfSrcApplicationRom is always 'PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomPartitionIdx' Reason: 'the value of PduR_McQBufferRomPartitionIdxOfSrcApplicationRom is always 'PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM' due to this, the array is deactivated.' */
#define PduR_IsMcQBufferRomUsedOfSrcApplicationRom(Index)                                             /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IsBswMPduRTransmitCallbackOfTx2Lo(Index)                                                 /**< Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' */
#define PduR_IsCancelTransmitUsedOfTx2Lo(Index)                                                       /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' and Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' */
#define PduR_IsInvalidHndOfTx2Lo(Index)                                                               /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PduR_GetRmSrcRomIdxOfTx2Lo(Index)                                                           (PduR_GetTx2LoOfPCPartitionConfig()[(Index)].RmSrcRomIdxOfTx2Lo)
#define PduR_GetRmTransmitFctPtrIdxOfTx2Lo(Index)                                                   (PduR_GetTx2LoOfPCPartitionConfig()[(Index)].RmTransmitFctPtrIdxOfTx2Lo)
#define PduR_IsBswMPduRTxConfirmationCallbackOfTxIf2Up(Index)                                         /**< Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PduR_IsInvalidHndOfTxIf2Up(Index)                                                             /**< Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_GetRmGDestRomIdxOfTxIf2Up(Index)                                                         /**< Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IsTxConfirmationUsedOfTxIf2Up(Index)                                                     /**< Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' and Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' */
#define PduR_IsBswMPduRTpTxConfirmationCallbackOfTxTp2Src(Index)                                      /**< Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PduR_IsInvalidHndOfTxTp2Src(Index)                                                            /**< Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PduR_GetRmGDestRomIdxOfTxTp2Src(Index)                                                      (PduR_GetTxTp2SrcOfPCPartitionConfig()[(Index)].RmGDestRomIdxOfTxTp2Src)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetBitDataMacros  PduR Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define PduR_IsLoTpOfMmRom(Index)                                                                   (PDUR_LOTPOFMMROM_MASK == (PduR_GetMaskedBitsOfMmRom(Index) & PDUR_LOTPOFMMROM_MASK))  /**< Is the module a lower transport protocol module. */
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
#define PduR_GetRmGDestRomEndIdxOfDestApplicationManagerRom(Index)                                  ((PduR_RmGDestRomEndIdxOfDestApplicationManagerRomType)((((PduR_RmGDestRomEndIdxOfDestApplicationManagerRomType)(Index)) + 9u)))  /**< the end index of the 0:n relation pointing to PduR_RmGDestRom */
#define PduR_IsRmGDestRomUsedOfDestApplicationManagerRom(Index)                                     (((boolean)(PduR_GetRmGDestRomStartIdxOfDestApplicationManagerRom(Index) != PDUR_NO_RMGDESTROMSTARTIDXOFDESTAPPLICATIONMANAGERROM)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to PduR_RmGDestRom */
#define PduR_GetSrcApplicationRomEndIdxOfDestApplicationManagerRom(Index)                           ((PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType)((((PduR_SrcApplicationRomEndIdxOfDestApplicationManagerRomType)(Index)) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_SrcApplicationRom */
#define PduR_GetSrcApplicationRomStartIdxOfDestApplicationManagerRom(Index)                         ((PduR_SrcApplicationRomStartIdxOfDestApplicationManagerRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_SrcApplicationRom */
#define PduR_GetFinalMagicNumber()                                                                    /**< Deactivateable: 'PduR_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_GetInitDataHashCode()                                                                    /**< Deactivateable: 'PduR_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_IsExclusiveAreaRomUsedOfLockRom(Index)                                                 (((boolean)(PduR_GetExclusiveAreaRomIdxOfLockRom(Index) != PDUR_NO_EXCLUSIVEAREAROMIDXOFLOCKROM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_ExclusiveAreaRom */
#define PduR_IsChangeParameterSupportedOfMmRom(Index)                                               PduR_IsLoTpOfMmRom(Index)  /**< Does the module support the ChangeParameter API. */
#define PduR_IsUpTpOfMmRom(Index)                                                                   (((!(PduR_IsLoTpOfMmRom(Index)))) != FALSE)  /**< Is the module a upper transport protocol module. */
#define PduR_GetPCPartitionConfigIdxOfPartitionIdentifiers(Index)                                   ((PduR_PCPartitionConfigIdxOfPartitionIdentifiersType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_PCPartitionConfig */
#define PduR_GetDestApplicationManagerRomIdxOfRmGDestRom(Index)                                     PduR_GetLockRomIdxOfRmGDestRom(Index)  /**< the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom */
#define PduR_GetPduRDestPduProcessingOfRmGDestRom(Index)                                            ((PduR_PduRDestPduProcessingOfRmGDestRomType)((PduR_GetLockRomIdxOfRmGDestRom(Index) + 1u)))  /**< Is Processing Type of destination PDU. */
#define PduR_GetTxIf2UpIdxOfRmGDestRom(Index)                                                       PduR_GetLockRomIdxOfRmGDestRom(Index)  /**< TxIf2Up index. */
#define PduR_GetDestApplicationManagerRomIdxOfRmSrcRom(Index)                                       PduR_GetLockRomIdxOfRmSrcRom(Index)  /**< the index of the 1:1 relation pointing to PduR_DestApplicationManagerRom */
#define PduR_GetRmDestRomEndIdxOfRmSrcRom(Index)                                                    ((PduR_RmDestRomEndIdxOfRmSrcRomType)((PduR_GetRmDestRomStartIdxOfRmSrcRom(Index) + 1u)))  /**< the end index of the 1:n relation pointing to PduR_RmDestRom */
#define PduR_GetRmDestRomLengthOfRmSrcRom(Index)                                                    ((PduR_RmDestRomLengthOfRmSrcRomType)((PduR_GetLockRomIdxOfRmSrcRom(Index) + 1u)))  /**< the number of relations pointing to PduR_RmDestRom */
#define PduR_GetRmSrcRomIdxOfRxTp2Dest(Index)                                                       ((PduR_RmSrcRomIdxOfRxTp2DestType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
#define PduR_GetSizeOfDestApplicationManagerRom()                                                   PduR_GetSizeOfDestApplicationManagerRomOfPCPartitionConfig()
#define PduR_GetSizeOfExclusiveAreaRom()                                                            PduR_GetSizeOfExclusiveAreaRomOfPCPartitionConfig()
#define PduR_GetSizeOfInitializedRam(partitionIndex)                                                PduR_GetSizeOfInitializedRamOfPCPartitionConfig(partitionIndex)
#define PduR_GetSizeOfLockRom()                                                                     PduR_GetSizeOfLockRomOfPCPartitionConfig()
#define PduR_GetSizeOfMmRom()                                                                       PduR_GetSizeOfMmRomOfPCPartitionConfig()
#define PduR_GetSizeOfPartitionIdentifiers()                                                        PduR_GetSizeOfPartitionIdentifiersOfPCConfig()
#define PduR_GetSizeOfRmDestRom()                                                                   PduR_GetSizeOfRmDestRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmGDestRom()                                                                  PduR_GetSizeOfRmGDestRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmSrcRom()                                                                    PduR_GetSizeOfRmSrcRomOfPCPartitionConfig()
#define PduR_GetSizeOfRmTransmitFctPtr()                                                            PduR_GetSizeOfRmTransmitFctPtrOfPCPartitionConfig()
#define PduR_GetSizeOfRxTp2Dest()                                                                   PduR_GetSizeOfRxTp2DestOfPCPartitionConfig()
#define PduR_GetSizeOfRxTp2Src()                                                                    PduR_GetSizeOfRxTp2SrcOfPCPartitionConfig()
#define PduR_GetSizeOfSrcApplicationRom()                                                           PduR_GetSizeOfSrcApplicationRomOfPCPartitionConfig()
#define PduR_GetSizeOfTx2Lo()                                                                       PduR_GetSizeOfTx2LoOfPCPartitionConfig()
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
#define PduR_SetBmTxBufferArrayRam(Index, Value, partitionIndex)                                      /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_SetBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, Value, partitionIndex)        /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetAllocatedOfBmTxBufferRam(Index, Value, partitionIndex)                                /**< Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, Value, partitionIndex)               /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetRxLengthOfBmTxBufferRam(Index, Value, partitionIndex)                                 /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetRmGDestRomIdxOfDeferredEventCacheArrayRam(Index, Value, partitionIndex)               /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_SetDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_SetDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_SetBmTxBufferRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                      /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetRmDestRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                          /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, Value, partitionIndex)             /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetFillLevelOfFmFifoRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetFmFifoElementRamReadIdxOfFmFifoRam(Index, Value, partitionIndex)                      /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetFmFifoElementRamWriteIdxOfFmFifoRam(Index, Value, partitionIndex)                     /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetPendingConfirmationsOfFmFifoRam(Index, Value, partitionIndex)                         /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetTpTxSmStateOfFmFifoRam(Index, Value, partitionIndex)                                  /**< Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetInitializedRam(Index, Value, partitionIndex)                                        PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)[(Index)] = (Value)
#define PduR_SetInterfaceFifoQueueArrayRam(Index, Value, partitionIndex)                              /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_SetActualLengthOfInterfaceFifoQueueElementRam(Index, Value, partitionIndex)              /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetFifoFullOfInterfaceFifoQueueRam(Index, Value, partitionIndex)                         /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetMcQBufferArrayRam(Index, Value, partitionIndex)                                       /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SetMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(Index, Value, partitionIndex)           /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SetMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(Index, Value, partitionIndex)          /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SetMcQBufferArrayRamReadIdxOfMcQBufferRam(Index, Value, partitionIndex)                  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SetMcQBufferArrayRamWriteIdxOfMcQBufferRam(Index, Value, partitionIndex)                 /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SetOsApplicationToPduROfPartitionLookupTableRam(Index, Value)                            /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetIfSmStateOfRmBufferedIfPropertiesRam(Index, Value, partitionIndex)                    /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_SetFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)          /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetTpRxSmStateOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)                  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetEnabledCntOfRmDestRpgRam(Index, Value, partitionIndex)                                /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetRmDestRomIdxOfRmGDestNto1InfoRam(Index, Value, partitionIndex)                        /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetTransmissionActiveOfRmGDestNto1InfoRam(Index, Value, partitionIndex)                  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetTpTxInstSmStateOfRmGDestTpTxStateRam(Index, Value, partitionIndex)                    /**< Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetEnabledOfRpgRam(Index, Value, partitionIndex)                                         /**< Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetSingleBufferArrayRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_SetActualLengthOfSingleBufferRam(Index, Value, partitionIndex)                           /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SetLearnedConnectionIdOfSmFibRam(Index, Value, partitionIndex)                           /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_SetCounterOfSpinlockRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SetLockVariableOfSpinlockRam(Index, Value, partitionIndex)                               /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetAddressOfDataMacros  PduR Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define PduR_GetAddrBmTxBufferArrayRam(Index, partitionIndex)                                         /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetAddrInitializedRam(Index, partitionIndex)                                           (&(PduR_GetInitializedRamOfPCPartitionConfig(partitionIndex)[(Index)]))
#define PduR_GetAddrInterfaceFifoQueueArrayRam(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetAddrMcQBufferArrayRam(Index, partitionIndex)                                          /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetAddrSingleBufferArrayRam(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetAddrSingleBufferInitValuesRom(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_GetAddrCounterOfSpinlockRam(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_GetAddrLockVariableOfSpinlockRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCHasMacros  PduR Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasApplicationId2DestApplicationManagerRom()                                             /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasDestApplicationManagerRomIdxOfApplicationId2DestApplicationManagerRom()               /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasDestApplicationManagerRomUsedOfApplicationId2DestApplicationManagerRom()              /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.DestApplicationManagerRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasInvalidHndOfApplicationId2DestApplicationManagerRom()                                 /**< Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_ApplicationId2DestApplicationManagerRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasBmTxBufferArrayRam(partitionIndex)                                                    /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferIndRom(partitionIndex)                                                      /**< Deactivateable: 'PduR_BmTxBufferIndRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_BmTxBufferIndRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasBmTxBufferRomIdxOfBmTxBufferIndRom(partitionIndex)                                    /**< Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferInstanceRam(partitionIndex)                                                 /**< Deactivateable: 'PduR_BmTxBufferInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(partitionIndex)                      /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasBmTxBufferInstanceRom(partitionIndex)                                                 /**< Deactivateable: 'PduR_BmTxBufferInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_BmTxBufferInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasBmTxBufferRomIdxOfBmTxBufferInstanceRom(partitionIndex)                               /**< Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferRam(partitionIndex)                                                         /**< Deactivateable: 'PduR_BmTxBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasAllocatedOfBmTxBufferRam(partitionIndex)                                              /**< Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.Allocated' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(partitionIndex)                             /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRxLengthOfBmTxBufferRam(partitionIndex)                                               /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasBmTxBufferRom(partitionIndex)                                                         /**< Deactivateable: 'PduR_BmTxBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_BmTxBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasBmTxBufferArrayRamEndIdxOfBmTxBufferRom(partitionIndex)                               /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferArrayRamLengthOfBmTxBufferRom(partitionIndex)                               /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferArrayRamStartIdxOfBmTxBufferRom(partitionIndex)                             /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferInstanceRomEndIdxOfBmTxBufferRom(partitionIndex)                            /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferInstanceRomStartIdxOfBmTxBufferRom(partitionIndex)                          /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasConfigId(partitionIndex)                                                            (TRUE != FALSE)
#define PduR_HasDeferredEventCacheArrayRam(partitionIndex)                                            /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasRmGDestRomIdxOfDeferredEventCacheArrayRam(partitionIndex)                             /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheRam(partitionIndex)                                                 /**< Deactivateable: 'PduR_DeferredEventCacheRam' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(partitionIndex)              /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(partitionIndex)             /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheRom(partitionIndex)                                                 /**< Deactivateable: 'PduR_DeferredEventCacheRom' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheArrayRamEndIdxOfDeferredEventCacheRom(partitionIndex)               /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamEndIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheArrayRamLengthOfDeferredEventCacheRom(partitionIndex)               /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamLength' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheArrayRamStartIdxOfDeferredEventCacheRom(partitionIndex)             /**< Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRom.DeferredEventCacheArrayRamStartIdx' Reason: 'No Deferred Event Cache is configured' */
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
#define PduR_HasFinalMagicNumber()                                                                    /**< Deactivateable: 'PduR_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_HasFmFifoElementRam(partitionIndex)                                                      /**< Deactivateable: 'PduR_FmFifoElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasBmTxBufferRomIdxOfFmFifoElementRam(partitionIndex)                                    /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRmDestRomIdxOfFmFifoElementRam(partitionIndex)                                        /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFmFifoInstanceRam(partitionIndex)                                                     /**< Deactivateable: 'PduR_FmFifoInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(partitionIndex)                           /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFmFifoInstanceRom(partitionIndex)                                                     /**< Deactivateable: 'PduR_FmFifoInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_FmFifoInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasFmFifoRomIdxOfFmFifoInstanceRom(partitionIndex)                                       /**< Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasFmFifoRam(partitionIndex)                                                             /**< Deactivateable: 'PduR_FmFifoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFillLevelOfFmFifoRam(partitionIndex)                                                  /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFmFifoElementRamReadIdxOfFmFifoRam(partitionIndex)                                    /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFmFifoElementRamWriteIdxOfFmFifoRam(partitionIndex)                                   /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasPendingConfirmationsOfFmFifoRam(partitionIndex)                                       /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasTpTxSmStateOfFmFifoRam(partitionIndex)                                                /**< Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFmFifoRom(partitionIndex)                                                             /**< Deactivateable: 'PduR_FmFifoRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_FmFifoRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasBmTxBufferIndRomEndIdxOfFmFifoRom(partitionIndex)                                     /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferIndRomLengthOfFmFifoRom(partitionIndex)                                     /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasBmTxBufferIndRomStartIdxOfFmFifoRom(partitionIndex)                                   /**< Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasFmFifoElementRamEndIdxOfFmFifoRom(partitionIndex)                                     /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasFmFifoElementRamLengthOfFmFifoRom(partitionIndex)                                     /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasFmFifoElementRamStartIdxOfFmFifoRom(partitionIndex)                                   /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasLockRomIdxOfFmFifoRom(partitionIndex)                                                 /**< Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_FmFifoRom.LockRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasLockRomUsedOfFmFifoRom(partitionIndex)                                                /**< Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_FmFifoRom.LockRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasGeneralPropertiesRom()                                                                /**< Deactivateable: 'PduR_GeneralPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_GeneralPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasSpinlockRetryCounterOfGeneralPropertiesRom()                                          /**< Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' and Deactivateable: 'PduR_GeneralPropertiesRom.SpinlockRetryCounter' Reason: 'No Spinlocks used.' */
#define PduR_HashasIfRoutingOfGeneralPropertiesRom()                                                  /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfRouting' Reason: 'No Communication Interface BswModule active.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfRouting' Reason: 'No Communication Interface BswModule active.' */
#define PduR_HashasIfTxFifoOfGeneralPropertiesRom()                                                   /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'No Communication Interface BswModule active.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasIfTxFifo' Reason: 'No Communication Interface BswModule active.' */
#define PduR_HashasTpBufferUlSourceOfGeneralPropertiesRom()                                           /**< Deactivateable: 'PduR_GeneralPropertiesRom.hasTpBufferUlSource' Reason: 'the value of PduR_hasTpBufferUlSourceOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_GeneralPropertiesRom.hasTpBufferUlSource' Reason: 'the value of PduR_hasTpBufferUlSourceOfGeneralPropertiesRom is always 'false' due to this, the array is deactivated.' */
#define PduR_HasInitDataHashCode()                                                                    /**< Deactivateable: 'PduR_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_HasInitializedRam(partitionIndex)                                                      (TRUE != FALSE)
#define PduR_HasInterfaceFifoQueueArrayRam(partitionIndex)                                            /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasInterfaceFifoQueueElementRam(partitionIndex)                                          /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasActualLengthOfInterfaceFifoQueueElementRam(partitionIndex)                            /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasInterfaceFifoQueueRam(partitionIndex)                                                 /**< Deactivateable: 'PduR_InterfaceFifoQueueRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFifoFullOfInterfaceFifoQueueRam(partitionIndex)                                       /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.FifoFull' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(partitionIndex)            /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(partitionIndex)           /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasInterfaceFifoQueueRom(partitionIndex)                                                 /**< Deactivateable: 'PduR_InterfaceFifoQueueRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_InterfaceFifoQueueRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasInterfaceFifoQueueArrayRamEndIdxOfInterfaceFifoQueueRom(partitionIndex)               /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasInterfaceFifoQueueArrayRamStartIdxOfInterfaceFifoQueueRom(partitionIndex)             /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasInterfaceFifoQueueElementRamEndIdxOfInterfaceFifoQueueRom(partitionIndex)             /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasInterfaceFifoQueueElementRamStartIdxOfInterfaceFifoQueueRom(partitionIndex)           /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.InterfaceFifoQueueElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasMaxPduLengthOfInterfaceFifoQueueRom(partitionIndex)                                   /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.MaxPduLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRomIdxOfInterfaceFifoQueueRom(partitionIndex)                                   /**< Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasLockRom()                                                                           (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomIdxOfLockRom()                                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomUsedOfLockRom()                                                     (TRUE != FALSE)
#define PduR_HasSpinlockRamIdxOfLockRom()                                                             /**< Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_LockRom.SpinlockRamIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasSpinlockRamPartitionIdxOfLockRom()                                                    /**< Deactivateable: 'PduR_LockRom.SpinlockRamPartitionIdx' Reason: 'the value of PduR_SpinlockRamPartitionIdxOfLockRom is always 'PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_LockRom.SpinlockRamPartitionIdx' Reason: 'the value of PduR_SpinlockRamPartitionIdxOfLockRom is always 'PDUR_NO_SPINLOCKRAMPARTITIONIDXOFLOCKROM' due to this, the array is deactivated.' */
#define PduR_HasSpinlockRamUsedOfLockRom()                                                            /**< Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_LockRom.SpinlockRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRam(partitionIndex)                                                     /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferRam(partitionIndex)                                                          /**< Deactivateable: 'PduR_McQBufferRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(partitionIndex)                         /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(partitionIndex)                        /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamReadIdxOfMcQBufferRam(partitionIndex)                                /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamWriteIdxOfMcQBufferRam(partitionIndex)                               /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferRom(partitionIndex)                                                          /**< Deactivateable: 'PduR_McQBufferRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamEndIdxOfMcQBufferRom(partitionIndex)                                 /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamLengthOfMcQBufferRom(partitionIndex)                                 /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferArrayRamStartIdxOfMcQBufferRom(partitionIndex)                               /**< Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRom.McQBufferArrayRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMmRom()                                                                             (TRUE != FALSE)
#define PduR_HasCancelReceiveSupportedOfMmRom()                                                       /**< Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_HasChangeParameterSupportedOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasIfCancelTransmitSupportedOfMmRom()                                                    /**< Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_HasLoIfCancelTransmitFctPtrOfMmRom()                                                     /**< Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasLoIfOfMmRom()                                                                         /**< Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_HasLoIfTransmitFctPtrOfMmRom()                                                           /**< Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasLoTpCancelReceiveFctPtrOfMmRom()                                                      /**< Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasLoTpCancelTransmitFctPtrOfMmRom()                                                     /**< Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasLoTpChangeParameterFctPtrOfMmRom()                                                  (TRUE != FALSE)
#define PduR_HasLoTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasLoTpTransmitFctPtrOfMmRom()                                                         (TRUE != FALSE)
#define PduR_HasMaskedBitsOfMmRom()                                                                 (TRUE != FALSE)
#define PduR_HasTpCancelTransmitSupportedOfMmRom()                                                    /**< Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_HasUpIfOfMmRom()                                                                         /**< Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PduR_HasUpIfRxIndicationFctPtrOfMmRom()                                                       /**< Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasUpIfTriggerTransmitFctPtrOfMmRom()                                                    /**< Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasUpIfTxConfirmationFctPtrOfMmRom()                                                     /**< Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' and Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PduR_HasUpTpCopyRxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpCopyTxDataFctPtrOfMmRom()                                                       (TRUE != FALSE)
#define PduR_HasUpTpOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasUpTpStartOfReceptionFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasUpTpTpRxIndicationFctPtrOfMmRom()                                                   (TRUE != FALSE)
#define PduR_HasUpTpTpTxConfirmationFctPtrOfMmRom()                                                 (TRUE != FALSE)
#define PduR_HasPartitionIdentifiers()                                                              (TRUE != FALSE)
#define PduR_HasPCPartitionConfigIdxOfPartitionIdentifiers()                                        (TRUE != FALSE)
#define PduR_HasPartitionSNVOfPartitionIdentifiers()                                                (TRUE != FALSE)
#define PduR_HasPartitionLookupTableRam()                                                             /**< Deactivateable: 'PduR_PartitionLookupTableRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasOsApplicationToPduROfPartitionLookupTableRam()                                        /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasQueueFctPtrRom()                                                                      /**< Deactivateable: 'PduR_QueueFctPtrRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_QueueFctPtrRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasFlushFctPtrOfQueueFctPtrRom()                                                         /**< Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.FlushFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasGetFctPtrOfQueueFctPtrRom()                                                           /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.GetFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasGetFillLevelFctPtrOfQueueFctPtrRom()                                                  /**< Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.GetFillLevelFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasPutFctPtrOfQueueFctPtrRom()                                                           /**< Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.PutFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRemoveFctPtrOfQueueFctPtrRom()                                                        /**< Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_QueueFctPtrRom.RemoveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmBufferedIfPropertiesRam(partitionIndex)                                             /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasIfSmStateOfRmBufferedIfPropertiesRam(partitionIndex)                                  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasRmBufferedIfPropertiesRom(partitionIndex)                                             /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasImplementationTypeOfRmBufferedIfPropertiesRom(partitionIndex)                         /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.ImplementationType' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasInterfaceFifoQueueRomIdxOfRmBufferedIfPropertiesRom(partitionIndex)                   /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasInterfaceFifoQueueRomUsedOfRmBufferedIfPropertiesRom(partitionIndex)                  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.InterfaceFifoQueueRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasQueueDataProvisionTypeOfRmBufferedIfPropertiesRom(partitionIndex)                     /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueDataProvisionType' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasQueueFctPtrRomIdxOfRmBufferedIfPropertiesRom(partitionIndex)                          /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueFctPtrRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasQueueTypeOfRmBufferedIfPropertiesRom(partitionIndex)                                  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.QueueType' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasSingleBufferRomIdxOfRmBufferedIfPropertiesRom(partitionIndex)                         /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasSingleBufferRomUsedOfRmBufferedIfPropertiesRom(partitionIndex)                        /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmBufferedIfPropertiesRom.SingleBufferRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasRmBufferedTpPropertiesRam(partitionIndex)                                             /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(partitionIndex)                        /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasTpRxSmStateOfRmBufferedTpPropertiesRam(partitionIndex)                                /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRmBufferedTpPropertiesRom(partitionIndex)                                             /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasFmFifoRomIdxOfRmBufferedTpPropertiesRom(partitionIndex)                               /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasMetaDataLengthOfRmBufferedTpPropertiesRom(partitionIndex)                             /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'Meta Data Support is not active' */
#define PduR_HasMetaDataLengthUsedOfRmBufferedTpPropertiesRom(partitionIndex)                         /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasQueuedDestCntOfRmBufferedTpPropertiesRom(partitionIndex)                              /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.QueuedDestCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.QueuedDestCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasTpThresholdOfRmBufferedTpPropertiesRom(partitionIndex)                                /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRom()                                                                         (PduR_GetRmDestRomOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasBswMPduRPreTransmitCallbackOfRmDestRom()                                              /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RmDestRomRBTM_FR.BswMPduRPreTransmitCallback' Reason: 'Callback Support is not active' */
#define PduR_HasPduLengthHandlingStrategyOfRmDestRom()                                              (TRUE != FALSE)
#define PduR_HasRmDestRpgRomIdxOfRmDestRom()                                                          /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmDestRpgRomPartitionIdxOfRmDestRom()                                                 /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomPartitionIdx' Reason: 'the value of PduR_RmDestRpgRomPartitionIdxOfRmDestRom is always 'PDUR_NO_RMDESTRPGROMPARTITIONIDXOFRMDESTROM' due to this, the array is deactivated.' */
#define PduR_HasRmDestRpgRomUsedOfRmDestRom()                                                         /**< Deactivateable: 'PduR_RmDestRomRBTM_FL.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmDestRomRBTM_FR.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmGDestRomIdxOfRmDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRoutingTypeOfRmDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmDestRpgRam(partitionIndex)                                                          /**< Deactivateable: 'PduR_RmDestRpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasEnabledCntOfRmDestRpgRam(partitionIndex)                                              /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRmDestRpgRom(partitionIndex)                                                          /**< Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasInitialEnabledCntOfRmDestRpgRom(partitionIndex)                                       /**< Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRomIdxOfRmDestRpgRom(partitionIndex)                                            /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRomUsedOfRmDestRpgRom(partitionIndex)                                           /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRpgRomInd(partitionIndex)                                                       /**< Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmGDestNto1InfoRam(partitionIndex)                                                    /**< Deactivateable: 'PduR_RmGDestNto1InfoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRmDestRomIdxOfRmGDestNto1InfoRam(partitionIndex)                                      /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasTransmissionActiveOfRmGDestNto1InfoRam(partitionIndex)                                /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRmGDestRom()                                                                        (PduR_GetRmGDestRomOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasDestApplicationManagerRomIdxOfRmGDestRom()                                          (TRUE != FALSE)
#define PduR_HasDestHndOfRmGDestRom()                                                               (TRUE != FALSE)
#define PduR_HasDirectionOfRmGDestRom()                                                             (TRUE != FALSE)
#define PduR_HasFmFifoInstanceRomIdxOfRmGDestRom()                                                    /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomIdx' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasFmFifoInstanceRomPartitionIdxOfRmGDestRom()                                           /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomPartitionIdx' Reason: 'the value of PduR_FmFifoInstanceRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_FMFIFOINSTANCEROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_HasFmFifoInstanceRomUsedOfRmGDestRom()                                                   /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.FmFifoInstanceRomUsed' Reason: 'the optional indirection is deactivated because FmFifoInstanceRomUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasLockRomIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasMaxPduLengthOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmGDestRom()                                                              (TRUE != FALSE)
#define PduR_HasPduRDestPduProcessingOfRmGDestRom()                                                 (TRUE != FALSE)
#define PduR_HasRmBufferedIfPropertiesRomIdxOfRmGDestRom()                                            /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasRmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom()                                   /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedIfPropertiesRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMBUFFEREDIFPROPERTIESROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_HasRmBufferedIfPropertiesRomUsedOfRmGDestRom()                                           /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PduR_HasRmDestRomIdxOfRmGDestRom()                                                          (TRUE != FALSE)
#define PduR_HasRmGDestNto1InfoRamIdxOfRmGDestRom()                                                   /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamIdx' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmGDestNto1InfoRamPartitionIdxOfRmGDestRom()                                          /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamPartitionIdx' Reason: 'the value of PduR_RmGDestNto1InfoRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTNTO1INFORAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_HasRmGDestNto1InfoRamUsedOfRmGDestRom()                                                  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestNto1InfoRamUsed' Reason: 'the optional indirection is deactivated because RmGDestNto1InfoRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmGDestTpTxStateRamIdxOfRmGDestRom()                                                  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamIdx' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmGDestTpTxStateRamPartitionIdxOfRmGDestRom()                                         /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamPartitionIdx' Reason: 'the value of PduR_RmGDestTpTxStateRamPartitionIdxOfRmGDestRom is always 'PDUR_NO_RMGDESTTPTXSTATERAMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_HasRmGDestTpTxStateRamUsedOfRmGDestRom()                                                 /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.RmGDestTpTxStateRamUsed' Reason: 'the optional indirection is deactivated because RmGDestTpTxStateRamUsedOfRmGDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasSmGDestRomIdxOfRmGDestRom()                                                           /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmGDestRomPartitionIdxOfRmGDestRom()                                                  /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomPartitionIdx' Reason: 'the value of PduR_SmGDestRomPartitionIdxOfRmGDestRom is always 'PDUR_NO_SMGDESTROMPARTITIONIDXOFRMGDESTROM' due to this, the array is deactivated.' */
#define PduR_HasSmGDestRomUsedOfRmGDestRom()                                                          /**< Deactivateable: 'PduR_RmGDestRomRBTM_FL.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmGDestRomRBTM_FR.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasTxIf2UpIdxOfRmGDestRom()                                                            (TRUE != FALSE)
#define PduR_HasRmGDestTpTxStateRam(partitionIndex)                                                   /**< Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasTpTxInstSmStateOfRmGDestTpTxStateRam(partitionIndex)                                  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRmSrcRom()                                                                          (PduR_GetRmSrcRomOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasDestApplicationManagerRomIdxOfRmSrcRom()                                            (TRUE != FALSE)
#define PduR_HasLockRomIdxOfRmSrcRom()                                                              (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmSrcRom()                                                                (TRUE != FALSE)
#define PduR_HasRmBufferedTpPropertiesRomIdxOfRmSrcRom()                                              /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomIdx' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom()                                     /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomPartitionIdx' Reason: 'the value of PduR_RmBufferedTpPropertiesRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_RMBUFFEREDTPPROPERTIESROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PduR_HasRmBufferedTpPropertiesRomUsedOfRmSrcRom()                                             /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.RmBufferedTpPropertiesRomUsed' Reason: 'the optional indirection is deactivated because RmBufferedTpPropertiesRomUsedOfRmSrcRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PduR_HasRmDestRomEndIdxOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomLengthOfRmSrcRom()                                                         (TRUE != FALSE)
#define PduR_HasRmDestRomStartIdxOfRmSrcRom()                                                       (TRUE != FALSE)
#define PduR_HasSmSrcRomIdxOfRmSrcRom()                                                               /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSrcRomPartitionIdxOfRmSrcRom()                                                      /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomPartitionIdx' Reason: 'the value of PduR_SmSrcRomPartitionIdxOfRmSrcRom is always 'PDUR_NO_SMSRCROMPARTITIONIDXOFRMSRCROM' due to this, the array is deactivated.' */
#define PduR_HasSmSrcRomUsedOfRmSrcRom()                                                              /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSrcHndOfRmSrcRom()                                                                  (TRUE != FALSE)
#define PduR_HasTriggerTransmitSupportedOfRmSrcRom()                                                  /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' */
#define PduR_HasTxConfirmationSupportedOfRmSrcRom()                                                   /**< Deactivateable: 'PduR_RmSrcRomRBTM_FL.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' and Deactivateable: 'PduR_RmSrcRomRBTM_FR.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' */
#define PduR_HasRmTransmitFctPtr()                                                                  (TRUE != FALSE)
#define PduR_HasRpgExtIdRom()                                                                         /**< Deactivateable: 'PduR_RpgExtIdRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgExtIdRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasInvalidHndOfRpgExtIdRom()                                                             /**< Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasRpgRomIdxOfRpgExtIdRom()                                                              /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRpgRomPartitionIdxOfRpgExtIdRom()                                                     /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomPartitionIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRpgRomUsedOfRpgExtIdRom()                                                             /**< Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgExtIdRom.RpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRpgRam(partitionIndex)                                                                /**< Deactivateable: 'PduR_RpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasEnabledOfRpgRam(partitionIndex)                                                       /**< Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasRpgRom(partitionIndex)                                                                /**< Deactivateable: 'PduR_RpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_RpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasEnabledAtInitOfRpgRom(partitionIndex)                                                 /**< Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRpgRomIndEndIdxOfRpgRom(partitionIndex)                                         /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRpgRomIndStartIdxOfRpgRom(partitionIndex)                                       /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRmDestRpgRomIndUsedOfRpgRom(partitionIndex)                                           /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasRxIf2Dest()                                                                           /**< Deactivateable: 'PduR_RxIf2Dest' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_HasBswMPduRRxIndicationCallbackOfRxIf2Dest()                                             /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_HasInvalidHndOfRxIf2Dest()                                                               /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_HasRmSrcRomIdxOfRxIf2Dest()                                                              /**< Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' and Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PduR_HasRxTp2Dest()                                                                         (TRUE != FALSE)
#define PduR_HasBswMPduRTpRxIndicationCallbackOfRxTp2Dest()                                           /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PduR_HasBswMPduRTpStartOfReceptionCallbackOfRxTp2Dest()                                       /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PduR_HasInvalidHndOfRxTp2Dest()                                                               /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PduR_HasRmSrcRomIdxOfRxTp2Dest()                                                            (TRUE != FALSE)
#define PduR_HasRxTp2Src()                                                                          (PduR_GetRxTp2SrcOfPCPartitionConfig() != NULL_PTR)
#define PduR_HasInvalidHndOfRxTp2Src()                                                                /**< Deactivateable: 'PduR_RxTp2SrcRBTM_FL.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FL.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FR.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_RxTp2SrcRBTM_FR.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PduR_HasRmDestRomIdxOfRxTp2Src()                                                            (TRUE != FALSE)
#define PduR_HasSingleBufferArrayRam(partitionIndex)                                                  /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferInitValuesRom(partitionIndex)                                             /**< Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferInitValuesRom' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferRam(partitionIndex)                                                       /**< Deactivateable: 'PduR_SingleBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasActualLengthOfSingleBufferRam(partitionIndex)                                         /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_HasSingleBufferRom(partitionIndex)                                                       /**< Deactivateable: 'PduR_SingleBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_SingleBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasRmDestRomIdxOfSingleBufferRom(partitionIndex)                                         /**< Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferArrayRamEndIdxOfSingleBufferRom(partitionIndex)                           /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferArrayRamLengthOfSingleBufferRom(partitionIndex)                           /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferArrayRamStartIdxOfSingleBufferRom(partitionIndex)                         /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferInitValuesRomEndIdxOfSingleBufferRom(partitionIndex)                      /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferInitValuesRomLengthOfSingleBufferRom(partitionIndex)                      /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSingleBufferInitValuesRomStartIdxOfSingleBufferRom(partitionIndex)                    /**< Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferRom.SingleBufferInitValuesRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasSizeOfDestApplicationManagerRom()                                                   (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRom()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfInitializedRam(partitionIndex)                                                (TRUE != FALSE)
#define PduR_HasSizeOfLockRom()                                                                     (TRUE != FALSE)
#define PduR_HasSizeOfMmRom()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfPartitionIdentifiers()                                                        (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRom()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRom()                                                                  (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRom()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtr()                                                            (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Dest()                                                                   (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Src()                                                                    (TRUE != FALSE)
#define PduR_HasSizeOfSrcApplicationRom()                                                           (TRUE != FALSE)
#define PduR_HasSizeOfTx2Lo()                                                                       (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2Src()                                                                    (TRUE != FALSE)
#define PduR_HasSmDataPlaneRom(partitionIndex)                                                        /**< Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmFibRamEndIdxOfSmDataPlaneRom(partitionIndex)                                        /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmFibRamStartIdxOfSmDataPlaneRom(partitionIndex)                                      /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmFibRamUsedOfSmDataPlaneRom(partitionIndex)                                          /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmLinearTaToSaCalculationStrategyRomIdxOfSmDataPlaneRom(partitionIndex)               /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmLinearTaToSaCalculationStrategyRomUsedOfSmDataPlaneRom(partitionIndex)              /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSaTaFromMetaDataCalculationStrategyRomIdxOfSmDataPlaneRom(partitionIndex)           /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSaTaFromMetaDataCalculationStrategyRomUsedOfSmDataPlaneRom(partitionIndex)          /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmFibRam(partitionIndex)                                                              /**< Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasLearnedConnectionIdOfSmFibRam(partitionIndex)                                         /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmGDestFilterFctPtr(partitionIndex)                                                   /**< Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmGDestRom(partitionIndex)                                                            /**< Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasConnectionIdOfSmGDestRom(partitionIndex)                                              /**< Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasMetaDataLengthOfSmGDestRom(partitionIndex)                                            /**< Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmDataPlaneRomIdxOfSmGDestRom(partitionIndex)                                         /**< Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmGDestFilterFctPtrIdxOfSmGDestRom(partitionIndex)                                    /**< Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmLinearTaToSaCalculationStrategyGetSaFctPtr(partitionIndex)                          /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmLinearTaToSaCalculationStrategyRom(partitionIndex)                                  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasMaskOfSmLinearTaToSaCalculationStrategyRom(partitionIndex)                            /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasOffsetOfSmLinearTaToSaCalculationStrategyRom(partitionIndex)                          /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSaTaFromMetaDataCalculationStrategyRom(partitionIndex)                              /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSaMaskOfSmSaTaFromMetaDataCalculationStrategyRom(partitionIndex)                      /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSaStartBitOfSmSaTaFromMetaDataCalculationStrategyRom(partitionIndex)                  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasTaMaskOfSmSaTaFromMetaDataCalculationStrategyRom(partitionIndex)                      /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasTaStartBitOfSmSaTaFromMetaDataCalculationStrategyRom(partitionIndex)                  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSrcFilterFctPtr(partitionIndex)                                                     /**< Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSrcRom(partitionIndex)                                                              /**< Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasConnectionIdOfSmSrcRom(partitionIndex)                                                /**< Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasMetaDataLengthOfSmSrcRom(partitionIndex)                                              /**< Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmDataPlaneRomIdxOfSmSrcRom(partitionIndex)                                           /**< Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmLinearTaToSaCalculationStrategyGetSaFctPtrIdxOfSmSrcRom(partitionIndex)             /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmLinearTaToSaCalculationStrategyGetSaFctPtrUsedOfSmSrcRom(partitionIndex)            /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSmSrcFilterFctPtrIdxOfSmSrcRom(partitionIndex)                                        /**< Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_HasSpinlockRam(partitionIndex)                                                           /**< Deactivateable: 'PduR_SpinlockRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasCounterOfSpinlockRam(partitionIndex)                                                  /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasLockVariableOfSpinlockRam(partitionIndex)                                             /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasSrcApplicationRom()                                                                 (TRUE != FALSE)
#define PduR_HasDeferredEventCacheRomIdxOfSrcApplicationRom()                                         /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasDeferredEventCacheRomPartitionIdxOfSrcApplicationRom()                              (TRUE != FALSE)
#define PduR_HasDeferredEventCacheRomUsedOfSrcApplicationRom()                                        /**< Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_SrcApplicationRom.DeferredEventCacheRomUsed' Reason: 'No Deferred Event Cache is configured' */
#define PduR_HasMcQBufferRomIdxOfSrcApplicationRom()                                                  /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasMcQBufferRomPartitionIdxOfSrcApplicationRom()                                         /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomPartitionIdx' Reason: 'the value of PduR_McQBufferRomPartitionIdxOfSrcApplicationRom is always 'PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM' due to this, the array is deactivated.' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomPartitionIdx' Reason: 'the value of PduR_McQBufferRomPartitionIdxOfSrcApplicationRom is always 'PDUR_NO_MCQBUFFERROMPARTITIONIDXOFSRCAPPLICATIONROM' due to this, the array is deactivated.' */
#define PduR_HasMcQBufferRomUsedOfSrcApplicationRom()                                                 /**< Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SrcApplicationRom.McQBufferRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_HasTx2Lo()                                                                             (TRUE != FALSE)
#define PduR_HasBswMPduRTransmitCallbackOfTx2Lo()                                                     /**< Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' */
#define PduR_HasCancelTransmitUsedOfTx2Lo()                                                           /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' and Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'No PduRBswModule configured which uses the CancelTransmit API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelTransmit' */
#define PduR_HasInvalidHndOfTx2Lo()                                                                   /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PduR_HasRmSrcRomIdxOfTx2Lo()                                                                (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfTx2Lo()                                                               (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrIdxOfTx2Lo()                                                        (TRUE != FALSE)
#define PduR_HasTxIf2Up()                                                                             /**< Deactivateable: 'PduR_TxIf2Up' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_TxIf2Up' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasBswMPduRTxConfirmationCallbackOfTxIf2Up()                                             /**< Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PduR_HasInvalidHndOfTxIf2Up()                                                                 /**< Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PduR_HasRmGDestRomIdxOfTxIf2Up()                                                              /**< Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_HasTxConfirmationUsedOfTxIf2Up()                                                         /**< Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' and Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' */
#define PduR_HasTxTp2Src()                                                                          (TRUE != FALSE)
#define PduR_HasBswMPduRTpTxConfirmationCallbackOfTxTp2Src()                                          /**< Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' and Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PduR_HasInvalidHndOfTxTp2Src()                                                                /**< Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' and Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PduR_HasRmGDestRomIdxOfTxTp2Src()                                                           (TRUE != FALSE)
#define PduR_HasPCConfig()                                                                          (TRUE != FALSE)
#define PduR_HasFinalMagicNumberOfPCConfig()                                                          /**< Deactivateable: 'PduR_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_HasInitDataHashCodeOfPCConfig()                                                          /**< Deactivateable: 'PduR_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PduR_HasPCPartitionConfigOfPCConfig()                                                       (TRUE != FALSE)
#define PduR_HasPartitionIdentifiersOfPCConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfPartitionIdentifiersOfPCConfig()                                              (TRUE != FALSE)
#define PduR_HasPCPartitionConfig()                                                                 (PduR_GetPCPartitionConfigOfPCConfig() != NULL_PTR)
#define PduR_HasConfigIdOfPCPartitionConfig(partitionIndex)                                         (TRUE != FALSE)
#define PduR_HasDestApplicationManagerRomOfPCPartitionConfig()                                      (TRUE != FALSE)
#define PduR_HasExclusiveAreaRomOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasInitializedRamOfPCPartitionConfig(partitionIndex)                                   (TRUE != FALSE)
#define PduR_HasLockRomOfPCPartitionConfig()                                                        (TRUE != FALSE)
#define PduR_HasMmRomOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define PduR_HasRmDestRomOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasRmGDestRomOfPCPartitionConfig()                                                     (TRUE != FALSE)
#define PduR_HasRmSrcRomOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasRxTp2DestOfPCPartitionConfig()                                                      (TRUE != FALSE)
#define PduR_HasRxTp2SrcOfPCPartitionConfig()                                                       (TRUE != FALSE)
#define PduR_HasSizeOfDestApplicationManagerRomOfPCPartitionConfig()                                (TRUE != FALSE)
#define PduR_HasSizeOfExclusiveAreaRomOfPCPartitionConfig()                                         (TRUE != FALSE)
#define PduR_HasSizeOfInitializedRamOfPCPartitionConfig(partitionIndex)                             (TRUE != FALSE)
#define PduR_HasSizeOfLockRomOfPCPartitionConfig()                                                  (TRUE != FALSE)
#define PduR_HasSizeOfMmRomOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRomOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRomOfPCPartitionConfig()                                               (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRomOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtrOfPCPartitionConfig()                                         (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2DestOfPCPartitionConfig()                                                (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2SrcOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSizeOfSrcApplicationRomOfPCPartitionConfig()                                        (TRUE != FALSE)
#define PduR_HasSizeOfTx2LoOfPCPartitionConfig()                                                    (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2SrcOfPCPartitionConfig()                                                 (TRUE != FALSE)
#define PduR_HasSrcApplicationRomOfPCPartitionConfig()                                              (TRUE != FALSE)
#define PduR_HasTx2LoOfPCPartitionConfig()                                                          (TRUE != FALSE)
#define PduR_HasTxTp2SrcOfPCPartitionConfig()                                                       (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCExistsEnumMacros  PduR Exists Enum Macros (PRE_COMPILE)
  \brief  These macros can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define PduR_ExistsSINGLE_BUFFER_QUEUEImplementationTypeOfRmBufferedIfPropertiesRom(partitionIndex)   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsSIMPLE_FIFO_QUEUEImplementationTypeOfRmBufferedIfPropertiesRom(partitionIndex)     /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsSHARED_FIFO_QUEUEImplementationTypeOfRmBufferedIfPropertiesRom(partitionIndex)     /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsDIRECTQueueDataProvisionTypeOfRmBufferedIfPropertiesRom(partitionIndex)            /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsTRIGGER_TRANSMITQueueDataProvisionTypeOfRmBufferedIfPropertiesRom(partitionIndex)   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsSINGLE_BUFFERQueueTypeOfRmBufferedIfPropertiesRom(partitionIndex)                  /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsFIFOQueueTypeOfRmBufferedIfPropertiesRom(partitionIndex)                           /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsSHORTENPduLengthHandlingStrategyOfRmDestRom()                                      /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsDISCARDPduLengthHandlingStrategyOfRmDestRom()                                      /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIGNOREPduLengthHandlingStrategyOfRmDestRom()                                       /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsUNUSEDPduLengthHandlingStrategyOfRmDestRom()                                       /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIF_UNBUFFERED_RX_API_FWDRoutingTypeOfRmDestRom()                                   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIF_UNBUFFERED_TX_API_FWDRoutingTypeOfRmDestRom()                                   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIF_UNBUFFERED_UL_API_FWDRoutingTypeOfRmDestRom()                                   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIF_NOBUFFER_GATEWAYRoutingTypeOfRmDestRom()                                        /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIF_BUFFEREDRoutingTypeOfRmDestRom()                                                /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsTP_UNBUFFERED_RX_API_FWDRoutingTypeOfRmDestRom()                                   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsTP_UNBUFFERED_TX_API_FWDRoutingTypeOfRmDestRom()                                   /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsTP_BUFFEREDRoutingTypeOfRmDestRom()                                                /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsRXDirectionOfRmGDestRom()                                                          /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsTXDirectionOfRmGDestRom()                                                          /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsDEFERREDPduRDestPduProcessingOfRmGDestRom()                                        /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
#define PduR_ExistsIMMEDIATEPduRDestPduProcessingOfRmGDestRom()                                       /**< Deactivated, because the PrecompilePreprocessingStrategy isn't COMPILETIME_CHECKING! */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIncrementDataMacros  PduR Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define PduR_IncBmTxBufferArrayRam(Index, partitionIndex)                                             /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IncBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, partitionIndex)               /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, partitionIndex)                      /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncRxLengthOfBmTxBufferRam(Index, partitionIndex)                                        /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncRmGDestRomIdxOfDeferredEventCacheArrayRam(Index, partitionIndex)                      /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_IncDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(Index, partitionIndex)       /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_IncDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(Index, partitionIndex)      /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_IncBmTxBufferRomIdxOfFmFifoElementRam(Index, partitionIndex)                             /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncRmDestRomIdxOfFmFifoElementRam(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, partitionIndex)                    /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncFillLevelOfFmFifoRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncFmFifoElementRamReadIdxOfFmFifoRam(Index, partitionIndex)                             /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncFmFifoElementRamWriteIdxOfFmFifoRam(Index, partitionIndex)                            /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncPendingConfirmationsOfFmFifoRam(Index, partitionIndex)                                /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncInterfaceFifoQueueArrayRam(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IncActualLengthOfInterfaceFifoQueueElementRam(Index, partitionIndex)                     /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(Index, partitionIndex)     /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(Index, partitionIndex)    /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncMcQBufferArrayRam(Index, partitionIndex)                                              /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IncMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(Index, partitionIndex)                  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IncMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(Index, partitionIndex)                 /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IncMcQBufferArrayRamReadIdxOfMcQBufferRam(Index, partitionIndex)                         /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IncMcQBufferArrayRamWriteIdxOfMcQBufferRam(Index, partitionIndex)                        /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IncOsApplicationToPduROfPartitionLookupTableRam(Index)                                   /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, partitionIndex)                 /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncEnabledCntOfRmDestRpgRam(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncRmDestRomIdxOfRmGDestNto1InfoRam(Index, partitionIndex)                               /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncSingleBufferArrayRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_IncActualLengthOfSingleBufferRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_IncLearnedConnectionIdOfSmFibRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_IncCounterOfSpinlockRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_IncLockVariableOfSpinlockRam(Index, partitionIndex)                                      /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCDecrementDataMacros  PduR Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define PduR_DecBmTxBufferArrayRam(Index, partitionIndex)                                             /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_DecBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, partitionIndex)               /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, partitionIndex)                      /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecRxLengthOfBmTxBufferRam(Index, partitionIndex)                                        /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecRmGDestRomIdxOfDeferredEventCacheArrayRam(Index, partitionIndex)                      /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_DecDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(Index, partitionIndex)       /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_DecDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(Index, partitionIndex)      /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_DecBmTxBufferRomIdxOfFmFifoElementRam(Index, partitionIndex)                             /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecRmDestRomIdxOfFmFifoElementRam(Index, partitionIndex)                                 /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, partitionIndex)                    /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecFillLevelOfFmFifoRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecFmFifoElementRamReadIdxOfFmFifoRam(Index, partitionIndex)                             /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecFmFifoElementRamWriteIdxOfFmFifoRam(Index, partitionIndex)                            /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecPendingConfirmationsOfFmFifoRam(Index, partitionIndex)                                /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecInterfaceFifoQueueArrayRam(Index, partitionIndex)                                     /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_DecActualLengthOfInterfaceFifoQueueElementRam(Index, partitionIndex)                     /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(Index, partitionIndex)     /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(Index, partitionIndex)    /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecMcQBufferArrayRam(Index, partitionIndex)                                              /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_DecMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(Index, partitionIndex)                  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_DecMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(Index, partitionIndex)                 /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_DecMcQBufferArrayRamReadIdxOfMcQBufferRam(Index, partitionIndex)                         /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_DecMcQBufferArrayRamWriteIdxOfMcQBufferRam(Index, partitionIndex)                        /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_DecOsApplicationToPduROfPartitionLookupTableRam(Index)                                   /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, partitionIndex)                 /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecEnabledCntOfRmDestRpgRam(Index, partitionIndex)                                       /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecRmDestRomIdxOfRmGDestNto1InfoRam(Index, partitionIndex)                               /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecSingleBufferArrayRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_DecActualLengthOfSingleBufferRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_DecLearnedConnectionIdOfSmFibRam(Index, partitionIndex)                                  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_DecCounterOfSpinlockRam(Index, partitionIndex)                                           /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_DecLockVariableOfSpinlockRam(Index, partitionIndex)                                      /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCAddDataMacros  PduR Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define PduR_AddBmTxBufferArrayRam(Index, Value, partitionIndex)                                      /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_AddBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, Value, partitionIndex)        /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, Value, partitionIndex)               /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddRxLengthOfBmTxBufferRam(Index, Value, partitionIndex)                                 /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddRmGDestRomIdxOfDeferredEventCacheArrayRam(Index, Value, partitionIndex)               /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_AddDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_AddDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_AddBmTxBufferRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                      /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddRmDestRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                          /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, Value, partitionIndex)             /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddFillLevelOfFmFifoRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddFmFifoElementRamReadIdxOfFmFifoRam(Index, Value, partitionIndex)                      /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddFmFifoElementRamWriteIdxOfFmFifoRam(Index, Value, partitionIndex)                     /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddPendingConfirmationsOfFmFifoRam(Index, Value, partitionIndex)                         /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddInterfaceFifoQueueArrayRam(Index, Value, partitionIndex)                              /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_AddActualLengthOfInterfaceFifoQueueElementRam(Index, Value, partitionIndex)              /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddMcQBufferArrayRam(Index, Value, partitionIndex)                                       /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_AddMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(Index, Value, partitionIndex)           /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_AddMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(Index, Value, partitionIndex)          /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_AddMcQBufferArrayRamReadIdxOfMcQBufferRam(Index, Value, partitionIndex)                  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_AddMcQBufferArrayRamWriteIdxOfMcQBufferRam(Index, Value, partitionIndex)                 /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_AddOsApplicationToPduROfPartitionLookupTableRam(Index, Value)                            /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)          /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddEnabledCntOfRmDestRpgRam(Index, Value, partitionIndex)                                /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddRmDestRomIdxOfRmGDestNto1InfoRam(Index, Value, partitionIndex)                        /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddSingleBufferArrayRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_AddActualLengthOfSingleBufferRam(Index, Value, partitionIndex)                           /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_AddLearnedConnectionIdOfSmFibRam(Index, Value, partitionIndex)                           /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_AddCounterOfSpinlockRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_AddLockVariableOfSpinlockRam(Index, Value, partitionIndex)                               /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSubstractDataMacros  PduR Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define PduR_SubBmTxBufferArrayRam(Index, Value, partitionIndex)                                      /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_SubBmTxBufferArrayRamReadIdxOfBmTxBufferInstanceRam(Index, Value, partitionIndex)        /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubBmTxBufferArrayRamWriteIdxOfBmTxBufferRam(Index, Value, partitionIndex)               /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubRxLengthOfBmTxBufferRam(Index, Value, partitionIndex)                                 /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubRmGDestRomIdxOfDeferredEventCacheArrayRam(Index, Value, partitionIndex)               /**< Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheArrayRam.RmGDestRomIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_SubDeferredEventCacheArrayRamReadIdxOfDeferredEventCacheRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamReadIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_SubDeferredEventCacheArrayRamWriteIdxOfDeferredEventCacheRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' and Deactivateable: 'PduR_DeferredEventCacheRam.DeferredEventCacheArrayRamWriteIdx' Reason: 'No Deferred Event Cache is configured' */
#define PduR_SubBmTxBufferRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                      /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubRmDestRomIdxOfFmFifoElementRam(Index, Value, partitionIndex)                          /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubBmTxBufferInstanceRomIdxOfFmFifoInstanceRam(Index, Value, partitionIndex)             /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubFillLevelOfFmFifoRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubFmFifoElementRamReadIdxOfFmFifoRam(Index, Value, partitionIndex)                      /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubFmFifoElementRamWriteIdxOfFmFifoRam(Index, Value, partitionIndex)                     /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubPendingConfirmationsOfFmFifoRam(Index, Value, partitionIndex)                         /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubInterfaceFifoQueueArrayRam(Index, Value, partitionIndex)                              /**< Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_InterfaceFifoQueueArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_SubActualLengthOfInterfaceFifoQueueElementRam(Index, Value, partitionIndex)              /**< Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueElementRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubInterfaceFifoQueueElementRamReadIdxOfInterfaceFifoQueueRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamReadIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubInterfaceFifoQueueElementRamWriteIdxOfInterfaceFifoQueueRam(Index, Value, partitionIndex)   /**< Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_InterfaceFifoQueueRam.InterfaceFifoQueueElementRamWriteIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubMcQBufferArrayRam(Index, Value, partitionIndex)                                       /**< Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferArrayRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SubMcQBufferArrayRamPendingReadIdxOfMcQBufferRam(Index, Value, partitionIndex)           /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SubMcQBufferArrayRamPendingWriteIdxOfMcQBufferRam(Index, Value, partitionIndex)          /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamPendingWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SubMcQBufferArrayRamReadIdxOfMcQBufferRam(Index, Value, partitionIndex)                  /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamReadIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SubMcQBufferArrayRamWriteIdxOfMcQBufferRam(Index, Value, partitionIndex)                 /**< Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_McQBufferRam.McQBufferArrayRamWriteIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SubOsApplicationToPduROfPartitionLookupTableRam(Index, Value)                            /**< Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_PartitionLookupTableRam.OsApplicationToPduR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubFmFifoElementRamIdxOfRmBufferedTpPropertiesRam(Index, Value, partitionIndex)          /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubEnabledCntOfRmDestRpgRam(Index, Value, partitionIndex)                                /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubRmDestRomIdxOfRmGDestNto1InfoRam(Index, Value, partitionIndex)                        /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubSingleBufferArrayRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' and Deactivateable: 'PduR_SingleBufferArrayRam' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PduR_SubActualLengthOfSingleBufferRam(Index, Value, partitionIndex)                           /**< Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_SingleBufferRam.ActualLength' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PduR_SubLearnedConnectionIdOfSmFibRam(Index, Value, partitionIndex)                           /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' and Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PduR_SubCounterOfSpinlockRam(Index, Value, partitionIndex)                                    /**< Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.Counter' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
#define PduR_SubLockVariableOfSpinlockRam(Index, Value, partitionIndex)                               /**< Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' and Deactivateable: 'PduR_SpinlockRam.LockVariable' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] is configured to 'false'' */
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
/** 
  \defgroup  PduRLTGetRootDataMacros  PduR Get Root Data Macros (LINK)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define PduR_GetLTPartitionConfigOfLTConfig()                                                         /**< Deactivateable: 'PduR_LTConfig.LTPartitionConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRLTHasMacros  PduR Has Macros (LINK)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasLTConfig()                                                                            /**< Deactivateable: 'PduR_LTConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define PduR_HasLTPartitionConfigOfLTConfig()                                                         /**< Deactivateable: 'PduR_LTConfig.LTPartitionConfig' Reason: 'deactivated because PartitionConfig is deactivated.' */
#define PduR_HasLTPartitionConfig()                                                                   /**< Deactivateable: 'PduR_LTPartitionConfigRBTM_FL' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' and Deactivateable: 'PduR_LTPartitionConfigRBTM_FR' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 

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

/**   \brief  type used to iterate PduR_RxTp2Dest */
typedef uint8_least PduR_RxTp2DestIterType;

/**   \brief  type used to iterate PduR_RxTp2Src */
typedef uint8_least PduR_RxTp2SrcIterType;

/**   \brief  type used to iterate PduR_SrcApplicationRom */
typedef uint8_least PduR_SrcApplicationRomIterType;

/**   \brief  type used to iterate PduR_Tx2Lo */
typedef uint8_least PduR_Tx2LoIterType;

/**   \brief  type used to iterate PduR_TxTp2Src */
typedef uint8_least PduR_TxTp2SrcIterType;

/**   \brief  type used to iterate PduR_PCPartitionConfig */
typedef uint8_least PduR_PCPartitionConfigIterType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIterableTypesWithSizeRelations  PduR Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
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

/**   \brief  value based type definition for PduR_InitializedRam */
typedef boolean PduR_InitializedRamType;

/**   \brief  value based type definition for PduR_ExclusiveAreaRomIdxOfLockRom */
typedef uint8 PduR_ExclusiveAreaRomIdxOfLockRomType;

/**   \brief  value based type definition for PduR_ExclusiveAreaRomUsedOfLockRom */
typedef boolean PduR_ExclusiveAreaRomUsedOfLockRomType;

/**   \brief  value based type definition for PduR_ChangeParameterSupportedOfMmRom */
typedef boolean PduR_ChangeParameterSupportedOfMmRomType;

/**   \brief  value based type definition for PduR_LoTpOfMmRom */
typedef boolean PduR_LoTpOfMmRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfMmRom */
typedef uint8 PduR_MaskedBitsOfMmRomType;

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

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRxTp2Dest */
typedef uint8 PduR_RmSrcRomIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_RmDestRomIdxOfRxTp2Src */
typedef uint8 PduR_RmDestRomIdxOfRxTp2SrcType;

/**   \brief  value based type definition for PduR_SizeOfDestApplicationManagerRom */
typedef uint8 PduR_SizeOfDestApplicationManagerRomType;

/**   \brief  value based type definition for PduR_SizeOfExclusiveAreaRom */
typedef uint8 PduR_SizeOfExclusiveAreaRomType;

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

/**   \brief  value based type definition for PduR_SizeOfRxTp2Dest */
typedef uint8 PduR_SizeOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfRxTp2Src */
typedef uint8 PduR_SizeOfRxTp2SrcType;

/**   \brief  value based type definition for PduR_SizeOfSrcApplicationRom */
typedef uint8 PduR_SizeOfSrcApplicationRomType;

/**   \brief  value based type definition for PduR_SizeOfTx2Lo */
typedef uint8 PduR_SizeOfTx2LoType;

/**   \brief  value based type definition for PduR_SizeOfTxTp2Src */
typedef uint8 PduR_SizeOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_DeferredEventCacheRomPartitionIdxOfSrcApplicationRom */
typedef uint8 PduR_DeferredEventCacheRomPartitionIdxOfSrcApplicationRomType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfTx2Lo */
typedef uint8 PduR_RmSrcRomIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmSrcRomUsedOfTx2Lo */
typedef boolean PduR_RmSrcRomUsedOfTx2LoType;

/**   \brief  value based type definition for PduR_RmTransmitFctPtrIdxOfTx2Lo */
typedef uint8 PduR_RmTransmitFctPtrIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfTxTp2Src */
typedef uint8 PduR_RmGDestRomIdxOfTxTp2SrcType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRLTIterableTypes  PduR Iterable Types (LINK)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/** 
  \}
*/ 



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

/**   \brief  type used in PduR_LockRom */
typedef struct sPduR_LockRomType
{
  PduR_ExclusiveAreaRomIdxOfLockRomType ExclusiveAreaRomIdxOfLockRom;  /**< the index of the 0:1 relation pointing to PduR_ExclusiveAreaRom */
} PduR_LockRomType;

/**   \brief  type used in PduR_MmRom */
typedef struct sPduR_MmRomType
{
  PduR_MaskedBitsOfMmRomType MaskedBitsOfMmRom;  /**< contains bitcoded the boolean data of PduR_ChangeParameterSupportedOfMmRom, PduR_LoTpOfMmRom, PduR_UpTpOfMmRom */
  PduR_ChangeParameterFctPtrType LoTpChangeParameterFctPtrOfMmRom;  /**< lower layer change parameter function pointers to change e.g. BS or STmin.. */
  PduR_CopyRxDataFctPtrType UpTpCopyRxDataFctPtrOfMmRom;  /**< Transport protocol CopyRxData function pointers */
  PduR_CopyTxDataFctPtrType UpTpCopyTxDataFctPtrOfMmRom;  /**< Transport protocol CopyTxData function pointers */
  PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFctPtrOfMmRom;  /**< Transport protocol StartOfReception function pointers */
  PduR_TpRxIndicationFctPtrType UpTpTpRxIndicationFctPtrOfMmRom;  /**< Transport protocol TpRxIndication function pointers */
  PduR_TpTxConfirmationFctPtrType UpTpTpTxConfirmationFctPtrOfMmRom;  /**< Transport protocol TpTxConfimation function pointers */
  PduR_TransmitFctPtrType LoTpTransmitFctPtrOfMmRom;  /**< Lower layer Tp transmit function pointers */
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
  PduR_MmRomIdxOfRmSrcRomType MmRomIdxOfRmSrcRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_RmDestRomStartIdxOfRmSrcRomType RmDestRomStartIdxOfRmSrcRom;  /**< the start index of the 1:n relation pointing to PduR_RmDestRom */
  PduR_SrcHndOfRmSrcRomType SrcHndOfRmSrcRom;  /**< handle to be used as parameter for the TxConfirmation or TriggerTransmit function call. */
} PduR_RmSrcRomType;

/**   \brief  type used in PduR_RxTp2Dest */
typedef struct sPduR_RxTp2DestType
{
  uint8 PduR_RxTp2DestNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_RxTp2DestType;

/**   \brief  type used in PduR_RxTp2Src */
typedef struct sPduR_RxTp2SrcType
{
  PduR_RmDestRomIdxOfRxTp2SrcType RmDestRomIdxOfRxTp2Src;  /**< the index of the 1:1 relation pointing to PduR_RmDestRom */
} PduR_RxTp2SrcType;

/**   \brief  type used in PduR_SrcApplicationRom */
typedef struct sPduR_SrcApplicationRomType
{
  uint8 PduR_SrcApplicationRomNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_SrcApplicationRomType;

/**   \brief  type used in PduR_Tx2Lo */
typedef struct sPduR_Tx2LoType
{
  PduR_RmSrcRomIdxOfTx2LoType RmSrcRomIdxOfTx2Lo;  /**< the index of the 0:1 relation pointing to PduR_RmSrcRom */
  PduR_RmTransmitFctPtrIdxOfTx2LoType RmTransmitFctPtrIdxOfTx2Lo;  /**< the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr */
} PduR_Tx2LoType;

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
/**   \brief  type to be used as symbolic data element access to PduR_InitializedRam in the predefined variant RBTM_FL in the partition context  */
typedef struct PduR_InitializedRamRBTM_FLStructSTag
{
  PduR_InitializedRamType PduRSinglePartitionDummy;
} PduR_InitializedRamRBTM_FLStructSType;

/**   \brief  type to be used as symbolic data element access to PduR_InitializedRam in the predefined variant RBTM_FR in the partition context  */
typedef struct PduR_InitializedRamRBTM_FRStructSTag
{
  PduR_InitializedRamType PduRSinglePartitionDummy;
} PduR_InitializedRamRBTM_FRStructSType;

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
  PduR_InitializedRamRBTM_FLStructSType strRBTM_FL;
  PduR_InitializedRamRBTM_FRStructSType strRBTM_FR;
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

/**   \brief  type used to point to PduR_RxTp2Dest */
typedef P2CONST(PduR_RxTp2DestType, TYPEDEF, PDUR_CONST) PduR_RxTp2DestPtrType;

/**   \brief  type used to point to PduR_RxTp2Src */
typedef P2CONST(PduR_RxTp2SrcType, TYPEDEF, PDUR_CONST) PduR_RxTp2SrcPtrType;

/**   \brief  type used to point to PduR_SrcApplicationRom */
typedef P2CONST(PduR_SrcApplicationRomType, TYPEDEF, PDUR_CONST) PduR_SrcApplicationRomPtrType;

/**   \brief  type used to point to PduR_Tx2Lo */
typedef P2CONST(PduR_Tx2LoType, TYPEDEF, PDUR_CONST) PduR_Tx2LoPtrType;

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
  PduR_RxTp2SrcPtrType RxTp2SrcOfPCPartitionConfig;  /**< the pointer to PduR_RxTp2Src */
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
  PduR_PCConfigType Config_RBTM_FL;  /**< [Config_RBTM_FL] */
  PduR_PCConfigType Config_RBTM_FR;  /**< [Config_RBTM_FR] */
} PduR_PCConfigsType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRLTPartitionRootPointer  PduR Partition Root Pointer (LINK)
  \brief  This type definitions are used for partition specific instance.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  PduRLTRootValueTypes  PduR Root Value Types (LINK)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



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
  MaskedBits                    contains bitcoded the boolean data of PduR_ChangeParameterSupportedOfMmRom, PduR_LoTpOfMmRom, PduR_UpTpOfMmRom
  LoTpChangeParameterFctPtr     lower layer change parameter function pointers to change e.g. BS or STmin..
  UpTpCopyRxDataFctPtr          Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr          Transport protocol CopyTxData function pointers
  UpTpStartOfReceptionFctPtr    Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr      Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr    Transport protocol TpTxConfimation function pointers
  LoTpTransmitFctPtr            Lower layer Tp transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PartitionIdentifiers
**********************************************************************************************************************/
/** 
  \var    PduR_PartitionIdentifiers
  \brief  the partition context in Config_RBTM_FL
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
  PduR_RmDestRomRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomRBTM_FL
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
extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomRBTM_FL[9];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRomRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRomRBTM_FR
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
extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRomRBTM_FR[9];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomRBTM_FL
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
extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomRBTM_FL[9];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRomRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRomRBTM_FR
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
extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRomRBTM_FR[9];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomRBTM_FL
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomRBTM_FL[9];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRomRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRomRBTM_FR
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  LockRomIdx           the index of the 1:1 relation pointing to PduR_LockRom
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRomRBTM_FR[9];
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
extern CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2SrcRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2SrcRBTM_FL
  \brief  This table contains all routing information to perform the ChangeParameter or CancelReceive handling. Used in ChangeParameter and CancelReceive APIs 	race SPEC-1024
  \details
  Element         Description
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RxTp2SrcType, PDUR_CONST) PduR_RxTp2SrcRBTM_FL[6];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2SrcRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2SrcRBTM_FR
  \brief  This table contains all routing information to perform the ChangeParameter or CancelReceive handling. Used in ChangeParameter and CancelReceive APIs 	race SPEC-1024
  \details
  Element         Description
  RmDestRomIdx    the index of the 1:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_RxTp2SrcType, PDUR_CONST) PduR_RxTp2SrcRBTM_FR[6];
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
  RmSrcRomIdx            the index of the 0:1 relation pointing to PduR_RmSrcRom
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[3];
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
  PduR_PCPartitionConfigRBTM_FL
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigRBTM_FL
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  RxTp2Src      the pointer to PduR_RxTp2Src
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigRBTM_FL[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_PCPartitionConfigRBTM_FR
**********************************************************************************************************************/
/** 
  \var    PduR_PCPartitionConfigRBTM_FR
  \details
  Element       Description
  RmDestRom     the pointer to PduR_RmDestRom
  RmGDestRom    the pointer to PduR_RmGDestRom
  RmSrcRom      the pointer to PduR_RmSrcRom
  RxTp2Src      the pointer to PduR_RxTp2Src
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "PduR_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(PduR_PCPartitionConfigType, PDUR_CONST) PduR_PCPartitionConfigRBTM_FR[1];
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

