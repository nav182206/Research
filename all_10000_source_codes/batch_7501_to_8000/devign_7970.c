/* 
 * Benchmark Sample ID : devign_7970
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b5eab66e9fe6c93056e414b0b4a70a34948843e1
 */

void avfilter_default_start_frame(AVFilterLink *link, AVFilterPicRef *picref)

{

    AVFilterLink *out = NULL;



    if(link->dst->output_count)

        out = link->dst->outputs[0];



    if(out) {

        out->outpic      = avfilter_get_video_buffer(out, AV_PERM_WRITE, link->w, link->h);

        out->outpic->pts = picref->pts;

        avfilter_start_frame(out, avfilter_ref_pic(out->outpic, ~0));

    }

}
