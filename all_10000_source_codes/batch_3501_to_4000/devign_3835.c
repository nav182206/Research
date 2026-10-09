/* 
 * Benchmark Sample ID : devign_3835
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9bc3a3a216e2689bfcdd36c3e079333bbdbf3ba0
 */

static void ehci_queues_rip_unused(EHCIState *ehci, int async, int flush)

{

    EHCIQueueHead *head = async ? &ehci->aqueues : &ehci->pqueues;

    uint64_t maxage = FRAME_TIMER_NS * ehci->maxframes * 4;

    EHCIQueue *q, *tmp;



    QTAILQ_FOREACH_SAFE(q, head, next, tmp) {

        if (q->seen) {

            q->seen = 0;

            q->ts = ehci->last_run_ns;

            continue;

        }

        if (!flush && ehci->last_run_ns < q->ts + maxage) {

            continue;

        }

        ehci_free_queue(q);

    }

}
