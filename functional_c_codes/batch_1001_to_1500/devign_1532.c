/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1532
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0058584580b87feb47898e60e4b80c7f425882ad
 */

static int _do_rematrixing(AC3DecodeContext *ctx, int start, int end)

{

    float tmp0, tmp1;



    while (start < end) {

        tmp0 = ctx->samples[start];

        tmp1 = (ctx->samples + 256)[start];

        ctx->samples[start] = tmp0 + tmp1;

        (ctx->samples + 256)[start] = tmp0 - tmp1;

        start++;

    }



    return 0;

}
