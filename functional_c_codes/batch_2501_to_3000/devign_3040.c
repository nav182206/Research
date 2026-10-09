/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3040
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af7e9e74c6a62a5bcd911726a9e88d28b61490e0
 */

static int IRQ_get_next(OpenPICState *opp, IRQ_queue_t *q)

{

    if (q->next == -1) {

        /* XXX: optimize */

        IRQ_check(opp, q);

    }



    return q->next;

}
