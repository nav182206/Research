/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7014
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=345e7072ab867ee1e56cbf857dbc93d37f168294
 */

int avfilter_graph_config(AVFilterGraph *graphctx, void *log_ctx)

{

    int ret;



    if ((ret = graph_check_validity(graphctx, log_ctx)))


    if ((ret = graph_insert_fifos(graphctx, log_ctx)) < 0)


    if ((ret = graph_config_formats(graphctx, log_ctx)))


    if ((ret = graph_config_links(graphctx, log_ctx)))




    if ((ret = graph_config_pointers(graphctx, log_ctx)))




    return 0;

}
