/* 
 * Benchmark Sample ID : devign_2175
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6d86ae0824bdd6175dd3874688a871e981093888
 */

static void perf_cost(void)

{

    const unsigned long maxcycles = 40000000;

    unsigned long i = 0;

    double duration;

    unsigned long ops;

    Coroutine *co;



    g_test_timer_start();

    while (i++ < maxcycles) {

        co = qemu_coroutine_create(perf_cost_func);

        qemu_coroutine_enter(co, &i);

        qemu_coroutine_enter(co, NULL);

    }

    duration = g_test_timer_elapsed();

    ops = (long)(maxcycles / (duration * 1000));



    g_test_message("Run operation %lu iterations %f s, %luK operations/s, "

                   "%luns per coroutine",

                   maxcycles,

                   duration, ops,

                   (unsigned long)(1000000000 * duration) / maxcycles);

}
