/* 
 * Benchmark Sample ID : devign_8173
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d6f723b513a0c3c4e58343b7c52a2f9850861fa0
 */

static void test_qemu_strtol_full_max(void)

{

    const char *str = g_strdup_printf("%ld", LONG_MAX);

    long res;

    int err;



    err = qemu_strtol(str, NULL, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, LONG_MAX);

}
