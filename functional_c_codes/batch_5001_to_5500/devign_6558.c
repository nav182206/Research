/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6558
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=35ecde26018207fe723bec6efbd340db6e9c2d53
 */

static void test_submit_aio(void)

{

    WorkerTestData data = { .n = 0, .ret = -EINPROGRESS };

    data.aiocb = thread_pool_submit_aio(pool, worker_cb, &data,

                                        done_cb, &data);



    /* The callbacks are not called until after the first wait.  */

    active = 1;

    g_assert_cmpint(data.ret, ==, -EINPROGRESS);

    qemu_aio_wait_all();

    g_assert_cmpint(active, ==, 0);

    g_assert_cmpint(data.n, ==, 1);

    g_assert_cmpint(data.ret, ==, 0);

}
