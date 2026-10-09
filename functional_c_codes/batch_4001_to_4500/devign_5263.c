/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5263
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void validate_test_add(const char *testpath,

                               TestInputVisitorData *data,

                               void (*test_func)(TestInputVisitorData *data, const void *user_data))

{

    g_test_add(testpath, TestInputVisitorData, data, NULL, test_func,

               validate_teardown);

}
