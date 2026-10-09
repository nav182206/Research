/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4367
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1afab338575810acc5eb75c17c4adfb73504de10
 */

static void end_frame(AVFilterLink *link)

{

    CropContext *crop = link->dst->priv;



    crop->var_values[N] += 1.0;

    avfilter_unref_buffer(link->cur_buf);

    avfilter_end_frame(link->dst->outputs[0]);

}
