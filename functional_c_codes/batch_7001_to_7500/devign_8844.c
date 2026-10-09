/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8844
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eabb7b91b36b202b4dac2df2d59d698e3aff197a
 */

static void tcg_out_ri64(TCGContext *s, int const_arg, TCGArg arg)

{

    if (const_arg) {

        assert(const_arg == 1);

        tcg_out8(s, TCG_CONST);

        tcg_out64(s, arg);

    } else {

        tcg_out_r(s, arg);

    }

}
