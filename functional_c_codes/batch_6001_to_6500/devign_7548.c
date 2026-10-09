/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7548
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=77fa9aee38758a078870e25f0dcf642066b4d5cc
 */

static void uhci_async_cancel_all(UHCIState *s)

{

    UHCIQueue *queue;

    UHCIAsync *curr, *n;



    QTAILQ_FOREACH(queue, &s->queues, next) {

        QTAILQ_FOREACH_SAFE(curr, &queue->asyncs, next, n) {

            uhci_async_unlink(curr);

            uhci_async_cancel(curr);

        }

        uhci_queue_free(queue);

    }

}
