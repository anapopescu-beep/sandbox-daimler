/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2007 - 2013 by Vector Informatik GmbH.                                           All rights reserved.
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
 *         File:  _Compiler_Cfg.h
 *    Component:  -
 *       Module:  -
 *    Generator:  -
 *
 *  Description:  This File is a template for the Compiler_Cfg.h
 *                This file has to be extended with the memory and pointer classes for all BSW modules
 *                which where used.
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  MISRA VIOLATIONS
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Heike Honert                  Ht            Vector Informatik GmbH
 *  Eugen Stripling               Seu           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2007-08-01  Jk                    Initial creation
 *  01.01.00  2007-12-14  Jk                    Component specific defines filtering added
 *  01.01.01  2008-12-17  Ht                    Improve list of components  (Tp_AsrTpCan,Tp_AsrTpFr,DrvMcu,DrvIcu added)
 *  01.01.02  2009-04-27  Ht                    support OEM specific _compiler_cfg.inc file, improve list of components 
 *                                              (Cp_XcpOnCanAsr, Il_AsrIpduM, If_VxFblDcm, If_VxFblVpm_Volvo_ab, DrvFls added)
 *  01.01.03  2009-04-24  Msr                   Renamed J1939_AsrBase as TpJ1939_AsrBase
 *  01.01.04  2009-06-03  Ht                    Improve list of components (Adc, Dio, Gpt, Pwm, Spi, Wdg, Fls, Port, Fim)
 *  01.02.00  2009-08-01  Ht                    Improve list of components (Fee_30_Inst2, Can, ...Sub)
 *                                              Support filtering for RTE
 *  01.02.01  2009-09-02  Lo                    add external Flash driver support
 *  01.02.02  2009-09-21  Lo                    add DrvFls_Mcs12xFslftm01ExtVx
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
 *  01.03.02  2010-02-15  Ht                   support SysService_SswRcs_Daimler, SysService_Tls, Tp_Http, 
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
 *  01.05.04  2010-11-16  Ht                    add SysService_Exi, DrvTrans_Int6400EthAsr, Cdd_AsrCdd_Fiat, Diag_AsrDem_Fiat,
 *  01.05.05  2010-12-17  Ht                    add SysService_AsrSchM, DrvEep_XXStubAsr, DrvIcu_Tms570Tinhet01ExtVx
 *                                                  DrvWd_XTle4278gEAsr, DrvWd_XXStubAsr
 *  01.05.06  2011-02-17  Ht                    add DrvEed, SysService_AsrBswM
 *  01.05.07  2011-03-04  Ht                    add DrvTrans_Tja1055CandioAsr
 *                                              rename CanTrcv_30_Tja1040dio to CanTrcv_30_Tja1040
 *                                              add SysService_XmlEngine
 *  01.06.00  2011-03-04  Ht                    support ASR4.0
 *                                              add Ccl_Asr4ComM, Ccl_Asr4SmCan, Nm_Asr4NmIf, Nm_AsrNmDirOsek
 *  01.06.01  2011-04-15  Ht                    add Diag_AsrDcm_<OEM>
 *  01.06.02  2011-06-17  Ht                    correct Diag_AsrDcm_<OEM>
 *                                              add Monitoring_AsrDlt and Monitoring_GenericMeasurement
 *  01.06.03  2011-09-01  Ht                    add DrvTrans_Tja1145CanSpiAsr, DrvTrans_E52013CanspiAsr, DrvFls_XXStubAsr,
 *                                              If_AsrIfFeeV85xNec05Sub, If_AsrIfFeeV85xNec06Sub, If_AsrIfFeeV85xNec07Sub
 *                                              SysService_AsrWdMTttechSub and If_AsrIfWdTttechSub
 *  01.06.04  2011-10-20  Ht                    ESCAN00054334: add If_AsrIfFeeTiSub
 *                                              ESCAN00054719: add Cdd_AsrCdd
 *  01.06.05  2011-12-09  Ht                    add Tp_IpV4, Tp_IpV6
 *  01.06.06  2011-12-14  Ht                    add Monitoring_RuntimeMeasurement
 *  01.06.07  2012-01-03  Ht                    add DrvI2c, SysService_Asr4BswM
 *  01.06.08  2012-01-31  Ht                    add DrvTrans_Ar7000EthAsr, DrvTrans_GenericEthmiiAsr
 *  01.06.09  2012-03-06  Ht                    add If_AsrIfFeeMb9df126Fuji01Sub, 
 *                                              Infineon_Tc1767Inf01Sub, Infineon_Tc178xInf01Sub, Infineon_Tc1797Inf01Sub, Infineon_Tc1797Inf02Sub
 *  01.06.10  2012-03-13  Ht                    add Gw_AsrPduRCfg5, Il_AsrComCfg5, Il_AsrIpduMCfg5, Cdd_AsrCddCfg5,
 *                                              Tp_Asr4TpCan, Diag_Asr4Dcm, Diag_Asr4Dem
 *  01.06.11  2012-03-20  Ht                    add Cp_AsrCcp, Cp_XcpOnTcpIpAsr
 *  01.07.00  2012-07-26  Ht                    add Nm_Asr4NmCan, Nm_Asr4NmFr, Infineon_Xc2000Inf01Sub, Ccl_Asr4ComMCfg5, SysService_Asr4BswMCfg5, SysService_Asr4EcuM, SysService_AsrRamTst,
 *                                                  Ccl_Asr4SmLin
 *                                              add define REGSPACE - add support for ASR specification 4.0 R3
 *  01.07.01  2012-10-23  Seu                   add SysService_XmlSecurity
 *  01.07.02  2013-12-16  Seu                   MISRA compliance: usage of character "'" removed, typos corrected
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* Package Merger: Start Section CompilerCfgIncludes */
#ifdef VSWT_USED
#include "EthTrcv_30_Generic_Compiler_Cfg.h"
#endif


/* Package Merger: Stop Section CompilerCfgIncludes */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define AUTOSAR_COMSTACKDATA

#define MSR_REGSPACE  REGSPACE

/* Configurable memory class for pointers to registers (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */
#define REGSPACE


/* due to compatibility to ASR 2.1 */
#define _STATIC_   STATIC
#define _INLINE_   INLINE

/* Package Merger: Start Section CompilerCfgModuleList */



/**********************************************************************************************************************
 *  EEP_30_XXI2C01 START
 *********************************************************************************************************************/

#define EEP_30_XXI2C01_CODE
#define EEP_30_XXI2C01_APPL_CODE
#define EEP_30_XXI2C01_CONST
#define EEP_30_XXI2C01_PBCFG
#define EEP_30_XXI2C01_VAR_NO_INIT
#define EEP_30_XXI2C01_VAR_INIT
#define EEP_30_XXI2C01_APPL_DATA

/**********************************************************************************************************************
 *  EEP_30_XXI2C01 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  EEP_30_XXSPI01 START
 *********************************************************************************************************************/

#define EEP_30_XXSPI01_CODE
#define EEP_30_XXSPI01_APPL_CODE
#define EEP_30_XXSPI01_CONST
#define EEP_30_XXSPI01_PBCFG
#define EEP_30_XXSPI01_VAR_NO_INIT
#define EEP_30_XXSPI01_VAR_INIT
#define EEP_30_XXSPI01_APPL_DATA

/**********************************************************************************************************************
 *  EEP_30_XXSPI01 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHSWT_30_88Q5050 START
 *********************************************************************************************************************/

#define ETHSWT_30_88Q5050_CODE
#define ETHSWT_30_88Q5050_CODE_FAST
#define ETHSWT_30_88Q5050_CODE_ISR

#define ETHSWT_30_88Q5050_CONST
#define ETHSWT_30_88Q5050_CONST_FAST
#define ETHSWT_30_88Q5050_PBCFG

#define ETHSWT_30_88Q5050_VAR_INIT
#define ETHSWT_30_88Q5050_VAR_NOINIT
#define ETHSWT_30_88Q5050_VAR_ZERO_INIT
#define ETHSWT_30_88Q5050_VAR_INIT_FAST
#define ETHSWT_30_88Q5050_VAR_NOINIT_FAST
#define ETHSWT_30_88Q5050_VAR_ZERO_INIT_FAST

#define ETHSWT_30_88Q5050_VAR_INIT_NOCACHE
#define ETHSWT_30_88Q5050_VAR_NOINIT_NOCACHE
#define ETHSWT_30_88Q5050_VAR_ZERO_INIT_NOCACHE

#define ETHSWT_30_88Q5050_APPL_VAR
#define ETHSWT_30_88Q5050_APPL_CONST

/**********************************************************************************************************************
 *  ETHSWT_30_88Q5050 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHSWT_30_88Q5072 START
 *********************************************************************************************************************/

#define ETHSWT_30_88Q5072_CODE
#define ETHSWT_30_88Q5072_CODE_FAST
#define ETHSWT_30_88Q5072_CODE_ISR

#define ETHSWT_30_88Q5072_CONST
#define ETHSWT_30_88Q5072_CONST_FAST
#define ETHSWT_30_88Q5072_PBCFG

#define ETHSWT_30_88Q5072_VAR_INIT
#define ETHSWT_30_88Q5072_VAR_NOINIT
#define ETHSWT_30_88Q5072_VAR_ZERO_INIT
#define ETHSWT_30_88Q5072_VAR_INIT_FAST
#define ETHSWT_30_88Q5072_VAR_NOINIT_FAST
#define ETHSWT_30_88Q5072_VAR_ZERO_INIT_FAST

