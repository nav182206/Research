/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8129
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a4d18a3f54e5b0277234d8fcff65dff8516417a0
 */

static int lut2_config_output(AVFilterLink *outlink)

{

    AVFilterContext *ctx = outlink->src;

    LUT2Context *s = ctx->priv;

    AVFilterLink *srcx = ctx->inputs[0];

    AVFilterLink *srcy = ctx->inputs[1];

    FFFrameSyncIn *in;

    int ret;



    if (srcx->format != srcy->format) {

        av_log(ctx, AV_LOG_ERROR, "inputs must be of same pixel format\n");

        return AVERROR(EINVAL);

    }

    if (srcx->w                       != srcy->w ||

        srcx->h                       != srcy->h ||

        srcx->sample_aspect_ratio.num != srcy->sample_aspect_ratio.num ||

        srcx->sample_aspect_ratio.den != srcy->sample_aspect_ratio.den) {

        av_log(ctx, AV_LOG_ERROR, "First input link %s parameters "

               "(size %dx%d, SAR %d:%d) do not match the corresponding "

               "second input link %s parameters (%dx%d, SAR %d:%d)\n",

               ctx->input_pads[0].name, srcx->w, srcx->h,

               srcx->sample_aspect_ratio.num,

               srcx->sample_aspect_ratio.den,

               ctx->input_pads[1].name,

               srcy->w, srcy->h,

               srcy->sample_aspect_ratio.num,

               srcy->sample_aspect_ratio.den);

        return AVERROR(EINVAL);

    }



    outlink->w = srcx->w;

    outlink->h = srcx->h;

    outlink->time_base = srcx->time_base;

    outlink->sample_aspect_ratio = srcx->sample_aspect_ratio;

    outlink->frame_rate = srcx->frame_rate;



    if ((ret = ff_framesync2_init(&s->fs, ctx, 2)) < 0)

        return ret;



    in = s->fs.in;

    in[0].time_base = srcx->time_base;

    in[1].time_base = srcy->time_base;

    in[0].sync   = 1;

    in[0].before = EXT_STOP;

    in[0].after  = EXT_INFINITY;

    in[1].sync   = 1;

    in[1].before = EXT_STOP;

    in[1].after  = EXT_INFINITY;

    s->fs.opaque   = s;

    s->fs.on_event = process_frame;



    if ((ret = config_output(outlink)) < 0)

        return ret;



    return ff_framesync2_configure(&s->fs);

}
