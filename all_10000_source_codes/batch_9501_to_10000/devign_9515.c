/* 
 * Benchmark Sample ID : devign_9515
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b164d66e35d349de414e2f0d7365a147aba8a620
 */

static void entropy_decode(APEContext *ctx, int blockstodecode, int stereo)

{

    int32_t *decoded0 = ctx->decoded[0];

    int32_t *decoded1 = ctx->decoded[1];



    while (blockstodecode--) {

        *decoded0++ = ape_decode_value(ctx, &ctx->riceY);

        if (stereo)

            *decoded1++ = ape_decode_value(ctx, &ctx->riceX);

    }

}
