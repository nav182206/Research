/* 
 * Benchmark Sample ID : devign_1954
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void test_lifecycle(void)

{

    Coroutine *coroutine;

    bool done = false;



    /* Create, enter, and return from coroutine */

    coroutine = qemu_coroutine_create(set_and_exit);

    qemu_coroutine_enter(coroutine, &done);

    g_assert(done); /* expect done to be true (first time) */



    /* Repeat to check that no state affects this test */

    done = false;

    coroutine = qemu_coroutine_create(set_and_exit);

    qemu_coroutine_enter(coroutine, &done);

    g_assert(done); /* expect done to be true (second time) */

}