#define ETHSWT_30_88Q5072_VAR_INIT_NOCACHE
#define ETHSWT_30_88Q5072_VAR_NOINIT_NOCACHE
#define ETHSWT_30_88Q5072_VAR_ZERO_INIT_NOCACHE

#define ETHSWT_30_88Q5072_APPL_VAR
#define ETHSWT_30_88Q5072_APPL_CONST

/**********************************************************************************************************************
 *  ETHSWT_30_88Q5072 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHSWT START 
 *********************************************************************************************************************/

#define ETHSWT_30_BCM8953X_CODE
#define ETHSWT_30_BCM8953X_CODE_FAST
#define ETHSWT_30_BCM8953X_CODE_ISR

#define ETHSWT_30_BCM8953X_CONST
#define ETHSWT_30_BCM8953X_CONST_FAST

#define ETHSWT_30_BCM8953X_VAR_INIT
#define ETHSWT_30_BCM8953X_VAR_NOINIT
#define ETHSWT_30_BCM8953X_VAR_ZERO_INIT
#define ETHSWT_30_BCM8953X_VAR_INIT_FAST
#define ETHSWT_30_BCM8953X_VAR_NOINIT_FAST
#define ETHSWT_30_BCM8953X_VAR_ZERO_INIT_FAST

#define ETHSWT_30_BCM8953X_VAR_INIT_NOCACHE
#define ETHSWT_30_BCM8953X_VAR_NOINIT_NOCACHE
#define ETHSWT_30_BCM8953X_VAR_ZERO_INIT_NOCACHE

#define ETHSWT_30_BCM8953X_APPL_DATA
#define ETHSWT_30_BCM8953X_APPL_VAR
#define ETHSWT_30_BCM8953X_APPL_CONST


/**********************************************************************************************************************
 *  ETHSWT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHSWT_30_RTL90XX START
 *********************************************************************************************************************/

#define ETHSWT_30_RTL90XX_CODE
#define ETHSWT_30_RTL90XX_CODE_FAST
#define ETHSWT_30_RTL90XX_CODE_ISR

#define ETHSWT_30_RTL90XX_CONST
#define ETHSWT_30_RTL90XX_CONST_FAST
#define ETHSWT_30_RTL90XX_PBCFG

#define ETHSWT_30_RTL90XX_VAR_INIT
#define ETHSWT_30_RTL90XX_VAR_NOINIT
#define ETHSWT_30_RTL90XX_VAR_ZERO_INIT
#define ETHSWT_30_RTL90XX_VAR_INIT_FAST
#define ETHSWT_30_RTL90XX_VAR_NOINIT_FAST
#define ETHSWT_30_RTL90XX_VAR_ZERO_INIT_FAST

#define ETHSWT_30_RTL90XX_VAR_INIT_NOCACHE
#define ETHSWT_30_RTL90XX_VAR_NOINIT_NOCACHE
#define ETHSWT_30_RTL90XX_VAR_ZERO_INIT_NOCACHE

#define ETHSWT_30_RTL90XX_APPL_VAR
#define ETHSWT_30_RTL90XX_APPL_CONST

/**********************************************************************************************************************
 *  ETHSWT_30_RTL90XX END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHSWT START 
 *********************************************************************************************************************/

#define ETHSWT_30_SJA1105PQRS_CODE
#define ETHSWT_30_SJA1105PQRS_CODE_FAST
#define ETHSWT_30_SJA1105PQRS_CODE_ISR

#define ETHSWT_30_SJA1105PQRS_CONST
#define ETHSWT_30_SJA1105PQRS_CONST_FAST

#define ETHSWT_30_SJA1105PQRS_VAR_INIT
#define ETHSWT_30_SJA1105PQRS_VAR_NOINIT
#define ETHSWT_30_SJA1105PQRS_VAR_ZERO_INIT
#define ETHSWT_30_SJA1105PQRS_VAR_INIT_FAST
#define ETHSWT_30_SJA1105PQRS_VAR_NOINIT_FAST
#define ETHSWT_30_SJA1105PQRS_VAR_ZERO_INIT_FAST

#define ETHSWT_30_SJA1105PQRS_VAR_INIT_NOCACHE
#define ETHSWT_30_SJA1105PQRS_VAR_NOINIT_NOCACHE
#define ETHSWT_30_SJA1105PQRS_VAR_ZERO_INIT_NOCACHE

#define ETHSWT_30_SJA1105PQRS_APPL_DATA
#define ETHSWT_30_SJA1105PQRS_APPL_VAR
#define ETHSWT_30_SJA1105PQRS_APPL_CONST


/**********************************************************************************************************************
 *  ETHSWT END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  ETHSWT_30_SJA1110ABCD START
 *********************************************************************************************************************/

#define ETHSWT_30_SJA1110ABCD_CODE
#define ETHSWT_30_SJA1110ABCD_CODE_FAST
#define ETHSWT_30_SJA1110ABCD_CODE_ISR

#define ETHSWT_30_SJA1110ABCD_CONST
#define ETHSWT_30_SJA1110ABCD_CONST_FAST
#define ETHSWT_30_SJA1110ABCD_PBCFG

#define ETHSWT_30_SJA1110ABCD_VAR_INIT
#define ETHSWT_30_SJA1110ABCD_VAR_NOINIT
#define ETHSWT_30_SJA1110ABCD_VAR_ZERO_INIT
#define ETHSWT_30_SJA1110ABCD_VAR_INIT_FAST
#define ETHSWT_30_SJA1110ABCD_VAR_NOINIT_FAST
#define ETHSWT_30_SJA1110ABCD_VAR_ZERO_INIT_FAST

#define ETHSWT_30_SJA1110ABCD_VAR_INIT_NOCACHE
#define ETHSWT_30_SJA1110ABCD_VAR_NOINIT_NOCACHE
#define ETHSWT_30_SJA1110ABCD_VAR_ZERO_INIT_NOCACHE

#define ETHSWT_30_SJA1110ABCD_APPL_VAR
#define ETHSWT_30_SJA1110ABCD_APPL_CONST

/**********************************************************************************************************************
 *  ETHSWT_30_SJA1110ABCD END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETH_30_AR7000 START 
 *********************************************************************************************************************/
 
#define ETH_30_AR7000_CODE
#define ETH_30_AR7000_CODE_ISR

#define ETH_30_AR7000_CONST
#define ETH_30_AR7000_APPL_CONST
#define ETH_30_AR7000_APPL_VAR
#define ETH_30_AR7000_APPL_DATA

#define ETH_30_AR7000_VAR_NOINIT
#define ETH_30_AR7000_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETH_30_AR7000 END 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETH_30_MSE102X START 
 *********************************************************************************************************************/

#define ETH_30_MSE102X_CODE
#define ETH_30_MSE102X_CODE_ISR

#define ETH_30_MSE102X_CONST
#define ETH_30_MSE102X_APPL_CONST
#define ETH_30_MSE102X_PBCFG
#define ETH_30_MSE102X_APPL_DATA
#define ETH_30_MSE102X_APPL_VAR

#define ETH_30_MSE102X_APPL_CODE

#define ETH_30_MSE102X_VAR_NOINIT
#define ETH_30_MSE102X_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETH_30_MSE102X END
 *********************************************************************************************************************/


/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**        \file  Lin_Compiler_Cfg.inc
 *        \brief  AUTOSAR LIN Driver
 *
 *      \details  AUTOSAR LIN Driver for all target systems
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  LIN DRIVER START
 **********************************************************************************************************************/

#define LIN_30_SJA1124SPI_CODE
#define LIN_30_SJA1124SPI_CODE_FAST
#define LIN_30_SJA1124SPI_CODE_ISR
#define LIN_30_SJA1124SPI_APPL_CODE

#define LIN_30_SJA1124SPI_CONST
#define LIN_30_SJA1124SPI_CONST_FAST
#define LIN_30_SJA1124SPI_PBCFG

#define LIN_30_SJA1124SPI_VAR_PBCFG
#define LIN_30_SJA1124SPI_VAR_INIT
#define LIN_30_SJA1124SPI_VAR_NOINIT
#define LIN_30_SJA1124SPI_VAR_ZERO_INIT
#define LIN_30_SJA1124SPI_VAR_INIT_FAST
#define LIN_30_SJA1124SPI_VAR_NOINIT_FAST
#define LIN_30_SJA1124SPI_VAR_ZERO_INIT_FAST

#define LIN_30_SJA1124SPI_VAR_INIT_NOCACHE
#define LIN_30_SJA1124SPI_VAR_NOINIT_NOCACHE
#define LIN_30_SJA1124SPI_VAR_ZERO_INIT_NOCACHE

#define LIN_30_SJA1124SPI_APPL_VAR
#define LIN_30_SJA1124SPI_VAR_REGS

/***********************************************************************************************************************
 *  LIN DRIVER END
 **********************************************************************************************************************/




/***********************************************************************************************************************
 *  VMEM_30_XXHYPER01 START
 **********************************************************************************************************************/

#define VMEM_30_XXHYPER01_CODE
#define VMEM_30_XXHYPER01_CONST
#define VMEM_30_XXHYPER01_VAR
#define VMEM_30_XXHYPER01_VAR_NOINIT
#define VMEM_30_XXHYPER01_VAR_ZERO_INIT
#define VMEM_30_XXHYPER01_APPL_VAR
#define VMEM_30_XXHYPER01_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_XXHYPER01 END
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VMEM_30_XXSPI01 START
 **********************************************************************************************************************/

