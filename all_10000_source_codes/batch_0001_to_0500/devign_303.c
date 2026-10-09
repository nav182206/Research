/* 
 * Benchmark Sample ID : devign_303
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=11748ba72ea4fc03e975aa5f5d876b5b0902e356
 */

static int kvm_recommended_vcpus(KVMState *s)

{

    int ret = kvm_check_extension(s, KVM_CAP_NR_VCPUS);

    return (ret) ? ret : 4;

}
