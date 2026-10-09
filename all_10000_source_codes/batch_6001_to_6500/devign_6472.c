/* 
 * Benchmark Sample ID : devign_6472
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6eb8f212d2686ed9b17077d554465df7ae06f805
 */

static void sigp_cpu_restart(void *arg)

{

    CPUState *cs = arg;

    S390CPU *cpu = S390_CPU(cs);

    struct kvm_s390_irq irq = {

        .type = KVM_S390_RESTART,

    };



    kvm_s390_vcpu_interrupt(cpu, &irq);

    s390_cpu_set_state(CPU_STATE_OPERATING, cpu);

}
