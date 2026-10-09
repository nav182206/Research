/* 
 * Benchmark Sample ID : devign_5081
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c7ded42d5dfc0124008b5b9b13a1a342324885ed
 */

static int activate(AVFilterContext *ctx)

{

    PreMultiplyContext *s = ctx->priv;



    if (s->inplace) {

        AVFrame *frame = NULL;

        AVFrame *out = NULL;

        int ret, status;

        int64_t pts;



        if ((ret = ff_inlink_consume_frame(ctx->inputs[0], &frame)) > 0) {

            if ((ret = filter_frame(ctx, &out, frame, frame)) < 0)

                return ret;

            av_frame_free(&frame);

            ret = ff_filter_frame(ctx->outputs[0], out);

        }

        if (ret < 0) {

            return ret;

        } else if (ff_inlink_acknowledge_status(ctx->inputs[0], &status, &pts)) {

            ff_outlink_set_status(ctx->outputs[0], status, pts);

            return 0;

        } else {

            if (ff_outlink_frame_wanted(ctx->outputs[0]))

                ff_inlink_request_frame(ctx->inputs[0]);

            return 0;

        }

    } else {

        return ff_framesync_activate(&s->fs);

    }

}
