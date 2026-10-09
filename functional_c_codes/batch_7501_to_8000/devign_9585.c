/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9585
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void coroutine_fn nest(void *opaque)

{

    NestData *nd = opaque;



    nd->n_enter++;



    if (nd->n_enter < nd->max) {

        Coroutine *child;



        child = qemu_coroutine_create(nest);

        qemu_coroutine_enter(child, nd);

    }



    nd->n_return++;

}
