/* 
 * Benchmark Sample ID : devign_1775
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42a268c241183877192c376d03bd9b6d527407c7
 */

static inline void gen_op_jz_ecx(TCGMemOp size, int label1)

{

    tcg_gen_mov_tl(cpu_tmp0, cpu_regs[R_ECX]);

    gen_extu(size, cpu_tmp0);

    tcg_gen_brcondi_tl(TCG_COND_EQ, cpu_tmp0, 0, label1);

}
