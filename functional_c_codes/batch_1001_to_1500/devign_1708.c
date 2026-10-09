/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1708
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de13d2161473d02ae97ec0f8e4503147554892dd
 */

void kvm_s390_virtio_irq(S390CPU *cpu, int config_change, uint64_t token)

{

    kvm_s390_interrupt_internal(cpu, KVM_S390_INT_VIRTIO, config_change,

                                token, 1);

}
