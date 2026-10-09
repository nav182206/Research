/* 
 * Benchmark Sample ID : devign_10000
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=99b9cc0679585b2d495d7d31ce556549b6b2721c
 */

static void mem_add(MemoryListener *listener, MemoryRegionSection *section)

{

    AddressSpaceDispatch *d = container_of(listener, AddressSpaceDispatch, listener);

    MemoryRegionSection now = limit(*section), remain = limit(*section);



    if ((now.offset_within_address_space & ~TARGET_PAGE_MASK)

        || (now.size < TARGET_PAGE_SIZE)) {

        now.size = MIN(TARGET_PAGE_ALIGN(now.offset_within_address_space)

                       - now.offset_within_address_space,

                       now.size);

        register_subpage(d, &now);

        remain.size -= now.size;

        remain.offset_within_address_space += now.size;

        remain.offset_within_region += now.size;

    }

    while (remain.size >= TARGET_PAGE_SIZE) {

        now = remain;

        if (remain.offset_within_region & ~TARGET_PAGE_MASK) {

            now.size = TARGET_PAGE_SIZE;

            register_subpage(d, &now);

        } else {

            now.size &= TARGET_PAGE_MASK;

            register_multipage(d, &now);

        }

        remain.size -= now.size;

        remain.offset_within_address_space += now.size;

        remain.offset_within_region += now.size;

    }

    now = remain;

    if (now.size) {

        register_subpage(d, &now);

    }

}
