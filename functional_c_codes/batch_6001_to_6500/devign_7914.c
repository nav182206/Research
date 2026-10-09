/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7914
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f17fd4fdf0df3d2f3444399d04c38d22b9a3e1b7
 */

static void test_qemu_strtosz_float(void)

{

    const char *str = "12.345M";

    char *endptr = NULL;

    int64_t res;



    res = qemu_strtosz(str, &endptr);

    g_assert_cmpint(res, ==, 12.345 * M_BYTE);

    g_assert(endptr == str + 7);

}
