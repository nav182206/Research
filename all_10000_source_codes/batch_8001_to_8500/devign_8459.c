/* 
 * Benchmark Sample ID : devign_8459
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0fb6395c0cb5046432a80d608ddde7a3b2f8a9ae
 */

static void test_validate_union_anon(TestInputVisitorData *data,

                                     const void *unused)

{

    UserDefAnonUnion *tmp = NULL;

    Visitor *v;

    Error *errp = NULL;



    v = validate_test_init(data, "42");



    visit_type_UserDefAnonUnion(v, &tmp, NULL, &errp);

    g_assert(!error_is_set(&errp));

    qapi_free_UserDefAnonUnion(tmp);

}
