/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5084
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void gen_rfe(DisasContext *s, TCGv pc, TCGv cpsr)

{

    gen_set_cpsr(cpsr, 0xffffffff);

    dead_tmp(cpsr);

    store_reg(s, 15, pc);

    s->is_jmp = DISAS_UPDATE;

}
