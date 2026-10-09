/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1193
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void gen_sub_carry(TCGv dest, TCGv t0, TCGv t1)

{

    TCGv tmp;

    tcg_gen_sub_i32(dest, t0, t1);

    tmp = load_cpu_field(CF);

    tcg_gen_add_i32(dest, dest, tmp);

    tcg_gen_subi_i32(dest, dest, 1);

    dead_tmp(tmp);

}
