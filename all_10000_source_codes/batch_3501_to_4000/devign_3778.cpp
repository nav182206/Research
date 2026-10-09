/* 
 * Benchmark Sample ID : devign_3778
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=63736fe48c30c5db313c3a25d1462ad31b2a1671
 */

int ff_avfilter_graph_config_formats(AVFilterGraph *graph, AVClass *log_ctx)

{

    int ret;



    /* find supported formats from sub-filters, and merge along links */

    if ((ret = query_formats(graph, log_ctx)) < 0)

        return ret;



    /* Once everything is merged, it's possible that we'll still have

     * multiple valid media format choices. We pick the first one. */

    pick_formats(graph);



    return 0;

}
