/* 
 * Benchmark Sample ID : devign_9999
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bc7c08a2c375acb7ae4d433054415588b176d34c
 */

static void test_qemu_strtoull_full_max(void)

{

    char *str = g_strdup_printf("%lld", ULLONG_MAX);

    uint64_t res = 999;

    int err;



    err = qemu_strtoull(str, NULL, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, ULLONG_MAX);

    g_free(str);

}
