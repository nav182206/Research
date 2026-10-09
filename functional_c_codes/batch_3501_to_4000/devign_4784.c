/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4784
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d6f723b513a0c3c4e58343b7c52a2f9850861fa0
 */

static void test_qemu_strtoull_full_max(void)

{

    const char *str = g_strdup_printf("%lld", ULLONG_MAX);

    uint64_t res = 999;

    int err;



    err = qemu_strtoull(str, NULL, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, ULLONG_MAX);

}
