/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9753
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=47d4be12c3997343e436c6cca89aefbbbeb70863
 */

static void test_qemu_strtoll_full_empty(void)

{

    const char *str = "";

    int64_t res = 999;

    int err;



    err = qemu_strtoll(str, NULL, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, 0);

}
