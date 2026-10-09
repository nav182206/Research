/* 
 * Benchmark Sample ID : devign_2752
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_validate_alternate(TestInputVisitorData *data,

                                    const void *unused)

{

    UserDefAlternate *tmp = NULL;

    Visitor *v;



    v = validate_test_init(data, "42");



    visit_type_UserDefAlternate(v, NULL, &tmp, &error_abort);

    qapi_free_UserDefAlternate(tmp);

}
