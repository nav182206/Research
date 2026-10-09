/* 
 * Benchmark Sample ID : devign_9643
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=18c6bd098baba1ace8fea946e4bc0c60098f49d4
 */

static void start_frame(AVFilterLink *inlink, AVFilterBufferRef *picref)

{

    AVFilterContext *ctx = inlink->dst;

    TInterlaceContext *tinterlace = ctx->priv;



    if (tinterlace->cur)

        avfilter_unref_buffer(tinterlace->cur);

    tinterlace->cur  = tinterlace->next;

    tinterlace->next = picref;

}
