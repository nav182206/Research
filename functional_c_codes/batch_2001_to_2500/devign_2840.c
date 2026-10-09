/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2840
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a890643958f03aaa344290700093b280cb606c28
 */

static void qht_bucket_reset__locked(struct qht_bucket *head)

{

    struct qht_bucket *b = head;

    int i;



    seqlock_write_begin(&head->sequence);

    do {

        for (i = 0; i < QHT_BUCKET_ENTRIES; i++) {

            if (b->pointers[i] == NULL) {

                goto done;

            }

            b->hashes[i] = 0;

            atomic_set(&b->pointers[i], NULL);

        }

        b = b->next;

    } while (b);

 done:

    seqlock_write_end(&head->sequence);

}
