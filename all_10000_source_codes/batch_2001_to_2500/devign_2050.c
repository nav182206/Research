/* 
 * Benchmark Sample ID : devign_2050
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac95190ea92f7625bb0065c2864321607b95c26b
 */

static void do_address_space_destroy(AddressSpace *as)
{
    MemoryListener *listener;
    address_space_destroy_dispatch(as);
    QTAILQ_FOREACH(listener, &memory_listeners, link) {
        assert(listener->address_space_filter != as);
    }
    flatview_unref(as->current_map);
    g_free(as->name);
    g_free(as->ioeventfds);
}
