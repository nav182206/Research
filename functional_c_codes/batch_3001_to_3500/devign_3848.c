/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3848
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void perf_yield(void)

{

    unsigned int i, maxcycles;

    double duration;



    maxcycles = 100000000;

    i = maxcycles;

    Coroutine *coroutine = qemu_coroutine_create(yield_loop);



    g_test_timer_start();

    while (i > 0) {

        qemu_coroutine_enter(coroutine, &i);

    }

    duration = g_test_timer_elapsed();



    g_test_message("Yield %u iterations: %f s\n",

        maxcycles, duration);

}
