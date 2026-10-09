/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8895
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void nbd_recv_coroutines_enter_all(NbdClientSession *s)

{

    int i;



    for (i = 0; i < MAX_NBD_REQUESTS; i++) {

        if (s->recv_coroutine[i]) {

            qemu_coroutine_enter(s->recv_coroutine[i], NULL);

        }

    }

}