#define VMEM_30_XXSPI01_CODE
#define VMEM_30_XXSPI01_VAR
#define VMEM_30_XXSPI01_CONST
#define VMEM_30_XXSPI01_APPL_VAR
#define VMEM_30_XXSPI01_APPL_CONST
#define VMEM_30_XXSPI01_VAR_ZERO_INIT
#define VMEM_30_XXSPI01_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_XXSPI01 END
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  VMEM_30_XXSPI02 START
 **********************************************************************************************************************/

#define VMEM_30_XXSPI02_CODE
#define VMEM_30_XXSPI02_CONST
#define VMEM_30_XXSPI02_APPL_VAR
#define VMEM_30_XXSPI02_APPL_CONST
#define VMEM_30_XXSPI02_VAR
#define VMEM_30_XXSPI02_VAR_ZERO_INIT
#define VMEM_30_XXSPI02_VAR_NOINIT
#define VMEM_30_XXSPI02_PBCFG

/***********************************************************************************************************************
 *  VMEM_30_XXSPI02 END
 **********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_FS26_CODE
#define SBC_30_FS26_CODE_FAST
#define SBC_30_FS26_CODE_ISR

#define SBC_30_FS26_CONST
#define SBC_30_FS26_CONST_FAST
#define SBC_30_FS26_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_FS26_PBCFG_ROOT

#define SBC_30_FS26_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_FS26_VAR_INIT
#define SBC_30_FS26_VAR_NOINIT
#define SBC_30_FS26_VAR_ZERO_INIT
#define SBC_30_FS26_VAR_INIT_FAST
#define SBC_30_FS26_VAR_NOINIT_FAST
#define SBC_30_FS26_VAR_ZERO_INIT_FAST

#define SBC_30_FS26_VAR_INIT_NOCACHE
#define SBC_30_FS26_VAR_NOINIT_NOCACHE
#define SBC_30_FS26_VAR_ZERO_INIT_NOCACHE

#define SBC_30_FS26_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_FS6500_CODE
#define SBC_30_FS6500_CODE_FAST
#define SBC_30_FS6500_CODE_ISR

#define SBC_30_FS6500_CONST
#define SBC_30_FS6500_CONST_FAST
#define SBC_30_FS6500_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_FS6500_PBCFG_ROOT

#define SBC_30_FS6500_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_FS6500_VAR_INIT
#define SBC_30_FS6500_VAR_NOINIT
#define SBC_30_FS6500_VAR_ZERO_INIT
#define SBC_30_FS6500_VAR_INIT_FAST
#define SBC_30_FS6500_VAR_NOINIT_FAST
#define SBC_30_FS6500_VAR_ZERO_INIT_FAST

#define SBC_30_FS6500_VAR_INIT_NOCACHE
#define SBC_30_FS6500_VAR_NOINIT_NOCACHE
#define SBC_30_FS6500_VAR_ZERO_INIT_NOCACHE

#define SBC_30_FS6500_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_FS85_CODE
#define SBC_30_FS85_CODE_FAST
#define SBC_30_FS85_CODE_ISR

#define SBC_30_FS85_CONST
#define SBC_30_FS85_CONST_FAST
#define SBC_30_FS85_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_FS85_PBCFG_ROOT

#define SBC_30_FS85_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_FS85_VAR_INIT
#define SBC_30_FS85_VAR_NOINIT
#define SBC_30_FS85_VAR_ZERO_INIT
#define SBC_30_FS85_VAR_INIT_FAST
#define SBC_30_FS85_VAR_NOINIT_FAST
#define SBC_30_FS85_VAR_ZERO_INIT_FAST

#define SBC_30_FS85_VAR_INIT_NOCACHE
#define SBC_30_FS85_VAR_NOINIT_NOCACHE
#define SBC_30_FS85_VAR_ZERO_INIT_NOCACHE

#define SBC_30_FS85_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_GENERIC_CODE
#define SBC_30_GENERIC_CODE_FAST
#define SBC_30_GENERIC_CODE_ISR

#define SBC_30_GENERIC_CONST
#define SBC_30_GENERIC_CONST_FAST
#define SBC_30_GENERIC_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_GENERIC_PBCFG_ROOT

#define SBC_30_GENERIC_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_GENERIC_VAR_INIT
#define SBC_30_GENERIC_VAR_NOINIT
#define SBC_30_GENERIC_VAR_ZERO_INIT
#define SBC_30_GENERIC_VAR_INIT_FAST
#define SBC_30_GENERIC_VAR_NOINIT_FAST
#define SBC_30_GENERIC_VAR_ZERO_INIT_FAST

#define SBC_30_GENERIC_VAR_INIT_NOCACHE
#define SBC_30_GENERIC_VAR_NOINIT_NOCACHE
#define SBC_30_GENERIC_VAR_ZERO_INIT_NOCACHE

#define SBC_30_GENERIC_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_L9396_CODE
#define SBC_30_L9396_CODE_FAST
#define SBC_30_L9396_CODE_ISR

#define SBC_30_L9396_CONST
#define SBC_30_L9396_CONST_FAST
#define SBC_30_L9396_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_L9396_PBCFG_ROOT

#define SBC_30_L9396_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_L9396_VAR_INIT
#define SBC_30_L9396_VAR_NOINIT
#define SBC_30_L9396_VAR_ZERO_INIT
#define SBC_30_L9396_VAR_INIT_FAST
#define SBC_30_L9396_VAR_NOINIT_FAST
#define SBC_30_L9396_VAR_ZERO_INIT_FAST

#define SBC_30_L9396_VAR_INIT_NOCACHE
#define SBC_30_L9396_VAR_NOINIT_NOCACHE
#define SBC_30_L9396_VAR_ZERO_INIT_NOCACHE

#define SBC_30_L9396_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_L99PM62_CODE
#define SBC_30_L99PM62_CODE_FAST
#define SBC_30_L99PM62_CODE_ISR

#define SBC_30_L99PM62_CONST
#define SBC_30_L99PM62_CONST_FAST
#define SBC_30_L99PM62_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_L99PM62_PBCFG_ROOT

#define SBC_30_L99PM62_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_L99PM62_VAR_INIT
#define SBC_30_L99PM62_VAR_NOINIT
#define SBC_30_L99PM62_VAR_ZERO_INIT
#define SBC_30_L99PM62_VAR_INIT_FAST
#define SBC_30_L99PM62_VAR_NOINIT_FAST
#define SBC_30_L99PM62_VAR_ZERO_INIT_FAST

#define SBC_30_L99PM62_VAR_INIT_NOCACHE
#define SBC_30_L99PM62_VAR_NOINIT_NOCACHE
#define SBC_30_L99PM62_VAR_ZERO_INIT_NOCACHE

#define SBC_30_L99PM62_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_LP8774_CODE
#define SBC_30_LP8774_CODE_FAST
#define SBC_30_LP8774_CODE_ISR

#define SBC_30_LP8774_CONST
#define SBC_30_LP8774_CONST_FAST
#define SBC_30_LP8774_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_LP8774_PBCFG_ROOT

#define SBC_30_LP8774_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_LP8774_VAR_INIT
#define SBC_30_LP8774_VAR_NOINIT
#define SBC_30_LP8774_VAR_ZERO_INIT
#define SBC_30_LP8774_VAR_INIT_FAST
#define SBC_30_LP8774_VAR_NOINIT_FAST
#define SBC_30_LP8774_VAR_ZERO_INIT_FAST

#define SBC_30_LP8774_VAR_INIT_NOCACHE
#define SBC_30_LP8774_VAR_NOINIT_NOCACHE
#define SBC_30_LP8774_VAR_ZERO_INIT_NOCACHE

#define SBC_30_LP8774_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_MC33905_CODE
#define SBC_30_MC33905_CODE_FAST
#define SBC_30_MC33905_CODE_ISR

#define SBC_30_MC33905_CONST
#define SBC_30_MC33905_CONST_FAST
#define SBC_30_MC33905_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_MC33905_PBCFG_ROOT

#define SBC_30_MC33905_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_MC33905_VAR_INIT
#define SBC_30_MC33905_VAR_NOINIT
#define SBC_30_MC33905_VAR_ZERO_INIT
#define SBC_30_MC33905_VAR_INIT_FAST
#define SBC_30_MC33905_VAR_NOINIT_FAST
#define SBC_30_MC33905_VAR_ZERO_INIT_FAST

#define SBC_30_MC33905_VAR_INIT_NOCACHE
#define SBC_30_MC33905_VAR_NOINIT_NOCACHE
#define SBC_30_MC33905_VAR_ZERO_INIT_NOCACHE

#define SBC_30_MC33905_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_MC33908_CODE
#define SBC_30_MC33908_CODE_FAST
#define SBC_30_MC33908_CODE_ISR

#define SBC_30_MC33908_CONST
#define SBC_30_MC33908_CONST_FAST
#define SBC_30_MC33908_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_MC33908_PBCFG_ROOT

#define SBC_30_MC33908_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_MC33908_VAR_INIT
#define SBC_30_MC33908_VAR_NOINIT
#define SBC_30_MC33908_VAR_ZERO_INIT
#define SBC_30_MC33908_VAR_INIT_FAST
#define SBC_30_MC33908_VAR_NOINIT_FAST
#define SBC_30_MC33908_VAR_ZERO_INIT_FAST

#define SBC_30_MC33908_VAR_INIT_NOCACHE
#define SBC_30_MC33908_VAR_NOINIT_NOCACHE
#define SBC_30_MC33908_VAR_ZERO_INIT_NOCACHE

#define SBC_30_MC33908_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TCAN114X_CODE
#define SBC_30_TCAN114X_CODE_FAST
#define SBC_30_TCAN114X_CODE_ISR

#define SBC_30_TCAN114X_CONST
#define SBC_30_TCAN114X_CONST_FAST
#define SBC_30_TCAN114X_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TCAN114X_PBCFG_ROOT

#define SBC_30_TCAN114X_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TCAN114X_VAR_INIT
#define SBC_30_TCAN114X_VAR_NOINIT
#define SBC_30_TCAN114X_VAR_ZERO_INIT
#define SBC_30_TCAN114X_VAR_INIT_FAST
#define SBC_30_TCAN114X_VAR_NOINIT_FAST
#define SBC_30_TCAN114X_VAR_ZERO_INIT_FAST

#define SBC_30_TCAN114X_VAR_INIT_NOCACHE
#define SBC_30_TCAN114X_VAR_NOINIT_NOCACHE
#define SBC_30_TCAN114X_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TCAN114X_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TCAN1167_CODE
#define SBC_30_TCAN1167_CODE_FAST
#define SBC_30_TCAN1167_CODE_ISR

#define SBC_30_TCAN1167_CONST
#define SBC_30_TCAN1167_CONST_FAST
#define SBC_30_TCAN1167_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TCAN1167_PBCFG_ROOT

#define SBC_30_TCAN1167_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TCAN1167_VAR_INIT
#define SBC_30_TCAN1167_VAR_NOINIT
#define SBC_30_TCAN1167_VAR_ZERO_INIT
#define SBC_30_TCAN1167_VAR_INIT_FAST
#define SBC_30_TCAN1167_VAR_NOINIT_FAST
#define SBC_30_TCAN1167_VAR_ZERO_INIT_FAST

#define SBC_30_TCAN1167_VAR_INIT_NOCACHE
#define SBC_30_TCAN1167_VAR_NOINIT_NOCACHE
#define SBC_30_TCAN1167_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TCAN1167_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TLE9263_CODE
#define SBC_30_TLE9263_CODE_FAST
#define SBC_30_TLE9263_CODE_ISR

#define SBC_30_TLE9263_CONST
#define SBC_30_TLE9263_CONST_FAST
#define SBC_30_TLE9263_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TLE9263_PBCFG_ROOT

#define SBC_30_TLE9263_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TLE9263_VAR_INIT
#define SBC_30_TLE9263_VAR_NOINIT
#define SBC_30_TLE9263_VAR_ZERO_INIT
#define SBC_30_TLE9263_VAR_INIT_FAST
#define SBC_30_TLE9263_VAR_NOINIT_FAST
#define SBC_30_TLE9263_VAR_ZERO_INIT_FAST

#define SBC_30_TLE9263_VAR_INIT_NOCACHE
#define SBC_30_TLE9263_VAR_NOINIT_NOCACHE
#define SBC_30_TLE9263_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLE9263_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TLE9273_CODE
#define SBC_30_TLE9273_CODE_FAST
#define SBC_30_TLE9273_CODE_ISR

#define SBC_30_TLE9273_CONST
#define SBC_30_TLE9273_CONST_FAST
#define SBC_30_TLE9273_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TLE9273_PBCFG_ROOT

#define SBC_30_TLE9273_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TLE9273_VAR_INIT
#define SBC_30_TLE9273_VAR_NOINIT
#define SBC_30_TLE9273_VAR_ZERO_INIT
#define SBC_30_TLE9273_VAR_INIT_FAST
#define SBC_30_TLE9273_VAR_NOINIT_FAST
#define SBC_30_TLE9273_VAR_ZERO_INIT_FAST

#define SBC_30_TLE9273_VAR_INIT_NOCACHE
#define SBC_30_TLE9273_VAR_NOINIT_NOCACHE
#define SBC_30_TLE9273_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLE9273_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TLE9278_CODE
#define SBC_30_TLE9278_CODE_FAST
#define SBC_30_TLE9278_CODE_ISR

#define SBC_30_TLE9278_CONST
#define SBC_30_TLE9278_CONST_FAST
#define SBC_30_TLE9278_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TLE9278_PBCFG_ROOT

#define SBC_30_TLE9278_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TLE9278_VAR_INIT
#define SBC_30_TLE9278_VAR_NOINIT
#define SBC_30_TLE9278_VAR_ZERO_INIT
#define SBC_30_TLE9278_VAR_INIT_FAST
#define SBC_30_TLE9278_VAR_NOINIT_FAST
#define SBC_30_TLE9278_VAR_ZERO_INIT_FAST

#define SBC_30_TLE9278_VAR_INIT_NOCACHE
#define SBC_30_TLE9278_VAR_NOINIT_NOCACHE
#define SBC_30_TLE9278_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLE9278_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TLF3068X_CODE
#define SBC_30_TLF3068X_CODE_FAST
#define SBC_30_TLF3068X_CODE_ISR

#define SBC_30_TLF3068X_CONST
#define SBC_30_TLF3068X_CONST_FAST
#define SBC_30_TLF3068X_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TLF3068X_PBCFG_ROOT

#define SBC_30_TLF3068X_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TLF3068X_VAR_INIT
#define SBC_30_TLF3068X_VAR_NOINIT
#define SBC_30_TLF3068X_VAR_ZERO_INIT
#define SBC_30_TLF3068X_VAR_INIT_FAST
#define SBC_30_TLF3068X_VAR_NOINIT_FAST
#define SBC_30_TLF3068X_VAR_ZERO_INIT_FAST

#define SBC_30_TLF3068X_VAR_INIT_NOCACHE
#define SBC_30_TLF3068X_VAR_NOINIT_NOCACHE
#define SBC_30_TLF3068X_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLF3068X_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TLF35584_CODE
#define SBC_30_TLF35584_CODE_FAST
#define SBC_30_TLF35584_CODE_ISR

#define SBC_30_TLF35584_CONST
#define SBC_30_TLF35584_CONST_FAST
#define SBC_30_TLF35584_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TLF35584_PBCFG_ROOT

#define SBC_30_TLF35584_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TLF35584_VAR_INIT
#define SBC_30_TLF35584_VAR_NOINIT
#define SBC_30_TLF35584_VAR_ZERO_INIT
#define SBC_30_TLF35584_VAR_INIT_FAST
#define SBC_30_TLF35584_VAR_NOINIT_FAST
#define SBC_30_TLF35584_VAR_ZERO_INIT_FAST

#define SBC_30_TLF35584_VAR_INIT_NOCACHE
#define SBC_30_TLF35584_VAR_NOINIT_NOCACHE
#define SBC_30_TLF35584_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TLF35584_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_TPS653850_CODE
#define SBC_30_TPS653850_CODE_FAST
#define SBC_30_TPS653850_CODE_ISR

#define SBC_30_TPS653850_CONST
#define SBC_30_TPS653850_CONST_FAST
#define SBC_30_TPS653850_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_TPS653850_PBCFG_ROOT

#define SBC_30_TPS653850_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_TPS653850_VAR_INIT
#define SBC_30_TPS653850_VAR_NOINIT
#define SBC_30_TPS653850_VAR_ZERO_INIT
#define SBC_30_TPS653850_VAR_INIT_FAST
#define SBC_30_TPS653850_VAR_NOINIT_FAST
#define SBC_30_TPS653850_VAR_ZERO_INIT_FAST

#define SBC_30_TPS653850_VAR_INIT_NOCACHE
#define SBC_30_TPS653850_VAR_NOINIT_NOCACHE
#define SBC_30_TPS653850_VAR_ZERO_INIT_NOCACHE

#define SBC_30_TPS653850_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_UJA1078_CODE
#define SBC_30_UJA1078_CODE_FAST
#define SBC_30_UJA1078_CODE_ISR

#define SBC_30_UJA1078_CONST
#define SBC_30_UJA1078_CONST_FAST
#define SBC_30_UJA1078_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_UJA1078_PBCFG_ROOT

#define SBC_30_UJA1078_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_UJA1078_VAR_INIT
#define SBC_30_UJA1078_VAR_NOINIT
#define SBC_30_UJA1078_VAR_ZERO_INIT
#define SBC_30_UJA1078_VAR_INIT_FAST
#define SBC_30_UJA1078_VAR_NOINIT_FAST
#define SBC_30_UJA1078_VAR_ZERO_INIT_FAST

#define SBC_30_UJA1078_VAR_INIT_NOCACHE
#define SBC_30_UJA1078_VAR_NOINIT_NOCACHE
#define SBC_30_UJA1078_VAR_ZERO_INIT_NOCACHE

#define SBC_30_UJA1078_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  SBC START
 *********************************************************************************************************************/

