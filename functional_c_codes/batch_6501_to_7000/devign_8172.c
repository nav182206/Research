/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8172
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=19dfc44a94f759848a0f7de7378b2f8b9af6b5d0
 */

static void qed_check_for_leaks(QEDCheck *check)

{

    BDRVQEDState *s = check->s;

    size_t i;



    for (i = s->header.header_size; i < check->nclusters; i++) {

        if (!qed_test_bit(check->used_clusters, i)) {

            check->result->leaks++;

        }

    }

}
