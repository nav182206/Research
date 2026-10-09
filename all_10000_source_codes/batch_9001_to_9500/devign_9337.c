/* 
 * Benchmark Sample ID : devign_9337
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=729633c2bc30496073431584eb6e304776b4ebd4
 */

static MemoryRegionSection *address_space_lookup_region(AddressSpaceDispatch *d,

                                                        hwaddr addr,

                                                        bool resolve_subpage)

{

    MemoryRegionSection *section;

    subpage_t *subpage;



    section = phys_page_find(d->phys_map, addr, d->map.nodes, d->map.sections);

    if (resolve_subpage && section->mr->subpage) {

        subpage = container_of(section->mr, subpage_t, iomem);

        section = &d->map.sections[subpage->sub_section[SUBPAGE_IDX(addr)]];

    }

    return section;

}
