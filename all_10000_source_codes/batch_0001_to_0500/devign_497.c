/* 
 * Benchmark Sample ID : devign_497
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=39bbdebb1ed8eb9c9b0cd6db85afde6ba89d86e4
 */

static void destroy_buffers(SANMVideoContext *ctx)

{

    av_freep(&ctx->frm0);

    av_freep(&ctx->frm1);

    av_freep(&ctx->frm2);

    av_freep(&ctx->stored_frame);

    av_freep(&ctx->rle_buf);

    ctx->frm0_size =

    ctx->frm1_size =

    ctx->frm2_size = 0;


}
