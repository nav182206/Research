/* 
 * Benchmark Sample ID : devign_8664
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc40c056d01a95b0a57950d4d8aec9e86060c6b6
 */

static av_cold int adx_encode_init(AVCodecContext *avctx)

{

    ADXContext *c = avctx->priv_data;



    if (avctx->channels > 2)

        return -1;

    avctx->frame_size = 32;



    avctx->coded_frame = avcodec_alloc_frame();

    avctx->coded_frame->key_frame = 1;



    /* the cutoff can be adjusted, but this seems to work pretty well */

    c->cutoff = 500;

    ff_adx_calculate_coeffs(c->cutoff, avctx->sample_rate, COEFF_BITS, c->coeff);



    return 0;

}
