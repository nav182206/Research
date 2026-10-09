/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9745
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c4d9d19645a484298a67e9021060bc7c2b081d0f
 */

static void qemu_aio_wait_all(void)

{

    while (qemu_aio_wait()) {

        /* Do nothing */

    }

}
