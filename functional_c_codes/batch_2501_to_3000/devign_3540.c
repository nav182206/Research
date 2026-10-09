/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3540
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=577bf808958d06497928c639efaa473bf8c5e099
 */

static inline void gen_lookup_tb(DisasContext *s)

{

    tcg_gen_movi_i32(cpu_R[15], s->pc & ~1);

    s->is_jmp = DISAS_UPDATE;

}
