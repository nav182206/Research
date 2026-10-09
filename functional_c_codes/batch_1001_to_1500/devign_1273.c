/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1273
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=53cb28cbfea038f8ad50132dc8a684e638c7d48b
 */

static void register_multipage(AddressSpaceDispatch *d,

                               MemoryRegionSection *section)

{

    hwaddr start_addr = section->offset_within_address_space;

    uint16_t section_index = phys_section_add(section);

    uint64_t num_pages = int128_get64(int128_rshift(section->size,

                                                    TARGET_PAGE_BITS));



    assert(num_pages);

    phys_page_set(d, start_addr >> TARGET_PAGE_BITS, num_pages, section_index);

}
