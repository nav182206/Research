/* 
 * Benchmark Sample ID : devign_5680
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=058bc4b57f9d6b39d9a6748b4049e1be3fde3dac
 */

static void destroy_page_desc(uint16_t section_index)

{

    MemoryRegionSection *section = &phys_sections[section_index];

    MemoryRegion *mr = section->mr;



    if (mr->subpage) {

        subpage_t *subpage = container_of(mr, subpage_t, iomem);

        memory_region_destroy(&subpage->iomem);

        g_free(subpage);

    }

}
