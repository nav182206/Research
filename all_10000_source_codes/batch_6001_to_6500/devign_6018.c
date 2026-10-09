/* 
 * Benchmark Sample ID : devign_6018
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8ff4316795c7051b38727ec4a81c65dfcf63dc6
 */

static void xen_io_add(MemoryListener *listener,

                       MemoryRegionSection *section)

{

    XenIOState *state = container_of(listener, XenIOState, io_listener);



    memory_region_ref(section->mr);



    xen_map_io_section(xen_xc, xen_domid, state->ioservid, section);

}
