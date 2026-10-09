/* 
 * Benchmark Sample ID : devign_2951
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a8ab52fae7286d4e7eec9256a08b6ad0b1e39d6c
 */

static int config_output(AVFilterLink *outlink)

{

    AVFilterContext *ctx = outlink->src;

    LIBVMAFContext *s = ctx->priv;

    AVFilterLink *mainlink = ctx->inputs[0];

    int ret;



    outlink->w = mainlink->w;

    outlink->h = mainlink->h;

    outlink->time_base = mainlink->time_base;

    outlink->sample_aspect_ratio = mainlink->sample_aspect_ratio;

    outlink->frame_rate = mainlink->frame_rate;

    if ((ret = ff_dualinput_init(ctx, &s->dinput)) < 0)

        return ret;



    return 0;

}
