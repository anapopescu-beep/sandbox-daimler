/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2021 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                Please note, that this file contains example configuration used by the 
 *                MICROSAR BSW. This code may influence the behaviour of the MICROSAR BSW
 *                in principle. Therefore, great care must be taken to verify
 *                the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples respectively
 *                implementation proposals. With regard to the fact that these functions
 *                are meant for demonstration purposes only, the liability of Vector Informatik
 *                shall be expressly excluded in cases of ordinary negligence, 
 *                to the extent admissible by law or statute.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _MemMap.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the MemMap.h
 *                This file has to be extended with the memory section defined for all BSW modules
 *                which are used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.02  2008-11-04  Jk                    Component specific defines filtering added
 *  01.01.03  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.04  2009-04-27  Ht                    improve list of components  (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm,
 *                                              If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.05  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.06  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-08-18  HH                    replaced C++ comment by C comment
 *  01.02.02  2009-09-02  Lo                    add external Flash driver support
 *  01.02.03  2009-09-12  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
 *                        Ht                    Improve list of components (CanTrcv_30_Tja1040dio,
 *                                                Eth, EthTrcv, EthIf, SoAd, TcpIp, EthSM)
 *  01.03.00  2009-10-30  Ht                    support R8: change EthTrcv to EthTrcv_30_Canoeemu
 *                                              support EthTrcv_30_Dp83848
 *                                              change CanTrcv_30_Xdio to CanTrcv_30___Your_Trcv__
 *                                              change CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1041
 *                                              change name FrTrcv to FrTrcv_30_Tja1080dio
 *                        Lo                    add Cp_AsrXcp
 *                        Ht                    add Cp_XcpOnFrAsr
 *  01.03.01  2010-01-13  Ht                    support SysService_AsrCal
 *  01.03.02  2010-02-15  Ht                    support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
 *                                                      SysService_Dns, SysService_Json, DrvTrans_GenericLindioAsr
 *                        Lo                    add Diag_AsrDem for all OEMs
 *                                              rename internal variables and filter methods
 *  01.04.00  2010-03-04  Ht                    change name FrTrcv_30_Tja1080dio to FrTrcv_30_Tja1080
 *  01.04.01  2010-03-10  Ht                    support DrvTrans_GenericFrAsr, DrvTrans_As8223FrspiAsr, DrvEep and If_AsrIfEa
 *  01.04.02  2010-04-07  Lo                    change IfFee to real components and add If_AsrIfWdV85xNec01Sub
 *  01.04.03  2010-06-11  Ht                    add CanTrcv_30_Tja1043
 *                        Lo                    add Il_AsrIpduMEbBmwSub
 *  01.04.04  2010-08-24  Ht                    add CanTrcv_30_Tle62512G, DrvEep_XAt25128EAsr, Tp_AsrTpFrEbBmwSub
 *  01.05.00  2010-08-24  Ht                    support R10:
 *                                              change LinTrcv_30_Tle7259dio to LinTrcv_30_Tle7259
 *  01.05.01  2010-10-14  Ht                    add VStdLib, SysService_SswScc, SysService_IpBase, SysService_Crypto
 *  01.05.02  2010-10-20  Ht                    support comments for Package Merge Tool
 *  01.05.03  2010-11-03  Ht                    add SysService_E2eLibTttechSub, SysService_E2ePwTttechSub
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-15  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-20  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-11-22  Ht                    add If_AsrIfFeeTiSub, 
 *                                              ESCAN00054718: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    ESCAN00059365: [AUTOSAR4, compiler warning]: Wrong define name in #undef statement causes re-definition warning
 *                                              add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin 
 *            2012-09-04  Ht                    add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-01-10  Seu                   MISRA deviation comments added
 *  01.08.00  2013-03-01  Seu    ESCAN00065501  AR4-325: Add support for Post-build RAM memory section
 *            2013-04-12  Seu    ESCAN00066614  Add the deviation for violation of MISRA rule 19.6
 *  01.09.00  2013-12-10  Seu    ESCAN00072537  Add *_NOCACHE_* memory sections for variables
 *            2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *  01.10.00  2016-09-27  Seu                   FEATC-317: FEAT-2002: CommonAsr__Common: Support 64 Bit Signal Types for COM according to ASR 4.2.2
 *  01.11.00  2017-07-05  Seu    ESCAN00095756  FEAT-2455: Support ASR4.2 compatible MemMap for MCALs
 *            2017-08-01  Seu    ESCAN00096129  MEMMAP_SW_MINOR_VERSION / MEM_SW_MINOR_VERSION is not correct
 *  01.12.00  2018-10-17  visdfe ESCAN00095695  Add support for Os_CoreGen7 within _MemMap.h (Include of Os_MemMap.h)
 *                               TASK-78775     Change MemMap_Common.h to Template
 *  01.13.00  2021-05-06  virmfr HALBE-3985     CommonAsr_MemMap shall include Common_MemMap generated compatibility header
 *  02.00.00  2021-06-09  visto  HALBE-4594     Create a branch for >=R27 Features
 *  02.01.00  2021-08-25  virmfr HALBE-4526     MemMap_Common.h removed
 *  02.01.01  2021-09-07  virmfr HALBE-5304     MemMapIncludesList removed
 *********************************************************************************************************************/

/* PRQA S 0841 MEMMAP_0841_TAG */ /* MD_MSR_19.6 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* PRQA S 0883 1 */ /* MD_MemMap_19.15 */
#undef MEMMAP_VENDOR_ID /* PRQA S 0841 */ /* MD_MSR_19.6 */

#define MEMMAP_VENDOR_ID        (30u)

/* AUTOSAR Software Specification Version Information */


# undef MEMMAP_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_AR_RELEASE_REVISION_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

/* AUTOSAR release 4.0 R3 */
# define MEMMAP_AR_RELEASE_MAJOR_VERSION       (4u)
# define MEMMAP_AR_RELEASE_MINOR_VERSION       (0u)
# define MEMMAP_AR_RELEASE_REVISION_VERSION    (3u)

/* compatiblity to older versions */
# undef MEM_AR_RELEASE_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_AR_RELEASE_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_AR_RELEASE_MAJOR_VERSION          MEMMAP_AR_RELEASE_MAJOR_VERSION
# define MEM_AR_RELEASE_MINOR_VERSION          MEMMAP_AR_RELEASE_MINOR_VERSION
# define MEM_AR_RELEASE_PATCH_VERSION          MEMMAP_AR_RELEASE_REVISION_VERSION


# undef MEMMAP_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEMMAP_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEMMAP_SW_MAJOR_VERSION     (2u)
# define MEMMAP_SW_MINOR_VERSION     (1u)
# define MEMMAP_SW_PATCH_VERSION     (1u)

/* compatiblity to older versions */
# undef MEM_SW_MAJOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_MINOR_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */
# undef MEM_SW_PATCH_VERSION /* PRQA S 0841 */ /* MD_MSR_19.6 */

# define MEM_SW_MAJOR_VERSION        MEMMAP_SW_MAJOR_VERSION 
# define MEM_SW_MINOR_VERSION        MEMMAP_SW_MINOR_VERSION 
# define MEM_SW_PATCH_VERSION        MEMMAP_SW_PATCH_VERSION 
  
#define MEMMAP_ERROR

/* Package Merger: Start Section MemMapModuleList */


/**********************************************************************************************************************
 *  CRYPTO_30_HWA START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CRYPTO_30_HWA_START_SEC_CODE)
# undef CRYPTO_30_HWA_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CODE)
# undef CRYPTO_30_HWA_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE /* default code stop section */
#endif

#ifdef CRYPTO_30_HWA_START_SEC_CODE_ISR
# undef CRYPTO_30_HWA_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR
#endif
#ifdef CRYPTO_30_HWA_STOP_SEC_CODE_ISR
# undef CRYPTO_30_HWA_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(CRYPTO_30_HWA_START_SEC_CODE_NOINLINE)
# undef CRYPTO_30_HWA_START_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs startnoinline
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma noinline
# endif
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CODE_NOINLINE)
# undef CRYPTO_30_HWA_STOP_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs endnoinline
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma noinline default
# endif
#endif

