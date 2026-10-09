/* 
 * Benchmark Sample ID : devign_3170
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6b2fef739127ee6135d5ccc2da0bf1f3bebf66b7
 */

static void coroutine_fn verify_entered_step_2(void *opaque)

{

    Coroutine *caller = (Coroutine *)opaque;



    g_assert(qemu_coroutine_entered(caller));

    g_assert(qemu_coroutine_entered(qemu_coroutine_self()));

    qemu_coroutine_yield();



    /* Once more to check it still works after yielding */

    g_assert(qemu_coroutine_entered(caller));

    g_assert(qemu_coroutine_entered(qemu_coroutine_self()));

    qemu_coroutine_yield();

}
