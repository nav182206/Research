/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4985
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ed1c83508ec920bfef773e3aa3ac1764a65826ec
 */

static int request_frame(AVFilterLink *outlink)

{

    AVFilterContext *ctx = outlink->src;

    TrimContext       *s = ctx->priv;

    int ret;



    s->got_output = 0;

    while (!s->got_output) {

        if (s->eof)

            return AVERROR_EOF;



        ret = ff_request_frame(ctx->inputs[0]);

        if (ret < 0)

            return ret;

    }



    return 0;

}