#if defined(CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED)
# undef CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED)
# undef CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CRYPTO_30_HWA_START_SEC_CONST_8BIT)
# undef CRYPTO_30_HWA_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CONST_8BIT)
# undef CRYPTO_30_HWA_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CRYPTO_30_HWA_START_SEC_RAMCODE)
# undef CRYPTO_30_HWA_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define CODE_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs section text=".vHsmRamCode"
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma section "vHsmRamCode"
# endif
# if defined(_HIGHTEC_GCC_C_ARM32_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma section ".vHsmRamCode" ax 4
# endif
# if defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma SET_CODE_SECTION(".vHsmRamCode")
# endif
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_RAMCODE)
# undef CRYPTO_30_HWA_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs section text=default
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma endsection
# endif
# if defined(_HIGHTEC_GCC_C_ARM32_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma section
# endif
# if defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma SET_CODE_SECTION()
# endif
#endif

/* VAR NOINIT sections */

#if defined(CRYPTO_30_HWA_START_SEC_VAR_NOINIT_8BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_8BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_NOINIT_32BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_32BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYPTO_30_HWA END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYPTO_30_HWA START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CRYPTO_30_HWA_START_SEC_CODE)
# undef CRYPTO_30_HWA_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CODE)
# undef CRYPTO_30_HWA_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CRYPTO_30_HWA_START_SEC_CODE_ISR
# undef CRYPTO_30_HWA_START_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE_ISR
#endif
#ifdef CRYPTO_30_HWA_STOP_SEC_CODE_ISR
# undef CRYPTO_30_HWA_STOP_SEC_CODE_ISR /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(CRYPTO_30_HWA_START_SEC_CODE_NOINLINE)
# undef CRYPTO_30_HWA_START_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs startnoinline
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma noinline
# endif
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CODE_NOINLINE)
# undef CRYPTO_30_HWA_STOP_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs endnoinline
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma noinline default
# endif
#endif

#if defined(CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED)
# undef CRYPTO_30_HWA_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED)
# undef CRYPTO_30_HWA_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CRYPTO_30_HWA_START_SEC_CONST_8BIT)
# undef CRYPTO_30_HWA_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_CONST_8BIT)
# undef CRYPTO_30_HWA_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(CRYPTO_30_HWA_START_SEC_RAMCODE)
# undef CRYPTO_30_HWA_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define CODE_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs section text=".vHsmRamCode"
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma section "vHsmRamCode"
# endif
# if defined(_HIGHTEC_GCC_C_ARM32_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma section ".vHsmRamCode" ax 4
# endif
# if defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma SET_CODE_SECTION(".vHsmRamCode")
# endif
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_RAMCODE)
# undef CRYPTO_30_HWA_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma ghs section text=default
# endif
# if defined(_TASKING_C_ARM_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma endsection
# endif
# if defined(_HIGHTEC_GCC_C_ARM32_) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma section
# endif
# if defined(__TI_COMPILER_VERSION__) /* COV_CRYPTO_30_HWA_MEMMAP_EXAMPLE */
#  pragma SET_CODE_SECTION()
# endif
#endif

