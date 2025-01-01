// =============================================================================
// @file:    pkc_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
// @purpose: Register Definition File for Infineon HSM Device Series
//
// THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". INFINEON
// TECHNOLOGIES MAKES NO OTHER WARRANTY OF ANY KIND,WHETHER EXPRESS,IMPLIED OR,
// STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
// SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
//
// THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. INFINEON TECHNOLOGIES
// RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
// REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR
// THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
//
// INFINEON TECHNOLOGIES SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
// CONSEQUENTIAL DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR
// ANY DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR
// PROFITS, DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE
// DAMAGES, LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION
// WITH THIS AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR
// PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
// WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
//
// (C)Copyright INFINEON TECHNOLOGIES All rights reserved
// =============================================================================

#ifndef __PKC_HSM_INTERNAL_H__
#define __PKC_HSM_INTERNAL_H__
 
#include "pkc_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define PKC_CONFIG_wr_msk                0xffffffff
#define PKC_CONFIG_rd_msk                0xffffffff
#define PKC_CONFIG_res                   0x0
#define PKC_CONFIG_res_msk               0xffffffff
#define PKC_CMD_wr_msk                   0xffffffff
#define PKC_CMD_rd_msk                   0xffffffff
#define PKC_CMD_res                      0x0
#define PKC_CMD_res_msk                  0xffffffff
#define PKC_CTRL_wr_msk                  0xffffffff
#define PKC_CTRL_rd_msk                  0xffffffff
#define PKC_CTRL_res                     0x0
#define PKC_CTRL_res_msk                 0xffffffff
#define PKC_STATUS_wr_msk                0x0
#define PKC_STATUS_rd_msk                0x10eef
#define PKC_STATUS_res                   0x0
#define PKC_STATUS_res_msk               0xffffffff
#define PKC_SCM_R0_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R0_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R0_res                   0x0
#define PKC_SCM_R0_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R1_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R1_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R1_res                   0x0
#define PKC_SCM_R1_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R2_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R2_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R2_res                   0x0
#define PKC_SCM_R2_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R3_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R3_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R3_res                   0x0
#define PKC_SCM_R3_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R4_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R4_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R4_res                   0x0
#define PKC_SCM_R4_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R5_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R5_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R5_res                   0x0
#define PKC_SCM_R5_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R6_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R6_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R6_res                   0x0
#define PKC_SCM_R6_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R7_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R7_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R7_res                   0x0
#define PKC_SCM_R7_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R8_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R8_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R8_res                   0x0
#define PKC_SCM_R8_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R9_wr_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R9_rd_msk                0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R9_res                   0x0
#define PKC_SCM_R9_res_msk               0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R10_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R10_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R10_res                  0x0
#define PKC_SCM_R10_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R11_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R11_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R11_res                  0x0
#define PKC_SCM_R11_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R12_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R12_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R12_res                  0x0
#define PKC_SCM_R12_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R13_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R13_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R13_res                  0x0
#define PKC_SCM_R13_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R14_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R14_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R14_res                  0x0
#define PKC_SCM_R14_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R15_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R15_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R15_res                  0x0
#define PKC_SCM_R15_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R16_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R16_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R16_res                  0x0
#define PKC_SCM_R16_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R17_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R17_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R17_res                  0x0
#define PKC_SCM_R17_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R18_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R18_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R18_res                  0x0
#define PKC_SCM_R18_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R19_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R19_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R19_res                  0x0
#define PKC_SCM_R19_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R20_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R20_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R20_res                  0x0
#define PKC_SCM_R20_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R21_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R21_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R21_res                  0x0
#define PKC_SCM_R21_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R22_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R22_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R22_res                  0x0
#define PKC_SCM_R22_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R23_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R23_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R23_res                  0x0
#define PKC_SCM_R23_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R24_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R24_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R24_res                  0x0
#define PKC_SCM_R24_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R25_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R25_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R25_res                  0x0
#define PKC_SCM_R25_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R26_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R26_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R26_res                  0x0
#define PKC_SCM_R26_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R27_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R27_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R27_res                  0x0
#define PKC_SCM_R27_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R28_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R28_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R28_res                  0x0
#define PKC_SCM_R28_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R29_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R29_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R29_res                  0x0
#define PKC_SCM_R29_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R30_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R30_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R30_res                  0x0
#define PKC_SCM_R30_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0
#define PKC_SCM_R31_wr_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R31_rd_msk               0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
#define PKC_SCM_R31_res                  0x0
#define PKC_SCM_R31_res_msk              0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0


#endif  /* __PKC_HSM_INTERNAL_H__ */
