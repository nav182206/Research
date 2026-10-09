/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4574
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static inline void tcg_out_rld(TCGContext *s, int op, TCGReg ra, TCGReg rs,

                               int sh, int mb)

{

    assert(TCG_TARGET_REG_BITS == 64);

    sh = SH(sh & 0x1f) | (((sh >> 5) & 1) << 1);

    mb = MB64((mb >> 5) | ((mb << 1) & 0x3f));

    tcg_out32(s, op | RA(ra) | RS(rs) | sh | mb);

}
