/* 
 * Benchmark Sample ID : devign_4582
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bec1631100323fac0900aea71043d5c4e22fc2fa
 */

static void tcg_out_brcond_i32(TCGContext *s, TCGCond cond, TCGReg arg1,

                               int32_t arg2, int const_arg2, int label)

{

    tcg_out_cmp(s, arg1, arg2, const_arg2);

    tcg_out_bpcc(s, tcg_cond_to_bcond[cond], BPCC_ICC | BPCC_PT, label);

    tcg_out_nop(s);

}
