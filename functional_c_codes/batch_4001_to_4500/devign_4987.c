/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4987
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bec1631100323fac0900aea71043d5c4e22fc2fa
 */

static void tcg_out_brcond32(TCGContext *s, TCGCond cond,

                             TCGArg arg1, TCGArg arg2, int const_arg2,

                             int label_index, int small)

{

    tcg_out_cmp(s, arg1, arg2, const_arg2, 0);

    tcg_out_jxx(s, tcg_cond_to_jcc[cond], label_index, small);

}
