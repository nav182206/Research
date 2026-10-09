/* 
 * Benchmark Sample ID : devign_6491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=39ea3d4eaf1ff300ee55946108394729bc053dfa
 */

uint32_t HELPER(get_r13_banked)(CPUState *env, uint32_t mode)

{

    return env->banked_r13[bank_number(mode)];

}
