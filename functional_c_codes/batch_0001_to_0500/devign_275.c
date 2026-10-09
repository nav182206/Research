/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_275
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4c19eb721a5929f2277d33a98bb59963c58c2e3b
 */

void address_space_init(AddressSpace *as, MemoryRegion *root)

{

    memory_region_transaction_begin();

    as->root = root;

    as->current_map = g_new(FlatView, 1);

    flatview_init(as->current_map);



    QTAILQ_INSERT_TAIL(&address_spaces, as, address_spaces_link);

    as->name = NULL;

    memory_region_transaction_commit();

    address_space_init_dispatch(as);

}
