/* 
 * Benchmark Sample ID : devign_2512
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4295e15aa730a95003a3639d6dad2eb1e65a59e2
 */

void qemu_spice_destroy_primary_surface(SimpleSpiceDisplay *ssd,

                                        uint32_t id, qxl_async_io async)

{

    if (async != QXL_SYNC) {

#if SPICE_INTERFACE_QXL_MINOR >= 1

        spice_qxl_destroy_primary_surface_async(&ssd->qxl, id, 0);

#else

        abort();

#endif

    } else {

        ssd->worker->destroy_primary_surface(ssd->worker, id);

    }

}
