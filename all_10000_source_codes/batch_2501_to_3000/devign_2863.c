/* 
 * Benchmark Sample ID : devign_2863
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=771c86c13d7133035e53f7aeb14407ae5dca6453
 */

av_cold void ff_psy_preprocess_end(struct FFPsyPreprocessContext *ctx)

{

    int i;

    ff_iir_filter_free_coeffs(ctx->fcoeffs);

    if (ctx->fstate)

        for (i = 0; i < ctx->avctx->channels; i++)

            ff_iir_filter_free_state(ctx->fstate[i]);

    av_freep(&ctx->fstate);


}
