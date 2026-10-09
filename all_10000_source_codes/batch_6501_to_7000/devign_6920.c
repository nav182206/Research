/* 
 * Benchmark Sample ID : devign_6920
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5eb901cfec4a1bca4d961c6eb6889a91a87031ca
 */

static int request_frame(AVFilterLink *outlink)

{

    AVFilterBufferRef *outpicref;

    MovieContext *movie = outlink->src->priv;

    int ret;



    if (movie->is_done)

        return AVERROR_EOF;

    if ((ret = movie_get_frame(outlink)) < 0)

        return ret;



    outpicref = avfilter_ref_buffer(movie->picref, ~0);

    avfilter_start_frame(outlink, outpicref);

    avfilter_draw_slice(outlink, 0, outlink->h, 1);

    avfilter_end_frame(outlink);





    return 0;

}
