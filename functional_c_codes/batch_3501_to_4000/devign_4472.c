/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4472
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static inline void gen_st8(TCGv val, TCGv addr, int index)

{

    tcg_gen_qemu_st8(val, addr, index);

    dead_tmp(val);

}
