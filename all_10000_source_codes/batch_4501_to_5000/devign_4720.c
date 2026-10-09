/* 
 * Benchmark Sample ID : devign_4720
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=35ecde26018207fe723bec6efbd340db6e9c2d53
 */

static void test_submit(void)

{

    WorkerTestData data = { .n = 0 };

    thread_pool_submit(pool, worker_cb, &data);

    qemu_aio_wait_all();

    g_assert_cmpint(data.n, ==, 1);

}
