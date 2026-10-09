/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1841
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=710c15a2e9078931f496424d8e10241f4930f940
 */

void OPPROTO op_lmsw_T0(void)

{

    /* only 4 lower bits of CR0 are modified */

    T0 = (env->cr[0] & ~0xf) | (T0 & 0xf);

    helper_movl_crN_T0(0);

}
