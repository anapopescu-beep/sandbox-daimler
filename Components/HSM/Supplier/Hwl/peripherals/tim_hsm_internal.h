// =============================================================================
// @file:    tim_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __TIM_HSM_INTERNAL_H__
#define __TIM_HSM_INTERNAL_H__
 
#include "tim_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define TIM_CTRL_wr_msk                  0x1f1f
#define TIM_CTRL_rd_msk                  0x1b1b
#define TIM_CTRL_res                     0x0
#define TIM_CTRL_res_msk                 0xffff
#define TIM_CTRL_unlock_msk              0x404
#define TIM_CFG_wr_msk                   0xf0f
#define TIM_CFG_rd_msk                   0xf0f
#define TIM_CFG_res                      0x0
#define TIM_CFG_res_msk                  0xffff
#define TIM_CNT0_wr_msk                  0x0
#define TIM_CNT0_rd_msk                  0xffff
#define TIM_CNT0_res                     0x0
#define TIM_CNT0_res_msk                 0x0
#define TIM_CNT1_wr_msk                  0x0
#define TIM_CNT1_rd_msk                  0xffff
#define TIM_CNT1_res                     0x0
#define TIM_CNT1_res_msk                 0x0
#define TIM_RLD0_wr_msk                  0xffff
#define TIM_RLD0_rd_msk                  0xffff
#define TIM_RLD0_res                     0x0
#define TIM_RLD0_res_msk                 0x0
#define TIM_RLD1_wr_msk                  0xffff
#define TIM_RLD1_rd_msk                  0xffff
#define TIM_RLD1_res                     0x0
#define TIM_RLD1_res_msk                 0x0


#endif  /* __TIM_HSM_INTERNAL_H__ */
