/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1389
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_visitor_in_number(TestInputVisitorData *data,

                                   const void *unused)

{

    double res = 0, value = 3.14;

    Visitor *v;



    v = visitor_input_test_init(data, "%f", value);



    visit_type_number(v, NULL, &res, &error_abort);

    g_assert_cmpfloat(res, ==, value);

}
