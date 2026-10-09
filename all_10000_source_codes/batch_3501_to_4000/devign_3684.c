/* 
 * Benchmark Sample ID : devign_3684
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6f3d2fb18bb6225c27e22a95846c42f2093dc3b7
 */

static int start_frame(AVFilterLink *inlink, AVFilterBufferRef *picref)

{

    AVFilterContext *ctx  = inlink->dst;

    TileContext *tile    = ctx->priv;

    AVFilterLink *outlink = ctx->outputs[0];



    if (tile->current)

        return 0;

    outlink->out_buf = ff_get_video_buffer(outlink, AV_PERM_WRITE,

                                                 outlink->w, outlink->h);

    avfilter_copy_buffer_ref_props(outlink->out_buf, picref);

    outlink->out_buf->video->w = outlink->w;

    outlink->out_buf->video->h = outlink->h;



    /* fill surface once for margin/padding */

    if (tile->margin || tile->padding)

        ff_fill_rectangle(&tile->draw, &tile->blank,

                          outlink->out_buf->data, outlink->out_buf->linesize,

                          0, 0, outlink->w, outlink->h);

    return 0;

}
