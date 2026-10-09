/* 
 * Benchmark Sample ID : devign_705
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bc7c08a2c375acb7ae4d433054415588b176d34c
 */

static void test_qemu_strtoul_correct(void)

{

    const char *str = "12345 foo";

    char f = 'X';

    const char *endptr = &f;

    unsigned long res = 999;

    int err;



    err = qemu_strtoul(str, &endptr, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, 12345);

    g_assert(endptr == str + 5);

}
