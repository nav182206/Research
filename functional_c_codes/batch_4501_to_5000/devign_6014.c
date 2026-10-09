/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6014
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=acfb23ad3dd8d0ab385a10e483776ba7dcf927ad
 */

static void wait_for_aio(void)

{

    while (aio_poll(ctx, true)) {

        /* Do nothing */

    }

}
