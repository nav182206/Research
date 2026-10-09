/* 
 * Benchmark Sample ID : devign_6765
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=45f4bf94afb8b70d99fb7b5760fd65f5c3ad8b88
 */

static av_cold int xma_decode_init(AVCodecContext *avctx)

{

    XMADecodeCtx *s = avctx->priv_data;

    int i, ret;



    for (i = 0; i < avctx->channels / 2; i++) {

        ret = decode_init(&s->xma[i], avctx);

        s->frames[i] = av_frame_alloc();

        if (!s->frames[i])

            return AVERROR(ENOMEM);

        s->frames[i]->nb_samples = 512;

        if ((ret = ff_get_buffer(avctx, s->frames[i], 0)) < 0) {

            return AVERROR(ENOMEM);

        }



    }



    return ret;

}
