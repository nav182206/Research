/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5909
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af7e9e74c6a62a5bcd911726a9e88d28b61490e0
 */

static void IRQ_check(OpenPICState *opp, IRQ_queue_t *q)

{

    int next, i;

    int priority;



    next = -1;

    priority = -1;



    if (!q->pending) {

        /* IRQ bitmap is empty */

        goto out;

    }



    for (i = 0; i < opp->max_irq; i++) {

        if (IRQ_testbit(q, i)) {

            DPRINTF("IRQ_check: irq %d set ipvp_pr=%d pr=%d\n",

                    i, IPVP_PRIORITY(opp->src[i].ipvp), priority);

            if (IPVP_PRIORITY(opp->src[i].ipvp) > priority) {

                next = i;

                priority = IPVP_PRIORITY(opp->src[i].ipvp);

            }

        }

    }



out:

    q->next = next;

    q->priority = priority;

}
