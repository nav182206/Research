/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2600
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b199d29cd597a3518136d78860e172060b9e83d
 */

static av_cold int qtrle_decode_init(AVCodecContext *avctx)

{

    QtrleContext *s = avctx->priv_data;



    s->avctx = avctx;

    switch (avctx->bits_per_coded_sample) {

    case 1:

    case 33:

        avctx->pix_fmt = AV_PIX_FMT_MONOWHITE;

        break;



    case 2:

    case 4:

    case 8:

    case 34:

    case 36:

    case 40:

        avctx->pix_fmt = AV_PIX_FMT_PAL8;

        break;



    case 16:

        avctx->pix_fmt = AV_PIX_FMT_RGB555;

        break;



    case 24:

        avctx->pix_fmt = AV_PIX_FMT_RGB24;

        break;



    case 32:

        avctx->pix_fmt = AV_PIX_FMT_RGB32;

        break;



    default:

        av_log (avctx, AV_LOG_ERROR, "Unsupported colorspace: %d bits/sample?\n",

            avctx->bits_per_coded_sample);

        return AVERROR_INVALIDDATA;

    }



    s->frame.data[0] = NULL;



    return 0;

}
