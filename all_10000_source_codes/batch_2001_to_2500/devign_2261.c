/* 
 * Benchmark Sample ID : devign_2261
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

static inline void gen_op_fcmpd(int fccno, TCGv_i64 r_rs1, TCGv_i64 r_rs2)

{

    gen_helper_fcmpd(cpu_env, r_rs1, r_rs2);

}
