/* 
 * Benchmark Sample ID : devign_5367
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e9b060e4f0c24d2689bebd7fc03e52d75da25b2
 */

static av_cold int png_dec_init(AVCodecContext *avctx)

{

    PNGDecContext *s = avctx->priv_data;



    s->avctx = avctx;

    s->previous_picture.f = av_frame_alloc();

    s->last_picture.f = av_frame_alloc();

    s->picture.f = av_frame_alloc();

    if (!s->previous_picture.f || !s->last_picture.f || !s->picture.f)

        return AVERROR(ENOMEM);



    if (!avctx->internal->is_copy) {

        avctx->internal->allocate_progress = 1;

        ff_pngdsp_init(&s->dsp);

    }



    return 0;

}
