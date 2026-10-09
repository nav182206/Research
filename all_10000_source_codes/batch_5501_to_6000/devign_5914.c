/* 
 * Benchmark Sample ID : devign_5914
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void store_reg(DisasContext *s, int reg, TCGv var)

{

    if (reg == 15) {

        tcg_gen_andi_i32(var, var, ~1);

        s->is_jmp = DISAS_JUMP;

    }

    tcg_gen_mov_i32(cpu_R[reg], var);

    dead_tmp(var);

}
