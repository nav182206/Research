/* 
 * Benchmark Sample ID : devign_6743
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=39a7a362e16bb27e98738d63f24d1ab5811e26a8
 */

static CoroutineThreadState *coroutine_get_thread_state(void)

{

    CoroutineThreadState *s = pthread_getspecific(thread_state_key);



    if (!s) {

        s = g_malloc0(sizeof(*s));

        s->current = &s->leader.base;

        QLIST_INIT(&s->pool);

        pthread_setspecific(thread_state_key, s);

    }

    return s;

}
