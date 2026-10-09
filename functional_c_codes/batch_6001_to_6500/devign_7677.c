/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7677
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5ad23e873c858292dc58b9296261365312b8f683
 */

static void uhci_async_cancel_device(UHCIState *s, USBDevice *dev)

{

    UHCIQueue *queue;

    UHCIAsync *curr, *n;



    QTAILQ_FOREACH(queue, &s->queues, next) {

        QTAILQ_FOREACH_SAFE(curr, &queue->asyncs, next, n) {

            if (!usb_packet_is_inflight(&curr->packet) ||

                curr->packet.ep->dev != dev) {

                continue;

            }

            uhci_async_cancel(curr);

        }

    }

}
