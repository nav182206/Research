/* 
 * Benchmark Sample ID : devign_2475
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dd673288a8ff73ad77fcc1c255486d2466a772e1
 */

void kvm_arch_reset_vcpu(CPUX86State *env)

{

    env->exception_injected = -1;

    env->interrupt_injected = -1;

    env->xcr0 = 1;

    if (kvm_irqchip_in_kernel()) {

        env->mp_state = cpu_is_bsp(env) ? KVM_MP_STATE_RUNNABLE :

                                          KVM_MP_STATE_UNINITIALIZED;

    } else {

        env->mp_state = KVM_MP_STATE_RUNNABLE;

    }

}
