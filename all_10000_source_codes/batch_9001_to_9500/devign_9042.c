/* 
 * Benchmark Sample ID : devign_9042
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b164d66e35d349de414e2f0d7365a147aba8a620
 */

static void ape_unpack_mono(APEContext *ctx, int count)

{

    if (ctx->frameflags & APE_FRAMECODE_STEREO_SILENCE) {

        /* We are pure silence, so we're done. */

        av_log(ctx->avctx, AV_LOG_DEBUG, "pure silence mono\n");

        return;

    }



    entropy_decode(ctx, count, 0);

    ape_apply_filters(ctx, ctx->decoded[0], NULL, count);



    /* Now apply the predictor decoding */

    predictor_decode_mono(ctx, count);



    /* Pseudo-stereo - just copy left channel to right channel */

    if (ctx->channels == 2) {

        memcpy(ctx->decoded[1], ctx->decoded[0], count * sizeof(*ctx->decoded[1]));

    }

}
