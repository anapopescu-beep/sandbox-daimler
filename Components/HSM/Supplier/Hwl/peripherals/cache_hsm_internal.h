// =============================================================================
// @file:    cache_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __CACHE_HSM_INTERNAL_H__
#define __CACHE_HSM_INTERNAL_H__
 
#include "cache_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define CACHE_CONFIG_wr_msk              0x0
#define CACHE_CONFIG_rd_msk              0xffffff
#define CACHE_CONFIG_res                 0x60404
#define CACHE_CONFIG_res_msk             0xffffffff
#define CACHE_CTRL_wr_msk                0x1
#define CACHE_CTRL_rd_msk                0x1
#define CACHE_CTRL_res                   0x0
#define CACHE_CTRL_res_msk               0xffffffff
#define CACHE_AC_wr_msk                  0xffffffff
#define CACHE_AC_rd_msk                  0x0
#define CACHE_AC_res                     0x0
#define CACHE_AC_res_msk                 0xffffffff
#define CACHE_SC_wr_msk                  0xffffffff
#define CACHE_SC_rd_msk                  0x0
#define CACHE_SC_res                     0x0
#define CACHE_SC_res_msk                 0xffffffff
#define CACHE_BC_wr_msk                  0xffffffff
#define CACHE_BC_rd_msk                  0x0
#define CACHE_BC_res                     0x0
#define CACHE_BC_res_msk                 0xffffffff
#define CACHE_BT_wr_msk                  0xffffffff
#define CACHE_BT_rd_msk                  0x0
#define CACHE_BT_res                     0x0
#define CACHE_BT_res_msk                 0xffffffff
#define CACHE_BL_wr_msk                  0xffffffff
#define CACHE_BL_rd_msk                  0x0
#define CACHE_BL_res                     0x0
#define CACHE_BL_res_msk                 0xffffffff
#define CACHE_BU_wr_msk                  0xffffffff
#define CACHE_BU_rd_msk                  0x0
#define CACHE_BU_res                     0x0
#define CACHE_BU_res_msk                 0xffffffff


#endif  /* __CACHE_HSM_INTERNAL_H__ */
