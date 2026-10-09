/* 
 * Benchmark Sample ID : devign_2302
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bc7c08a2c375acb7ae4d433054415588b176d34c
 */

static void test_qemu_strtoull_hex(void)

{

    const char *str = "0123";

    char f = 'X';

    const char *endptr = &f;

    uint64_t res = 999;

    int err;



    err = qemu_strtoull(str, &endptr, 16, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, 0x123);

    g_assert(endptr == str + strlen(str));



    str = "0x123";

    endptr = &f;

    res = 999;

    err = qemu_strtoull(str, &endptr, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, 0x123);

    g_assert(endptr == str + strlen(str));

}
