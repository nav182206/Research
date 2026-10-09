/* 
 * Benchmark Sample ID : devign_5125
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=367790cce8e14131426f5190dfd7d1bdbf656e4d
 */

uint32_t HELPER(shl_cc)(CPUM68KState *env, uint32_t val, uint32_t shift)

{

    uint64_t result;



    shift &= 63;

    result = (uint64_t)val << shift;



    env->cc_c = (result >> 32) & 1;

    env->cc_n = result;

    env->cc_z = result;

    env->cc_v = 0;

    env->cc_x = shift ? env->cc_c : env->cc_x;



    return result;

}
