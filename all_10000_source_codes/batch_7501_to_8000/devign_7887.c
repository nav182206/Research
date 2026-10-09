/* 
 * Benchmark Sample ID : devign_7887
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dcc39ee10e82833ce24aa57926c00ffeb1948198
 */

static enum AVPixelFormat mpeg_get_pixelformat(AVCodecContext *avctx)

{

    Mpeg1Context *s1  = avctx->priv_data;

    MpegEncContext *s = &s1->mpeg_enc_ctx;

    const enum AVPixelFormat *pix_fmts;



#if FF_API_XVMC

FF_DISABLE_DEPRECATION_WARNINGS

    if (avctx->xvmc_acceleration)

        return ff_get_format(avctx, pixfmt_xvmc_mpg2_420);

FF_ENABLE_DEPRECATION_WARNINGS

#endif /* FF_API_XVMC */



    if (s->chroma_format < 2)

        pix_fmts = mpeg12_hwaccel_pixfmt_list_420;

    else if (s->chroma_format == 2)

        pix_fmts = mpeg12_pixfmt_list_422;

    else

        pix_fmts = mpeg12_pixfmt_list_444;



    return ff_get_format(avctx, pix_fmts);

}
