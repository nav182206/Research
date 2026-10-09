/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6507
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6133b39f3c36623425a6ede9e89d93175fde15cd
 */

static void co_sleep_cb(void *opaque)

{

    CoSleepCB *sleep_cb = opaque;





    aio_co_wake(sleep_cb->co);

}
