/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7361
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6dc7dd7af45aa1e341b471fd054f85ae2747775b
 */

static av_cold int atrac1_decode_end(AVCodecContext * avctx) {

    AT1Ctx *q = avctx->priv_data;



    av_freep(&q->out_samples[0]);



    ff_mdct_end(&q->mdct_ctx[0]);

    ff_mdct_end(&q->mdct_ctx[1]);

    ff_mdct_end(&q->mdct_ctx[2]);

    return 0;

}
