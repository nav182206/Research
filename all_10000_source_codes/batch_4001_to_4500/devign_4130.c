/* 
 * Benchmark Sample ID : devign_4130
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a3251186fc6a04d421e9c4b65aa04ec32379ec38
 */

static void gen_op_update_neg_cc(void)

{

    tcg_gen_neg_tl(cpu_cc_src, cpu_T[0]);

    tcg_gen_mov_tl(cpu_cc_dst, cpu_T[0]);

}
