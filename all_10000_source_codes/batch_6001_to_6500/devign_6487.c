/* 
 * Benchmark Sample ID : devign_6487
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static void tcg_out_r(TCGContext *s, TCGArg t0)

{

    assert(t0 < TCG_TARGET_NB_REGS);

    tcg_out8(s, t0);

}
