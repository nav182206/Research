/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2912
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void co_read_response(void *opaque)

{

    BDRVSheepdogState *s = opaque;



    if (!s->co_recv) {

        s->co_recv = qemu_coroutine_create(aio_read_response);

    }



    qemu_coroutine_enter(s->co_recv, opaque);

}
