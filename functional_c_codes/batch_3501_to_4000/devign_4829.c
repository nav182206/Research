/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4829
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void do_order_test(void)

{

    Coroutine *co;



    co = qemu_coroutine_create(co_order_test);

    record_push(1, 1);

    qemu_coroutine_enter(co, NULL);

    record_push(1, 2);

    g_assert(!qemu_in_coroutine());

    qemu_coroutine_enter(co, NULL);

    record_push(1, 3);

    g_assert(!qemu_in_coroutine());

}