#define SBC_30_UJA1168_CODE
#define SBC_30_UJA1168_CODE_FAST
#define SBC_30_UJA1168_CODE_ISR

#define SBC_30_UJA1168_CONST
#define SBC_30_UJA1168_CONST_FAST
#define SBC_30_UJA1168_PBCFG

/* NOTE: Use the next keyword for the PBCFG-root-struct only in case of a ASR3.x till ASR4.0.1 implementation.
   In case of a ASR4.0.3 (CFG5) implementation use for the PBCFG-root-struct the keyword SBC_PBCFG as well and remove the following keyword from this template. */
#define SBC_30_UJA1168_PBCFG_ROOT

#define SBC_30_UJA1168_VAR_PBCFG /* ESCAN00065502 */

#define SBC_30_UJA1168_VAR_INIT
#define SBC_30_UJA1168_VAR_NOINIT
#define SBC_30_UJA1168_VAR_ZERO_INIT
#define SBC_30_UJA1168_VAR_INIT_FAST
#define SBC_30_UJA1168_VAR_NOINIT_FAST
#define SBC_30_UJA1168_VAR_ZERO_INIT_FAST

#define SBC_30_UJA1168_VAR_INIT_NOCACHE
#define SBC_30_UJA1168_VAR_NOINIT_NOCACHE
#define SBC_30_UJA1168_VAR_ZERO_INIT_NOCACHE

