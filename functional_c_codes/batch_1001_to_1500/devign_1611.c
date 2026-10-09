/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1611
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fd7a7e11b94b12259c6f1e375da15298cbc37e83
 */

static int vsink_query_formats(AVFilterContext *ctx)

{

    BufferSinkContext *buf = ctx->priv;

    AVFilterFormats *formats = NULL;

    unsigned i;

    int ret;



    CHECK_LIST_SIZE(pixel_fmts)

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
