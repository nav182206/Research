/* 
 * Benchmark Sample ID : devign_3844
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b505f15b1530d72682b3314e84936f80fe6e43b2
 */

void ff_slice_thread_free(AVCodecContext *avctx)

{

    SliceThreadContext *c = avctx->internal->thread_ctx;

    int i;



    pthread_mutex_lock(&c->current_job_lock);

    c->done = 1;

    pthread_cond_broadcast(&c->current_job_cond);

    for (i = 0; i < c->thread_count; i++)

        pthread_cond_broadcast(&c->progress_cond[i]);

    pthread_mutex_unlock(&c->current_job_lock);



    for (i=0; i<avctx->thread_count; i++)

         pthread_join(c->workers[i], NULL);



    for (i = 0; i < c->thread_count; i++) {

        pthread_mutex_destroy(&c->progress_mutex[i]);

        pthread_cond_destroy(&c->progress_cond[i]);

    }



    pthread_mutex_destroy(&c->current_job_lock);

    pthread_cond_destroy(&c->current_job_cond);

    pthread_cond_destroy(&c->last_job_cond);



    av_freep(&c->entries);

    av_freep(&c->progress_mutex);

    av_freep(&c->progress_cond);



    av_freep(&c->workers);

    av_freep(&avctx->internal->thread_ctx);

}
