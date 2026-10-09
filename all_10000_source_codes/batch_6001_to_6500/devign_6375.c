/* 
 * Benchmark Sample ID : devign_6375
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=235ea1f5c89abf30e452539b973b0dbe43d3fe2b
 */

static void gen_exception_return(DisasContext *s, TCGv_i32 pc)

{

    TCGv_i32 tmp;

    store_reg(s, 15, pc);

    tmp = load_cpu_field(spsr);

    gen_set_cpsr(tmp, CPSR_ERET_MASK);

    tcg_temp_free_i32(tmp);

    s->is_jmp = DISAS_JUMP;

}
