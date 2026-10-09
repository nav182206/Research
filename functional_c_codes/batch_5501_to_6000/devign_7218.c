/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7218
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_visitor_in_int(TestInputVisitorData *data,

                                const void *unused)

{

    int64_t res = 0, value = -42;

    Visitor *v;



    v = visitor_input_test_init(data, "%" PRId64, value);



    visit_type_int(v, NULL, &res, &error_abort);

    g_assert_cmpint(res, ==, value);

}
