/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7776
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4c9080a7ef18ad71fb0a75c8d1c1803edd780edd
 */

static void default_end_frame(AVFilterLink *inlink)

{

    AVFilterLink *outlink = NULL;



    if (inlink->dst->nb_outputs)

        outlink = inlink->dst->outputs[0];



    if (outlink) {

        if (outlink->out_buf) {

            avfilter_unref_buffer(outlink->out_buf);

            outlink->out_buf = NULL;

        }

        ff_end_frame(outlink);

    }

}