/* VAR NOINIT sections */

#if defined(CRYPTO_30_HWA_START_SEC_VAR_NOINIT_8BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_8BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_NOINIT_32BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_32BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_8BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_32BIT)
# undef CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef CRYPTO_30_HWA_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYPTO_30_HWA END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  CRYPTO_30_KEYM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(CRYPTO_30_KEYM_START_SEC_CODE)
# undef CRYPTO_30_KEYM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#if defined(CRYPTO_30_KEYM_STOP_SEC_CODE)
# undef CRYPTO_30_KEYM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#if defined(CRYPTO_30_KEYM_START_SEC_CONST_8BIT)
# undef CRYPTO_30_KEYM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(CRYPTO_30_KEYM_STOP_SEC_CONST_8BIT)
# undef CRYPTO_30_KEYM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR ZERO INIT sections */
#ifdef CRYPTO_30_KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef CRYPTO_30_KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef CRYPTO_30_KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef CRYPTO_30_KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif
/**********************************************************************************************************************
 *  CRYPTO_30_KEYM END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr START 
 **********************************************************************************************************************/

/*******  CODE sections ***********************************************************************************************/
#ifdef FLS_START_SEC_CODE
# undef FLS_START_SEC_CODE
# define START_SEC_CODE
#endif

#ifdef FLS_STOP_SEC_CODE
# undef FLS_STOP_SEC_CODE
# define STOP_SEC_CODE
#endif

/*******  CONST sections  *********************************************************************************************/

/*******  VAR sections  ***********************************************************************************************/


/**********************************************************************************************************************
 *  DrvFls_VttCanoe01Asr END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VMEM_30_TC3XXINF01 START 
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEM_30_TC3XXINF01_START_SEC_CODE)
# undef VMEM_30_TC3XXINF01_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEM_30_TC3XXINF01_STOP_SEC_CODE)
# undef VMEM_30_TC3XXINF01_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif


/*******  CONST sections  ********************************************************************************************/

/* CONST sections */
#if defined VMEM_30_TC3XXINF01_START_SEC_CONST_UNSPECIFIED
# undef VMEM_30_TC3XXINF01_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED
# undef VMEM_30_TC3XXINF01_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_TC3XXINF01_START_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_TC3XXINF01_START_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined VMEM_30_TC3XXINF01_STOP_SEC_HEADER_CONST_UNSPECIFIED
# undef VMEM_30_TC3XXINF01_STOP_SEC_HEADER_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined VMEM_30_TC3XXINF01_START_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_TC3XXINF01_START_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined VMEM_30_TC3XXINF01_STOP_SEC_FOOTER_CONST_32BIT
# undef VMEM_30_TC3XXINF01_STOP_SEC_FOOTER_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif


/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef VMEM_30_TC3XXINF01_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_TC3XXINF01_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VMEM_30_TC3XXINF01_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VMEM_30_TC3XXINF01_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR INIT sections */

/**********************************************************************************************************************
 *  VMEM_30_TC3XXINF01 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
* 3rdParty_Mcal START
*********************************************************************************************************************/

#ifdef FEE_START_SEC_CODE
  #undef FEE_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE
  #undef FEE_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CODE_QM_LOCAL
  #undef FEE_START_SEC_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_CODE_QM_LOCAL
  #undef FEE_STOP_SEC_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #undef FEE_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #undef FEE_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_CONST_QM_LOCAL_32
  #undef FEE_START_SEC_CONST_QM_LOCAL_32
  #define START_SEC_CONST_32BIT
#endif

#ifdef FEE_STOP_SEC_CONST_QM_LOCAL_32
  #undef FEE_STOP_SEC_CONST_QM_LOCAL_32
  #define STOP_SEC_CONST
#endif

#ifdef FEE_START_SEC_ERASEERRORNOTI_CODE_QM_LOCAL
  #undef FEE_START_SEC_ERASEERRORNOTI_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_ERASEERRORNOTI_CODE_QM_LOCAL
  #undef FEE_STOP_SEC_ERASEERRORNOTI_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_ILLEGALNOTIF_CODE_QM_LOCAL
  #undef FEE_START_SEC_ILLEGALNOTIF_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_ILLEGALNOTIF_CODE_QM_LOCAL
  #undef FEE_STOP_SEC_ILLEGALNOTIF_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_JOBENDNOTIF_CODE_QM_LOCAL
  #undef FEE_START_SEC_JOBENDNOTIF_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_JOBENDNOTIF_CODE_QM_LOCAL
  #undef FEE_STOP_SEC_JOBENDNOTIF_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_JOBERRNOTIF_CODE_QM_LOCAL
  #undef FEE_START_SEC_JOBERRNOTIF_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_JOBERRNOTIF_CODE_QM_LOCAL
  #undef FEE_STOP_SEC_JOBERRNOTIF_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_PROGERRORNOTI_CODE_QM_LOCAL
  #undef FEE_START_SEC_PROGERRORNOTI_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FEE_STOP_SEC_PROGERRORNOTI_CODE_QM_LOCAL
  #undef FEE_STOP_SEC_PROGERRORNOTI_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #undef FEE_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #undef FEE_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #undef FEE_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #undef FEE_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

