/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3806
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=03a96b83b539498510e22aab585e41015ba18247
 */

static int kvm_set_ioeventfd_mmio(int fd, hwaddr addr, uint32_t val,

                                  bool assign, uint32_t size, bool datamatch)

{

    int ret;

    struct kvm_ioeventfd iofd;



    iofd.datamatch = datamatch ? adjust_ioeventfd_endianness(val, size) : 0;

    iofd.addr = addr;

    iofd.len = size;

    iofd.flags = 0;

    iofd.fd = fd;



    if (!kvm_enabled()) {

        return -ENOSYS;

    }



    if (datamatch) {

        iofd.flags |= KVM_IOEVENTFD_FLAG_DATAMATCH;

    }

    if (!assign) {

        iofd.flags |= KVM_IOEVENTFD_FLAG_DEASSIGN;

    }



    ret = kvm_vm_ioctl(kvm_state, KVM_IOEVENTFD, &iofd);



    if (ret < 0) {

        return -errno;

    }



    return 0;

}
