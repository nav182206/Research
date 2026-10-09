/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4592
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6f3d2fb18bb6225c27e22a95846c42f2093dc3b7
 */

static int draw_slice(AVFilterLink *inlink, int y, int h, int slice_dir)

{

    AVFilterContext *ctx  = inlink->dst;

    TileContext *tile    = ctx->priv;

    AVFilterLink *outlink = ctx->outputs[0];

    unsigned x0, y0;



    get_current_tile_pos(ctx, &x0, &y0);

    ff_copy_rectangle2(&tile->draw,

                       outlink->out_buf->data, outlink->out_buf->linesize,

                       inlink ->cur_buf->data, inlink ->cur_buf->linesize,

                       x0, y0 + y, 0, y, inlink->cur_buf->video->w, h);

    /* TODO if tile->w == 1 && slice_dir is always 1, we could draw_slice

     * immediately. */

    return 0;

}
