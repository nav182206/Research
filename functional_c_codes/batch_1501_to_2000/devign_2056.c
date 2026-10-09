/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2056
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b0fd8d18683f0d77a8e6b482771ebea82234d727
 */

static inline int copy_siginfo_to_user(target_siginfo_t *tinfo,

                                       const target_siginfo_t *info)

{

    tswap_siginfo(tinfo, info);

    return 0;

}
