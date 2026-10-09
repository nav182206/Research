/* 
 * Benchmark Sample ID : devign_8969
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42a268c241183877192c376d03bd9b6d527407c7
 */

void tcg_gen_brcondi_i64(TCGCond cond, TCGv_i64 arg1, int64_t arg2, int label)

{

    if (cond == TCG_COND_ALWAYS) {

        tcg_gen_br(label);

    } else if (cond != TCG_COND_NEVER) {

        TCGv_i64 t0 = tcg_const_i64(arg2);

        tcg_gen_brcond_i64(cond, arg1, t0, label);

        tcg_temp_free_i64(t0);

    }

}