#ifdef FLS_17_DMU_START_SEC_CODE
  #undef FLS_17_DMU_START_SEC_CODE
  #define START_SEC_CODE
#endif

#ifdef FLS_17_DMU_STOP_SEC_CODE
  #undef FLS_17_DMU_STOP_SEC_CODE
  #define STOP_SEC_CODE
#endif

#ifdef FLS_17_DMU_START_SEC_CODE_QM_LOCAL
  #undef FLS_17_DMU_START_SEC_CODE_QM_LOCAL
  #define START_SEC_CODE
#endif

#ifdef FLS_17_DMU_STOP_SEC_CODE_QM_LOCAL
  #undef FLS_17_DMU_STOP_SEC_CODE_QM_LOCAL
  #define STOP_SEC_CODE
#endif

#ifdef FLS_17_DMU_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #define START_SEC_CONST_UNSPECIFIED
#endif

#ifdef FLS_17_DMU_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
  #define STOP_SEC_CONST
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #undef FLS_17_DMU_START_SEC_VAR_CLEARED_QM_LOCAL_32
  #define START_SEC_VAR_ZERO_INIT_32BIT
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
  #define STOP_SEC_VAR
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #undef FLS_17_DMU_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
  #define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
* 3rdParty_Mcal END
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  CRYIF START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CRYIF_START_SEC_CODE
# undef CRYIF_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CRYIF_STOP_SEC_CODE
# undef CRYIF_STOP_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CRYIF_START_SEC_CONST_UNSPECIFIED
# undef CRYIF_START_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */


/* VAR ZERO INIT sections */

#ifdef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CRYIF END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VMEMACCM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VMEMACCM_START_SEC_CODE)
# undef VMEMACCM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VMEMACCM_STOP_SEC_CODE)
# undef VMEMACCM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_8BIT          /* mapped to default var init 8bit section */
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR                     /* default var stop section */
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_INIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_INIT_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_8BIT    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED    /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR CONST sections */

#if defined(VMEMACCM_START_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_START_SEC_CONST_UNSPECIFIED  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_CONST_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_CONST_UNSPECIFIED   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/* VAR NOINIT sections */

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_16BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_32BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VMEMACCM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* Multi partition sections. */

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition0"
#   pragma ghs section sdata=".svMemAccMPartition0"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID0
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif


#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition1"
#   pragma ghs section sdata=".svMemAccMPartition1"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID1
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition2"
#   pragma ghs section sdata=".svMemAccMPartition2"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID2
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition3"
#   pragma ghs section sdata=".svMemAccMPartition3"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID3
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition4"
#   pragma ghs section sdata=".svMemAccMPartition4"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID4
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition5"
#   pragma ghs section sdata=".svMemAccMPartition5"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID5
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition6"
#   pragma ghs section sdata=".svMemAccMPartition6"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID6
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition7"
#   pragma ghs section sdata=".svMemAccMPartition7"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID7
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition8"
#   pragma ghs section sdata=".svMemAccMPartition8"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID8
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition9"
#   pragma ghs section sdata=".svMemAccMPartition9"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID9
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition10"
#   pragma ghs section sdata=".svMemAccMPartition10"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID10
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition11"
#   pragma ghs section sdata=".svMemAccMPartition11"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID11
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition12"
#   pragma ghs section sdata=".svMemAccMPartition12"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID12
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition13"
#   pragma ghs section sdata=".svMemAccMPartition13"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID13
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition14"
#   pragma ghs section sdata=".svMemAccMPartition14"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID14
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition15"
#   pragma ghs section sdata=".svMemAccMPartition15"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID15
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

#if defined VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_START_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else    
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
   /* Pragma demo for GHS compiler: */
#   pragma ghs section data=".vMemAccMPartition16"
#   pragma ghs section sdata=".svMemAccMPartition16"
#  else 
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define START_SEC_VAR_INIT_32BIT
#endif

#if defined VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# undef VMEMACCM_STOP_SEC_MULTIPARTITION_PARTITION_ID16
# if defined VMEMACCM_COMPONENT_TEST
  /* Nothing to to here. */
# else
#  if defined VMEMACCM_MEMMAP_DEMO_GHS
    /* Pragma demo for GHS compiler: */
#   pragma ghs section data=default
#   pragma ghs section sdata=default
#  else
#   error "vMemAccM multi partition pragma: Please set the pragma appropriately! See technical reference for more information."
   /* Remove the error and place the appropriate pragma command here. */
#  endif
# endif
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VMEMACCM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef CSM_START_SEC_CODE
# undef CSM_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_CODE
# undef CSM_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef CSM_START_SEC_APPL_CODE
# undef CSM_START_SEC_APPL_CODE  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef CSM_STOP_SEC_APPL_CODE
# undef CSM_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef CSM_START_SEC_CONST_8BIT
# undef CSM_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif

#ifdef CSM_STOP_SEC_CONST_8BIT
# undef CSM_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef CSM_START_SEC_CONST_UNSPECIFIED
# undef CSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_CONST_UNSPECIFIED
# undef CSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NOINIT sections */

#ifdef CSM_START_SEC_VAR_NOINIT_8BIT
# undef CSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_8BIT
# undef CSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_16BIT
# undef CSM_START_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_16BIT
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_16BIT
# undef CSM_STOP_SEC_VAR_NOINIT_16BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#ifdef CSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef CSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  CSM END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  KEYM START
 **********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/
