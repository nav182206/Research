/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4785
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=331fae80a1fb9b027442047fb564c02c6c41e70b
 */

static av_cold int mss1_decode_init(AVCodecContext *avctx)

{

    MSS1Context * const c = avctx->priv_data;

    int ret;



    c->ctx.avctx       = avctx;



    c->pic = av_frame_alloc();

    if (!c->pic)

        return AVERROR(ENOMEM);



    ret = ff_mss12_decode_init(&c->ctx, 0, &c->sc, NULL);





    avctx->pix_fmt = AV_PIX_FMT_PAL8;



    return ret;

}
