/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6749
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=03f47ee49e1478b5ffffb3a9b6203c672903196c
 */

void kvm_s390_cmma_reset(void)

{

    int rc;

    struct kvm_device_attr attr = {

        .group = KVM_S390_VM_MEM_CTRL,

        .attr = KVM_S390_VM_MEM_CLR_CMMA,

    };



    if (mem_path || !kvm_s390_cmma_available()) {

        return;

    }



    rc = kvm_vm_ioctl(kvm_state, KVM_SET_DEVICE_ATTR, &attr);

    trace_kvm_clear_cmma(rc);

}
