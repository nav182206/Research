/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9571
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static inline void tcg_out_goto(TCGContext *s, tcg_insn_unit *target)

{

    ptrdiff_t offset = target - s->code_ptr;

    assert(offset == sextract64(offset, 0, 26));

    tcg_out_insn(s, 3206, B, offset);

}
