/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6556
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3d3efba020da1de57a715e2087cf761ed0ad0904
 */

static void set_sigmask(const sigset_t *set)

{

    do_sigprocmask(SIG_SETMASK, set, NULL);

}
