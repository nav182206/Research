/* 
 * Benchmark Sample ID : devign_191
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=23979dc5411befabe9049e37075b2b6320debc4e
 */

static inline void sync_jmpstate(DisasContext *dc)

{

    if (dc->jmp == JMP_DIRECT) {

            dc->jmp = JMP_INDIRECT;

            tcg_gen_movi_tl(env_btaken, 1);

            tcg_gen_movi_tl(env_btarget, dc->jmp_pc);

    }

}
