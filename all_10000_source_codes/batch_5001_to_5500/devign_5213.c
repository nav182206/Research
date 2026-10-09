/* 
 * Benchmark Sample ID : devign_5213
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=47d4be12c3997343e436c6cca89aefbbbeb70863
 */

static void test_qemu_strtoll_empty(void)

{

    const char *str = "";

    char f = 'X';

    const char *endptr = &f;

    int64_t res = 999;

    int err;



    err = qemu_strtoll(str, &endptr, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert_cmpint(res, ==, 0);

    g_assert(endptr == str);

}
