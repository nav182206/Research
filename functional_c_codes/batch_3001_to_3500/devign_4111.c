/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4111
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fd5293d216316752fd34dcb29051e748f076e5fb
 */

static int start_frame(AVFilterLink *inlink, AVFilterBufferRef *picref)

{

    AVFilterContext *ctx = inlink->dst;

    TInterlaceContext *tinterlace = ctx->priv;



    avfilter_unref_buffer(tinterlace->cur);

    tinterlace->cur  = tinterlace->next;

    tinterlace->next = picref;


    return 0;

}
