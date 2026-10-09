/* 
 * Benchmark Sample ID : devign_1972
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=24ae353dfbe61019a86093a9c5cd15476aabef49
 */

static av_cold int xan_decode_init(AVCodecContext *avctx)

{

    XanContext *s = avctx->priv_data;



    s->avctx = avctx;

    s->frame_size = 0;



    if ((avctx->codec->id == CODEC_ID_XAN_WC3) &&

        (s->avctx->palctrl == NULL)) {

        av_log(avctx, AV_LOG_ERROR, "palette expected\n");

        return AVERROR(EINVAL);

    }



    avctx->pix_fmt = PIX_FMT_PAL8;



    s->buffer1_size = avctx->width * avctx->height;

    s->buffer1 = av_malloc(s->buffer1_size);

    if (!s->buffer1)

        return AVERROR(ENOMEM);

    s->buffer2_size = avctx->width * avctx->height;

    s->buffer2 = av_malloc(s->buffer2_size + 130);

    if (!s->buffer2) {

        av_freep(&s->buffer1);

        return AVERROR(ENOMEM);

    }



    return 0;

}
