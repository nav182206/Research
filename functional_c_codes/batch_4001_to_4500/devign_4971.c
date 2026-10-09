/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4971
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=255be0734d9293309b42d8029d2004ec3732c8bc
 */

static int filter_frame(AVFilterLink *inlink, AVFilterBufferRef *buf)

{

    AVFilterContext *ctx = inlink->dst;

    AlphaMergeContext *merge = ctx->priv;



    int is_alpha = (inlink == ctx->inputs[1]);

    struct FFBufQueue *queue =

        (is_alpha ? &merge->queue_alpha : &merge->queue_main);

    ff_bufqueue_add(ctx, queue, buf);



    while (1) {

        AVFilterBufferRef *main_buf, *alpha_buf;



        if (!ff_bufqueue_peek(&merge->queue_main, 0) ||

            !ff_bufqueue_peek(&merge->queue_alpha, 0)) break;



        main_buf = ff_bufqueue_get(&merge->queue_main);

        alpha_buf = ff_bufqueue_get(&merge->queue_alpha);



        merge->frame_requested = 0;

        draw_frame(ctx, main_buf, alpha_buf);

        ff_filter_frame(ctx->outputs[0], avfilter_ref_buffer(main_buf, ~0));

        avfilter_unref_buffer(alpha_buf);

    }

    return 0;

}
