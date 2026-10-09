/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6074
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static void tcg_out_insn_3405(TCGContext *s, AArch64Insn insn, TCGType ext,

                              TCGReg rd, uint16_t half, unsigned shift)

{

    assert((shift & ~0x30) == 0);

    tcg_out32(s, insn | ext << 31 | shift << (21 - 4) | half << 5 | rd);

}
