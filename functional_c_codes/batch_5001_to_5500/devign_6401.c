/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6401
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e57ca75ce3b2bd33102573a8c0555d62e1bcfceb
 */

void ppc_hash64_unmap_hptes(PowerPCCPU *cpu, const ppc_hash_pte64_t *hptes,

                            hwaddr ptex, int n)

{

    if (cpu->env.external_htab == MMU_HASH64_KVM_MANAGED_HPT) {

        g_free((void *)hptes);

    } else if (!cpu->env.external_htab) {

        address_space_unmap(CPU(cpu)->as, (void *)hptes, n * HASH_PTE_SIZE_64,

                            false, n * HASH_PTE_SIZE_64);

    }

}
