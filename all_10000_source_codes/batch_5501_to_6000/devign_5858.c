/* 
 * Benchmark Sample ID : devign_5858
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6470abc740367cc881c181db866891f8dd1d342f
 */

static int load_apply_palette(FFFrameSync *fs)

{

    AVFilterContext *ctx = fs->parent;

    AVFilterLink *inlink = ctx->inputs[0];

    PaletteUseContext *s = ctx->priv;

    AVFrame *master, *second, *out;

    int ret;



    // writable for error diffusal dithering

    ret = ff_framesync_dualinput_get_writable(fs, &master, &second);

    if (ret < 0)

        return ret;

    if (!master || !second) {

        ret = AVERROR_BUG;

        goto error;

    }

    if (!s->palette_loaded) {

        load_palette(s, second);

    }

    out = apply_palette(inlink, master);

    return ff_filter_frame(ctx->outputs[0], out);



error:

    av_frame_free(&master);

    av_frame_free(&second);

    return ret;

}
