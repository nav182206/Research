/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9422
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void test_yield(void)

{

    Coroutine *coroutine;

    bool done = false;

    int i = -1; /* one extra time to return from coroutine */



    coroutine = qemu_coroutine_create(yield_5_times);

    while (!done) {

        qemu_coroutine_enter(coroutine, &done);

        i++;

    }

    g_assert_cmpint(i, ==, 5); /* coroutine must yield 5 times */

}
