/* 
 * Benchmark Sample ID : devign_6138
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eca1bdf415c454093dfc7eb983cd49287c043967
 */

void cpu_reset (CPUCRISState *env)
{
	memset(env, 0, offsetof(CPUCRISState, breakpoints));
	tlb_flush(env, 1);
	env->pregs[PR_VR] = 32;
#if defined(CONFIG_USER_ONLY)
	/* start in user mode with interrupts enabled.  */
	env->pregs[PR_CCS] |= U_FLAG | I_FLAG;
#else
	env->pregs[PR_CCS] = 0;
#endif
