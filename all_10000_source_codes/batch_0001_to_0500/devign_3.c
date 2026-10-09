/* 
 * Benchmark Sample ID : devign_3
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5d5de3eba4c7890c2e8077f5b4ae569671d11cf8
 */

static void v4l2_free_buffer(void *opaque, uint8_t *unused)

{

    V4L2Buffer* avbuf = opaque;

    V4L2m2mContext *s = buf_to_m2mctx(avbuf);



    if (atomic_fetch_sub(&avbuf->context_refcount, 1) == 1) {

        atomic_fetch_sub_explicit(&s->refcount, 1, memory_order_acq_rel);



        if (s->reinit) {

            if (!atomic_load(&s->refcount))

                sem_post(&s->refsync);

        } else if (avbuf->context->streamon)

            ff_v4l2_buffer_enqueue(avbuf);



        av_buffer_unref(&avbuf->context_ref);

    }

}
