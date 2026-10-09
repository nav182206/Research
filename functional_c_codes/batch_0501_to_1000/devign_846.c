/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_846
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca616b0f72c65b0ef5f9e1e6125698b15f50a26e
 */

static av_cold int init_buffers(SANMVideoContext *ctx)

{

    av_fast_padded_malloc(&ctx->frm0, &ctx->frm0_size, ctx->buf_size);

    av_fast_padded_malloc(&ctx->frm1, &ctx->frm1_size, ctx->buf_size);

    av_fast_padded_malloc(&ctx->frm2, &ctx->frm2_size, ctx->buf_size);

    if (!ctx->version)

        av_fast_padded_malloc(&ctx->stored_frame,

                              &ctx->stored_frame_size, ctx->buf_size);



    if (!ctx->frm0 || !ctx->frm1 || !ctx->frm2 ||

        (!ctx->stored_frame && !ctx->version)) {

        destroy_buffers(ctx);

        return AVERROR(ENOMEM);

    }



    return 0;

}
