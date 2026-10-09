/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3676
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aed6efb90cc43faf45f1e40425646c55d37a340f
 */

int kvm_set_signal_mask(CPUState *cpu, const sigset_t *sigset)

{

    struct kvm_signal_mask *sigmask;

    int r;



    if (!sigset) {

        return kvm_vcpu_ioctl(cpu, KVM_SET_SIGNAL_MASK, NULL);

    }



    sigmask = g_malloc(sizeof(*sigmask) + sizeof(*sigset));



    sigmask->len = 8;

    memcpy(sigmask->sigset, sigset, sizeof(*sigset));

    r = kvm_vcpu_ioctl(cpu, KVM_SET_SIGNAL_MASK, sigmask);

    g_free(sigmask);



    return r;

}
