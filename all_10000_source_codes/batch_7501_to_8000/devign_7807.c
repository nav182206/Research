/* 
 * Benchmark Sample ID : devign_7807
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8786db7cb96f8ce5c75c6e1e074319c9dca8d356
 */

static void address_space_update_topology(AddressSpace *as)

{

    FlatView old_view = as->current_map;

    FlatView new_view = generate_memory_topology(as->root);



    address_space_update_topology_pass(as, old_view, new_view, false);

    address_space_update_topology_pass(as, old_view, new_view, true);



    as->current_map = new_view;

    flatview_destroy(&old_view);

    address_space_update_ioeventfds(as);

}
