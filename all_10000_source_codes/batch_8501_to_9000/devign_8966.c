/* 
 * Benchmark Sample ID : devign_8966
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a6b28c7b5104263344508df0f4bce97f22cfcaf
 */

static void gen_exception_insn(DisasContext *s, int offset, int excp,

                               int syn, uint32_t target_el)

{

    gen_set_condexec(s);

    gen_set_pc_im(s, s->pc - offset);

    gen_exception(excp, syn, target_el);

    s->is_jmp = DISAS_JUMP;

}
