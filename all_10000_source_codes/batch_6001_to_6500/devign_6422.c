/* 
 * Benchmark Sample ID : devign_6422
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f7d3e466764e0258d0883d90edb7e98ad0b56e18
 */

static int s390_cpu_initial_reset(S390CPU *cpu)

{

    CPUState *cs = CPU(cpu);

    CPUS390XState *env = &cpu->env;

    int i;



    s390_del_running_cpu(cpu);

    if (kvm_vcpu_ioctl(cs, KVM_S390_INITIAL_RESET, NULL) < 0) {

        perror("cannot init reset vcpu");

    }



    /* Manually zero out all registers */

    cpu_synchronize_state(cs);

    for (i = 0; i < 16; i++) {

        env->regs[i] = 0;

    }



    DPRINTF("DONE: SIGP initial reset: %p\n", env);

    return 0;

}
