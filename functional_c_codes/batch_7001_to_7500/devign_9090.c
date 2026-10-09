/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9090
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7f6613cedc59fa849105668ae971dc31004bca1c
 */

static void gen_store_fpr32h(TCGv_i32 t, int reg)

{

    TCGv_i64 t64 = tcg_temp_new_i64();

    tcg_gen_extu_i32_i64(t64, t);

    tcg_gen_deposit_i64(fpu_f64[reg], fpu_f64[reg], t64, 32, 32);

    tcg_temp_free_i64(t64);

}
