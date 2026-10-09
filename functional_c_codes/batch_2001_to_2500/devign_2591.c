/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2591
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=044897ef4a22af89aecb8df509477beba0a2e0ce
 */

void helper_store_msr(CPUPPCState *env, target_ulong val)

{

    uint32_t excp = hreg_store_msr(env, val, 0);



    if (excp != 0) {

        CPUState *cs = CPU(ppc_env_get_cpu(env));

        cs->interrupt_request |= CPU_INTERRUPT_EXITTB;

        raise_exception(env, excp);

    }

}
