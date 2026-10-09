/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5050
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static inline void gen_bx_im(DisasContext *s, uint32_t addr)

{

    TCGv tmp;



    s->is_jmp = DISAS_UPDATE;

    if (s->thumb != (addr & 1)) {

        tmp = new_tmp();

        tcg_gen_movi_i32(tmp, addr & 1);

        tcg_gen_st_i32(tmp, cpu_env, offsetof(CPUState, thumb));

        dead_tmp(tmp);

    }

    tcg_gen_movi_i32(cpu_R[15], addr & ~1);

}