#define SBC_30_UJA1168_APPL_DATA

/**********************************************************************************************************************
 *  SBC END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_88Q1010 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_88Q1010_CODE
#define ETHTRCV_30_88Q1010_CODE_INLINE
#define ETHTRCV_30_88Q1010_CODE_FAST
#define ETHTRCV_30_88Q1010_CODE_ISR

#define ETHTRCV_30_88Q1010_CONST
#define ETHTRCV_30_88Q1010_CONST_FAST
#define ETHTRCV_30_88Q1010_PBCFG


#define ETHTRCV_30_88Q1010_PBCFG_ROOT

#define ETHTRCV_30_88Q1010_VAR_PBCFG

#define ETHTRCV_30_88Q1010_APPL_VAR
#define ETHTRCV_30_88Q1010_APPL_CONST
#define ETHTRCV_30_88Q1010_APPL_CODE
#define ETHTRCV_30_88Q1010_APPL_DATA
#define ETHTRCV_30_88Q1010_VAR_NOINIT
#define ETHTRCV_30_88Q1010_VAR_ZERO_INIT
#define ETHTRCV_30_88Q1010_VAR_INIT_FAST
#define ETHTRCV_30_88Q1010_VAR_NOINIT_FAST
#define ETHTRCV_30_88Q1010_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_88Q1010_VAR_INIT_NOCACHE
#define ETHTRCV_30_88Q1010_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_88Q1010_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q1010 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_88Q2112 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_88Q2112_CODE
#define ETHTRCV_30_88Q2112_CODE_INLINE
#define ETHTRCV_30_88Q2112_CODE_FAST
#define ETHTRCV_30_88Q2112_CODE_ISR

#define ETHTRCV_30_88Q2112_CONST
#define ETHTRCV_30_88Q2112_CONST_FAST
#define ETHTRCV_30_88Q2112_PBCFG


#define ETHTRCV_30_88Q2112_PBCFG_ROOT

#define ETHTRCV_30_88Q2112_VAR_PBCFG

#define ETHTRCV_30_88Q2112_APPL_VAR
#define ETHTRCV_30_88Q2112_APPL_CONST
#define ETHTRCV_30_88Q2112_APPL_CODE
#define ETHTRCV_30_88Q2112_APPL_DATA
#define ETHTRCV_30_88Q2112_VAR_NOINIT
#define ETHTRCV_30_88Q2112_VAR_ZERO_INIT
#define ETHTRCV_30_88Q2112_VAR_INIT_FAST
#define ETHTRCV_30_88Q2112_VAR_NOINIT_FAST
#define ETHTRCV_30_88Q2112_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_88Q2112_VAR_INIT_NOCACHE
#define ETHTRCV_30_88Q2112_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_88Q2112_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_88Q2112 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_AR7000_CODE

#define ETHTRCV_30_AR7000_CONST

#define ETHTRCV_30_AR7000_APPL_CONST
#define ETHTRCV_30_AR7000_APPL_DATA
#define ETHTRCV_30_AR7000_APPL_VAR

#define ETHTRCV_30_AR7000_VAR_NOINIT
#define ETHTRCV_30_AR7000_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  ETHTRCV_30_AR7000 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89810 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_BCM89810_CODE
#define ETHTRCV_30_BCM89810_CODE_INLINE
#define ETHTRCV_30_BCM89810_CODE_FAST
#define ETHTRCV_30_BCM89810_CODE_ISR

#define ETHTRCV_30_BCM89810_CONST
#define ETHTRCV_30_BCM89810_CONST_FAST
#define ETHTRCV_30_BCM89810_PBCFG


#define ETHTRCV_30_BCM89810_PBCFG_ROOT

#define ETHTRCV_30_BCM89810_VAR_PBCFG

#define ETHTRCV_30_BCM89810_APPL_VAR
#define ETHTRCV_30_BCM89810_APPL_CONST
#define ETHTRCV_30_BCM89810_APPL_CODE
#define ETHTRCV_30_BCM89810_APPL_DATA
#define ETHTRCV_30_BCM89810_VAR_NOINIT
#define ETHTRCV_30_BCM89810_VAR_ZERO_INIT
#define ETHTRCV_30_BCM89810_VAR_INIT_FAST
#define ETHTRCV_30_BCM89810_VAR_NOINIT_FAST
#define ETHTRCV_30_BCM89810_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_BCM89810_VAR_INIT_NOCACHE
#define ETHTRCV_30_BCM89810_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_BCM89810_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89810 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89811 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_BCM89811_CODE
#define ETHTRCV_30_BCM89811_CODE_INLINE
#define ETHTRCV_30_BCM89811_CODE_FAST
#define ETHTRCV_30_BCM89811_CODE_ISR

#define ETHTRCV_30_BCM89811_CONST
#define ETHTRCV_30_BCM89811_CONST_FAST
#define ETHTRCV_30_BCM89811_PBCFG


#define ETHTRCV_30_BCM89811_PBCFG_ROOT

#define ETHTRCV_30_BCM89811_VAR_PBCFG

#define ETHTRCV_30_BCM89811_APPL_VAR
#define ETHTRCV_30_BCM89811_APPL_CONST
#define ETHTRCV_30_BCM89811_APPL_CODE
#define ETHTRCV_30_BCM89811_APPL_DATA
#define ETHTRCV_30_BCM89811_VAR_NOINIT
#define ETHTRCV_30_BCM89811_VAR_ZERO_INIT
#define ETHTRCV_30_BCM89811_VAR_INIT_FAST
#define ETHTRCV_30_BCM89811_VAR_NOINIT_FAST
#define ETHTRCV_30_BCM89811_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_BCM89811_VAR_INIT_NOCACHE
#define ETHTRCV_30_BCM89811_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_BCM89811_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM89811 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_BCM8988X START 
 *********************************************************************************************************************/

#define ETHTRCV_30_BCM8988X_CODE
#define ETHTRCV_30_BCM8988X_CODE_INLINE
#define ETHTRCV_30_BCM8988X_CODE_FAST
#define ETHTRCV_30_BCM8988X_CODE_ISR

#define ETHTRCV_30_BCM8988X_CONST
#define ETHTRCV_30_BCM8988X_CONST_FAST
#define ETHTRCV_30_BCM8988X_PBCFG


#define ETHTRCV_30_BCM8988X_PBCFG_ROOT

#define ETHTRCV_30_BCM8988X_VAR_PBCFG

#define ETHTRCV_30_BCM8988X_APPL_VAR
#define ETHTRCV_30_BCM8988X_APPL_CONST
#define ETHTRCV_30_BCM8988X_APPL_CODE
#define ETHTRCV_30_BCM8988X_APPL_DATA
#define ETHTRCV_30_BCM8988X_VAR_NOINIT
#define ETHTRCV_30_BCM8988X_VAR_ZERO_INIT
#define ETHTRCV_30_BCM8988X_VAR_INIT_FAST
#define ETHTRCV_30_BCM8988X_VAR_NOINIT_FAST
#define ETHTRCV_30_BCM8988X_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_BCM8988X_VAR_INIT_NOCACHE
#define ETHTRCV_30_BCM8988X_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_BCM8988X_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_BCM8988X END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TC811 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_DP83TC811_CODE
#define ETHTRCV_30_DP83TC811_CODE_INLINE
#define ETHTRCV_30_DP83TC811_CODE_FAST
#define ETHTRCV_30_DP83TC811_CODE_ISR

#define ETHTRCV_30_DP83TC811_CONST
#define ETHTRCV_30_DP83TC811_CONST_FAST
#define ETHTRCV_30_DP83TC811_PBCFG


#define ETHTRCV_30_DP83TC811_PBCFG_ROOT

#define ETHTRCV_30_DP83TC811_VAR_PBCFG

#define ETHTRCV_30_DP83TC811_APPL_VAR
#define ETHTRCV_30_DP83TC811_APPL_CONST
#define ETHTRCV_30_DP83TC811_APPL_CODE
#define ETHTRCV_30_DP83TC811_APPL_DATA
#define ETHTRCV_30_DP83TC811_VAR_NOINIT
#define ETHTRCV_30_DP83TC811_VAR_ZERO_INIT
#define ETHTRCV_30_DP83TC811_VAR_INIT_FAST
#define ETHTRCV_30_DP83TC811_VAR_NOINIT_FAST
#define ETHTRCV_30_DP83TC811_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_DP83TC811_VAR_INIT_NOCACHE
#define ETHTRCV_30_DP83TC811_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_DP83TC811_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TC811 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TG720 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_DP83TG720_CODE
#define ETHTRCV_30_DP83TG720_CODE_INLINE
#define ETHTRCV_30_DP83TG720_CODE_FAST
#define ETHTRCV_30_DP83TG720_CODE_ISR

#define ETHTRCV_30_DP83TG720_CONST
#define ETHTRCV_30_DP83TG720_CONST_FAST
#define ETHTRCV_30_DP83TG720_PBCFG


