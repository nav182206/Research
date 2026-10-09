/* 
 * Benchmark Sample ID : devign_7977
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_visitor_out_native_list_int(TestOutputVisitorData *data,

                                             const void *unused)

{

    test_native_list(data, unused, USER_DEF_NATIVE_LIST_UNION_KIND_INTEGER);

}
