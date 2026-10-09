/* 
 * Benchmark Sample ID : devign_7268
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=78016694706776fbfe4be9533704be3180b31623
 */

static av_cold int vtenc_close(AVCodecContext *avctx)

{

    VTEncContext *vtctx = avctx->priv_data;



    if(!vtctx->session) return 0;



    VTCompressionSessionInvalidate(vtctx->session);

    pthread_cond_destroy(&vtctx->cv_sample_sent);

    pthread_mutex_destroy(&vtctx->lock);

    CFRelease(vtctx->session);

    vtctx->session = NULL;



    return 0;

}