#define ETHTRCV_30_DP83TG720_PBCFG_ROOT

#define ETHTRCV_30_DP83TG720_VAR_PBCFG

#define ETHTRCV_30_DP83TG720_APPL_VAR
#define ETHTRCV_30_DP83TG720_APPL_CONST
#define ETHTRCV_30_DP83TG720_APPL_CODE
#define ETHTRCV_30_DP83TG720_APPL_DATA
#define ETHTRCV_30_DP83TG720_VAR_NOINIT
#define ETHTRCV_30_DP83TG720_VAR_ZERO_INIT
#define ETHTRCV_30_DP83TG720_VAR_INIT_FAST
#define ETHTRCV_30_DP83TG720_VAR_NOINIT_FAST
#define ETHTRCV_30_DP83TG720_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_DP83TG720_VAR_INIT_NOCACHE
#define ETHTRCV_30_DP83TG720_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_DP83TG720_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_DP83TG720 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_E52013 START 
 *********************************************************************************************************************/

#define CANTRCV_30_E52013_CODE /* PRQA S 0883 */ /* Appears only while testing */
#define CANTRCV_30_E52013_CODE_FAST
#define CANTRCV_30_E52013_CODE_ISR

#define CANTRCV_30_E52013_CONST
#define CANTRCV_30_E52013_CONST_FAST
#define CANTRCV_30_E52013_PBCFG

#define CANTRCV_30_E52013_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_E52013_VAR_INIT
#define CANTRCV_30_E52013_VAR_NOINIT
#define CANTRCV_30_E52013_APPL_VAR
#define CANTRCV_30_E52013_APPL_CODE
#define CANTRCV_30_E52013_VAR_ZERO_INIT
#define CANTRCV_30_E52013_VAR_INIT_FAST
#define CANTRCV_30_E52013_VAR_NOINIT_FAST
#define CANTRCV_30_E52013_VAR_ZERO_INIT_FAST

#define CANTRCV_30_E52013_VAR_INIT_NOCACHE
#define CANTRCV_30_E52013_VAR_NOINIT_NOCACHE
#define CANTRCV_30_E52013_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_E52013 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_ETHMII START 
 *********************************************************************************************************************/

#define ETHTRCV_30_ETHMII_CODE
#define ETHTRCV_30_ETHMII_CODE_INLINE
#define ETHTRCV_30_ETHMII_CODE_FAST
#define ETHTRCV_30_ETHMII_CODE_ISR

#define ETHTRCV_30_ETHMII_CONST
#define ETHTRCV_30_ETHMII_CONST_FAST
#define ETHTRCV_30_ETHMII_PBCFG


#define ETHTRCV_30_ETHMII_PBCFG_ROOT

#define ETHTRCV_30_ETHMII_VAR_PBCFG

#define ETHTRCV_30_ETHMII_APPL_VAR
#define ETHTRCV_30_ETHMII_APPL_CONST
#define ETHTRCV_30_ETHMII_APPL_CODE
#define ETHTRCV_30_ETHMII_APPL_DATA
#define ETHTRCV_30_ETHMII_VAR_NOINIT
#define ETHTRCV_30_ETHMII_VAR_ZERO_INIT
#define ETHTRCV_30_ETHMII_VAR_INIT_FAST
#define ETHTRCV_30_ETHMII_VAR_NOINIT_FAST
#define ETHTRCV_30_ETHMII_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_ETHMII_VAR_INIT_NOCACHE
#define ETHTRCV_30_ETHMII_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_ETHMII_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_ETHMII END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN START 
 *********************************************************************************************************************/

#define CANTRCV_30_GENERICCAN_CODE
#define CANTRCV_30_GENERICCAN_CODE_FAST
#define CANTRCV_30_GENERICCAN_CODE_ISR

#define CANTRCV_30_GENERICCAN_CONST
#define CANTRCV_30_GENERICCAN_CONST_FAST
#define CANTRCV_30_GENERICCAN_PBCFG

#define CANTRCV_30_GENERICCAN_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_GENERICCAN_VAR_INIT
#define CANTRCV_30_GENERICCAN_VAR_NOINIT
#define CANTRCV_30_GENERICCAN_APPL_VAR
#define CANTRCV_30_GENERICCAN_APPL_CODE
#define CANTRCV_30_GENERICCAN_VAR_ZERO_INIT
#define CANTRCV_30_GENERICCAN_VAR_INIT_FAST
#define CANTRCV_30_GENERICCAN_VAR_NOINIT_FAST
#define CANTRCV_30_GENERICCAN_VAR_ZERO_INIT_FAST

#define CANTRCV_30_GENERICCAN_VAR_INIT_NOCACHE
#define CANTRCV_30_GENERICCAN_VAR_NOINIT_NOCACHE
#define CANTRCV_30_GENERICCAN_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_GENERICCAN END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */



/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

#define FRTRCV_CONST
#define FRTRCV_30___YOUR_TRCV___CONST
#define FRTRCV_30___YOUR_TRCV___VAR_NOINIT
#define FRTRCV_30___YOUR_TRCV___CODE
#define FRTRCV_30___YOUR_TRCV___APPL_DATA
#define FRTRCV_30___YOUR_TRCV___APPL_CODE

/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LIN TRANSCEIVER GENERIC DRIVER START
 *********************************************************************************************************************/

#define LINTRCV_30_GENERIC_CODE

#define LINTRCV_30_GENERIC_CONST
#define LINTRCV_30_GENERIC_PBCFG

#define LINTRCV_30_GENERIC_VAR_NOINIT
#define LINTRCV_30_GENERIC_VAR_ZERO_INIT

#define LINTRCV_30_GENERIC_APPL_VAR
#define LINTRCV_30_GENERIC_APPL_CODE
/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER GENERIC DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_KD10XX START 
 *********************************************************************************************************************/

#define ETHTRCV_30_KD10XX_CODE
#define ETHTRCV_30_KD10XX_CODE_INLINE
#define ETHTRCV_30_KD10XX_CODE_FAST
#define ETHTRCV_30_KD10XX_CODE_ISR

#define ETHTRCV_30_KD10XX_CONST
#define ETHTRCV_30_KD10XX_CONST_FAST
#define ETHTRCV_30_KD10XX_PBCFG


#define ETHTRCV_30_KD10XX_PBCFG_ROOT

#define ETHTRCV_30_KD10XX_VAR_PBCFG

#define ETHTRCV_30_KD10XX_APPL_VAR
#define ETHTRCV_30_KD10XX_APPL_CONST
#define ETHTRCV_30_KD10XX_APPL_CODE
#define ETHTRCV_30_KD10XX_APPL_DATA
#define ETHTRCV_30_KD10XX_VAR_NOINIT
#define ETHTRCV_30_KD10XX_VAR_ZERO_INIT
#define ETHTRCV_30_KD10XX_VAR_INIT_FAST
#define ETHTRCV_30_KD10XX_VAR_NOINIT_FAST
#define ETHTRCV_30_KD10XX_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_KD10XX_VAR_INIT_NOCACHE
#define ETHTRCV_30_KD10XX_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_KD10XX_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_KD10XX END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_KSZ9031 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_KSZ9031_CODE
#define ETHTRCV_30_KSZ9031_CODE_INLINE
#define ETHTRCV_30_KSZ9031_CODE_FAST
#define ETHTRCV_30_KSZ9031_CODE_ISR

#define ETHTRCV_30_KSZ9031_CONST
#define ETHTRCV_30_KSZ9031_CONST_FAST
#define ETHTRCV_30_KSZ9031_PBCFG


#define ETHTRCV_30_KSZ9031_PBCFG_ROOT

#define ETHTRCV_30_KSZ9031_VAR_PBCFG

#define ETHTRCV_30_KSZ9031_APPL_VAR
#define ETHTRCV_30_KSZ9031_APPL_CONST
#define ETHTRCV_30_KSZ9031_APPL_CODE
#define ETHTRCV_30_KSZ9031_APPL_DATA
#define ETHTRCV_30_KSZ9031_VAR_NOINIT
#define ETHTRCV_30_KSZ9031_VAR_ZERO_INIT
#define ETHTRCV_30_KSZ9031_VAR_INIT_FAST
#define ETHTRCV_30_KSZ9031_VAR_NOINIT_FAST
#define ETHTRCV_30_KSZ9031_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_KSZ9031_VAR_INIT_NOCACHE
#define ETHTRCV_30_KSZ9031_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_KSZ9031_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_KSZ9031 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_MSE102X START 
 *********************************************************************************************************************/

#define ETHTRCV_30_MSE102X_CODE
#define ETHTRCV_30_MSE102X_CODE_INLINE
#define ETHTRCV_30_MSE102X_CODE_FAST
#define ETHTRCV_30_MSE102X_CODE_ISR

#define ETHTRCV_30_MSE102X_CONST
#define ETHTRCV_30_MSE102X_CONST_FAST
#define ETHTRCV_30_MSE102X_PBCFG


#define ETHTRCV_30_MSE102X_PBCFG_ROOT

#define ETHTRCV_30_MSE102X_VAR_PBCFG

