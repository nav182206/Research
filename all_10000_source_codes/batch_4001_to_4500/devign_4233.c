/* 
 * Benchmark Sample ID : devign_4233
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bee818872cd9e8c07be529f75da3e48a68bf7a93
 */

static inline void gen_op_movo(int d_offset, int s_offset)

{

    tcg_gen_ld_i64(cpu_tmp1_i64, cpu_env, s_offset);

    tcg_gen_st_i64(cpu_tmp1_i64, cpu_env, d_offset);

    tcg_gen_ld_i64(cpu_tmp1_i64, cpu_env, s_offset + 8);

    tcg_gen_st_i64(cpu_tmp1_i64, cpu_env, d_offset + 8);

}
