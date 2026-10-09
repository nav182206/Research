/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_306
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fb0c43f34eed8b18678c6e1f481d8564b35c99ed
 */

static coroutine_fn void test_multi_co_schedule_entry(void *opaque)

{

    g_assert(to_schedule[id] == NULL);

    atomic_mb_set(&to_schedule[id], qemu_coroutine_self());



    while (!atomic_mb_read(&now_stopping)) {

        int n;



        n = g_test_rand_int_range(0, NUM_CONTEXTS);

        schedule_next(n);

        qemu_coroutine_yield();



        g_assert(to_schedule[id] == NULL);

        atomic_mb_set(&to_schedule[id], qemu_coroutine_self());

    }

}