#ifdef KEYM_START_SEC_CODE
# undef KEYM_START_SEC_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_CODE
# undef KEYM_STOP_SEC_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#ifdef KEYM_START_SEC_APPL_CODE
# undef KEYM_START_SEC_APPL_CODE                         /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif
#ifdef KEYM_STOP_SEC_APPL_CODE
# undef KEYM_STOP_SEC_APPL_CODE                          /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef KEYM_START_SEC_CONST_8
# undef KEYM_START_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8
#endif
#ifdef KEYM_STOP_SEC_CONST_8
# undef KEYM_STOP_SEC_CONST_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_16
# undef KEYM_START_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_16
#endif
#ifdef KEYM_STOP_SEC_CONST_16
# undef KEYM_STOP_SEC_CONST_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_32
# undef KEYM_START_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32
#endif
#ifdef KEYM_STOP_SEC_CONST_32
# undef KEYM_STOP_SEC_CONST_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef KEYM_START_SEC_CONST_UNSPECIFIED
# undef KEYM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_CONST_UNSPECIFIED
# undef KEYM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR NO_INIT sections */

#ifdef KEYM_START_SEC_VAR_NO_INIT_8
# undef KEYM_START_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_8
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_8
# undef KEYM_STOP_SEC_VAR_NO_INIT_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_16
# undef KEYM_START_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_16
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_16
# undef KEYM_STOP_SEC_VAR_NO_INIT_16 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_32
# undef KEYM_START_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_32
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_32
# undef KEYM_STOP_SEC_VAR_NO_INIT_32 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_START_SEC_VAR_NO_INIT_UNSPECIFIED              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED               /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef KEYM_START_SEC_VAR_CLEARED_8
# undef KEYM_START_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_8
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_8
# undef KEYM_STOP_SEC_VAR_CLEARED_8 /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_START_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#ifdef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
# undef KEYM_STOP_SEC_VAR_CLEARED_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/***********************************************************************************************************************
 *  KEYM END
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  VSTDLIB START
 *********************************************************************************************************************/

#if defined(VSTDLIB_START_SEC_CODE)
# undef VSTDLIB_START_SEC_CODE                             /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                    /* mapped to default code section */
#endif
#if defined(VSTDLIB_STOP_SEC_CODE)
# undef VSTDLIB_STOP_SEC_CODE                              /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined(VSTDLIB_START_SEC_CONST_8BIT)
# undef VSTDLIB_START_SEC_CONST_8BIT                       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                              /* mapped to const 8 bit section */
#endif
#if defined(VSTDLIB_STOP_SEC_CONST_8BIT)
# undef VSTDLIB_STOP_SEC_CONST_8BIT                        /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                    /* default const stop section */
#endif

/**********************************************************************************************************************
 *  VSTDLIB END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VHSMUPD START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VHSMUPD_START_SEC_CODE)
# undef VHSMUPD_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VHSMUPD_STOP_SEC_CODE)
# undef VHSMUPD_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(VHSMUPD_START_SEC_CODE_RAM)
/* Example definition of own section for ram code */
# undef VHSMUPD_START_SEC_CODE_RAM  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_CODE_SEC
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs section text=".vHsmUpdRamCode"
# endif
# if defined(_TASKING_C_ARM_)
#  pragma section "vHsmUpdRamCode"
#  pragma call far
# endif
# if defined(_GNU_C_CORTEXM3_)
#  pragma section ".vHsmUpdRamCode" ax 4
# endif
#endif
#if defined(VHSMUPD_STOP_SEC_CODE_RAM)
# undef VHSMUPD_STOP_SEC_CODE_RAM  /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef START_CODE_SEC /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs section text=default
# endif
# if defined(_TASKING_C_ARM_)
#  pragma call default
#  pragma endsection
# endif
# if defined(_GNU_C_CORTEXM3_)
#  pragma section
# endif
#endif

/*******  CONST sections  ********************************************************************************************/
/* CONST sections */

#if defined(VHSMUPD_START_SEC_CONST_8BIT)
# undef VHSMUPD_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(VHSMUPD_STOP_SEC_CONST_8BIT)
# undef VHSMUPD_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/**********************************************************************************************************************
 *  VHSMUPD END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VHSMUPD_EXT START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VHSMUPD_EXT_START_SEC_CODE)
# undef VHSMUPD_EXT_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_CODE)
# undef VHSMUPD_EXT_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/*******  CONST sections  ********************************************************************************************/
/* CONST sections */

#if defined(VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED)
# undef VHSMUPD_EXT_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED)
# undef VHSMUPD_EXT_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(VHSMUPD_EXT_START_SEC_CONST_8BIT)
# undef VHSMUPD_EXT_START_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_CONST_8BIT)
# undef VHSMUPD_EXT_STOP_SEC_CONST_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(VHSMUPD_EXT_START_SEC_CONST_32BIT)
# undef VHSMUPD_EXT_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_CONST_32BIT)
# undef VHSMUPD_EXT_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/
/* VAR NOINIT sections */
#if defined(VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VHSMUPD_EXT_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER)
/* own section for internal data buffer, which will be forwared to the vMem. On some platforms this buffer
 * must be aligned to prevent unaligned memory access exceptions */
# undef VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER)
# undef VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER_TMP)
/* Own section for internal data buffer, which will be forwared to the vMem. On some platforms this buffer
 * must be aligned to prevent unaligned memory access exceptions */
