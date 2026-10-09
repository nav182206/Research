/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7031
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=daa7a1d4431b6acf1f93c4a98b3de123abf4ca18
 */

static av_always_inline void thread_park_workers(ThreadContext *c, int thread_count)

{

    while (c->current_job != thread_count + c->job_count)

        pthread_cond_wait(&c->last_job_cond, &c->current_job_lock);

    pthread_mutex_unlock(&c->current_job_lock);

}
