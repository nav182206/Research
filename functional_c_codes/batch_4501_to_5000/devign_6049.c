/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6049
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ea375f9ab8c76686dca0af8cb4f87a4eb569cad3
 */

static int handle_hypercall(CPUState *env, struct kvm_run *run)

{

    int r;



    cpu_synchronize_state(env);

    r = s390_virtio_hypercall(env);

    kvm_arch_put_registers(env);



    return r;

}
