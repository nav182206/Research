/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6955
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=386aee6864c5cfc438785d2421b2f056450da014
 */

static av_cold int vsink_init(AVFilterContext *ctx, const char *args, void *opaque)

{

    BufferSinkContext *buf = ctx->priv;

    av_unused AVBufferSinkParams *params;



    if (!opaque) {

        av_log(ctx, AV_LOG_ERROR,

               "No opaque field provided\n");

        return AVERROR(EINVAL);

    } else {

#if FF_API_OLD_VSINK_API

        buf->pixel_fmts = (const enum PixelFormat *)opaque;

#else

        params = (AVBufferSinkParams *)opaque;

        buf->pixel_fmts = params->pixel_fmts;

#endif

    }



    return common_init(ctx);

}
