/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3042
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=69b8d83ecf5f6deb9ad94bdaa816aa205430d3e9
 */

static void end_frame(AVFilterLink *inlink)

{

    GradFunContext *gf = inlink->dst->priv;

    AVFilterBufferRef *inpic = inlink->cur_buf;

    AVFilterLink *outlink = inlink->dst->outputs[0];

    AVFilterBufferRef *outpic = outlink->out_buf;

    int p;



    for (p = 0; p < 4 && inpic->data[p]; p++) {

        int w = inlink->w;

        int h = inlink->h;

        int r = gf->radius;

        if (p) {

            w = gf->chroma_w;

            h = gf->chroma_h;

            r = gf->chroma_r;

        }



        if (FFMIN(w, h) > 2 * r)

            filter(gf, outpic->data[p], inpic->data[p], w, h, outpic->linesize[p], inpic->linesize[p], r);

        else if (outpic->data[p] != inpic->data[p])

            av_image_copy_plane(outpic->data[p], outpic->linesize[p], inpic->data[p], inpic->linesize[p], w, h);

    }



    avfilter_draw_slice(outlink, 0, inlink->h, 1);

    avfilter_end_frame(outlink);

    avfilter_unref_buffer(inpic);

    avfilter_unref_buffer(outpic);

}
