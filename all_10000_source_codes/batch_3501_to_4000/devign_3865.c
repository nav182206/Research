/* 
 * Benchmark Sample ID : devign_3865
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fb0e8e79a9d77ee240dbca036fa8698ce654e5d1
 */

void HELPER(cpsr_write_eret)(CPUARMState *env, uint32_t val)
{
    cpsr_write(env, val, CPSR_ERET_MASK, CPSRWriteExceptionReturn);
    arm_call_el_change_hook(arm_env_get_cpu(env));
}
