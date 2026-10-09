/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2602
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a2e2fc34aaeb0c092a9fd08d18bd5af7d240f1d
 */

inline static int push_frame(AVFilterLink *outlink)

{

    AVFilterContext *ctx = outlink->src;

    AVFilterLink *inlink = ctx->inputs[0];

    ShowWavesContext *showwaves = outlink->src->priv;

    int nb_channels = inlink->channels;

    int ret, i;



    if ((ret = ff_filter_frame(outlink, showwaves->outpicref)) >= 0)

        showwaves->req_fullfilled = 1;

    showwaves->outpicref = NULL;

    showwaves->buf_idx = 0;

    for (i = 0; i < nb_channels; i++)

        showwaves->buf_idy[i] = 0;

    return ret;

}
