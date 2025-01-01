// =============================================================================
// @file:    bridge_hsm_internal.h (HRM Doc_State_importance_=_required_Revision_2.0-BUILD-147)
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

#ifndef __BRIDGE_HSM_INTERNAL_H__
#define __BRIDGE_HSM_INTERNAL_H__
 
#include "bridge_hsm.h"



/******************************************************************************************/
/*  Additional register mask definitions                                                  */
/******************************************************************************************/

#define HSM_ID_wr_msk                    0xffffffff
#define HSM_ID_rd_msk                    0xffffffff
#define HSM_ID_res                       0xbec002
#define HSM_ID_res_msk                   0xffffffff
#define HT2HSMF_wr_msk                   0xffffffff
#define HT2HSMF_rd_msk                   0xffffffff
#define HT2HSMF_res                      0x0
#define HT2HSMF_res_msk                  0xffffffff
#define HT2HSMIE_wr_msk                  0xffffffff
#define HT2HSMIE_rd_msk                  0xffffffff
#define HT2HSMIE_res                     0x0
#define HT2HSMIE_res_msk                 0xffffffff
#define HSM2HTF_wr_msk                   0xffffffff
#define HSM2HTF_rd_msk                   0xffffffff
#define HSM2HTF_res                      0x0
#define HSM2HTF_res_msk                  0xffffffff
#define HSM2HTIE_wr_msk                  0xffffffff
#define HSM2HTIE_rd_msk                  0xffffffff
#define HSM2HTIE_res                     0x0
#define HSM2HTIE_res_msk                 0xffffffff
#define HSM2HTIS_wr_msk                  0xffffffff
#define HSM2HTIS_rd_msk                  0xffffffff
#define HSM2HTIS_res                     0x0
#define HSM2HTIS_res_msk                 0xffffffff
#define HSM2HTS_wr_msk                   0xffffffff
#define HSM2HTS_rd_msk                   0xffffffff
#define HSM2HTS_res                      0x0
#define HSM2HTS_res_msk                  0xffffffff
#define HT2HSMS_wr_msk                   0xffffffff
#define HT2HSMS_rd_msk                   0xffffffff
#define HT2HSMS_res                      0x0
#define HT2HSMS_res_msk                  0xffffffff
#define CLKCTRL_wr_msk                   0x3
#define CLKCTRL_rd_msk                   0x3
#define CLKCTRL_res                      0x0
#define CLKCTRL_res_msk                  0xffffffff
#define DBGCTRL_wr_msk                   0x733
#define DBGCTRL_rd_msk                   0x733
#define DBGCTRL_res                      0x0
#define DBGCTRL_res_msk                  0xfffff000
#define PINCTRL_wr_msk                   0x8000000f
#define PINCTRL_rd_msk                   0x8000000f
#define PINCTRL_res                      0x0
#define PINCTRL_res_msk                  0xffffffff
#define ERRCTRL_wr_msk                   0xb01ffffd
#define ERRCTRL_rd_msk                   0xb01ffffd
#define ERRCTRL_res                      0x0
#define ERRCTRL_res_msk                  0xffffffff
#define ERRIE_wr_msk                     0x1ffffd
#define ERRIE_rd_msk                     0x1ffffd
#define ERRIE_res                        0x0
#define ERRIE_res_msk                    0xffffffff
#define ERRADDR_wr_msk                   0xffffffff
#define ERRADDR_rd_msk                   0xffffffff
#define ERRADDR_res                      0x0
#define ERRADDR_res_msk                  0xffffffff
#define EXTIF_wr_msk                     0xffffffff
#define EXTIF_rd_msk                     0xffffffff
#define EXTIF_res                        0x0
#define EXTIF_res_msk                    0xffffffff
#define EXTIE_wr_msk                     0xffffffff
#define EXTIE_rd_msk                     0xffffffff
#define EXTIE_res                        0x0
#define EXTIE_res_msk                    0xffffffff
#define SAHBASE_wr_msk                   0xffff0000
#define SAHBASE_rd_msk                   0xffff0000
#define SAHBASE_res                      0xf0000000
#define SAHBASE_res_msk                  0xffffffff
#define RSTCTRL_wr_msk                   0x3
#define RSTCTRL_rd_msk                   0x3
#define RSTCTRL_res                      0x0
#define RSTCTRL_res_msk                  0xffffffff
#define RSTPWD_wr_msk                    0xffffffff
#define RSTPWD_rd_msk                    0xffffffff
#define RSTPWD_res                       0x0
#define RSTPWD_res_msk                   0xffffffff
#define SENSIF_wr_msk                    0x3ff
#define SENSIF_rd_msk                    0x3ff
#define SENSIF_res                       0x0
#define SENSIF_res_msk                   0xffffffff
#define SENSIE_wr_msk                    0x3ff
#define SENSIE_rd_msk                    0x3ff
#define SENSIE_res                       0x0
#define SENSIE_res_msk                   0xffffffff
#define SENSAPPRST_wr_msk                0x3ff
#define SENSAPPRST_rd_msk                0x3ff
#define SENSAPPRST_res                   0x0
#define SENSAPPRST_res_msk               0xffffffff
#define SENSSYSRST_wr_msk                0x3ff
#define SENSSYSRST_rd_msk                0x3ff
#define SENSSYSRST_res                   0x0
#define SENSSYSRST_res_msk               0xffffffff


#endif  /* __BRIDGE_HSM_INTERNAL_H__ */
