/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4721
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9bf4523e40148fdd27064ab570952bd8c4d1016e
 */

static int vp8_lossy_decode_frame(AVCodecContext *avctx, AVFrame *p,

                                  int *got_frame, uint8_t *data_start,

                                  unsigned int data_size)

{

    WebPContext *s = avctx->priv_data;

    AVPacket pkt;

    int ret;



    if (!s->initialized) {

        ff_vp8_decode_init(avctx);

        s->initialized = 1;

        if (s->has_alpha)

            avctx->pix_fmt = AV_PIX_FMT_YUVA420P;

    }

    s->lossless = 0;



    if (data_size > INT_MAX) {

        av_log(avctx, AV_LOG_ERROR, "unsupported chunk size\n");

        return AVERROR_PATCHWELCOME;

    }



    av_init_packet(&pkt);

    pkt.data = data_start;

    pkt.size = data_size;



    ret = ff_vp8_decode_frame(avctx, p, got_frame, &pkt);



    if (s->has_alpha) {

        ret = vp8_lossy_decode_alpha(avctx, p, s->alpha_data,

                                     s->alpha_data_size);



    }


}
