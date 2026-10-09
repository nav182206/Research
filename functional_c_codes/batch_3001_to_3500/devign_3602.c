/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3602
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=447b0d0b9ee8a0ac216c3186e0f3c427a1001f0c
 */

static FlatView *address_space_get_flatview(AddressSpace *as)

{

    FlatView *view;



    rcu_read_lock();

    view = atomic_rcu_read(&as->current_map);

    flatview_ref(view);

    rcu_read_unlock();

    return view;

}
