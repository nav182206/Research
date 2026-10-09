/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5512
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a6b28c7b5104263344508df0f4bce97f22cfcaf
 */

static void gen_exception_internal_insn(DisasContext *s, int offset, int excp)

{

    gen_set_condexec(s);

    gen_set_pc_im(s, s->pc - offset);

    gen_exception_internal(excp);

    s->is_jmp = DISAS_JUMP;

}
