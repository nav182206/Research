/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8053
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=374f2981d1f10bc4307f250f24b2a7ddb9b14be0
 */

static FlatView *address_space_get_flatview(AddressSpace *as)

{

    FlatView *view;



    qemu_mutex_lock(&flat_view_mutex);

    view = as->current_map;

    flatview_ref(view);

    qemu_mutex_unlock(&flat_view_mutex);

    return view;

}