#define ETHTRCV_30_MSE102X_APPL_VAR
#define ETHTRCV_30_MSE102X_APPL_CONST
#define ETHTRCV_30_MSE102X_APPL_CODE
#define ETHTRCV_30_MSE102X_APPL_DATA
#define ETHTRCV_30_MSE102X_VAR_NOINIT
#define ETHTRCV_30_MSE102X_VAR_ZERO_INIT
#define ETHTRCV_30_MSE102X_VAR_INIT_FAST
#define ETHTRCV_30_MSE102X_VAR_NOINIT_FAST
#define ETHTRCV_30_MSE102X_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_MSE102X_VAR_INIT_NOCACHE
#define ETHTRCV_30_MSE102X_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_MSE102X_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_MSE102X END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9000 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_RTL9000_CODE
#define ETHTRCV_30_RTL9000_CODE_INLINE
#define ETHTRCV_30_RTL9000_CODE_FAST
#define ETHTRCV_30_RTL9000_CODE_ISR

#define ETHTRCV_30_RTL9000_CONST
#define ETHTRCV_30_RTL9000_CONST_FAST
#define ETHTRCV_30_RTL9000_PBCFG


#define ETHTRCV_30_RTL9000_PBCFG_ROOT

#define ETHTRCV_30_RTL9000_VAR_PBCFG

#define ETHTRCV_30_RTL9000_APPL_VAR
#define ETHTRCV_30_RTL9000_APPL_CONST
#define ETHTRCV_30_RTL9000_APPL_CODE
#define ETHTRCV_30_RTL9000_APPL_DATA
#define ETHTRCV_30_RTL9000_VAR_NOINIT
#define ETHTRCV_30_RTL9000_VAR_ZERO_INIT
#define ETHTRCV_30_RTL9000_VAR_INIT_FAST
#define ETHTRCV_30_RTL9000_VAR_NOINIT_FAST
#define ETHTRCV_30_RTL9000_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_RTL9000_VAR_INIT_NOCACHE
#define ETHTRCV_30_RTL9000_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_RTL9000_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9000 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9010 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_RTL9010_CODE
#define ETHTRCV_30_RTL9010_CODE_INLINE
#define ETHTRCV_30_RTL9010_CODE_FAST
#define ETHTRCV_30_RTL9010_CODE_ISR

#define ETHTRCV_30_RTL9010_CONST
#define ETHTRCV_30_RTL9010_CONST_FAST
#define ETHTRCV_30_RTL9010_PBCFG


#define ETHTRCV_30_RTL9010_PBCFG_ROOT

#define ETHTRCV_30_RTL9010_VAR_PBCFG

#define ETHTRCV_30_RTL9010_APPL_VAR
#define ETHTRCV_30_RTL9010_APPL_CONST
#define ETHTRCV_30_RTL9010_APPL_CODE
#define ETHTRCV_30_RTL9010_APPL_DATA
#define ETHTRCV_30_RTL9010_VAR_NOINIT
#define ETHTRCV_30_RTL9010_VAR_ZERO_INIT
#define ETHTRCV_30_RTL9010_VAR_INIT_FAST
#define ETHTRCV_30_RTL9010_VAR_NOINIT_FAST
#define ETHTRCV_30_RTL9010_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_RTL9010_VAR_INIT_NOCACHE
#define ETHTRCV_30_RTL9010_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_RTL9010_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_RTL9010 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_SBC START 
 *********************************************************************************************************************/

#define CANTRCV_30_SBC_CODE /* PRQA S 0883 */ /* Appears only while testing */
#define CANTRCV_30_SBC_CODE_FAST
#define CANTRCV_30_SBC_CODE_ISR

#define CANTRCV_30_SBC_CONST
#define CANTRCV_30_SBC_CONST_FAST
#define CANTRCV_30_SBC_PBCFG

#define CANTRCV_30_SBC_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_SBC_VAR_INIT
#define CANTRCV_30_SBC_VAR_NOINIT
#define CANTRCV_30_SBC_APPL_VAR
#define CANTRCV_30_SBC_VAR_ZERO_INIT
#define CANTRCV_30_SBC_VAR_INIT_FAST
#define CANTRCV_30_SBC_VAR_NOINIT_FAST
#define CANTRCV_30_SBC_VAR_ZERO_INIT_FAST

#define CANTRCV_30_SBC_VAR_INIT_NOCACHE
#define CANTRCV_30_SBC_VAR_NOINIT_NOCACHE
#define CANTRCV_30_SBC_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_SBC END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LIN TRANSCEIVER SBC DRIVER START
 *********************************************************************************************************************/

#define LINTRCV_30_SBC_CODE

#define LINTRCV_30_SBC_CONST
#define LINTRCV_30_SBC_PBCFG

#define LINTRCV_30_SBC_VAR_NOINIT
#define LINTRCV_30_SBC_VAR_ZERO_INIT

#define LINTRCV_30_SBC_APPL_VAR
#define LINTRCV_30_SBC_APPL_CODE
/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER SBC DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1040 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1040_CODE
#define CANTRCV_30_TJA1040_CODE_FAST
#define CANTRCV_30_TJA1040_CODE_ISR

#define CANTRCV_30_TJA1040_CONST
#define CANTRCV_30_TJA1040_CONST_FAST
#define CANTRCV_30_TJA1040_PBCFG

#define CANTRCV_30_TJA1040_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1040_VAR_INIT
#define CANTRCV_30_TJA1040_VAR_NOINIT
#define CANTRCV_30_TJA1040_APPL_VAR
#define CANTRCV_30_TJA1040_APPL_CODE
#define CANTRCV_30_TJA1040_VAR_ZERO_INIT
#define CANTRCV_30_TJA1040_VAR_INIT_FAST
#define CANTRCV_30_TJA1040_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1040_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1040_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1040_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1040_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1040 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1041 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1041_CODE
#define CANTRCV_30_TJA1041_CODE_FAST
#define CANTRCV_30_TJA1041_CODE_ISR

#define CANTRCV_30_TJA1041_CONST
#define CANTRCV_30_TJA1041_CONST_FAST
#define CANTRCV_30_TJA1041_PBCFG

#define CANTRCV_30_TJA1041_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1041_VAR_INIT
#define CANTRCV_30_TJA1041_VAR_NOINIT
#define CANTRCV_30_TJA1041_APPL_VAR
#define CANTRCV_30_TJA1041_APPL_CODE
#define CANTRCV_30_TJA1041_VAR_ZERO_INIT
#define CANTRCV_30_TJA1041_VAR_INIT_FAST
#define CANTRCV_30_TJA1041_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1041_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1041_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1041_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1041_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1041 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1043_CODE
#define CANTRCV_30_TJA1043_CODE_FAST
#define CANTRCV_30_TJA1043_CODE_ISR

#define CANTRCV_30_TJA1043_CONST
#define CANTRCV_30_TJA1043_CONST_FAST
#define CANTRCV_30_TJA1043_PBCFG

#define CANTRCV_30_TJA1043_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1043_VAR_INIT
#define CANTRCV_30_TJA1043_VAR_NOINIT
#define CANTRCV_30_TJA1043_APPL_VAR
#define CANTRCV_30_TJA1043_APPL_CODE
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT
#define CANTRCV_30_TJA1043_VAR_INIT_FAST
#define CANTRCV_30_TJA1043_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1043_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1043_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1043_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1043 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1048 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1048_CODE
#define CANTRCV_30_TJA1048_CODE_FAST
#define CANTRCV_30_TJA1048_CODE_ISR

#define CANTRCV_30_TJA1048_CONST
#define CANTRCV_30_TJA1048_CONST_FAST
#define CANTRCV_30_TJA1048_PBCFG

#define CANTRCV_30_TJA1048_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1048_VAR_INIT
#define CANTRCV_30_TJA1048_VAR_NOINIT
#define CANTRCV_30_TJA1048_APPL_VAR
#define CANTRCV_30_TJA1048_APPL_CODE
#define CANTRCV_30_TJA1048_VAR_ZERO_INIT
#define CANTRCV_30_TJA1048_VAR_INIT_FAST
#define CANTRCV_30_TJA1048_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1048_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1048_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1048_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1048_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1048 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1055 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1055_CODE
#define CANTRCV_30_TJA1055_CODE_FAST
#define CANTRCV_30_TJA1055_CODE_ISR

#define CANTRCV_30_TJA1055_CONST
#define CANTRCV_30_TJA1055_CONST_FAST
#define CANTRCV_30_TJA1055_PBCFG

#define CANTRCV_30_TJA1055_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1055_VAR_INIT
#define CANTRCV_30_TJA1055_VAR_NOINIT
#define CANTRCV_30_TJA1055_APPL_VAR
#define CANTRCV_30_TJA1055_APPL_CODE
#define CANTRCV_30_TJA1055_VAR_ZERO_INIT
#define CANTRCV_30_TJA1055_VAR_INIT_FAST
#define CANTRCV_30_TJA1055_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1055_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1055_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1055_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1055_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1055 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */



/**********************************************************************************************************************
 *  FRTRCV TJA1080 START 
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1080_CONST
#define FRTRCV_30_TJA1080_VAR_NOINIT
#define FRTRCV_30_TJA1080_VAR_ZERO_INIT
#define FRTRCV_30_TJA1080_CODE
#define FRTRCV_30_TJA1080_APPL_DATA

/**********************************************************************************************************************
 *  FRTRCV TJA1080 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 START 
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1082_CODE
#define FRTRCV_30_TJA1082_APPL_CODE
#define FRTRCV_30_TJA1082_CONST
#define FRTRCV_30_TJA1082_VAR_NOINIT
#define FRTRCV_30_TJA1082_VAR_INIT
#define FRTRCV_30_TJA1082_APPL_DATA
#define FRTRCV_30_TJA1082_VAR_ZERO_INIT

/**********************************************************************************************************************
 *  FRTRCV_30_TJA1082 END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  FRTRCV START 
 *********************************************************************************************************************/

