/* 
 * Benchmark Sample ID : devign_1229
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=11b7b07f8a15879134a54e73fade98d5e11e04f8
 */

char *qdist_pr_plain(const struct qdist *dist, size_t n)

{

    struct qdist binned;

    char *ret;



    if (dist->n == 0) {

        return NULL;

    }

    qdist_bin__internal(&binned, dist, n);

    ret = qdist_pr_internal(&binned);

    qdist_destroy(&binned);

    return ret;

}
