/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8383
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4be23939ab0d7019c7e59a37485b416fbbf0f073
 */

static int ehci_state_waitlisthead(EHCIState *ehci,  int async)

{

    EHCIqh qh;

    int i = 0;

    int again = 0;

    uint32_t entry = ehci->asynclistaddr;



    /* set reclamation flag at start event (4.8.6) */

    if (async) {

        ehci_set_usbsts(ehci, USBSTS_REC);

    }



    ehci_queues_rip_unused(ehci, async);



    /*  Find the head of the list (4.9.1.1) */

    for(i = 0; i < MAX_QH; i++) {

        get_dwords(ehci, NLPTR_GET(entry), (uint32_t *) &qh,

                   sizeof(EHCIqh) >> 2);

        ehci_trace_qh(NULL, NLPTR_GET(entry), &qh);



        if (qh.epchar & QH_EPCHAR_H) {

            if (async) {

                entry |= (NLPTR_TYPE_QH << 1);

            }



            ehci_set_fetch_addr(ehci, async, entry);

            ehci_set_state(ehci, async, EST_FETCHENTRY);

            again = 1;

            goto out;

        }



        entry = qh.next;

        if (entry == ehci->asynclistaddr) {

            break;

        }

    }



    /* no head found for list. */



    ehci_set_state(ehci, async, EST_ACTIVE);



out:

    return again;

}
