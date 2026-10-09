/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5335
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=158ef8cbb7e0fe8bb430310924b8bebe5f186e6e
 */

static inline void futex_wake(QemuEvent *ev, int n)

{


    if (n == 1) {

        pthread_cond_signal(&ev->cond);

    } else {

        pthread_cond_broadcast(&ev->cond);

    }


}
