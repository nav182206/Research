/* 
 * Benchmark Sample ID : devign_4262
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b0b1d69079fcb9453f45aade9e9f6b71422147b0
 */

int kvm_update_guest_debug(CPUState *env, unsigned long reinject_trap)

{

    struct kvm_set_guest_debug_data data;



    data.dbg.control = 0;

    if (env->singlestep_enabled)

        data.dbg.control = KVM_GUESTDBG_ENABLE | KVM_GUESTDBG_SINGLESTEP;



    kvm_arch_update_guest_debug(env, &data.dbg);

    data.dbg.control |= reinject_trap;

    data.env = env;



    on_vcpu(env, kvm_invoke_set_guest_debug, &data);

    return data.err;

}
