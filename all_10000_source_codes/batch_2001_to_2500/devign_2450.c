/* 
 * Benchmark Sample ID : devign_2450
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8b27f76bf8790536afccb96780b5feb9c65636be
 */

static av_cold int indeo3_decode_init(AVCodecContext *avctx)

{

    Indeo3DecodeContext *s = avctx->priv_data;



    s->avctx = avctx;

    s->width = avctx->width;

    s->height = avctx->height;

    avctx->pix_fmt = PIX_FMT_YUV410P;



    build_modpred(s);

    iv_alloc_frames(s);



    return 0;

}
