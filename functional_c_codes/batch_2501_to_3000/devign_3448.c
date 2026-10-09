/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3448
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fdbd924b84e85ac5c80f01ee059ed5c81d3cc205
 */

int ff_rv34_decode_init_thread_copy(AVCodecContext *avctx)

{

    int err;

    RV34DecContext *r = avctx->priv_data;



    r->s.avctx = avctx;



    if (avctx->internal->is_copy) {

        r->tmp_b_block_base = NULL;

        if ((err = ff_MPV_common_init(&r->s)) < 0)

            return err;

        if ((err = rv34_decoder_alloc(r)) < 0)

            return err;

    }



    return 0;

}
