/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5175
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=06bf6d3bc04979bd39ecdc7311d0daf8aee7e10f
 */

static void draw_slice(AVFilterLink *inlink, int y, int h, int slice_dir)

{

    AVFilterContext *ctx = inlink->dst;

    AVFilterLink *outlink = ctx->outputs[0];

    AVFilterBufferRef *outpicref = outlink->out_buf;

    OverlayContext *over = ctx->priv;



    if (over->overpicref &&

        !(over->x >= outpicref->video->w || over->y >= outpicref->video->h ||

          y+h < over->y || y >= over->y + over->overpicref->video->h)) {

        blend_slice(ctx, outpicref, over->overpicref, over->x, over->y,

                    over->overpicref->video->w, over->overpicref->video->h,

                    y, outpicref->video->w, h);

    }

    avfilter_draw_slice(outlink, y, h, slice_dir);

}
