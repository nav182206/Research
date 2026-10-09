/* 
 * Benchmark Sample ID : devign_5485
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=68f3f65b09a1ce8c82fac17911ffc3bb6031ebe4
 */

static uint16_t phys_section_add(MemoryRegionSection *section)
{
    if (phys_sections_nb == phys_sections_nb_alloc) {
        phys_sections_nb_alloc = MAX(phys_sections_nb_alloc * 2, 16);
        phys_sections = g_renew(MemoryRegionSection, phys_sections,
                                phys_sections_nb_alloc);
    }
    phys_sections[phys_sections_nb] = *section;
    return phys_sections_nb++;
}
