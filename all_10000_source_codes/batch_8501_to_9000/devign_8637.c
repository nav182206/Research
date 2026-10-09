/* 
 * Benchmark Sample ID : devign_8637
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6fbb21d6858b9d0152f89e1b30ffe683a9d33948
 */

static int vsink_query_formats(AVFilterContext *ctx)

{

    BufferSinkContext *buf = ctx->priv;

    AVFilterFormats *formats = NULL;

    unsigned i;

    int ret;



    if (buf->pixel_fmts_size % sizeof(*buf->pixel_fmts)) {

        av_log(ctx, AV_LOG_ERROR, "Invalid size for format list\n");

        return AVERROR(EINVAL);

    }



    if (buf->pixel_fmts_size) {

        for (i = 0; i < NB_ITEMS(buf->pixel_fmts); i++)

            if ((ret = ff_add_format(&formats, buf->pixel_fmts[i])) < 0)

                return ret;

        ff_set_common_formats(ctx, formats);

    } else {

        ff_default_query_formats(ctx);

    }



    return 0;

}
