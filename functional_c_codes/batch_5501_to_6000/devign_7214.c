/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7214
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=39a7a362e16bb27e98738d63f24d1ab5811e26a8
 */

static void qemu_coroutine_thread_cleanup(void *opaque)

{

    CoroutineThreadState *s = opaque;

    Coroutine *co;

    Coroutine *tmp;



    QLIST_FOREACH_SAFE(co, &s->pool, pool_next, tmp) {

        g_free(DO_UPCAST(CoroutineUContext, base, co)->stack);

        g_free(co);

    }

    g_free(s);

}
