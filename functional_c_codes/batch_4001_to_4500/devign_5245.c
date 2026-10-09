/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5245
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=94a8d39afd8ccfdbf578af04c3385fdb5f545af1
 */

int kvm_coalesce_mmio_region(target_phys_addr_t start, ram_addr_t size)

{

    int ret = -ENOSYS;

#ifdef KVM_CAP_COALESCED_MMIO

    KVMState *s = kvm_state;



    if (s->coalesced_mmio) {

        struct kvm_coalesced_mmio_zone zone;



        zone.addr = start;

        zone.size = size;



        ret = kvm_vm_ioctl(s, KVM_REGISTER_COALESCED_MMIO, &zone);

    }

#endif



    return ret;

}
