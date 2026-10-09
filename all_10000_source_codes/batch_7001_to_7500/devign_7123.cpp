/* 
 * Benchmark Sample ID : devign_7123
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=acfb23ad3dd8d0ab385a10e483776ba7dcf927ad
 */

static void test_bh_flush(void)

{

    BHTestData data = { .n = 0 };

    data.bh = aio_bh_new(ctx, bh_test_cb, &data);



    qemu_bh_schedule(data.bh);

    g_assert_cmpint(data.n, ==, 0);



    wait_for_aio();

    g_assert_cmpint(data.n, ==, 1);



    g_assert(!aio_poll(ctx, false));

    g_assert_cmpint(data.n, ==, 1);

    qemu_bh_delete(data.bh);

}
