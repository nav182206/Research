/* 
 * Benchmark Sample ID : devign_2095
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1ad9f0a464fe78d30ee60b3629f7a825cf2fab13
 */

void ppc_hash64_stop_access(PowerPCCPU *cpu, uint64_t token)

{

    if (cpu->env.external_htab == MMU_HASH64_KVM_MANAGED_HPT) {

        kvmppc_hash64_free_pteg(token);

    }

}
