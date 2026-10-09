/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5912
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e680cfa7e20f5049c475ac94f998a79c9997b48d
 */

static void qemu_co_queue_next_bh(void *opaque)

{

    struct unlock_bh *unlock_bh = opaque;

    Coroutine *next;



    trace_qemu_co_queue_next_bh();

    while ((next = QTAILQ_FIRST(&unlock_bh_queue))) {

        QTAILQ_REMOVE(&unlock_bh_queue, next, co_queue_next);

        qemu_coroutine_enter(next, NULL);

    }



    qemu_bh_delete(unlock_bh->bh);

    qemu_free(unlock_bh);

}
