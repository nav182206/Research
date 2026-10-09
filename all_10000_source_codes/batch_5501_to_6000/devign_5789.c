/* 
 * Benchmark Sample ID : devign_5789
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b8aecea23aaccf39da54c77ef248f5fa50dcfbc1
 */

void memory_region_del_eventfd(MemoryRegion *mr,

                               hwaddr addr,

                               unsigned size,

                               bool match_data,

                               uint64_t data,

                               EventNotifier *e)

{

    MemoryRegionIoeventfd mrfd = {

        .addr.start = int128_make64(addr),

        .addr.size = int128_make64(size),

        .match_data = match_data,

        .data = data,

        .e = e,

    };

    unsigned i;



    adjust_endianness(mr, &mrfd.data, size);

    memory_region_transaction_begin();

    for (i = 0; i < mr->ioeventfd_nb; ++i) {

        if (memory_region_ioeventfd_equal(mrfd, mr->ioeventfds[i])) {

            break;

        }

    }

    assert(i != mr->ioeventfd_nb);

    memmove(&mr->ioeventfds[i], &mr->ioeventfds[i+1],

            sizeof(*mr->ioeventfds) * (mr->ioeventfd_nb - (i+1)));

    --mr->ioeventfd_nb;

    mr->ioeventfds = g_realloc(mr->ioeventfds,

                                  sizeof(*mr->ioeventfds)*mr->ioeventfd_nb + 1);

    ioeventfd_update_pending |= mr->enabled;

    memory_region_transaction_commit();

}
