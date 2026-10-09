/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3100
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42a268c241183877192c376d03bd9b6d527407c7
 */

void tcg_gen_brcond_i32(TCGCond cond, TCGv_i32 arg1, TCGv_i32 arg2, int label)

{

    if (cond == TCG_COND_ALWAYS) {

        tcg_gen_br(label);

    } else if (cond != TCG_COND_NEVER) {

        tcg_gen_op4ii_i32(INDEX_op_brcond_i32, arg1, arg2, cond, label);

    }

}
