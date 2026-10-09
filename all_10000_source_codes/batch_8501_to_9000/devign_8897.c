/* 
 * Benchmark Sample ID : devign_8897
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f53c398aa603cea135ee58fd15249aeff7b9c7ea
 */

static void ehci_queues_rip_device(EHCIState *ehci, USBDevice *dev)

{

    EHCIQueue *q, *tmp;



    QTAILQ_FOREACH_SAFE(q, &ehci->queues, next, tmp) {

        if (q->packet.owner == NULL ||

            q->packet.owner->dev != dev) {

            continue;

        }

        ehci_free_queue(q);

    }

}
