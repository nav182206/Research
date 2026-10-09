/* 
 * Benchmark Sample ID : devign_6810
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b199d29cd597a3518136d78860e172060b9e83d
 */

static av_cold int msrle_decode_init(AVCodecContext *avctx)

{

    MsrleContext *s = avctx->priv_data;



    s->avctx = avctx;



    switch (avctx->bits_per_coded_sample) {

    case 4:

    case 8:

        avctx->pix_fmt = AV_PIX_FMT_PAL8;

        break;

    case 24:

        avctx->pix_fmt = AV_PIX_FMT_BGR24;

        break;

    default:

        av_log(avctx, AV_LOG_ERROR, "unsupported bits per sample\n");

        return AVERROR_INVALIDDATA;

    }



    s->frame.data[0] = NULL;



    return 0;

}
