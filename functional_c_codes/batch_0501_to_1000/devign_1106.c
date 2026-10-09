/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1106
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a87f39543a9259f671c5413723311180ee2ad2a8
 */

address_space_translate_internal(AddressSpaceDispatch *d, hwaddr addr, hwaddr *xlat,

                                 hwaddr *plen, bool resolve_subpage)

{

    MemoryRegionSection *section;

    Int128 diff, diff_page;



    section = address_space_lookup_region(d, addr, resolve_subpage);

    /* Compute offset within MemoryRegionSection */

    addr -= section->offset_within_address_space;



    /* Compute offset within MemoryRegion */

    *xlat = addr + section->offset_within_region;



    diff_page = int128_make64(((addr & TARGET_PAGE_MASK) + TARGET_PAGE_SIZE) - addr);

    diff = int128_sub(section->mr->size, int128_make64(addr));

    diff = int128_min(diff, diff_page);

    *plen = int128_get64(int128_min(diff, int128_make64(*plen)));

    return section;

}
