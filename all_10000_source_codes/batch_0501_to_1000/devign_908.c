/* 
 * Benchmark Sample ID : devign_908
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac1970fbe8ad5a70174f462109ac0f6c7bf1bc43
 */

static void register_multipage(MemoryRegionSection *section)

{

    target_phys_addr_t start_addr = section->offset_within_address_space;

    ram_addr_t size = section->size;

    target_phys_addr_t addr;

    uint16_t section_index = phys_section_add(section);



    assert(size);



    addr = start_addr;

    phys_page_set(addr >> TARGET_PAGE_BITS, size >> TARGET_PAGE_BITS,

                  section_index);

}
