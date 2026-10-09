/* 
 * Benchmark Sample ID : devign_4563
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de13d2161473d02ae97ec0f8e4503147554892dd
 */

void s390_virtio_irq(S390CPU *cpu, int config_change, uint64_t token)

{

    if (kvm_enabled()) {

        kvm_s390_virtio_irq(cpu, config_change, token);

    } else {

        cpu_inject_ext(cpu, EXT_VIRTIO, config_change, token);

    }

}
