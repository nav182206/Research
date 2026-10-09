/* 
 * Benchmark Sample ID : devign_6110
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b8664c929437d6d079e16979c496a2db40cf2324
 */

av_cold int ff_vp8_decode_init(AVCodecContext *avctx)

{

    VP8Context *s = avctx->priv_data;

    int ret;



    s->avctx = avctx;

    avctx->pix_fmt = AV_PIX_FMT_YUV420P;

    avctx->internal->allocate_progress = 1;



    ff_videodsp_init(&s->vdsp, 8);

    ff_h264_pred_init(&s->hpc, AV_CODEC_ID_VP8, 8, 1);

    ff_vp8dsp_init(&s->vp8dsp);



    if ((ret = vp8_init_frames(s)) < 0) {

        ff_vp8_decode_free(avctx);

        return ret;

    }



    return 0;

}
