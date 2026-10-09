/* 
 * Benchmark Sample ID : devign_9053
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static inline void tcg_out_adr(TCGContext *s, TCGReg rd, void *target)

{

    ptrdiff_t offset = tcg_pcrel_diff(s, target);

    assert(offset == sextract64(offset, 0, 21));

    tcg_out_insn(s, 3406, ADR, rd, offset);

}
