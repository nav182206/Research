/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1918
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=55d72a7eb32858d50ba0777cfde2027d007010b2
 */

void host_to_target_siginfo(target_siginfo_t *tinfo, const siginfo_t *info)

{

    host_to_target_siginfo_noswap(tinfo, info);

    tswap_siginfo(tinfo, tinfo);

}
