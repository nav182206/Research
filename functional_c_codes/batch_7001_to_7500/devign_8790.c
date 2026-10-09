/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8790
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a426e122173f36f05ea2cb72dcff77b7408546ce
 */

int kvm_init_vcpu(CPUState *env)

{

    KVMState *s = kvm_state;

    long mmap_size;

    int ret;



    DPRINTF("kvm_init_vcpu\n");



    ret = kvm_vm_ioctl(s, KVM_CREATE_VCPU, env->cpu_index);

    if (ret < 0) {

        DPRINTF("kvm_create_vcpu failed\n");

        goto err;

    }



    env->kvm_fd = ret;

    env->kvm_state = s;



    mmap_size = kvm_ioctl(s, KVM_GET_VCPU_MMAP_SIZE, 0);

    if (mmap_size < 0) {

        DPRINTF("KVM_GET_VCPU_MMAP_SIZE failed\n");

        goto err;

    }



    env->kvm_run = mmap(NULL, mmap_size, PROT_READ | PROT_WRITE, MAP_SHARED,

                        env->kvm_fd, 0);

    if (env->kvm_run == MAP_FAILED) {

        ret = -errno;

        DPRINTF("mmap'ing vcpu state failed\n");

        goto err;

    }



#ifdef KVM_CAP_COALESCED_MMIO

    if (s->coalesced_mmio && !s->coalesced_mmio_ring)

        s->coalesced_mmio_ring = (void *) env->kvm_run +

		s->coalesced_mmio * PAGE_SIZE;

#endif



    ret = kvm_arch_init_vcpu(env);

    if (ret == 0) {

        qemu_register_reset(kvm_reset_vcpu, env);

        kvm_arch_reset_vcpu(env);

    }

err:

    return ret;

}