# undef VHSMUPD_EXT_START_SEC_VAR_NOINIT_RAM_BUFFER_TMP /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER_TMP)
# undef VHSMUPD_EXT_STOP_SEC_VAR_NOINIT_RAM_BUFFER_TMP /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* vHsm Upd callout sections */
/* ----------------------------------------------------------------------------------------------------------------- */
#if defined( VHSMUPD_EXT_START_SEC_CODE_MAC_CALLOUT )
# undef VHSMUPD_EXT_START_SEC_CODE_MAC_CALLOUT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#if defined( VHSMUPD_EXT_STOP_SEC_CODE_MAC_CALLOUT )
# undef VHSMUPD_EXT_STOP_SEC_CODE_MAC_CALLOUT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

#if defined( VHSMUPD_EXT_START_SEC_CODE_CIPHER_CALLOUT )
# undef VHSMUPD_EXT_START_SEC_CODE_CIPHER_CALLOUT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE
#endif

#if defined( VHSMUPD_EXT_STOP_SEC_CODE_CIPHER_CALLOUT )
# undef VHSMUPD_EXT_STOP_SEC_CODE_CIPHER_CALLOUT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE
#endif

/**********************************************************************************************************************
 *  VHSMUPD_EXT END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  VHSMUPD_HAL START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VHSMUPD_HAL_START_SEC_CODE)
# undef VHSMUPD_HAL_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VHSMUPD_HAL_STOP_SEC_CODE)
# undef VHSMUPD_HAL_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE          /* default code stop section */
#endif

#if defined(VHSMUPD_HAL_START_SEC_CONST_32)
# undef VHSMUPD_HAL_START_SEC_CONST_32      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32         /* mapped to default code section */
#endif
#if defined(VHSMUPD_HAL_STOP_SEC_CONST_32)
# undef VHSMUPD_HAL_STOP_SEC_CONST_32       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST         /* default code stop section */
#endif


/**********************************************************************************************************************
 *  VHSMUPD_HAL END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VHSM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#ifdef VHSM_START_SEC_CODE
# undef VHSM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef VHSM_STOP_SEC_CODE
# undef VHSM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef VHSM_START_SEC_CODE_MAC_CALLOUT
# undef VHSM_START_SEC_CODE_MAC_CALLOUT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef VHSM_STOP_SEC_CODE_MAC_CALLOUT
# undef VHSM_STOP_SEC_CODE_MAC_CALLOUT       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef VHSM_START_SEC_CODE_CIPHER_CALLOUT
# undef VHSM_START_SEC_CODE_CIPHER_CALLOUT      /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE                                               /* mapped to default code section */
#endif
#ifdef VHSM_STOP_SEC_CODE_CIPHER_CALLOUT
# undef VHSM_STOP_SEC_CODE_CIPHER_CALLOUT       /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE                                                /* default code stop section */
#endif

#ifdef VHSM_START_SEC_RAMCODE
# undef VHSM_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define CODE_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section CODE ".vHsmRamCode"
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=".vHsmRamCode"
#  pragma ghs far
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section "vHsmRamCode"
#  pragma call far
# endif
# if (defined(_TASKING_C_TC4_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section all "vHsmRamCode"
#  pragma indirect
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmRamCode" ax 4
# endif
#endif
#ifdef VHSM_STOP_SEC_RAMCODE
# undef VHSM_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section CODE
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section text=default
#  pragma ghs callmode=default
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma call default
#  pragma endsection
# endif
# if (defined(_TASKING_C_TC4_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section all default
#  pragma indirect default
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# endif
#endif

#ifdef VHSM_START_SEC_CODE_NOINLINE
# undef VHSM_START_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs startnoinline
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma noinline
# endif
# if (defined(_TASKING_C_TC4_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma noinline
# endif
#endif
#ifdef VHSM_STOP_SEC_CODE_NOINLINE
# undef VHSM_STOP_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs endnoinline
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma noinline restore
# endif
# if (defined(_TASKING_C_TC4_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma noinline restore
# endif
#endif

/*******  CONST sections  ********************************************************************************************/

/* CONST sections */

#ifdef VHSM_START_SEC_CONST_8BIT
# undef VHSM_START_SEC_CONST_8BIT  /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_8BIT                                         /* mapped to default const 8bit section */
#endif
#ifdef VHSM_STOP_SEC_CONST_8BIT
# undef VHSM_STOP_SEC_CONST_8BIT   /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST                                               /* default const stop section */
#endif

#ifdef VHSM_START_SEC_CONST_32BIT
# undef VHSM_START_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_32BIT
#endif
#ifdef VHSM_STOP_SEC_CONST_32BIT
# undef VHSM_STOP_SEC_CONST_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#ifdef VHSM_START_SEC_CONST_UNSPECIFIED
# undef VHSM_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#ifdef VHSM_STOP_SEC_CONST_UNSPECIFIED
# undef VHSM_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

/*******  VAR sections  **********************************************************************************************/

