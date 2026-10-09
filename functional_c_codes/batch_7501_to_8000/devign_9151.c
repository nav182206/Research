/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9151
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b199d29cd597a3518136d78860e172060b9e83d
 */

static av_cold int truemotion1_decode_init(AVCodecContext *avctx)

{

    TrueMotion1Context *s = avctx->priv_data;



    s->avctx = avctx;



    // FIXME: it may change ?

//    if (avctx->bits_per_sample == 24)

//        avctx->pix_fmt = AV_PIX_FMT_RGB24;

//    else

//        avctx->pix_fmt = AV_PIX_FMT_RGB555;



    s->frame.data[0] = NULL;



    /* there is a vertical predictor for each pixel in a line; each vertical

     * predictor is 0 to start with */

    av_fast_malloc(&s->vert_pred, &s->vert_pred_size, s->avctx->width * sizeof(unsigned int));



    return 0;

}