#define FRTRCV_30_TJA1085_CODE
#define FRTRCV_30_TJA1085_APPL_CODE
#define FRTRCV_CONST
#define FRTRCV_30_TJA1085_CONST
#define FRTRCV_30_TJA1085_VAR_NOINIT
#define FRTRCV_30_TJA1085_VAR_ZERO_INIT
#define FRTRCV_30_TJA1085_APPL_DATA

/**********************************************************************************************************************
 *  FRTRCV END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1100 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_TJA1100_CODE
#define ETHTRCV_30_TJA1100_CODE_INLINE
#define ETHTRCV_30_TJA1100_CODE_FAST
#define ETHTRCV_30_TJA1100_CODE_ISR

#define ETHTRCV_30_TJA1100_CONST
#define ETHTRCV_30_TJA1100_CONST_FAST
#define ETHTRCV_30_TJA1100_PBCFG


#define ETHTRCV_30_TJA1100_PBCFG_ROOT

#define ETHTRCV_30_TJA1100_VAR_PBCFG

#define ETHTRCV_30_TJA1100_APPL_VAR
#define ETHTRCV_30_TJA1100_APPL_CONST
#define ETHTRCV_30_TJA1100_APPL_CODE
#define ETHTRCV_30_TJA1100_APPL_DATA
#define ETHTRCV_30_TJA1100_VAR_NOINIT
#define ETHTRCV_30_TJA1100_VAR_ZERO_INIT
#define ETHTRCV_30_TJA1100_VAR_INIT_FAST
#define ETHTRCV_30_TJA1100_VAR_NOINIT_FAST
#define ETHTRCV_30_TJA1100_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_TJA1100_VAR_INIT_NOCACHE
#define ETHTRCV_30_TJA1100_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_TJA1100_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1100 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1103 START 
 *********************************************************************************************************************/

#define ETHTRCV_30_TJA1103_CODE
#define ETHTRCV_30_TJA1103_CODE_INLINE
#define ETHTRCV_30_TJA1103_CODE_FAST
#define ETHTRCV_30_TJA1103_CODE_ISR

#define ETHTRCV_30_TJA1103_CONST
#define ETHTRCV_30_TJA1103_CONST_FAST
#define ETHTRCV_30_TJA1103_PBCFG


#define ETHTRCV_30_TJA1103_PBCFG_ROOT

#define ETHTRCV_30_TJA1103_VAR_PBCFG

#define ETHTRCV_30_TJA1103_APPL_VAR
#define ETHTRCV_30_TJA1103_APPL_CONST
#define ETHTRCV_30_TJA1103_APPL_CODE
#define ETHTRCV_30_TJA1103_APPL_DATA
#define ETHTRCV_30_TJA1103_VAR_NOINIT
#define ETHTRCV_30_TJA1103_VAR_ZERO_INIT
#define ETHTRCV_30_TJA1103_VAR_INIT_FAST
#define ETHTRCV_30_TJA1103_VAR_NOINIT_FAST
#define ETHTRCV_30_TJA1103_VAR_ZERO_INIT_FAST

#define ETHTRCV_30_TJA1103_VAR_INIT_NOCACHE
#define ETHTRCV_30_TJA1103_VAR_NOINIT_NOCACHE
#define ETHTRCV_30_TJA1103_VAR_ZERO_INIT_NOCACHE

/**********************************************************************************************************************
 *  ETHTRCV_30_TJA1103 END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TJA1145 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TJA1145_CODE
#define CANTRCV_30_TJA1145_CODE_FAST
#define CANTRCV_30_TJA1145_CODE_ISR

#define CANTRCV_30_TJA1145_CONST
#define CANTRCV_30_TJA1145_CONST_FAST
#define CANTRCV_30_TJA1145_PBCFG

#define CANTRCV_30_TJA1145_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TJA1145_VAR_INIT
#define CANTRCV_30_TJA1145_VAR_NOINIT
#define CANTRCV_30_TJA1145_APPL_VAR
#define CANTRCV_30_TJA1145_APPL_CODE
#define CANTRCV_30_TJA1145_VAR_ZERO_INIT
#define CANTRCV_30_TJA1145_VAR_INIT_FAST
#define CANTRCV_30_TJA1145_VAR_NOINIT_FAST
#define CANTRCV_30_TJA1145_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TJA1145_VAR_INIT_NOCACHE
#define CANTRCV_30_TJA1145_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TJA1145_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TJA1145 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  CANTRCV_30_TLE62512G START 
 *********************************************************************************************************************/

#define CANTRCV_30_TLE62512G_CODE
#define CANTRCV_30_TLE62512G_CODE_FAST
#define CANTRCV_30_TLE62512G_CODE_ISR

#define CANTRCV_30_TLE62512G_CONST
#define CANTRCV_30_TLE62512G_CONST_FAST
#define CANTRCV_30_TLE62512G_PBCFG

#define CANTRCV_30_TLE62512G_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TLE62512G_VAR_INIT
#define CANTRCV_30_TLE62512G_VAR_NOINIT
#define CANTRCV_30_TLE62512G_APPL_VAR
#define CANTRCV_30_TLE62512G_APPL_CODE
#define CANTRCV_30_TLE62512G_VAR_ZERO_INIT
#define CANTRCV_30_TLE62512G_VAR_INIT_FAST
#define CANTRCV_30_TLE62512G_VAR_NOINIT_FAST
#define CANTRCV_30_TLE62512G_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TLE62512G_VAR_INIT_NOCACHE
#define CANTRCV_30_TLE62512G_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TLE62512G_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TLE62512G END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  LIN TRANSCEIVER TLE7259 DRIVER START
 *********************************************************************************************************************/

#define LINTRCV_30_TLE7259_CODE

#define LINTRCV_30_TLE7259_CONST
#define LINTRCV_30_TLE7259_PBCFG

#define LINTRCV_30_TLE7259_VAR_NOINIT
#define LINTRCV_30_TLE7259_VAR_ZERO_INIT

#define LINTRCV_30_TLE7259_APPL_VAR
#define LINTRCV_30_TLE7259_APPL_CODE
/* PRQA S 0883 4 */ /* MD_LINTRCV_0883 */
/**********************************************************************************************************************
 *  LIN TRANSCEIVER TLE7259 DRIVER END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CANTRCV_30_TLE9255 START 
 *********************************************************************************************************************/

#define CANTRCV_30_TLE9255_CODE
#define CANTRCV_30_TLE9255_CODE_FAST
#define CANTRCV_30_TLE9255_CODE_ISR

#define CANTRCV_30_TLE9255_CONST
#define CANTRCV_30_TLE9255_CONST_FAST
#define CANTRCV_30_TLE9255_PBCFG

#define CANTRCV_30_TLE9255_VAR_PBCFG /* ESCAN00065502 */

#define CANTRCV_30_TLE9255_VAR_INIT
#define CANTRCV_30_TLE9255_VAR_NOINIT
#define CANTRCV_30_TLE9255_APPL_VAR
#define CANTRCV_30_TLE9255_APPL_CODE
#define CANTRCV_30_TLE9255_VAR_ZERO_INIT
#define CANTRCV_30_TLE9255_VAR_INIT_FAST
#define CANTRCV_30_TLE9255_VAR_NOINIT_FAST
#define CANTRCV_30_TLE9255_VAR_ZERO_INIT_FAST

#define CANTRCV_30_TLE9255_VAR_INIT_NOCACHE
#define CANTRCV_30_TLE9255_VAR_NOINIT_NOCACHE
#define CANTRCV_30_TLE9255_VAR_ZERO_INIT_NOCACHE



/**********************************************************************************************************************
 *  CANTRCV_30_TLE9255 END
 *********************************************************************************************************************/ /* PRQA S 0883 */ /* Appears only while testing */


/**********************************************************************************************************************
 *  WDG_30_SBC START
 *********************************************************************************************************************/

#define WDG_30_SBC_CODE
#define WDG_30_SBC_CONST
#define WDG_30_SBC_VAR
#define WDG_30_SBC_VAR_INIT
#define WDG_30_SBC_VAR_NOINIT
#define WDG_30_SBC_APPL_DATA
#define WDG_30_SBC_PBCFG


/**********************************************************************************************************************
 *  WDG_30_SBC END
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  WDG_30_TLE4278G START
 *********************************************************************************************************************/

#define WDG_30_TLE4278G_CODE
#define WDG_30_TLE4278G_CONST
#define WDG_30_TLE4278G_VAR
#define WDG_30_TLE4278G_VAR_INIT
#define WDG_30_TLE4278G_VAR_NOINIT
#define WDG_30_TLE4278G_APPL_DATA
#define WDG_30_TLE4278G_PBCFG


/**********************************************************************************************************************
 *  WDG_30_TLE4278G END
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  VCANIDPS START
 *********************************************************************************************************************/

#define VCANIDPS_CODE

#define VCANIDPS_CONST
#define VCANIDPS_PBCFG

#define VCANIDPS_VAR_NOINIT
#define VCANIDPS_VAR_ZERO_INIT

#define VCANIDPS_APPL_CODE
#define VCANIDPS_APPL_VAR

/**********************************************************************************************************************
 *  VCANIDPS END
 *********************************************************************************************************************/



/* Package Merger: Stop Section CompilerCfgModuleList */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  END OF FILE: Compiler_Cfg.h
 *********************************************************************************************************************/
