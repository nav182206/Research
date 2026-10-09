/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6801
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d04fb55dec381bc5105cb47f29d918e579e8cbd
 */

void HELPER(set_cp_reg)(CPUARMState *env, void *rip, uint32_t value)

{

    const ARMCPRegInfo *ri = rip;



    ri->writefn(env, ri, value);

}
