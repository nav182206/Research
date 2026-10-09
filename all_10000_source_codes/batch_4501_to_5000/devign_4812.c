/* 
 * Benchmark Sample ID : devign_4812
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f2a53c9e05a24352a0f9740db0539ce5aeed22ca
 */

static bool hyperv_enabled(X86CPU *cpu)

{

    CPUState *cs = CPU(cpu);

    return kvm_check_extension(cs->kvm_state, KVM_CAP_HYPERV) > 0 &&

           (hyperv_hypercall_available(cpu) ||

            cpu->hyperv_time  ||

            cpu->hyperv_relaxed_timing);

}
