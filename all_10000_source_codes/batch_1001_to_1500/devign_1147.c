/* 
 * Benchmark Sample ID : devign_1147
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=709628aa71f24520553eb10b0cf6d56784e6c3ec
 */

static void process_frame(AVFilterLink *inlink, AVFilterBufferRef *buf)

{

    AVFilterContext *ctx  = inlink->dst;

    ConcatContext *cat    = ctx->priv;

    unsigned in_no = FF_INLINK_IDX(inlink);



    if (in_no < cat->cur_idx) {

        av_log(ctx, AV_LOG_ERROR, "Frame after EOF on input %s\n",

               ctx->input_pads[in_no].name);

        avfilter_unref_buffer(buf);

    } if (in_no >= cat->cur_idx + ctx->nb_outputs) {

        ff_bufqueue_add(ctx, &cat->in[in_no].queue, buf);

    } else {

        push_frame(ctx, in_no, buf);

    }

}
