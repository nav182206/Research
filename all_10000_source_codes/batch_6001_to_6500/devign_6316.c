/* 
 * Benchmark Sample ID : devign_6316
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static void tcg_out_ext8s(TCGContext *s, int dest, int src, int rexw)

{

    /* movsbl */

    assert(src < 4 || TCG_TARGET_REG_BITS == 64);

    tcg_out_modrm(s, OPC_MOVSBL + P_REXB_RM + rexw, dest, src);

}
