/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7047
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=937cfebd72d30e617591c666ea4854a3898a64b2
 */

static av_cold void uninit(AVFilterContext *ctx)

{

    EvalContext *eval = ctx->priv;

    int i;



    for (i = 0; i < 8; i++) {

        av_expr_free(eval->expr[i]);

        eval->expr[i] = NULL;

    }

}
