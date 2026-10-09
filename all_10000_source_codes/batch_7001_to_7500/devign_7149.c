/* 
 * Benchmark Sample ID : devign_7149
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6a9b110d54b885dbb29872a142cc4d2a402fada8
 */

static ExitStatus gen_fbcond(DisasContext *ctx, TCGCond cond, int ra,

                             int32_t disp)

{

    TCGv cmp_tmp = tcg_temp_new();

    gen_fold_mzero(cond, cmp_tmp, load_fpr(ctx, ra));

    return gen_bcond_internal(ctx, cond, cmp_tmp, disp);

}
