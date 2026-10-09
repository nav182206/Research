/* 
 * Benchmark Sample ID : devign_6086
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

static void raw_aio_remove(RawAIOCB *acb)

{

    RawAIOCB **pacb;



    /* remove the callback from the queue */

    pacb = &posix_aio_state->first_aio;

    for(;;) {

        if (*pacb == NULL) {

            fprintf(stderr, "raw_aio_remove: aio request not found!\n");

            break;

        } else if (*pacb == acb) {

            *pacb = acb->next;

            qemu_aio_release(acb);

            break;

        }

        pacb = &(*pacb)->next;

    }

}
