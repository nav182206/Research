/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5850
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d6f723b513a0c3c4e58343b7c52a2f9850861fa0
 */

static void test_qemu_strtol_max(void)

{

    const char *str = g_strdup_printf("%ld", LONG_MAX);

    char f = 'X';

    const char *endptr = &f;

    long res = 999;

    int err;



    err = qemu_strtol(str, &endptr, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, LONG_MAX);

    g_assert(endptr == str + strlen(str));

}
