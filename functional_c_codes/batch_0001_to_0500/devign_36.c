/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_36
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e706a2afb09009bad49c4b12aaa997acf4491b1
 */

static av_cold int split_init(AVFilterContext *ctx)

{

    SplitContext *s = ctx->priv;

    int i;



    for (i = 0; i < s->nb_outputs; i++) {

        char name[32];

        AVFilterPad pad = { 0 };



        snprintf(name, sizeof(name), "output%d", i);

        pad.type = ctx->filter->inputs[0].type;

        pad.name = av_strdup(name);

        if (!pad.name)

            return AVERROR(ENOMEM);



        ff_insert_outpad(ctx, i, &pad);

    }



    return 0;

}
