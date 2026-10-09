/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_55
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=856d72454f03aea26fd61c728762ef9cd1d71512
 */

static void listener_add_address_space(MemoryListener *listener,

                                       AddressSpace *as)

{

    FlatView *view;

    FlatRange *fr;



    if (listener->address_space_filter

        && listener->address_space_filter != as) {

        return;

    }



    if (global_dirty_log) {

        if (listener->log_global_start) {

            listener->log_global_start(listener);

        }

    }



    view = as->current_map;

    FOR_EACH_FLAT_RANGE(fr, view) {

        MemoryRegionSection section = {

            .mr = fr->mr,

            .address_space = as,

            .offset_within_region = fr->offset_in_region,

            .size = fr->addr.size,

            .offset_within_address_space = int128_get64(fr->addr.start),

            .readonly = fr->readonly,

        };

        if (listener->region_add) {

            listener->region_add(listener, &section);

        }

    }

}
