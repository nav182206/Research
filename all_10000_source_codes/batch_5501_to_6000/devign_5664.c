/* 
 * Benchmark Sample ID : devign_5664
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a426e122173f36f05ea2cb72dcff77b7408546ce
 */

void kvm_cpu_synchronize_state(CPUState *env)

{

    if (!env->kvm_vcpu_dirty)

        run_on_cpu(env, do_kvm_cpu_synchronize_state, env);

}
