/* 
 * Benchmark Sample ID : devign_6141
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bd5c860fdbc33d19d2ff0f6d1f06de07c17560dd
 */

void av_thread_message_queue_set_err_recv(AVThreadMessageQueue *mq,

                                          int err)

{

#if HAVE_THREADS

    pthread_mutex_lock(&mq->lock);

    mq->err_recv = err;

    pthread_cond_broadcast(&mq->cond);

    pthread_mutex_unlock(&mq->lock);

#endif /* HAVE_THREADS */

}
