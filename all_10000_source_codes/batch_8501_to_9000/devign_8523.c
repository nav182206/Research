/* 
 * Benchmark Sample ID : devign_8523
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b60fae32ff33cbaab76d14cc5f55b979cf58516d
 */

static int handle_sw_breakpoint(S390CPU *cpu, struct kvm_run *run)

{

    CPUS390XState *env = &cpu->env;

    unsigned long pc;



    cpu_synchronize_state(CPU(cpu));



    pc = env->psw.addr - 4;

    if (kvm_find_sw_breakpoint(CPU(cpu), pc)) {

        env->psw.addr = pc;

        return EXCP_DEBUG;

    }



    return -ENOENT;

}
