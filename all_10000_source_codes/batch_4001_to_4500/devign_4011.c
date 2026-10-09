/* 
 * Benchmark Sample ID : devign_4011
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8a805c222caa0e20bf11d2267f726d0bb5917d94
 */

static void test_submit_aio(void)

{

    WorkerTestData data = { .n = 0, .ret = -EINPROGRESS };

    data.aiocb = thread_pool_submit_aio(worker_cb, &data, done_cb, &data);



    /* The callbacks are not called until after the first wait.  */

    active = 1;

    g_assert_cmpint(data.ret, ==, -EINPROGRESS);

    qemu_aio_flush();

    g_assert_cmpint(active, ==, 0);

    g_assert_cmpint(data.n, ==, 1);

    g_assert_cmpint(data.ret, ==, 0);

}
