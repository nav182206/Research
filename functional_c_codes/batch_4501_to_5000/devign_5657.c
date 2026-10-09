/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5657
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=08844473820c93541fc47bdfeae0f2cc88cfab59
 */

static void bdrv_co_io_em_complete(void *opaque, int ret)

{

    CoroutineIOCompletion *co = opaque;



    co->ret = ret;

    qemu_coroutine_enter(co->coroutine, NULL);

}
