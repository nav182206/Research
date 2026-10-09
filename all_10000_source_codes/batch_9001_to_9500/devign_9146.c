/* 
 * Benchmark Sample ID : devign_9146
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3748b2b8e8bcedba2de7fe826c4094169a885840
 */

int avfilter_graph_add_filter(AVFilterGraph *graph, AVFilterContext *filter)

{

    graph->filters = av_realloc(graph->filters,

                                sizeof(AVFilterContext*) * ++graph->filter_count);



    if (!graph->filters)

        return AVERROR(ENOMEM);



    graph->filters[graph->filter_count - 1] = filter;



    return 0;

}
