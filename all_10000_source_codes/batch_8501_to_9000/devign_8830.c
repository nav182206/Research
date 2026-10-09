/* 
 * Benchmark Sample ID : devign_8830
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=53cb28cbfea038f8ad50132dc8a684e638c7d48b
 */

static void phys_page_set(AddressSpaceDispatch *d,

                          hwaddr index, hwaddr nb,

                          uint16_t leaf)

{

    /* Wildly overreserve - it doesn't matter much. */

    phys_map_node_reserve(3 * P_L2_LEVELS);



    phys_page_set_level(&d->phys_map, &index, &nb, leaf, P_L2_LEVELS - 1);

}
