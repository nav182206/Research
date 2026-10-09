/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4509
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=425532d71d5d295cc9c649500e4969ac621ce51d
 */

static inline void tcg_out_ldst(TCGContext *s, int ret, int addr,

                                int offset, int op)

{

    if (check_fit_tl(offset, 13)) {

        tcg_out32(s, op | INSN_RD(ret) | INSN_RS1(addr) |

                  INSN_IMM13(offset));

    } else {

        tcg_out_movi(s, TCG_TYPE_PTR, TCG_REG_T1, offset);

        tcg_out_ldst_rr(s, ret, addr, TCG_REG_T1, op);

    }

}
