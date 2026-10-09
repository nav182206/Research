/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7729
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f927c5b753f2ec1f037ad38cb55b4407dd7a9d79
 */

theora_gptopts(AVFormatContext *ctx, int idx, uint64_t gp, int64_t *dts)

{

    struct ogg *ogg = ctx->priv_data;

    struct ogg_stream *os = ogg->streams + idx;

    struct theora_params *thp = os->private;

    uint64_t iframe = gp >> thp->gpshift;

    uint64_t pframe = gp & thp->gpmask;



    if (thp->version < 0x030201)

        iframe++;



    if(!pframe)

        os->pflags |= AV_PKT_FLAG_KEY;



    if (dts)

        *dts = iframe + pframe;



    return iframe + pframe;

}
