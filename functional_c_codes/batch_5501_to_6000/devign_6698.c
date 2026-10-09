/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6698
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca96ac44dcd290566090b2435bc828fded356ad9
 */

static void aio_rfifolock_cb(void *opaque)

{

    /* Kick owner thread in case they are blocked in aio_poll() */

    aio_notify(opaque);

}
