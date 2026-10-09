/* 
 * Benchmark Sample ID : devign_1448
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8ee5e4c476d5b0654d8f1271a2b7c065acc486e
 */

static void run_dependent_requests(BDRVQcowState *s, QCowL2Meta *m)

{

    /* Take the request off the list of running requests */

    if (m->nb_clusters != 0) {

        QLIST_REMOVE(m, next_in_flight);

    }



    /* Restart all dependent requests */

    if (!qemu_co_queue_empty(&m->dependent_requests)) {

        qemu_co_mutex_unlock(&s->lock);

        while(qemu_co_queue_next(&m->dependent_requests));

        qemu_co_mutex_lock(&s->lock);

    }

}
