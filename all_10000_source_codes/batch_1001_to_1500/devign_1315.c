/* 
 * Benchmark Sample ID : devign_1315
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8ff4316795c7051b38727ec4a81c65dfcf63dc6
 */

static void xen_io_del(MemoryListener *listener,

                       MemoryRegionSection *section)

{

    XenIOState *state = container_of(listener, XenIOState, io_listener);



    xen_unmap_io_section(xen_xc, xen_domid, state->ioservid, section);



    memory_region_unref(section->mr);

}
