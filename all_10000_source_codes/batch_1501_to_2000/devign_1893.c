/* 
 * Benchmark Sample ID : devign_1893
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a7afc6b8c13c70e9c40b4f666be80600f8ad0b3d
 */

void qtest_add_func(const char *str, void (*fn))

{

    gchar *path = g_strdup_printf("/%s/%s", qtest_get_arch(), str);

    g_test_add_func(path, fn);


}
