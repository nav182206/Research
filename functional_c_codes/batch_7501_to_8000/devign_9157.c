/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9157
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f3c75d42adbba553eaf218a832d4fbea32c8f7b8
 */

void helper_store_sdr1(CPUPPCState *env, target_ulong val)

{

    ppc_store_sdr1(env, val);

}
