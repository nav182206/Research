/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_219
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=577bf808958d06497928c639efaa473bf8c5e099
 */

static void gen_rfe(DisasContext *s, TCGv_i32 pc, TCGv_i32 cpsr)

{

    gen_set_cpsr(cpsr, CPSR_ERET_MASK);

    tcg_temp_free_i32(cpsr);

    store_reg(s, 15, pc);

    s->is_jmp = DISAS_UPDATE;

}
