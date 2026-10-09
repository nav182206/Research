/* 
 * Benchmark Sample ID : devign_2580
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0fbc9bbbbb39b9a6f62d57f237052b64eefac578
 */

static int nppscale_resize(AVFilterContext *ctx, NPPScaleStageContext *stage,

                           AVFrame *out, AVFrame *in)

{

    NPPScaleContext *s = ctx->priv;

    NppStatus err;

    int i;



    for (i = 0; i < FF_ARRAY_ELEMS(in->data) && in->data[i]; i++) {

        int iw = stage->planes_in[i].width;

        int ih = stage->planes_in[i].height;

        int ow = stage->planes_out[i].width;

        int oh = stage->planes_out[i].height;



        err = nppiResizeSqrPixel_8u_C1R(in->data[i], (NppiSize){ iw, ih },

                                        in->linesize[i], (NppiRect){ 0, 0, iw, ih },

                                        out->data[i], out->linesize[i],

                                        (NppiRect){ 0, 0, ow, oh },

                                        (double)ow / iw, (double)oh / ih,

                                        0.0, 0.0, s->interp_algo);

        if (err != NPP_SUCCESS) {

            av_log(ctx, AV_LOG_ERROR, "NPP resize error: %d\n", err);

            return AVERROR_UNKNOWN;

        }

    }



    return 0;

}
