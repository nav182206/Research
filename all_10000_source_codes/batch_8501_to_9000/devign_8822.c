/* 
 * Benchmark Sample ID : devign_8822
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f22d85e9e67262db34504f4079745f9843da6a92
 */

static void disable_logging(void)

{

    ga_disable_logging(ga_state);

}
