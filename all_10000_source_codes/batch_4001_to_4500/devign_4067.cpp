/* 
 * Benchmark Sample ID : devign_4067
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=acfb23ad3dd8d0ab385a10e483776ba7dcf927ad
 */

static void test_bh_delete_from_cb(void)

{

    BHTestData data1 = { .n = 0, .max = 1 };



    data1.bh = aio_bh_new(ctx, bh_delete_cb, &data1);



    qemu_bh_schedule(data1.bh);

    g_assert_cmpint(data1.n, ==, 0);



    wait_for_aio();

    g_assert_cmpint(data1.n, ==, data1.max);

    g_assert(data1.bh == NULL);



    g_assert(!aio_poll(ctx, false));

}
