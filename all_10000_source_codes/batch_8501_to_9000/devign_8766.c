/* 
 * Benchmark Sample ID : devign_8766
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b199d29cd597a3518136d78860e172060b9e83d
 */

static av_cold int msvideo1_decode_init(AVCodecContext *avctx)

{

    Msvideo1Context *s = avctx->priv_data;



    s->avctx = avctx;



    /* figure out the colorspace based on the presence of a palette */

    if (s->avctx->bits_per_coded_sample == 8) {

        s->mode_8bit = 1;

        avctx->pix_fmt = AV_PIX_FMT_PAL8;

    } else {

        s->mode_8bit = 0;

        avctx->pix_fmt = AV_PIX_FMT_RGB555;

    }



    s->frame.data[0] = NULL;



    return 0;

}
