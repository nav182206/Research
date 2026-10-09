/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2989
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

static void thread_pool_co_cb(void *opaque, int ret)

{

    ThreadPoolCo *co = opaque;



    co->ret = ret;

    qemu_coroutine_enter(co->co);

}
