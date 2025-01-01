// =============================================================================
// @file:    aes_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __AES_HSM_INTERNAL_H__
#define __AES_HSM_INTERNAL_H__
 
#include "aes_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define AESIN0_wr_msk                    0xffffffff
#define AESIN0_rd_msk                    0xffffffff
#define AESIN0_res                       0x0
#define AESIN0_res_msk                   0xffffffff
#define AESIN1_wr_msk                    0xffffffff
#define AESIN1_rd_msk                    0xffffffff
#define AESIN1_res                       0x0
#define AESIN1_res_msk                   0xffffffff
#define AESIN2_wr_msk                    0xffffffff
#define AESIN2_rd_msk                    0xffffffff
#define AESIN2_res                       0x0
#define AESIN2_res_msk                   0xffffffff
#define AESIN3_wr_msk                    0xffffffff
#define AESIN3_rd_msk                    0xffffffff
#define AESIN3_res                       0x0
#define AESIN3_res_msk                   0xffffffff
#define AESCTRL_wr_msk                   0x1f1f7
#define AESCTRL_rd_msk                   0x1f1f7
#define AESCTRL_res                      0x13000
#define AESCTRL_res_msk                  0xffffffff
#define AESSTAT_wr_msk                   0x0
#define AESSTAT_rd_msk                   0x7
#define AESSTAT_res                      0x6
#define AESSTAT_res_msk                  0xffffffff
#define AESOUT0_wr_msk                   0x0
#define AESOUT0_rd_msk                   0xffffffff
#define AESOUT0_res                      0x0
#define AESOUT0_res_msk                  0xffffffff
#define AESOUT1_wr_msk                   0x0
#define AESOUT1_rd_msk                   0xffffffff
#define AESOUT1_res                      0x0
#define AESOUT1_res_msk                  0xffffffff
#define AESOUT2_wr_msk                   0x0
#define AESOUT2_rd_msk                   0xffffffff
#define AESOUT2_res                      0x0
#define AESOUT2_res_msk                  0xffffffff
#define AESOUT3_wr_msk                   0x0
#define AESOUT3_rd_msk                   0xffffffff
#define AESOUT3_res                      0x0
#define AESOUT3_res_msk                  0xffffffff
#define AESOUTSAVE0_wr_msk               0x0
#define AESOUTSAVE0_rd_msk               0xffffffff
#define AESOUTSAVE0_res                  0x0
#define AESOUTSAVE0_res_msk              0xffffffff
#define AESOUTSAVE1_wr_msk               0x0
#define AESOUTSAVE1_rd_msk               0xffffffff
#define AESOUTSAVE1_res                  0x0
#define AESOUTSAVE1_res_msk              0xffffffff
#define AESOUTSAVE2_wr_msk               0x0
#define AESOUTSAVE2_rd_msk               0xffffffff
#define AESOUTSAVE2_res                  0x0
#define AESOUTSAVE2_res_msk              0xffffffff
#define AESOUTSAVE3_wr_msk               0x0
#define AESOUTSAVE3_rd_msk               0xffffffff
#define AESOUTSAVE3_res                  0x0
#define AESOUTSAVE3_res_msk              0xffffffff


#endif  /* __AES_HSM_INTERNAL_H__ */
