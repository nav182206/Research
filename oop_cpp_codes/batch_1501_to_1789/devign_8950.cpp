/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8950
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=74b4c74d5efb0a489bdf0acc5b5d0197167e7649
 */

static void sigp_cpu_reset(CPUState *cs, run_on_cpu_data arg)

{

    S390CPU *cpu = S390_CPU(cs);

    S390CPUClass *scc = S390_CPU_GET_CLASS(cpu);

    SigpInfo *si = arg.host_ptr;



    cpu_synchronize_state(cs);

    scc->cpu_reset(cs);

    cpu_synchronize_post_reset(cs);

    si->cc = SIGP_CC_ORDER_CODE_ACCEPTED;

}
