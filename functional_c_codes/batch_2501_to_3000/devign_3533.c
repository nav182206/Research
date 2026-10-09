/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3533
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e450a8f50ac12fc8f69b6ce555254c84efcf407
 */

hwaddr sparc_cpu_get_phys_page_debug(CPUState *cs, vaddr addr)

{

    SPARCCPU *cpu = SPARC_CPU(cs);

    CPUSPARCState *env = &cpu->env;

    hwaddr phys_addr;

    int mmu_idx = cpu_mmu_index(env, false);

    MemoryRegionSection section;



    if (cpu_sparc_get_phys_page(env, &phys_addr, addr, 2, mmu_idx) != 0) {

        if (cpu_sparc_get_phys_page(env, &phys_addr, addr, 0, mmu_idx) != 0) {

            return -1;

        }

    }

    section = memory_region_find(get_system_memory(), phys_addr, 1);

    memory_region_unref(section.mr);

    if (!int128_nz(section.size)) {

        return -1;

    }

    return phys_addr;

}
