/* 
 * Benchmark Sample ID : devign_2420
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d371c3c2e2830d9783465ecfe1ab7d93351083b7
 */

static int config_input_props(AVFilterLink *inlink)

{

    AVFilterContext *ctx = inlink->dst;

    Frei0rContext *s = ctx->priv;





    if (!(s->instance = s->construct(inlink->w, inlink->h))) {

        av_log(ctx, AV_LOG_ERROR, "Impossible to load frei0r instance");

        return AVERROR(EINVAL);

    }



    return set_params(ctx, s->params);

}
