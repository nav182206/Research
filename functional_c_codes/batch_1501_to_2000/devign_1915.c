/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1915
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static inline void store_cpu_offset(TCGv var, int offset)

{

    tcg_gen_st_i32(var, cpu_env, offset);

    dead_tmp(var);

}
