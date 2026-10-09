/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9516
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b9bec74bcb16519a876ec21cd5277c526a9b512d
 */

static int kvm_get_fpu(CPUState *env)

{

    struct kvm_fpu fpu;

    int i, ret;



    ret = kvm_vcpu_ioctl(env, KVM_GET_FPU, &fpu);

    if (ret < 0)

        return ret;



    env->fpstt = (fpu.fsw >> 11) & 7;

    env->fpus = fpu.fsw;

    env->fpuc = fpu.fcw;

    for (i = 0; i < 8; ++i)

	env->fptags[i] = !((fpu.ftwx >> i) & 1);

    memcpy(env->fpregs, fpu.fpr, sizeof env->fpregs);

    memcpy(env->xmm_regs, fpu.xmm, sizeof env->xmm_regs);

    env->mxcsr = fpu.mxcsr;



    return 0;

}
