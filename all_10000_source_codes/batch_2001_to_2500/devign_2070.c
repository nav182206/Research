/* 
 * Benchmark Sample ID : devign_2070
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a805c222caa0e20bf11d2267f726d0bb5917d94
 */

static void test_submit(void)

{

    WorkerTestData data = { .n = 0 };

    thread_pool_submit(worker_cb, &data);

    qemu_aio_flush();

    g_assert_cmpint(data.n, ==, 1);

}
