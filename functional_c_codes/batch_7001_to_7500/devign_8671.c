/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8671
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static TCGv gen_vfp_mrs(void)

{

    TCGv tmp = new_tmp();

    tcg_gen_mov_i32(tmp, cpu_F0s);

    return tmp;

}
