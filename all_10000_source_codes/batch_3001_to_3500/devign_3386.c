/* 
 * Benchmark Sample ID : devign_3386
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void coroutine_fn qed_co_pwrite_zeroes_cb(void *opaque, int ret)

{

    QEDWriteZeroesCB *cb = opaque;



    cb->done = true;

    cb->ret = ret;

    if (cb->co) {

        qemu_coroutine_enter(cb->co, NULL);

    }

}
