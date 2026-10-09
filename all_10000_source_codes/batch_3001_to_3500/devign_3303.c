/* 
 * Benchmark Sample ID : devign_3303
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

void qsb_free(QEMUSizedBuffer *qsb)

{

    size_t i;



    if (!qsb) {

        return;

    }



    for (i = 0; i < qsb->n_iov; i++) {

        g_free(qsb->iov[i].iov_base);

    }

    g_free(qsb->iov);

    g_free(qsb);

}
