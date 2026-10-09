/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8614
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3f66f764ee25f10d3e1144ebc057a949421b7728
 */

static void test_validate_union_native_list(TestInputVisitorData *data,

                                            const void *unused)

{

    UserDefNativeListUnion *tmp = NULL;

    Visitor *v;

    Error *err = NULL;



    v = validate_test_init(data, "{ 'type': 'integer', 'data' : [ 1, 2 ] }");



    visit_type_UserDefNativeListUnion(v, &tmp, NULL, &err);

    g_assert(!err);

    qapi_free_UserDefNativeListUnion(tmp);

}