/* VAR INIT sections */
#ifdef VHSM_START_SEC_VAR_INIT_UNSPECIFIED
# undef VHSM_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_INIT_UNSPECIFIED
#endif
#ifdef VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
# undef VHSM_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */
#ifdef VHSM_START_SEC_VAR_ZERO_INIT_8BIT
# undef VHSM_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#ifdef VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT
# undef VHSM_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VHSM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#ifdef VHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# undef VHSM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR NOINIT sections */
#ifdef VHSM_START_SEC_VAR_NOINIT_8BIT
# undef VHSM_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#ifdef VHSM_STOP_SEC_VAR_NOINIT_8BIT
# undef VHSM_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VHSM_START_SEC_VAR_NOINIT_32BIT
# undef VHSM_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#ifdef VHSM_STOP_SEC_VAR_NOINIT_32BIT
# undef VHSM_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# undef VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#ifdef VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# undef VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#ifdef VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA ".vHsmIpcMemory"
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  if defined(__CORE_CORTEXM0PLUS__) /* COV_VHSM_MEMMAP_EXAMPLE */
#   pragma ghs section bss=".vHsmIpcMemory"
#  else
#   pragma ghs section bss=".vHsmIpcMemory"
#   pragma ghs section sbss=".svHsmIpcMemory"
#  endif
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section "vHsmIpcMemory"
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmIpcMemory" aw 4
# endif
#endif
#ifdef VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# undef VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  if defined(__CORE_CORTEXM0PLUS__) /* COV_VHSM_MEMMAP_EXAMPLE */
#   pragma ghs section bss=default
#  else
#   pragma ghs section bss=default
#   pragma ghs section sbss=default
#  endif
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma endsection
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# endif
#endif

#ifdef VHSM_START_SEC_IPC_MEMORY1_VAR_NOINIT_32BIT
# undef VHSM_START_SEC_IPC_MEMORY1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA ".vHsmIpcMemory1"
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  if defined(__CORE_CORTEXM0PLUS__) /* COV_VHSM_MEMMAP_EXAMPLE */
#   pragma ghs section bss=".vHsmIpcMemory1"
#  else
#   pragma ghs section bss=".vHsmIpcMemory1"
#   pragma ghs section sbss=".svHsmIpcMemory1"
#  endif
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section "vHsmIpcMemory1"
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmIpcMemory1" aw 4
# endif
#endif
#ifdef VHSM_STOP_SEC_IPC_MEMORY1_VAR_NOINIT_32BIT
# undef VHSM_STOP_SEC_IPC_MEMORY1_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  if defined(__CORE_CORTEXM0PLUS__) /* COV_VHSM_MEMMAP_EXAMPLE */
#   pragma ghs section bss=default
#  else
#   pragma ghs section bss=default
#   pragma ghs section sbss=default
#  endif
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma endsection
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# endif
#endif

#ifdef VHSM_START_SEC_IPC_MEMORY2_VAR_NOINIT_32BIT
# undef VHSM_START_SEC_IPC_MEMORY2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define VAR_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA ".vHsmIpcMemory2"
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  if defined(__CORE_CORTEXM0PLUS__) /* COV_VHSM_MEMMAP_EXAMPLE */
#   pragma ghs section bss=".vHsmIpcMemory2"
#  else
#   pragma ghs section bss=".vHsmIpcMemory2"
#   pragma ghs section sbss=".svHsmIpcMemory2"
#  endif
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section "vHsmIpcMemory2"
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmIpcMemory2" aw 4
# endif
#endif
#ifdef VHSM_STOP_SEC_IPC_MEMORY2_VAR_NOINIT_32BIT
# undef VHSM_STOP_SEC_IPC_MEMORY2_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef VAR_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  if defined(__CORE_CORTEXM0PLUS__) /* COV_VHSM_MEMMAP_EXAMPLE */
#   pragma ghs section bss=default
#  else
#   pragma ghs section bss=default
#   pragma ghs section sbss=default
#  endif
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma endsection
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# endif
#endif

#ifdef VHSM_START_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED
# undef VHSM_START_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA ".vHsmResetInfo"
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=".vHsmResetInfo"
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section "vHsmResetInfo"
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section ".vHsmResetInfo" aw 4
# endif
#endif
#ifdef VHSM_STOP_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED
# undef VHSM_STOP_SEC_RESET_INFO_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__DCC__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section DATA
# endif
# if defined(__ghs__) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma ghs section bss=default
# endif
# if (defined(_TASKING_C_ARM_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma endsection
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_)) /* COV_VHSM_MEMMAP_EXAMPLE */
#  pragma section
# endif
#endif

/**********************************************************************************************************************
 *  VHSM END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VHSM_CUSTOM START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VHSM_CUSTOM_START_SEC_CODE)
# undef VHSM_CUSTOM_START_SEC_CODE      /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define START_SEC_CODE         /* mapped to default code section */
#endif
#if defined(VHSM_CUSTOM_STOP_SEC_CODE)
# undef VHSM_CUSTOM_STOP_SEC_CODE       /* PRQA S 0841 */ /* MD_MSR_19.6 */
# define STOP_SEC_CODE          /* default code stop section */
#endif

/**********************************************************************************************************************
 *  VHSM_CUSTOM END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VHSM_HAL START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VHSM_HAL_START_SEC_CODE)
# undef VHSM_HAL_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#if defined(VHSM_HAL_STOP_SEC_CODE)
# undef VHSM_HAL_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE /* default code stop section */
#endif

#if defined(VHSM_HAL_START_SEC_CODE_NOINLINE)
# undef VHSM_HAL_START_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs startnoinline
# endif
# if defined(_TASKING_C_ARM_)
#  pragma noinline
# endif
#endif
#if defined(VHSM_HAL_STOP_SEC_CODE_NOINLINE)
# undef VHSM_HAL_STOP_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs endnoinline
# endif
# if defined(_TASKING_C_ARM_)
#  pragma noinline default
# endif
#endif

