/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2967
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=577bf808958d06497928c639efaa473bf8c5e099
 */

static inline void gen_bx(DisasContext *s, TCGv_i32 var)

{

    s->is_jmp = DISAS_UPDATE;

    tcg_gen_andi_i32(cpu_R[15], var, ~1);

    tcg_gen_andi_i32(var, var, 1);

    store_cpu_field(var, thumb);

}
