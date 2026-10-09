/* 
 * Benchmark Sample ID : devign_8990
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=47d4be12c3997343e436c6cca89aefbbbeb70863
 */

static void test_qemu_strtoull_invalid(void)

{

    const char *str = "   xxxx  \t abc";

    char f = 'X';

    const char *endptr = &f;

    uint64_t res = 999;

    int err;



    err = qemu_strtoull(str, &endptr, 0, &res);



    g_assert_cmpint(err, ==, 0);

    g_assert(endptr == str);

}
