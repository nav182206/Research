/* 
 * Benchmark Sample ID : devign_9161
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static inline void gen_st32(TCGv val, TCGv addr, int index)

{

    tcg_gen_qemu_st32(val, addr, index);

    dead_tmp(val);

}
