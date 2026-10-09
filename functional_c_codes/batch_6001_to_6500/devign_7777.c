/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7777
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

static inline void gen_op_addq_ESP_im(int32_t val)

{

    tcg_gen_ld_tl(cpu_tmp0, cpu_env, offsetof(CPUState, regs[R_ESP]));

    tcg_gen_addi_tl(cpu_tmp0, cpu_tmp0, val);

    tcg_gen_st_tl(cpu_tmp0, cpu_env, offsetof(CPUState, regs[R_ESP]));

}
