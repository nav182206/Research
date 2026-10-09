/* 
 * Benchmark Sample ID : devign_5747
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a8ab52fae7286d4e7eec9256a08b6ad0b1e39d6c
 */

static AVFrame *do_vmaf(AVFilterContext *ctx, AVFrame *main, const AVFrame *ref)

{

    LIBVMAFContext *s = ctx->priv;



    pthread_mutex_lock(&s->lock);



    while (s->frame_set != 0) {

        pthread_cond_wait(&s->cond, &s->lock);

    }



    av_frame_ref(s->gref, ref);

    av_frame_ref(s->gmain, main);



    s->frame_set = 1;



    pthread_cond_signal(&s->cond);

    pthread_mutex_unlock(&s->lock);



    return main;

}
