/* 
 * Benchmark Sample ID : devign_2984
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c3a3a7d356c4df2fe145037172ae52cba5f545a5
 */

static int kvm_has_msr_star(CPUState *env)

{

    kvm_supported_msrs(env);

    return has_msr_star;

}
