/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9290
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7e09797c299712cafa7bc05dd57c1b13afcc6039
 */

static uint64_t pmsav5_data_ap_read(CPUARMState *env, const ARMCPRegInfo *ri)

{

    return simple_mpu_ap_bits(env->cp15.c5_data);

}
