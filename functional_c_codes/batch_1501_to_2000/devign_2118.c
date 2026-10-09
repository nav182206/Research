/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2118
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ea375f9ab8c76686dca0af8cb4f87a4eb569cad3
 */

static void kvm_reset_vcpu(void *opaque)

{

    CPUState *env = opaque;



    kvm_arch_reset_vcpu(env);

    if (kvm_arch_put_registers(env)) {

        fprintf(stderr, "Fatal: kvm vcpu reset failed\n");

        abort();

    }

}
