/* 
 * Benchmark Sample ID : devign_2161
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2b147555f78c3c20080b201fd1506467fa0ddf43
 */

static int kvm_s390_supports_mem_limit(KVMState *s)

{

    struct kvm_device_attr attr = {

        .group = KVM_S390_VM_MEM_CTRL,

        .attr = KVM_S390_VM_MEM_LIMIT_SIZE,

    };



    return (kvm_vm_ioctl(s, KVM_HAS_DEVICE_ATTR, &attr) == 0);

}
