/* 
 * Benchmark Sample ID : devign_9717
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=40fda982f2e887f7d5cc36b8a7e3b5a07a1e6704
 */

static void kvmppc_host_cpu_initfn(Object *obj)

{

    assert(kvm_enabled());

}