#if defined(VHSM_HAL_START_SEC_CONST_UNSPECIFIED)
# undef VHSM_HAL_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VHSM_HAL_STOP_SEC_CONST_UNSPECIFIED)
# undef VHSM_HAL_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(VHSM_HAL_START_SEC_RAMCODE)
# undef VHSM_HAL_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define CODE_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs section text=".vHsmRamCode"
# endif
# if defined(_TASKING_C_ARM_)
#  pragma section "vHsmRamCode"
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_) || defined(_HIGHTEC_GCC_C_MPC_))
#  pragma section ".vHsmRamCode" ax 4
# endif
#endif
#if defined(VHSM_HAL_STOP_SEC_RAMCODE)
# undef VHSM_HAL_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs section text=default
# endif
# if defined(_TASKING_C_ARM_)
#  pragma endsection
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_) || defined(_HIGHTEC_GCC_C_MPC_))
#  pragma section
# endif
#endif

/* VAR NOINIT sections */

#if defined(VHSM_HAL_START_SEC_VAR_NOINIT_8BIT)
# undef VHSM_HAL_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_NOINIT_8BIT)
# undef VHSM_HAL_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_NOINIT_32BIT)
# undef VHSM_HAL_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_NOINIT_32BIT)
# undef VHSM_HAL_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VHSM_HAL_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VHSM_HAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VHSM_HAL_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VHSM_HAL_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_ZERO_INIT_32BIT)
# undef VHSM_HAL_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VHSM_HAL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VHSM_HAL END
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  VHSM_HAL START
 *********************************************************************************************************************/

/*******  CODE sections **********************************************************************************************/

#if defined(VHSM_HAL_START_SEC_CODE)
# undef VHSM_HAL_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CODE /* mapped to default code section */
#endif
#if defined(VHSM_HAL_STOP_SEC_CODE)
# undef VHSM_HAL_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CODE /* default code stop section */
#endif

#if defined(VHSM_HAL_START_SEC_CODE_NOINLINE)
# undef VHSM_HAL_START_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs startnoinline
# endif
# if defined(_TASKING_C_ARM_)
#  pragma noinline
# endif
#endif
#if defined(VHSM_HAL_STOP_SEC_CODE_NOINLINE)
# undef VHSM_HAL_STOP_SEC_CODE_NOINLINE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs endnoinline
# endif
# if defined(_TASKING_C_ARM_)
#  pragma noinline default
# endif
#endif

#if defined(VHSM_HAL_START_SEC_CONST_UNSPECIFIED)
# undef VHSM_HAL_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_CONST_UNSPECIFIED
#endif
#if defined(VHSM_HAL_STOP_SEC_CONST_UNSPECIFIED)
# undef VHSM_HAL_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_CONST
#endif

#if defined(VHSM_HAL_START_SEC_RAMCODE)
# undef VHSM_HAL_START_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# define CODE_SEC_OPEN
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs section text=".vHsmRamCode"
# endif
# if defined(_TASKING_C_ARM_)
#  pragma section "vHsmRamCode"
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_) || defined(_HIGHTEC_GCC_C_MPC_))
#  pragma section ".vHsmRamCode" ax 4
# endif
#endif
#if defined(VHSM_HAL_STOP_SEC_RAMCODE)
# undef VHSM_HAL_STOP_SEC_RAMCODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef CODE_SEC_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
# if defined(__ghs__)
#  pragma ghs section text=default
# endif
# if defined(_TASKING_C_ARM_)
#  pragma endsection
# endif
# if (defined(_HIGHTEC_GCC_C_ARM32_) || defined(_HIGHTEC_GCC_C_MPC_))
#  pragma section
# endif
#endif

/* VAR NOINIT sections */

#if defined(VHSM_HAL_START_SEC_VAR_NOINIT_8BIT)
# undef VHSM_HAL_START_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_8BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_NOINIT_8BIT)
# undef VHSM_HAL_STOP_SEC_VAR_NOINIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_NOINIT_32BIT)
# undef VHSM_HAL_START_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_32BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_NOINIT_32BIT)
# undef VHSM_HAL_STOP_SEC_VAR_NOINIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VHSM_HAL_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_NOINIT_UNSPECIFIED
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
# undef VHSM_HAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/* VAR ZERO INIT sections */

#if defined(VHSM_HAL_START_SEC_VAR_ZERO_INIT_8BIT)
# undef VHSM_HAL_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_8BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_8BIT)
# undef VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_ZERO_INIT_32BIT)
# undef VHSM_HAL_START_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_32BIT
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_32BIT)
# undef VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

#if defined(VHSM_HAL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VHSM_HAL_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#endif
#if defined(VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED)
# undef VHSM_HAL_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# define STOP_SEC_VAR
#endif

/**********************************************************************************************************************
 *  VHSM_HAL END
 *********************************************************************************************************************/


/* DemoHsm */


/* PRQA L:MEMMAP_0841_TAG */

/* contains all configured MemMap Sections -> fallback for compatibility reasons */
#include "MemMap_Compatibility.h" /* generated by module MemMap */

/* MEMMAP_ERROR is
  - still defined if MemMap_Compatibility did not contain a matching section
  - undefined, if MemMap_Compatibility handled the section define. */               
#ifdef MEMMAP_ERROR
# include "MemMap_Common.h"
#endif


/**********************************************************************************************************************
 *  END OF FILE: MemMap.h
 *********************************************************************************************************************/

