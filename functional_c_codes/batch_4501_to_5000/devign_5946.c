/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5946
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=09b9418c6d085a0728372aa760ebd10128a020b1
 */

static target_long monitor_get_tbu (const struct MonitorDef *md, int val)

{

    CPUState *env = mon_get_cpu();

    if (!env)

        return 0;

    return cpu_ppc_load_tbu(env);

}
