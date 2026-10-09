/* 
 * Benchmark Sample ID : devign_3016
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void thread_pool_co_cb(void *opaque, int ret)

{

    ThreadPoolCo *co = opaque;



    co->ret = ret;

    qemu_coroutine_enter(co->co, NULL);

}
