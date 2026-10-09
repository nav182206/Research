/* 
 * Benchmark Sample ID : devign_6147
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9bc9732faeff09828fe38c0ebe2401ee131a6fca
 */

static void nbd_coroutine_end(NbdClientSession *s,

    struct nbd_request *request)

{

    int i = HANDLE_TO_INDEX(s, request->handle);

    s->recv_coroutine[i] = NULL;

    if (s->in_flight-- == MAX_NBD_REQUESTS) {

        qemu_co_mutex_unlock(&s->free_sema);

    }

}
