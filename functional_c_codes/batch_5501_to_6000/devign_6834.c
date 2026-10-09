/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6834
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=35ecde26018207fe723bec6efbd340db6e9c2d53
 */

static void qemu_aio_wait_all(void)

{

    while (aio_poll(ctx, true)) {

        /* Do nothing */

    }

}
