/* 
 * Benchmark Sample ID : devign_8079
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4295e15aa730a95003a3639d6dad2eb1e65a59e2
 */

void qemu_spice_add_memslot(SimpleSpiceDisplay *ssd, QXLDevMemSlot *memslot,

                            qxl_async_io async)

{

    if (async != QXL_SYNC) {

#if SPICE_INTERFACE_QXL_MINOR >= 1

        spice_qxl_add_memslot_async(&ssd->qxl, memslot, 0);

#else

        abort();

#endif

    } else {

        ssd->worker->add_memslot(ssd->worker, memslot);

    }

}
