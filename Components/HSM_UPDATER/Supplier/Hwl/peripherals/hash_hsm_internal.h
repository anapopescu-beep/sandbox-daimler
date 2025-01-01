// =============================================================================
// @file:    hash_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __HASH_HSM_INTERNAL_H__
#define __HASH_HSM_INTERNAL_H__
 
#include "hash_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define HASH_CFG_wr_msk                  0xdb
#define HASH_CFG_rd_msk                  0xdb
#define HASH_CFG_res                     0x0
#define HASH_CFG_res_msk                 0xffffffff
#define HASH_STAT_wr_msk                 0x0
#define HASH_STAT_rd_msk                 0xf07
#define HASH_STAT_res                    0x4
#define HASH_STAT_res_msk                0xffffffff
#define HASH_IVIN_wr_msk                 0xffffffff
#define HASH_IVIN_rd_msk                 0x0
#define HASH_IVIN_res                    0x0
#define HASH_IVIN_res_msk                0xffffffff
#define HASH_VAL_wr_msk                  0x0
#define HASH_VAL_rd_msk                  0xffffffff
#define HASH_VAL_res                     0x0
#define HASH_VAL_res_msk                 0xffffffff
#define HASH_DATA_wr_msk                 0xffffffff
#define HASH_DATA_rd_msk                 0x0
#define HASH_DATA_res                    0x0
#define HASH_DATA_res_msk                0xffffffff


#endif  /* __HASH_HSM_INTERNAL_H__ */
