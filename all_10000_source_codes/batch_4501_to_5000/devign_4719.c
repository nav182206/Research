/* 
 * Benchmark Sample ID : devign_4719
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4c19eb721a5929f2277d33a98bb59963c58c2e3b
 */

void address_space_destroy(AddressSpace *as)

{

    /* Flush out anything from MemoryListeners listening in on this */

    memory_region_transaction_begin();

    as->root = NULL;

    memory_region_transaction_commit();

    QTAILQ_REMOVE(&address_spaces, as, address_spaces_link);

    address_space_destroy_dispatch(as);

    flatview_destroy(as->current_map);

    g_free(as->current_map);


}
