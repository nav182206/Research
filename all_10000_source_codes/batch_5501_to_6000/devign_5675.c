/* 
 * Benchmark Sample ID : devign_5675
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4be23939ab0d7019c7e59a37485b416fbbf0f073
 */

static void ehci_queues_rip_unused(EHCIState *ehci, int async)

{

    EHCIQueueHead *head = async ? &ehci->aqueues : &ehci->pqueues;

    EHCIQueue *q, *tmp;



    QTAILQ_FOREACH_SAFE(q, head, next, tmp) {

        if (q->seen) {

            q->seen = 0;

            q->ts = ehci->last_run_ns;

            continue;

        }

        if (ehci->last_run_ns < q->ts + 250000000) {

            /* allow 0.25 sec idle */

            continue;

        }

        ehci_free_queue(q, async);

    }

}
