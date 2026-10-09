/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4700
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=537d3e8e6beea9a0fbd6469eb38450e718244dad
 */

void helper_lswx(CPUPPCState *env, target_ulong addr, uint32_t reg,

                 uint32_t ra, uint32_t rb)

{

    if (likely(xer_bc != 0)) {

        int num_used_regs = (xer_bc + 3) / 4;

        if (unlikely((ra != 0 && reg < ra && (reg + num_used_regs) > ra) ||

                     (reg < rb && (reg + num_used_regs) > rb))) {

            helper_raise_exception_err(env, POWERPC_EXCP_PROGRAM,

                                       POWERPC_EXCP_INVAL |

                                       POWERPC_EXCP_INVAL_LSWX);

        } else {

            helper_lsw(env, addr, xer_bc, reg);

        }

    }

}
