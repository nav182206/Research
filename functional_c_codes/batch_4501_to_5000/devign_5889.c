/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5889
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e70cdba9f220bef3f3481c663c066c2b80469aa
 */

static void coroutine_fn verify_self(void *opaque)

{

    g_assert(qemu_coroutine_self() == opaque);

}
