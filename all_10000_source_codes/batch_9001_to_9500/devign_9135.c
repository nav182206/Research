/* 
 * Benchmark Sample ID : devign_9135
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3511d4fc9784d5fbb024dce68ca7a0d7fdd74663
 */

static void slice_thread_park_workers(ThreadContext *c)

{

    pthread_cond_wait(&c->last_job_cond, &c->current_job_lock);

    pthread_mutex_unlock(&c->current_job_lock);

}
