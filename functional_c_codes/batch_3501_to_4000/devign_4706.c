/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4706
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e4afbf4fb4d026510700cb40bb72dea9aef14e3b
 */

static int nbd_can_accept(void *opaque)

{

    return nb_fds < shared;

}
