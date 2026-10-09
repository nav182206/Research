/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_850
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5eafc8b46644764f8aef1b7b2ecae53ee8034822
 */

static void release_delayed_buffers(PerThreadContext *p)

{

    FrameThreadContext *fctx = p->parent;



    while (p->num_released_buffers > 0) {

        AVFrame *f = &p->released_buffers[--p->num_released_buffers];



        pthread_mutex_lock(&fctx->buffer_mutex);

        free_progress(f);

        f->thread_opaque = NULL;



        f->owner->release_buffer(f->owner, f);

        pthread_mutex_unlock(&fctx->buffer_mutex);

    }

}
