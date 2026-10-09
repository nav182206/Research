/* 
 * Benchmark Sample ID : devign_3890
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d04fb55dec381bc5105cb47f29d918e579e8cbd
 */

uint64_t HELPER(get_cp_reg64)(CPUARMState *env, void *rip)

{

    const ARMCPRegInfo *ri = rip;



    return ri->readfn(env, ri);

}
